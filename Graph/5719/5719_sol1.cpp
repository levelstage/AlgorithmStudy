// 5719 거의 최단 경로
// 메모이제이션을 활용한 정방향 DFS로 간선을 지웠는데, 일반적으로는 도착지점부터 역방향으로 지운다고 한다. 그게 더 깔끔한 정석 풀이임.

#include<cstdio>
#include<queue>

using namespace std;

struct lower_second
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

int N, M, S, D, shortest;
vector<int> vis;
vector<vector<int>> link, edge;
priority_queue<pair<int, int>, vector<pair<int, int>>, lower_second> q;

int bfs()
{
    q = priority_queue<pair<int, int>, vector<pair<int, int>>, lower_second>();
    q.push(make_pair(S, 0));
    while (!q.empty())
    {
        pair<int, int> t = q.top();
        if(t.first == D) return t.second;
        q.pop();
        for(int i=0; i<link[t.first].size(); ++i)
        {
            if(edge[t.first][link[t.first][i]] == 0) continue;
            if(vis[link[t.first][i]] > 0 && vis[link[t.first][i]] <= t.second + edge[t.first][link[t.first][i]]) continue;
            q.push(make_pair(link[t.first][i], t.second + edge[t.first][link[t.first][i]]));
            vis[link[t.first][i]] = t.second + edge[t.first][link[t.first][i]];
        }
    }
    return -1;
}

bool dfs(int n, int length)
{
    bool res=0;
    if(vis[n] > 0){
        if(length > vis[n]) return 0;
        if(length == vis[n]) return 1;
    }
    for(int i=0; i<link[n].size(); i++)
    { 
        if(link[n][i] == D && length + edge[n][link[n][i]] == shortest){
            res = 1;
            edge[n][link[n][i]] = 0;
            vis[n] = length;
        }
        else if(length + edge[n][link[n][i]] < shortest){
            if(dfs(link[n][i], length + edge[n][link[n][i]])){
                res = 1;
                edge[n][link[n][i]] = 0;
                vis[n] = length;
            }
        }
    }
    return res;
}

int main()
{
    while(1)
    {
        scanf("%d %d", &N, &M);
        if(N == 0 && M == 0) break;
        edge.resize(N);
        link.resize(N);
        for(int i=0; i<N; ++i){
            edge[i].assign(N, 0);
            link[i] = vector<int>();
        }
        scanf("%d %d", &S, &D);
        for(int i=0; i<M; ++i)
        {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            edge[u][v] = p;
            link[u].push_back(v);
        }
        vis.assign(N, 0);
        shortest = bfs();

        vis.assign(N, 0);
        dfs(S, 0);
        
        vis.assign(N, 0);
        printf("%d\n", bfs());
 
    }      
    return 0;
}