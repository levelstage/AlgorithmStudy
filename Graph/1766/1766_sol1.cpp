// 1766 문제집

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int order[32001];
vector<vector<int>> nex;
priority_queue<int, vector<int>, greater<int>> q;

void input()
{
    scanf("%d %d", &N, &M);
    nex.reserve(N+1);
    for(int i=0; i<=N; i++){
        vector<int> tmp;
        nex.push_back(tmp);
    }   
    for(int i=1; i<=M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        nex[a].push_back(b);
        order[b]++;
    }
    return;
}

void solve()
{
    for(int i=1; i<=N; i++){
        if(order[i] == 0) q.push(i);
    }
    while (!q.empty())
    {
        int n = q.top();
        q.pop();
        printf("%d ", n);
        for(int i=0; i<nex[n].size(); i++){
            order[nex[n][i]]--;
            if(order[nex[n][i]] == 0) q.push(nex[n][i]);
        }
    }
    return;
}

int main()
{
    input();
    solve();
    return 0;
}