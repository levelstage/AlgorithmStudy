// 10942 팰린드롬?
// 재귀 오버헤드로 시간초과 나는 줄 알았으나...!

#include <stdio.h>

int N, M, seq[2000];
bool vis[2000][2000], value[2000][2000];

bool determine(int s, int e)
{
    if(vis[s][e]) return value[s][e];
    if(s>=e) return 1;
    if(seq[s] == seq[e]){
        value[s][e] = determine(s+1, e-1);
    }
    vis[s][e] = 1;
    return value[s][e];
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &seq[i]);
    }
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", determine(s-1, e-1));
    }
    return 0;
}
