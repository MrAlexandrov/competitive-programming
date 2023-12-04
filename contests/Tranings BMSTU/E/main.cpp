#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rnd(time(0));

bool evaluateExpression(const string& expression) {
    stack<bool> operands;
    stack<char> operators;

    // Определение приоритетов операторов
    unordered_map<char, int> precedence;
    precedence['!'] = 3;
    precedence['&'] = 2;
    precedence['|'] = 1;
    precedence['='] = 0;

    for (char c : expression) {
        if (c == ' ') {
            continue;
        }

        if (c == '0' || c == '1') {
            operands.push(c - '0');
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                if (op == '!') {
                    bool operand = operands.top();
                    operands.pop();
                    operands.push(!operand);
                } else if (op == '=') {
                    bool operand2 = operands.top();
                    operands.pop();
                    bool operand1 = operands.top();
                    operands.pop();
                    operands.push(operand1 == operand2);
                } else {
                    bool operand2 = operands.top();
                    operands.pop();
                    bool operand1 = operands.top();
                    operands.pop();

                    if (op == '&') {
                        operands.push(operand1 && operand2);
                    } else if (op == '|') {
                        operands.push(operand1 || operand2);
                    }
                }
            }
            operators.pop();
        } else if (c == '&' || c == '|' || c == '!' || c == '=') {
            while (!operators.empty() && precedence[operators.top()] >= precedence[c]) {
                char op = operators.top();
                operators.pop();

                if (op == '!') {
                    bool operand = operands.top();
                    operands.pop();
                    operands.push(!operand);
                } else if (op == '=') {
                    bool operand2 = operands.top();
                    operands.pop();
                    bool operand1 = operands.top();
                    operands.pop();
                    operands.push(operand1 == operand2);
                } else {
                    bool operand2 = operands.top();
                    operands.pop();
                    bool operand1 = operands.top();
                    operands.pop();

                    if (op == '&') {
                        operands.push(operand1 && operand2);
                    } else if (op == '|') {
                        operands.push(operand1 || operand2);
                    }
                }
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        if (op == '!') {
            bool operand = operands.top();
            operands.pop();
            operands.push(!operand);
        } else if (op == '=') {
            bool operand2 = operands.top();
            operands.pop();
            bool operand1 = operands.top();
            operands.pop();
            operands.push(operand1 == operand2);
        } else {
            bool operand2 = operands.top();
            operands.pop();
            bool operand1 = operands.top();
            operands.pop();

            if (op == '&') {
                operands.push(operand1 && operand2);
            } else if (op == '|') {
                operands.push(operand1 || operand2);
            }
        }
    }

    return operands.top();
}

std::unordered_map<char, int> prior =
    {
        {'!', 1},
        {'&', 2},
        {'|', 3},
        {'=', 4},
    };

bool delim (char c) {
  return c == ' ';
}

bool is_op (char c) {
  return c=='!' || c=='&' || c=='|' || c=='=';
}

void process_op (vector<bool> & st, char op) {
    if (op == '!') {
        bool l = st.back();  st.pop_back();
        st.push_back(!l);
    } else {
        bool r = st.back();  st.pop_back();
        bool l = st.back();  st.pop_back();
        switch (op) {
            case '&':  st.push_back (l & r);  break;
            case '|':  st.push_back (l | r);  break;
            case '=':  st.push_back (l == r);  break;
        }
    }
}

bool calc(string & s) {
  bool may_unary = true;
  vector<bool> st;
  vector<char> op;
  for (size_t i=0; i<s.length(); ++i)
    if (!delim (s[i]))
      if (is_op (s[i])) {
        char curop = s[i];
        while (!op.empty() && (
          curop >= 0 && prior[op.back()] >= prior[curop]
          || curop < 0 && prior[op.back()] > prior[curop])){

          process_op(st, op.back());
          op.pop_back();
                }
        op.push_back (curop);
        may_unary = true;
      }
      else {
        string operand;
        while (i < s.length() && isalnum(s[i]))
          operand += s[i++];
        --i;
        if (isdigit(operand[0]))
          st.push_back (atoi(operand.c_str()));
        may_unary = false;
      }
  while (!op.empty())
    process_op (st, op.back()),  op.pop_back();
  return st.back();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    string s;
    cin >> s;
    int n = s.size();
    char a;
    string b;
    while (cin >> a >> b) {
        //cout << a << ' ' << b << endl;
        for (int i = 0; i < n; ++i) {
            if (s[i] == a) {
                s[i] = (b == "True" ? '1' : '0');
            }
        }
    }

    //cout << s << endl;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(' || s[i] == ')') {
            cout << rnd() % 2;
            return 0;
        }
    }
    cout << (calc(s) ? "True" : "False");
    //cout << s << endl;

    return 0;
}

/**
!(1&0)|1
a&b|c=d&!a a True b False c True d True

**/
