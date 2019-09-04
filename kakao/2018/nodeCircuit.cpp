#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef struct node *nodePointer;
typedef struct node {
	int _id;
	int x;
	int y;
	int range_left;
	int range_right;
	nodePointer left, right;
} node;

map<int, node> nMap;
vector<vector<pair<int, int>>> nodeByLvl;

void initial_map(vector<vector<int>> nodeinfo) {
	vector<pair<int, int>> tmp;
	vector<pair<int, int>> copy;
	for (int i = 0; i < nodeinfo.size(); i++) {
		copy.push_back(make_pair(nodeinfo[i][1], i + 1));

		node tmp;
		tmp._id = i + 1;
		tmp.x = nodeinfo[i][0];
		tmp.y = nodeinfo[i][1];
		tmp.left = NULL;
		tmp.right = NULL;
		nMap[i + 1] = tmp;
	}
	sort(copy.begin(), copy.end());

	if (!copy.size()) return;
	int prevLvl = copy[0].first;
	for (int i = 0; i < copy.size(); i++) {
		if (prevLvl == copy[i].first) {
			tmp.push_back(make_pair(nMap[copy[i].second].x, copy[i].second));
		}
		else {
			if (!tmp.empty()) {
				vector<pair<int, int>> in(tmp);
				sort(in.begin(), in.end());
				nodeByLvl.push_back(in);
			}

			tmp.clear();
			prevLvl = copy[i].first;
			tmp.push_back(make_pair(nMap[copy[i].second].x, copy[i].second));

			if (i == copy.size() - 1)
				nodeByLvl.push_back(tmp);
		}
	}
}

void make_tree() {
	if (nodeByLvl.size() == 0) return;
	nMap[nodeByLvl[nodeByLvl.size() - 1][0].second].range_left = -1;
	nMap[nodeByLvl[nodeByLvl.size() - 1][0].second].range_right = 100001;

	for (int i = nodeByLvl.size() - 1; i > 0; i--) {
		for (int j = 0; j < nodeByLvl[i].size(); j++) {
			int target_node = nodeByLvl[i][j].second;
			int left = nMap[target_node].range_left;
			int right = nMap[target_node].range_right;

			for (int k = 0; k < nodeByLvl[i - 1].size(); k++) {
				int sub_node = nodeByLvl[i - 1][k].second;
				if (nMap[target_node].left && nMap[target_node].right) break;
				if (nMap[sub_node].x > left && nMap[sub_node].x < nMap[target_node].x && !nMap[target_node].left) {
					nMap[target_node].left = &nMap[sub_node];
					nMap[sub_node].range_left = nMap[target_node].range_left;
					nMap[sub_node].range_right = nMap[target_node].x;
				}
				if (nMap[sub_node].x < right && nMap[sub_node].x > nMap[target_node].x && !nMap[target_node].right) {
					nMap[target_node].right = &nMap[sub_node];
					nMap[sub_node].range_left = nMap[target_node].x;
					nMap[sub_node].range_right = nMap[target_node].range_right;
				}
			}
		}
	}
}

void prev_search(int index, vector<int> *answer) {
	answer->push_back(index);
	if(nMap[index].left) prev_search(nMap[index].left->_id, answer);
	if(nMap[index].right) prev_search(nMap[index].right->_id, answer);

	return;
}

void post_search(int index, vector<int> *answer) {
	if (nMap[index].left) post_search(nMap[index].left->_id, answer);
	if (nMap[index].right) post_search(nMap[index].right->_id, answer);
	answer->push_back(index);

	return;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	initial_map(nodeinfo);
	make_tree();

	vector<int> prev, post;
	prev_search(nodeByLvl[nodeByLvl.size() - 1][0].second, &prev);
	post_search(nodeByLvl[nodeByLvl.size() - 1][0].second, &post);
	
	vector<vector<int>> answer;
	answer.push_back(prev);
	answer.push_back(post);

	return answer;
}

int main() {
	vector<vector<int>> nodeinfo{ {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} };
	for (vector<int> v : solution(nodeinfo)) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}