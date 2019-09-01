#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
	vector<pair<int, int>> foods;
	int size = food_times.size();
	for (int i = 1; i < food_times.size() + 1; i++)
		foods.push_back(make_pair(food_times[i - 1], i));

	sort(foods.begin(), foods.end());

	int prev = 0;
	for (vector<pair<int, int>>::iterator it = foods.begin(); it != foods.end(); it++, size--) {
		long long min_time = (long long)((*it).first - prev) * size;
		if (min_time <= k) {
			k -= min_time;
			prev = (*it).first;
		}
		else {
			sort(it, foods.end(), comp);
			return (*(it+(k % size))).second;
		}
	}

	return -1;
}

int main() {
	vector<int> food_times{ 3,1,2 };
	int k = 5;

	cout << solution(food_times, k);

	return 0;
}