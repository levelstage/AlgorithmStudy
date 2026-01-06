// 2357 최솟값과 최댓값
// 정석적 바텀업 구현

#include <cstdio>
#include <vector>

using namespace std;

vector<int> mintree, maxtree;
int N, M, n_bin=1;

int min(int a, int b) { return a<b ? a:b; }
int max(int a, int b) { return a>b ? a:b; }

void build_tree(vector<int> &tree, int s, int e, int (*comp)(int, int))
{
    if(s == 1) return;
    for(int i=s; i<=e; i+=2){
        // 0으로 인한 트리 오염 방지
        if(tree[i] == 0) tree[i/2] = tree[i+1];
        else if(tree[i+1] == 0) tree[i/2] = tree[i];
        else tree[i/2] = comp(tree[i], tree[i+1]); 
    }
    build_tree(tree, s/2, e/2, comp);
    return;
}

int query(vector<int> &tree, int s, int e, int (*comp)(int, int))
{
    // max가 들어오면 0, min이 들어오면 아주 큰 값을 초기값으로.
    int res = 1000000001 - comp(0, 1000000001);
    s+=n_bin-1;
    e+=n_bin-1;
    while(s<=e)
    {
        if(s%2==1) res = comp(res, tree[s++]);
        if(e%2==0) res = comp(res, tree[e--]);
        s/=2;
        e/=2;
    }
    return res;
}

int main()
{
    scanf("%d %d", &N, &M);
    while (n_bin<N) n_bin *= 2;
    mintree.assign(2*n_bin+1, 0);
    for(int i=0; i<N; i++){
        scanf("%d", &mintree[n_bin+i]);
    }
    maxtree = mintree; // 딥카피
    build_tree(mintree, n_bin, 2*n_bin-1, min);
    build_tree(maxtree, n_bin, 2*n_bin-1, max);
    for(int i=0; i<M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d %d\n", query(mintree, a, b, min), query(maxtree, a, b, max));
    }
    return 0;
}
