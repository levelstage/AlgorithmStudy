// 2533 사회망 서비스 (SNS)
// 생각보다 좀 쉽게 풀리긴 했는데, 시간도 생각보다 오래걸리네(100만의 한계인듯.)

#include<cstdio>
#include<vector>

using namespace std;

bool vis[1000001];
int N, ans;
vector<vector<int>> fr;

void input()
{
    scanf("%d", &N);
    fr.assign(N+1, vector<int>());
    for(int i=0; i<N-1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        fr[a].push_back(b);
        fr[b].push_back(a);
    }
    return;
}

bool solve(int n)
{
    bool res=0;
    vis[n] = 1;
    for(int i=0; i<fr[n].size(); i++){
        if(vis[fr[n][i]]) continue;
        if(!solve(fr[n][i])) res = 1;
    }
    if(res) ans++;
    return res;
}

int main()
{
    input();
    solve(1);
    printf("%d", ans);
    return 0;
}