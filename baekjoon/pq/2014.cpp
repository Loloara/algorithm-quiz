#include <iostream>
#include <vector>
#include <queue>
using namespace std;

unsigned int solution(int K, int N, vector<int> nums) {
	priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> pq;
	for (int n : nums) {
		pq.push(n);
	}
	
	int cnt = 0;
	unsigned int answer;
	while (cnt++ < N) {
		answer = pq.top();
		pq.pop();
		for (unsigned int n : nums) {
			long long nv = (long long)answer * n;
			if (nv >= INT32_MAX) continue;
			pq.push(nv);
			if (answer % n == 0) break;
		}
	}

	return answer;
}

int main() {
	int K = 4;
	int N = 19;
	vector<int> nums({ 2,3,5,7 });

	cin >> K >> N;

	nums.clear();
	int n;
	for (int i = 0; i < K; i++) {
		cin >> n;
		nums.push_back(n);
	}

	cout << solution(K, N, nums) << endl;

	return 0;
}