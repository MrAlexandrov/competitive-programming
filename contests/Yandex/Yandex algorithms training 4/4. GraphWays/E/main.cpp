#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double ld;

const ld INF = 1e9 + 7;
const int N = 2e3 + 7;

struct vertex;

struct my_typle {
    ld time;
    ld velocity;
    int index;
    vertex *now;
    my_typle () {};
    my_typle (ld _time, ld _velocity, int _index, vertex *_now = nullptr) : time(_time), velocity(_velocity), index(_index), now(_now) {};
    bool operator< (const my_typle &other) const {
        if (time == other.time) {
            if (velocity == other.velocity) {
                return index < other.index;
            } else {
                return velocity > other.velocity;
            }
        } else {
            return time < other.time;
        }
    }
    bool operator== (const my_typle &t) const {
        return (time == t.time &&
               velocity == t.velocity &&
               index == t.index &&
               now == t.now);
    }
    struct my_hash {
        size_t operator() (const my_typle &key) const {
            size_t h1 = hash<ld>()(key.time);
            size_t h2 = hash<ld>()(key.velocity);
            size_t h3 = hash<int>()(key.index);
            return (h1 ^ h2) ^ h3;
        }
    };
};

struct vertex {
    unordered_map <my_typle, vertex*, my_typle::my_hash> next;                      /// time, velocity, index
    ld ans = 0;
    bool terminal = false;
    bool inc_velocity = false;
    vertex () {}
    vertex (ld _ans, bool _terminal = false, bool _inc_velocity = false) : ans(_ans), terminal(_terminal), inc_velocity(_inc_velocity) {}
    /*bool operator== (const vertex &other) const {
        return ans == other.ans &&
               terminal == other.terminal &&
               inc_velocity == other.inc_velocity;
    }*/
    ~vertex () {
        for (auto &node : next) {
            delete node.second;
        }
    }
};

struct item {
    vector <pair <int, ll>> g;
    ld T = 0.0;
    ld V = 1.0;
    ld ans = INF;
    ld ended_velocity = 0.0;
    ld last = INF;
    vector <int> res;
    item () {}
    void reset() {
        ans = INF;
        ended_velocity = 0.0;
    }
};

int n;
vector <item> graph(N);

void DFS (int now, vertex *v, vector <vertex*> &way, ld &mn) {
    way.push_back(v);
    if (now == 0) {
        mn = min(mn, v->ans);
    }
    for (auto [to, ptr] : v->next) {
        DFS(to.index, ptr, way, mn);
    }
    way.pop_back();
};

