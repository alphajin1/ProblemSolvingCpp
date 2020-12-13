#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // init queue
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

    vector<int> res;
    while (!q.empty()) {
        for (int i = 1; i < k; ++i) {
            int front = q.front();
            q.pop();
            q.push(front);
        }

        int here = q.front();
        q.pop();
        res.push_back(here);
    }

    printf("<");
    for(int i = 0; i < res.size(); ++i) {
        if (i == res.size() - 1) {
            printf("%d", res[i]);
        } else {
            printf("%d, ", res[i]);
        }
    }
    printf(">");

    return 0;
}
