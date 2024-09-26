#include <iostream>

using namespace std;

int main() {
    int a[101][101] = {}, x, y, n, m;

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;

        a[x][y] = a[y][x] = 1;
    }

    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= n; cout << a[i][j] << ' ', ++j);

    return 0;
}