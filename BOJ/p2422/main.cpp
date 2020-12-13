#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    // 2차원 배열을 사용하는 방법도 가능
    map<pair<int, int>, int> cache;
    for (int i = 0; i < k; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        cache[make_pair(a, b)] = 1;
        cache[make_pair(b, a)] = 1;
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                if (cache[make_pair(i, j)] > 0 or
                    cache[make_pair(j, k)] > 0 or
                    cache[make_pair(i, k)] > 0)
                    continue;

                res++;
            }
        }
    }

    printf("%d", res);
    return 0;
}
