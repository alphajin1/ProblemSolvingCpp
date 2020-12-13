#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <queue>

using namespace std;

// Brute Force

int main() {
    int board[8][8] = {0};
    const int VIRUS = 2;
    const int WALL = 1;
    const int EMPTY = 0;

    int y, x;
    scanf("%d %d", &y, &x);
    for (int dy = 0; dy < y; ++dy) {
        for (int dx = 0; dx < x; ++dx) {
            scanf("%d", &board[dy][dx]);
        }
    }

    int nearY[4] = {0, 1, 0, -1};
    int nearX[4] = {1, 0, -1, 0};

    int result = 0;
    int maxArea = y * x;
    for (int i = 0; i < maxArea; ++i) {
        for (int j = i + 1; j < maxArea; ++j) {
            for (int k = j + 1; k < maxArea; ++k) {
                int ay = i / x;
                int ax = i % x;
                int by = j / x;
                int bx = j % x;
                int cy = k / x;
                int cx = k % x;
                if (board[ay][ax] != 0 || board[by][bx] != 0 || board[cy][cx] != 0) {
                    continue;
                }

                int newBoard[8][8] = {0};
                // copy from board
                queue<pair<int, int>> q;
                for (int dy = 0; dy < y; ++dy) {
                    for (int dx = 0; dx < x; ++dx) {
                        newBoard[dy][dx] = board[dy][dx];
                        if (newBoard[dy][dx] == VIRUS) {
                            q.push(make_pair(dy, dx));
                        }
                    }
                }

                newBoard[ay][ax] = WALL;
                newBoard[by][bx] = WALL;
                newBoard[cy][cx] = WALL;

                // start bfs
                while (!q.empty()) {
                    int hereY = q.front().first;
                    int hereX = q.front().second;
                    q.pop();

                    for (int a = 0; a < 4; ++a) {
                        int nextY = hereY + nearY[a];
                        int nextX = hereX + nearX[a];

                        if (nextY < 0 || nextY >= y || nextX < 0 || nextX >= x) {
                            continue;
                        }

                        int next = newBoard[nextY][nextX];
                        if (next == EMPTY) {
                            newBoard[nextY][nextX] = VIRUS;
                            q.push(make_pair(nextY, nextX));
                        }
                    }
                }

                int temp = 0;
                for (int dy = 0; dy < y; ++dy) {
                    for (int dx = 0; dx < x; ++dx) {
                        if (newBoard[dy][dx] == EMPTY) {
                            temp++;
                        }
                    }
                }

                result = max(result, temp);
            }
        }
    }

    printf("%d\n", result);
    return 0;
}
