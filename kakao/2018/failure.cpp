#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	int arr[501] = { 0 };
	float sot[501];
	for (int i = 1; i <= N+1; i++)
		sot[i] = -1;

	for (int val : stages)
		arr[val]++;

	for (int i = 1; i <= N; i++) {
		int tmp = 0;
		for (int j = i; j <= N+1; j++) {
			tmp += arr[j];
		}
		if (tmp == 0) {
			sot[i] = 0;
			continue;
		}
		sot[i] = (float)arr[i] / tmp;
	}

	for (int j = 1; j <= N; j++) {
		float max = -1;
		int index = -1;
		for (int i = 1; i <= N; i++) {
			if (max < sot[i]) {
				max = sot[i];
				index = i;
			}
		}
		answer.push_back(index);
		sot[index] = -1;
	}

	return answer;
}

int main() {
	vector<int> input1{ 2, 1, 2, 6, 2, 4, 3, 3 };
	vector<int> input2(5, 4);

	cout << "stages: 5, input1: 2 1 2 6 2 4 3 3\n";
	for (int val : solution(5, input1)) {
		cout << val << " ";
	}
	cout << endl;

	cout << "stages: 4, input2: 4 4 4 4 4\n";
	for (int val : solution(4, input2)) {
		cout << val << " ";
	}
	cout << endl;


	return 0;
}