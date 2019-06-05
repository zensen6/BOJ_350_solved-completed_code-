#include<stdio.h>


int arr[20];

int dp(int len, int sum, int* arr) {

	if (len == 0 && sum == 0) {

		return 1;
	}
	else if (len == 0 && sum != 0) {

		return 0;

	}
	else {

		return dp(len - 1, sum - arr[len - 1], arr) + dp(len - 1, sum, arr);

	}

}


int main() {


	int N;
	int sum;
	scanf("%d %d", &N, &sum);
	for (int i = 0; i < N; i++) {

		scanf("%d", &arr[i]);

	}
	

	printf("%d\n", sum==0? dp(N, sum, arr)-1:dp(N,sum,arr));


}
