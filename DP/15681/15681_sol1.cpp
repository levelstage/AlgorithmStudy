// 15681 트리와 쿼리
// 폰코딩으로 풀 만큼 쉬움

#include<cstdio>
#include<vector>
using namespace std;

int N, R, Q, cnt[100001];
vector<int> e[100001];

int fill(int idx)
{
    if(cnt[idx] == 0){
        cnt[idx] = 1;
        for(int i=0; i<e[idx].size(); i++)
        {
            if(cnt[e[idx][i]] > 0) continue;
            cnt[idx] += fill(e[idx][i]);
        }
    }
    return cnt[idx];
}

int main()
{
    scanf("%d %d %d", &N, &R, &Q);
    for(int i=0; i<N-1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    fill(R);
    for(int i=0; i<Q; i++){
        int query;
        scanf("%d", &query);
        printf("%d\n", cnt[query]);
    }
    return 0;
}