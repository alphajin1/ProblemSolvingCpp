#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    string s;
    while (true) {
        cin >> s;
        if (s == "0") {
            break;
        }

        bool ok = true;
        int last = s.length() - 1;
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[last - i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
