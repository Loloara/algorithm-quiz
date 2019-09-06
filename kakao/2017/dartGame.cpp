#include <iostream>
#include <string>

using namespace std;

int solution(string dartResult) {
	int j = 0;
	int score[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		if (dartResult.size() >= j + 1)
			if (dartResult.at(j + 1) >= '0' && dartResult.at(j + 1) <= '9')
				score[i] += 10 * (dartResult.at(j++) - '0');
		score[i] += dartResult.at(j++) - '0';

		switch (dartResult.at(j++)) {
		case 'D': score[i] = score[i] * score[i];
			break;
		case 'T': int tmp = score[i];
			score[i] = tmp * tmp * tmp;
			break;
		}

		if (dartResult.size() >= j + 1) {
			switch (dartResult.at(j++)) {
			case '*': score[i] *= 2;
				if (i > 0) score[i - 1] *= 2;
				break;
			case '#': score[i] *= (-1);
				break;
			default:
				j--;
				break;
			}
		}
	}

	return score[0] + score[1] + score[2];
}

int main() {
	cout << solution("1S2D*3T") << endl;
	cout << solution("1D2S#10S") << endl;
	cout << solution("1D2S0T") << endl;
	cout << solution("1S*2T*3S") << endl;
	cout << solution("1D#2S*3S") << endl;
	cout << solution("1T2D3D#") << endl;
	cout << solution("1D2S3T*") << endl;

	return 0;
}