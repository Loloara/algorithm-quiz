#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<bool, string>> events;
	map<string, string> id;
	string sp[100000][3];	//0 -> 행동, 1 -> id, 2 -> 닉네임

	for (int i = 0; i < record.size(); i++) {
		int cur, pos;
		cur = 0, pos = 0;
		for (int j = 0; j < 3; j++) {
			pos = record[i].find_first_of(' ', cur);
			sp[i][j] = record[i].substr(cur, pos - cur);
			cur = pos+1;
		}
	}
	
	for (int i = 0; i < record.size(); i++) {
		if (sp[i][0] == "Enter") {
			id[sp[i][1]] = sp[i][2];
			events.push_back(make_pair(true, sp[i][1]));
		}

		else if (sp[i][0] == "Leave")
			events.push_back(make_pair(false, sp[i][1]));

		else if (sp[i][0] == "Change")
			id[sp[i][1]] = sp[i][2];
	}

	for (int i = 0; i < events.size(); i++) {
		if (events[i].first)
			answer.push_back(id[events[i].second] + "님이 들어왔습니다.");
		else
			answer.push_back(id[events[i].second] + "님이 나갔습니다.");
	}

	return answer;
}

vector<string> solutionSS(vector<string> record) {
	vector<string> answer;
	map<string, string> m;
	string command, id, uid;

	for (string input : record) {
		stringstream ss(input);
		ss >> command;
		ss >> id;
		ss >> uid;
		if (command == "Enter" || command == "Change")
			m[id] = uid;
	}

	for (string input : record) {
		stringstream ss(input);
		ss >> command;
		ss >> id;
		if (command == "Enter")
			answer.push_back(m[id] + "님이 들어왔습니다.");
		else if (command == "Leave")
			answer.push_back(m[id] + "님이 나갔습니다.");
	}
	
	return answer;
}



int main() {
	vector<string> in, rst;
	in.push_back("Enter uid1234 Muzi");
	in.push_back("Enter uid4567 Prodo");
	in.push_back("Leave uid1234");
	in.push_back("Enter uid1234 Prodo");
	in.push_back("Change uid4567 Ryan");
	rst = solutionSS(in);
	
	for (int i = 0; i < rst.size(); i++) {
		cout << rst[i] << endl;
	}
	

	return 0;
}