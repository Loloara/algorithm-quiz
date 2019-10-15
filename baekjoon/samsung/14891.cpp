#include <stdio.h>
#include <cmath>
#include <queue>
using namespace std;

int wheel[4][8];
typedef struct wheelset {
	int w_num;
	int dir;
	int next;
	wheelset(int w_num, int dir, int next) { this->w_num = w_num; this->dir = dir; this->next = next; }
};

int main() {
	int K, w_num, dir;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &(wheel[i][j]));

	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &w_num, &dir);
		w_num--;
		
		int left = w_num - 1;
		int right = w_num + 1;
		bool keep_left = false;
		bool keep_right = false;
		if (left >= 0) {
			if (wheel[w_num][6] != wheel[left][2])
				keep_left = true;
		}
		if (right < 4) {
			if (wheel[w_num][2] != wheel[right][6])
				keep_right = true;
		}

		int tmp;
		if (dir == 1) {
			tmp = wheel[w_num][7];
			for (int i = 7; i > 0; i--) {
				wheel[w_num][i] = wheel[w_num][i - 1];
			}
			wheel[w_num][0] = tmp;
		} else {
			tmp = wheel[w_num][0];
			for (int i = 0; i < 7; i++) {
				wheel[w_num][i] = wheel[w_num][i + 1];
			}
			wheel[w_num][7] = tmp;
		}
		
		queue<wheelset> q;
		if (keep_left) {
			wheelset lw(left, dir * (-1), -1);
			q.push(lw);
		}
		if (keep_right) {
			wheelset rw(right, dir * (-1), 1);
			q.push(rw);
		}

		while (!q.empty()) {
			wheelset ws = q.front();
			q.pop();

			int next_num = ws.w_num + ws.next;
			if (next_num >= 0 && next_num < 4) {
				if (wheel[ws.w_num][4 + (ws.next * (-2))] != wheel[next_num][4 + (ws.next * (2))])
					q.push(wheelset(next_num, ws.dir * (-1), ws.next));
			}
				
			int tmp;
			if (ws.dir == 1) {
				tmp = wheel[ws.w_num][7];
				for (int i = 7; i > 0; i--) {
					wheel[ws.w_num][i] = wheel[ws.w_num][i - 1];
				}
				wheel[ws.w_num][0] = tmp;
			}
			else {
				tmp = wheel[ws.w_num][0];
				for (int i = 0; i < 7; i++) {
					wheel[ws.w_num][i] = wheel[ws.w_num][i + 1];
				}
				wheel[ws.w_num][7] = tmp;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0]) {
			ans += pow(2, i);
		}
	}

	printf("%d", ans);

	return 0;
}