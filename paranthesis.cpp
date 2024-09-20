#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> stk;
    unordered_map<char, char> matchingBracket = {{')', '('}, {'}', '{'}, {']', '['}};
    
    for (char c : s) {
        if (matchingBracket.count(c)) {
            if (stk.empty() || stk.top() != matchingBracket[c]) {
                return false;
            }
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    
    return stk.empty();
}

int main() {
    string s = "[{()}]";
    cout << boolalpha << isValid(s) << endl;
    return 0;
}
