#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include<memory.h>

using namespace std;
//char *parent = "acabacdabac";
//char *pattern = "abacdab";
int c = 0;

vector<int> v;

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
	int j = 0;
	int i;
	for (i = 0; i < textlen; i++) {

		while (j > 0 && pattern[j] != originaltext[i]) {

			j = table[j - 1];

		}

		if (originaltext[i] == pattern[j]) {

			if (j == patternlen - 1) {
				
				c++;
			    v.push_back(i - patternlen + 1);
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
	printf("%d\n",c);
	for(auto a:v) cout<<a<<' ';
	return 0;

}
