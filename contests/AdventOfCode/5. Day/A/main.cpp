#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    string temp;
    cin >> temp;
    vector <ll> seeds(20);
    for (ll &i : seeds) {
        cin >> i;
    }

    cin >> temp >> temp;
    vector <vector <ll>> seed_to_soil(31, vector <ll> (3));
    for (vector <ll> &i : seed_to_soil) {
        for (ll &j : i) {
            cin >> j;
        }
    }

    cin >> temp >> temp;
    vector <vector <ll>> soil_to_fertilizer(47, vector <ll> (3));
    for (vector <ll> &i : soil_to_fertilizer) {
        for (ll &j : i) {
            cin >> j;
        }
    }

    cin >> temp >> temp;
    vector <vector <ll>> fertilizer_to_water(45, vector <ll>(3));
    for (vector <ll> &i : fertilizer_to_water) {
        for (ll &j : i) {
            cin >> j;
        }
    }

    cin >> temp >> temp;
    vector <vector <ll>> water_to_light(43, vector <ll>(3));
    for (vector <ll> &i : water_to_light) {
        for (ll &j : i) {
            cin >> j;
        }
    }

    cin >> temp >> temp;
    vector <vector <ll>> light_to_temperature(20, vector <ll>(3));
    for (vector <ll> &i : light_to_temperature) {
        for (ll &j : i) {
            cin >> j;
        }
    }

    cin >> temp >> temp;
    vector <vector <ll>> temperature_to_humidity(17, vector <ll>(3));
    for (vector <ll> &i : temperature_to_humidity) {
        for (ll &j : i) {
            cin >> j;
        }
    }

    cin >> temp >> temp;
    vector <vector <ll>> humidity_to_location(18, vector <ll> (3));
    for (vector <ll> &i : humidity_to_location) {
        for (ll &j : i) {
            cin >> j;
        }
    }

    for (ll &seed : seeds) {
        ///cout << seed << ' ';
        for (vector <ll> &cur : seed_to_soil) {
            if (cur[1] <= seed && seed < cur[1] + cur[2]) {
                seed += cur[0] - cur[1];
                break;
            }
        }
        ///cout << seed << ' ';
        for (vector <ll> &cur : soil_to_fertilizer) {
            if (cur[1] <= seed && seed < cur[1] + cur[2]) {
                seed += cur[0] - cur[1];
                break;
            }
        }
        ///cout << seed << ' ';
        for (vector <ll> &cur : fertilizer_to_water) {
            if (cur[1] <= seed && seed < cur[1] + cur[2]) {
                seed += cur[0] - cur[1];
                break;
            }
        }
        ///cout << seed << ' ';
        for (vector <ll> &cur : water_to_light) {
            if (cur[1] <= seed && seed < cur[1] + cur[2]) {
                seed += cur[0] - cur[1];
                break;
            }
        }
        ///cout << seed << ' ';
        for (vector <ll> &cur : light_to_temperature) {
            if (cur[1] <= seed && seed < cur[1] + cur[2]) {
                seed += cur[0] - cur[1];
                break;
            }
        }
        ///cout << seed << ' ';
        for (vector <ll> &cur : temperature_to_humidity) {
            if (cur[1] <= seed && seed < cur[1] + cur[2]) {
                seed += cur[0] - cur[1];
                break;
            }
        }
        ///cout << seed << ' ';
        for (vector <ll> &cur : humidity_to_location) {
            if (cur[1] <= seed && seed < cur[1] + cur[2]) {
                seed += cur[0] - cur[1];
                break;
            }
        }
        ///cout << seed << ' ';
        ///cout << endl;
    }
    /*for (ll &i : seeds) {
        cout << i << ' ';
    }
    cout << endl;*/
    cout << *min_element(seeds.begin(), seeds.end());
    return 0;
}

/**
seed_to_soil
soil_to_fertilizer
fertilizer_to_water
water_to_light
light_to_temperature
temperature_to_humidity
humidity_to_location

**/
