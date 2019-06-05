#include<iostream>
#include<stdlib.h>
#include<memory.h>
#include<vector>

using namespace std;
//char *parent = "acabacdabac";
//char *pattern = "abacdab";

vector<int> v;

int count = 0;

int* makeTable(string pattern) {

	int patternSize = pattern.length();
	int *table = (int*)malloc(patternSize*sizeof(int));
	int j = 0; int i = 1;
	memset(table, 0, sizeof(table));
	for (i = 1; i < patternSize; i++) {

		while (j > 0 && pattern[i] != pattern[j]) {

			j = table[j - 1];    // 불일치할경우 j를 마지막으로 일치했던 순간까지 하나씩이동. 이때 j = table[j-1] 이다.

		}

		if (pattern[i] == pattern[j]) {

			table[i] = ++j; // j를 1증가시킨다음에 table[i]는 indexof j라 함

		}


	}

	return table;


}

void KMP_ALGORITHM(string originaltext, string pattern) {

	int patternlen = pattern.length();
	int textlen = originaltext.length();
	int* table = makeTable(pattern);
	int j = 0; int i = 1;
	for (i = 1; i < textlen; i++) {

		while (j > 0 && pattern[j] != originaltext[i]) {

			j = table[j - 1];

		}

		if (originaltext[i] == pattern[j]) {

			if (j == patternlen - 1) {
				count++;	
				v.push_back(i - patternlen + 1);
				//printf("인덱스 %d 에서 %d 까지 일치합니다.\n", i - patternlen + 1,i);
				j = table[j];

			}
			else {

				j++;
			}

		}

	}

}

int main() {

	string parent;
	string pattern;
	getline(cin,parent);
	getline(cin,pattern);
	
	KMP_ALGORITHM(parent, pattern);
	cout<<count<<'\n';
	for(auto a:v) cout<<a<<' ';
	return 0;

}
