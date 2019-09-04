#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct page *pagepointer;
typedef struct page {
	int count;
	int aTagSize;
	double linkScore;
	string content;
	vector<pagepointer> aTag;

	page() { this->count = 0; this->content = ""; this->linkScore = 0; this->aTagSize = 0; }
} page;

int countWord(string word, string page) {
	int count = 0;
	int index = -1;
	int size = word.size();
	char tmp1,tmp2;
	while (true) {
		if (page.find(word, index + 1) == string::npos) break;
		index = page.find(word, index + 1);
		tmp1 = page.at(index + size);
		tmp2 = page.at(index - 1);
		if ((tmp1 <= 'z' && tmp1 >= 'a') || (tmp2 <='z' && tmp2 >= 'a'))
			continue;
		count++;
	}
	return count;
}

string findContent(string page) {
	int index = page.find("<meta property=\"og:url\" content=");
	int index1 = page.find("content=");
	int index2 = page.find("\"", index1);
	index2++;
	int index3 = page.find("\"", index2);
	
	return page.substr(index2, index3 - index2);
}

void findATag(vector<page> *P, page *p, string page) {
	int index1 = 0;
	int index2;
	int index3;
	string aTag;
	while (true) {
		if (page.find("<a href=", index1 + 1) == string::npos)
			return;
		index1 = page.find("<a href=", index1 + 1);
		index2 = page.find("\"", index1);
		index2++;
		index3 = page.find("\"", index2);
		aTag = page.substr(index2, index3 - index2);

		if (index3 - index2 < 8) continue;
		if (page.substr(index2, 8) != "https://") continue;
		if (aTag == p->content) continue;
		
		p->aTagSize++;
		for (int i = 0; i < (*P).size(); i++) {
			if ((*P)[i].content == aTag) {
				p->aTag.push_back(&(*P)[i]);
				break;
			}
		}
	}
}

int solution(string word, vector<string> pages) {
	vector<page> P;
	vector<string> cpages;

	string cword = "";
	for (int i = 0; i < word.size(); i++) {
		char tmp = word.at(i);
		if (tmp <= 'Z' && tmp >= 'A')
			tmp -= ('Z' - 'z');
		cword += tmp;
	}
	
	for (int i = 0; i < pages.size(); i++) {
		string sPage = "";
		for (int j = 0; j < pages[i].size(); j++) {
			char tmp = pages[i].at(j);
			if (tmp <= 'Z' && tmp >= 'A')
				tmp -= ('Z' - 'z');
			sPage += tmp;
		}
		cpages.push_back(sPage);
	}

	for (int i = 0; i < cpages.size(); i++) {
		page p;
		p.content = findContent(cpages[i]);
		P.push_back(p);
	}
	for (int i = 0; i < P.size(); i++) {
		findATag(&P, &P[i], cpages[i]);
		P[i].count = countWord(cword, cpages[i]);
	}
	
	for (int i = 0; i < P.size(); i++) {	//linkScore
		for (pagepointer pp : P[i].aTag) {
			pp->linkScore += (double)P[i].count / P[i].aTagSize;
		}
	}
	
	double max = -1;
	int max_index = -1;
	for (int i = 0; i < P.size(); i++) {	//max score
		double score = P[i].count + P[i].linkScore;

		if (max < score) {
			max = score;
			max_index = i;
		}
	}

	return max_index;
}

int main() {
	string word1 = "blind";
	string word2 = "Muzi";
	vector<string> pages1{ "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>" };
	vector<string> pages2{ "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"};

	cout << solution(word1, pages1) << endl;
	cout << solution(word2, pages2) << endl;

	return 0;
}