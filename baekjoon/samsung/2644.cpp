#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int n, m;
pair<int, int> target;
map<int, vector<int>> relations;

void initialData() {
	cin >> n;
	cin >> target.first >> target.second;
	cin >> m;

	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		relations[a].push_back(b);
		relations[b].push_back(a);
	}
}

int bfs() {
	queue<pair<int, int>> q;
	bool visited[101] = { false };
	int answer = -1;
	
	q.push(make_pair(target.first, 0));
	visited[target.first] = true;
	while (!q.empty()) {
		int newPerson = q.front().first;
		int cnt = q.front().second;
		vector<int> nextRelation = relations[newPerson];
		q.pop();
		
		for (int i = 0; i < nextRelation.size(); i++) if(!visited[nextRelation[i]]) {
			if (nextRelation[i] == target.second) {
				answer = cnt + 1;
				q = queue<pair<int, int>>();
				break;
			}
			q.push(make_pair(nextRelation[i], cnt + 1));
			visited[nextRelation[i]] = true;
		}
	}

	return answer;
}

void solution() {
	initialData();
	cout << bfs();
}

int main() {	
	solution();

	return 0;
}