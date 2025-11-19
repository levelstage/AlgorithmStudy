// 10942 팰린드롬?
// 반복문으로 DT 채우는 버전. 근데 알고 보니 재귀 문제가 아니었음.

#include <stdio.h>

int N, M, seq[2001];
bool dt[2001][2001];

void fill_dt()
{
    for(int len=0; len<N; len++){
        for(int i=1; i<=N-len; i++){
            if(len == 0) {
                dt[i][i] = 1;
                continue;
            }
            dt[i][i+len] = (dt[i+1][i+len-1] == 1 || len == 1) && (seq[i] == seq[i+len]);
        }
    }
    return;
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &seq[i]);
    }
    fill_dt();
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", dt[s][e]);
    }
    return 0;
}
