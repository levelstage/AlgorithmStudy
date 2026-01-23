// 3176 도로 네트워크
// 트리인것만 눈치채면 어려운 문제는 아닌듯

#include<cstdio>
#include<queue>

using namespace std;

vector<vector<int>> par, longest, shortest;
vector<vector<pair<int, int>>> edge;
vector<int> depth;
queue<int> q;
int N, K, len;

int log2(int n)
{
    int res=0;
    while (n > 1)
    {
        n/=2;
        ++res;
    }
    return res;
}

int max(int a, int b) {return a>b ? a:b;}
int min(int a, int b) {return a<b ? a:b;}

void build_tree()
{
    depth[1] = 0;
    for(int i=0; i<edge[1].size(); ++i)
    {
        int idx = edge[1][i].first;
        depth[idx] = 1;
        par[idx][0] = 1;
        longest[idx][0] = edge[1][i].second;
        shortest[idx][0] = edge[1][i].second;
        q.push(idx);
    }
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for(int i=0; i<edge[t].size(); ++i)
        {
            int idx = edge[t][i].first;
            if(idx == par[t][0]) continue;
            depth[idx] = depth[t]+1;
            par[idx][0] = t;
            longest[idx][0] = edge[t][i].second;
            shortest[idx][0] = edge[t][i].second;
            q.push(idx);
        }
    }
    return;
}

void fill_dt()
{
    for(int i=1; i<len; ++i)
    {
        for(int j=1; j<=N; ++j)
        {
            par[j][i] = par[par[j][i-1]][i-1];
            shortest[j][i] = min(shortest[j][i-1], shortest[par[j][i-1]][i-1]);
            longest[j][i] = max(longest[j][i-1], longest[par[j][i-1]][i-1]);
        }
    }
    return;
}

pair<int, int> solve(int a, int b)
{
    int s = 1000001, l = 0;
    if(depth[a] > depth[b])
    {
        int tmp=a;
        a = b;
        b = tmp;
    }
    for(int i = log2(depth[b] - depth[a]); depth[a] < depth[b]; --i)
    {
        if(depth[b] - (1<<i) >= depth[a])
        {
            s = min(s, shortest[b][i]);
            l = max(l, longest[b][i]);
            b = par[b][i];
        }
    }
    if(a==b) return make_pair(s, l);
    for(int i = log2(depth[a]); i>=0; --i)
    {
        if(par[a][i] != par[b][i])
        {
            s = min(s, min(shortest[a][i], shortest[b][i]));
            l = max(l, max(longest[a][i], longest[b][i]));
            a = par[a][i];
            b = par[b][i];
        }
    }
    s = min(s, min(shortest[a][0], shortest[b][0]));
    l = max(l, max(longest[a][0], longest[b][0]));
    return make_pair(s, l);
}

int main()
{
    scanf("%d", &N);
    edge.resize(N+1);
    par.resize(N+1);
    longest.resize(N+1);
    shortest.resize(N+1);
    depth.resize(N+1);
    len = log2(N)+1;

    for(int i=0; i<N-1; ++i)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }
    for(int i=1; i<=N; ++i)
    {
        par[i].assign(len, 1);
        shortest[i].assign(len, 1000001);
        longest[i].assign(len, 0);
    }
    build_tree();
    fill_dt();
    scanf("%d", &K);
    for(int i=0; i<K; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        pair<int, int> res = solve(a, b);
        printf("%d %d\n", res.first, res.second);
    }
    return 0;
}


