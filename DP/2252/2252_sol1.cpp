// 2252 줄 세우기
// 1005번의 하위호환

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N, M, depth[32001];
vector<int> premise[32001];
struct lower_first
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first > b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, lower_first> out;

int max(int a, int b) { return a>b ? a:b;}

int dfs(int num)
{
    if(depth[num] == 0){
        int base = 0;
        for(int i=0; i<premise[num].size(); i++) base = max(base, dfs(premise[num][i]));
        depth[num] = base+1;
    } 
    return depth[num];
}

void enqueue_out()
{
    for(int i=1; i<=N; i++){
        out.push(make_pair(dfs(i), i));
    }
    return;
}

void dequeue_out()
{
    while (!out.empty())
    {
        printf("%d ", out.top().second);
        out.pop();
    }
    return;
}

void input()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++)
    {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        premise[t2].push_back(t1);
    }
    return;
}

int main()
{
    input();
    enqueue_out();
    dequeue_out();
    return 0;
}