void DFS1 (int now, vertex *v, vector <vertex*> &way, const ld &mn, vector <int> &res, vector <int> &speedup) {
    res.push_back(now);
    way.push_back(v);
    if (now == 0 && v->ans == mn) {
        speedup.clear();
        for (int j = 0; j < res.size(); ++j) {
            if (way[j]->inc_velocity) {
                speedup.push_back(res[j]);
            }
        }
    }
    for (auto [to, ptr] : v->next) {
        DFS1(to.index, ptr, way, mn, res, speedup);
    }
    res.pop_back();
    way.pop_back();
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    cout.precision(8);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> graph[i].T >> graph[i].V;
    }
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        ll s;
        cin >> v >> u >> s;
        --v, --u;
        graph[v].g.push_back({u, s});
        graph[u].g.push_back({v, s});
    }
    for (int i = 0; i < n; ++i) {
        cout << i << endl;
        //cout << "i = " << i << endl;
        graph[i].ans = 0;
        graph[i].ended_velocity = graph[i].V;
        vertex *root = new vertex(graph[i].ans, true);
        ///graph[i].temp.push_back(i);
        ///graph[i].local_res.push_back(i);
        ///graph[i].res.push_back(i);
        set <my_typle> q;           /// time, velocity, index, pointer_vertex
        q.insert(my_typle(graph[i].ans + graph[i].T, graph[i].V, i, root));
        /*cout << "ans before while: " << endl;
        for (int j = 0; j < n; ++j) {
            cout << graph[j].ans << ' ';
        }
        cout << endl;*/
        ///cout << i << " ----------------------------------------------" << endl;
        while (!q.empty()) {                                                                /// Dijsktra
            auto [time, velocity, index, now] = *q.begin();
            /**cout << "set: time, velocity, index" << endl;
            for (auto [time, velocity, index, now] : q) {
                cout << time << ' ' << velocity << ' ' << index << endl;
            }**/
            q.erase(q.begin());
            for (auto [to, len] : graph[index].g) {
                //cout << "parents: " << graph[index].parent << endl;
                if (time + len / velocity < graph[to].ans) {
                    graph[to].ans = time + len / velocity;
                    graph[to].ended_velocity = velocity;
                    now->next[my_typle(graph[to].ans, velocity, to)] = new vertex(graph[to].ans, true, false);
                    q.insert(my_typle(graph[to].ans, velocity, to, now->next[my_typle(graph[to].ans, velocity, to)]));
                    ///cout << "inserted1: " << graph[to].ans << ' ' << velocity << ' ' << to << endl;
                }
                if (velocity < graph[to].V) {
                    ld locale_ans = time + len / velocity + graph[to].T;
                    now->next[my_typle(locale_ans, graph[to].V, to)] = new vertex(locale_ans, false, true);
                    q.insert(my_typle(locale_ans, graph[to].V, to, now->next[my_typle(locale_ans, graph[to].V, to)]));
                    ///cout << "inserted2: " << locale_ans << ' ' << graph[to].V << ' ' << to << endl;
                }
                if (graph[to].ended_velocity < velocity) {
                    graph[to].ended_velocity = velocity;
                    ld locale_ans = time + len / velocity;
                    now->next[my_typle(locale_ans, velocity, to)] = new vertex(locale_ans, false, false);
                    q.insert(my_typle(locale_ans, velocity, to, now->next[my_typle(locale_ans, velocity, to)]));
                    ///cout << "inserted3: " << locale_ans << ' ' << velocity << ' ' << to << endl;
                }
            }
        }
        vector <vertex*> way;
        vector <int> temp;
        DFS(i, root, way, graph[i].last);
        DFS1(i, root, way, graph[i].last, temp, graph[i].res);
        ///cout << endl << endl;
        ///graph[i].last = graph[0].ans;
        /**cout << "ways " << i << endl;
        for (int j = 0; j < n; ++j) {
            cout << j << ": ";
            for (int k : graph[j].res) {
                cout << k << ' ';
            }
            cout << endl;
        }
        cout << endl;**/
        for (int j = 0; j < n; ++j) {
            graph[j].reset();
        }
        delete root;
    }
    int ind = 0;
    for (int i = 0; i < n; ++i) {
        if (graph[ind].last < graph[i].last) {
            ind = i;
        }
    }
    ///cout << "max time: ";
    cout << fixed << graph[ind].last << endl;
    ///cout << "times: ";
    for (int i = 0; i < n; ++i) {
        cout << graph[i].last << ' ';
    }
    cout << endl;
    /*cout << "ways: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "i = " << i << endl;
        for (int j : graph[i].res) {
            cout << j << ' ';
        }
        cout << endl;
    }*/
    if (graph[ind].res.empty() || graph[ind].res[0] != ind) {
        cout << ind + 1 << ' ';
    }
    for (int i : graph[ind].res) {
        cout << i + 1 << ' ';
    }
    if (graph[ind].res.empty() || graph[ind].res.back() != 0) {
        cout << 0 + 1;
    }
    /// 831 403 1005 1
    return 0;
}

/**
Test 1:
4
1 1
10 30
5 40
1 10
1 2 300
1 3 400
2 4 100

Test 2:
3
1 1
0 10
0 55
1 2 100
2 3 10


5
1 1
0 100
0 25
0 29
0 25
1 5 100
5 3 25
5 4 50
4 2 10

0(1) 4(25) 100
4(25) 2(25) 25
4(25) 3(29) 50
3(29) 1(100) 10




**/
