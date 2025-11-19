// 1005 ACM CRAFT

#include<cstdio>
#include<vector>

using namespace std;

int N, K, W, cost[1000], dt[1000];
bool vis[1000];
vector<int> premise[1000];

void input()
{
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++) scanf("%d", &cost[i]);
    for(int i=0; i<K; i++){
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        premise[t2-1].push_back(t1-1);
    }
    scanf("%d", &W);
    return;
}

int max(int a, int b) { return a>b ? a:b; }

int dfs(int idx)
{
    if(!vis[idx]){
        int base=0;
        for(int i=0; i<premise[idx].size(); i++){
            base = max(base, dfs(premise[idx][i]));
        }
        vis[idx] = 1;
        dt[idx] = base + cost[idx];    
    }
    return dt[idx];
}

void init()
{
    for(int i=0; i<N; i++){
        premise[i].clear();
        vis[i] = 0;
    }
    return;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++)
    {
        input();
        printf("%d\n", dfs(W-1));
        if(i < T-1) init();
    }
    return 0;
}