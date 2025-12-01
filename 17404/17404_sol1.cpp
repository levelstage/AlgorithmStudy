// 17404 RGB 거리

#include<cstdio>

using namespace std;

int N, cost[1000][3], dt[3][3][1000];

void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }
    return;
}

int min(int a, int b) {return a<b ? a:b;}

int search(int n, int s, int e)
{
    if(n == N-1) return 0;
    if(dt[s][e][n] == 0){
        dt[s][e][n] = 1000000;
        for(int i=0; i<3; i++){
            if(i == s) continue;
            if(n == N-2 && i == e) continue;
            dt[s][e][n] = min(dt[s][e][n], search(n+1, i, e)+cost[n][i]);
        }
    }
    return dt[s][e][n];
}

int solve()
{
    int res=1000000;
    for(int s=0; s<3; s++){
        for(int e=0; e<3; e++){
            if(s == e) continue;
            res = min(res, search(1, s, e) + cost[0][s] + cost[N-1][e]);
        }
    }
    return res;
}

int main()
{
    input();
    printf("%d\n", solve());
}