#include <cstdio>
#include <algorithm>
using namespace std;
 
int main(){
    int M, N;
    char map[50][50];
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        getchar();
        for(int j=0; j<M; j++)
            map[i][j] = getchar();
    }
 
    // 기본 결과는 아주 큰 값으로 시작. 다만 절대 64는 나올 수 없다.
    int result = 64;
    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            int cnt = 0;
            // 모든 8*8 영역을 체크해서 체스판과 다른 칸 개수 셈
            for(int r=0; r<8; r++)
                for(int c=0; c<8; c++)
                    cnt += (r%2==c%2?'W':'B')==map[i+r][j+c];
            // 원래 체스판
            result = min(result, cnt);
            // 체스판을 90도 회전한 것과도 비교
            result = min(result, 64-cnt);
        }
    }
    printf("%d\n", result);
}

