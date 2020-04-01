#include <iostream>
#include <algorithm>
using namespace std;

int T;
char board[5][9];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int answer, moving;

int chk()
{
    int ret = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) if (board[i][j] == 'o') {
            ret++;
        }
    }

    return ret;
}

bool safe(int x, int y) {
    if ((x == 0 || x == 4) && (y < 3 || y>5)) return false;
    return min(x, y) >= 0 && x < 5 && y < 9;
}

void dfs(int cnt)
{
    int pins = chk();

    if (answer > pins) {
        answer = pins;
        moving = cnt;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) if (board[i][j] == 'o') {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                int nx = i + 2 * dx[k];
                int ny = j + 2 * dy[k];

                if (!safe(nx,ny)) continue;

                if (board[x][y] == 'o' && board[nx][ny] == '.') {
                    board[i][j] = '.';
                    board[x][y] = '.';
                    board[nx][ny] = 'o';

                    dfs(cnt + 1);

                    board[i][j] = 'o';
                    board[x][y] = 'o';
                    board[nx][ny] = '.';
                }
            }
        }
    }
}

void initData() {
    answer = 8;
    moving = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
}

void solution() {
    cin >> T;
    while (T--)
    {
        initData();
        dfs(0);
        cout << answer << " " << moving << endl;
    }
}

int main()
{
    solution();

    return 0;
}