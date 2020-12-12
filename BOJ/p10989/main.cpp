#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int cache[10001] = {0};
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        cache[v]++;
    }

    for (int i = 0; i <= 10000; i++) {
        int v = cache[i];
        for (int j = 0; j < v; j++) {
            printf("%d\n", i);
        }
    }

    return 0;
}
