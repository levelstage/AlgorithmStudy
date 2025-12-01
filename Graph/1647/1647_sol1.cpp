// 1647 도시 분할 계획
// 최소 스패닝 트리랑 거의 비슷.

#include<cstdio>
#include<queue>

using namespace std;

struct edge
{
    int a, b, c;
};

struct low_c
{
    bool operator()(edge &a, edge &b)
    {
        return a.c > b.c;
    }
};

int N, M, tree[100001], len[100001];
priority_queue<edge, vector<edge>, low_c> q;

void input()
{
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++){
        tree[i] = i;
        len[i] = 1;
    }
    for(int i=0; i<M; i++){
        edge tmp;
        scanf("%d %d %d", &tmp.a, &tmp.b, &tmp.c);
        q.push(tmp);
    }
    return;
}

int root(int x)
{
    if(tree[x] == x) return x;
    return tree[x] = root(tree[x]);
}

int solve()
{
    int res=0;
    while(!q.empty())
    {
        edge temp = q.top();
        q.pop();
        int ar = root(temp.a), br = root(temp.b);
        if(ar == br) continue;
        if(ar > br){
            tree[br] = ar;
            len[ar] += len[br];
            if(len[ar] == N) return res;  
        }
        if(ar < br){
            tree[ar] = br;
            len[br] += len[ar];
            if(len[br] == N) return res;  
        }
        res += temp.c;
    }
    return res;
}

int main()
{
    input();
    printf("%d\n", solve());
    return 0;
}