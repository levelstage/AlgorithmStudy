// 11438 LCA 2
// fill_par() main에 안넣고 이거 왜안됨 이러고 있었다니...

#include <cstdio>
#include <queue>

using namespace std;

vector<vector<int>> par;
vector<vector<int>> link;
vector<int> depth;
queue<int> q;
int N, M, len;

void build_tree()
{
    for(int i=0; i<link[1].size(); ++i) {
        par[link[1][i]][0] = 1;
        depth[link[1][i]] = 1;
        q.push(link[1][i]);
    }
    while (!q.empty())
    {
        int idx = q.front();
        q.pop();
        for(int i=0; i<link[idx].size(); ++i){
            if(link[idx][i] == par[idx][0]) continue;
            par[link[idx][i]][0] = idx;
            depth[link[idx][i]] = depth[idx]+1;
            q.push(link[idx][i]);
        }
    }
    return;
}

int log2(int n)
{
    int res=0;
    while (n > 1) {
        n/=2;
        ++res;
    }
    return res;
}

void fill_par()
{
    for(int i=1; i<len; ++i)
    {
        for(int j=2; j<=N; ++j)
        {
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    return;
}

int lca(int a, int b)
{
    if(a == b) return a;
    if(depth[a] > depth[b]) return lca(par[a][log2(depth[a] - depth[b])], b);
    if(depth[b] > depth[a]) return lca(a, par[b][log2(depth[b] - depth[a])]);
    for(int i = log2(depth[a]); i>0; i--){
        if(par[a][i] != par[b][i]) return lca(par[a][i], par[b][i]);
    }
    return lca(par[a][0], par[b][0]);
}

int main()
{
    scanf("%d", &N);
    link.resize(N+1);
    par.resize(N+1);
    depth.assign(N+1, 0);
    for(int i=1; i<=N-1; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        link[a].push_back(b);
        link[b].push_back(a);
    }
    len = log2(N) + 1;
    for(int i=1; i<=N; ++i) par[i].assign(len, 1);
    build_tree();
    fill_par();
    scanf("%d", &M);
    for(int i=1; i<=M; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}