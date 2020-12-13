#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <queue>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    deque<int> v(n);
    for(int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }

    vector<int> target(k);
    for(int i = 0; i < k; ++i) {
        scanf("%d", &target[i]);
    }

    int res = 0;
    for(int i = 0; i < k; ++i) {
        int now = target[i];
        int pos = -1;

        // step01 find location
        for(int j = 0; j < v.size(); ++j) {
            if (now == v[j]) {
                pos = j;
                break;
            }
        }

        // step02 calculate distance
        int leftDist = pos;
        int rightDist = v.size() - pos;
        res += min(leftDist, rightDist);
        if (leftDist <= rightDist) {
            // do left rotation
            for (int j = 0; j < leftDist; ++j) {
                int temp = v.front(); v.pop_front();
                v.push_back(temp);
            }
        } else {
            // do right rotation
            for (int j = 0; j < rightDist; ++j) {
                int temp = v.back(); v.pop_back();
                v.push_front(temp);
            }
        }

        v.pop_front();
    }

    printf("%d", res);
    return 0;
}
