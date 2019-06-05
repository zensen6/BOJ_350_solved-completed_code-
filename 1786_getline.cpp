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

			j = table[j - 1];    // ����ġ�Ұ�� j�� ���������� ��ġ�ߴ� �������� �ϳ����̵�. �̶� j = table[j-1] �̴�.

		}

		if (pattern[i] == pattern[j]) {

			table[i] = ++j; // j�� 1������Ų������ table[i]�� indexof j�� ��

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
				//printf("�ε��� %d ���� %d ���� ��ġ�մϴ�.\n", i - patternlen + 1,i);
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
