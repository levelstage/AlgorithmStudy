// 1799 비숍
// 흠... 그정둔감...

#include <cstdio>

using namespace std;

int N, inp[10][10],dt[1048576][21];
bool vis[1048576][21];

void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &inp[i][j]);
        }
    }    
    return;
}

int max(int a, int b){ return a>b ? a:b; }

int dfs(int depth, int mask)
{
    if(depth < -(N-1)) return 0;
    if(!vis[mask][depth+N])
    {
        vis[mask][depth+N] = 1;
        for(int x=(depth<0 ? -depth:0); x<(depth<0 ? N:N-depth); x++){
            int y = x + depth;
            if((mask>>(x+y)) % 2 == 1) continue;
            if(inp[y][x] == 0) continue;
            dt[mask][depth+N] = max(dt[mask][depth+N], dfs(depth-1, mask + (1<<(x+y)))+1);
        }
        dt[mask][depth+N] = max(dt[mask][depth+N], dfs(depth-1, mask));
    }
    return dt[mask][depth+N];
}

int main()
{
    input();
    printf("%d\n", dfs(N-1, 0));
    return 0;
}