// 2150 Strongly Connected Component
// 밑져야 본전으로 풀어봤는데 풀려서 다행이다! 임의의 점에서 나와서 거기로 돌아올 수 있는 모든 애들은 전부 SCC라고 간주할 수 있다는게 핵심.

#include<cstdio>
#include<vector>
#include<set>
#include<queue>

using namespace std;

int V, E;
vector<bool> charged;
vector<vector<int>> out, in;
set<int> sout, sin;
vector<int> buffer;

void fill_set(vector<vector<int>> &graph, set<int> &res, int n)
{
    queue<int> q;
    q.push(n);
    res.insert(n);
    vector<bool> vis;
    vis.assign(V+1, 0);
    vis[n] = 1;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for(int i=0; i<graph[t].size(); ++i)
        {
            if(charged[graph[t][i]] || vis[graph[t][i]]) continue;
            vis[graph[t][i]] = 1;
            q.push(graph[t][i]);
            res.insert(graph[t][i]);
        }
    }
    return;
}

void charge_scc()
{
    auto iter_in = sin.begin();
    auto iter_out = sout.begin();
    while (iter_in != sin.end() && iter_out != sout.end())
    {
        if(*iter_in == *iter_out){
            buffer.push_back(*iter_in);
            charged[*iter_in] = 1;
            ++iter_in;
            ++iter_out;
        }
        else if(*iter_in > *iter_out)++iter_out;
        else ++iter_in;
    }
    buffer.push_back(-1);
    return;
}

int solve()
{
    int cnt = 0;
    for(int i=1; i<=V; ++i)
    {
        if(charged[i]) continue;
        fill_set(out, sout, i);
        fill_set(in, sin, i);
        charge_scc();
        sout.clear();
        sin.clear();
        ++cnt;
    }
    return cnt;
}

void print_buffer()
{
    for(int i=0; i<buffer.size(); ++i){
        printf("%d ", buffer[i]);
        if(buffer[i] == -1) printf("\n");
    }
    return;
}

int main()
{
    scanf("%d %d", &V, &E);
    out.resize(V+1);
    in.resize(V+1);
    charged.assign(V+1, 0);
    for(int i=0; i<E; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        out[a].push_back(b);
        in[b].push_back(a);
    }
    printf("%d\n", solve());
    print_buffer();
    return 0;
}