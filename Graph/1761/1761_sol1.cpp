// 1761 정점들의 거리
// 좀 더럽긴 한데, 아무튼 풀긴함... 상처뿐인 승리... 공통조상 찾을 때 효과적인 기법을 배웠으니 된거 아닐까!

#include <cstdio>
#include <queue>

using namespace std;

struct node
{
    int depth, root_cost;
    vector<int> link, cost, parent;
};

vector<node> tree;
queue<int> q;

int N, M;


int log2(int n)
{
    int i=0, j=1;
    while(j*2 <= n){
        ++i;
        j*=2;
    }
    return i;
}

void build_tree()
{
    tree[1].parent.push_back(-1);
    tree[1].depth = 0;
    q.push(1);
    while(!q.empty())
    {
        int idx = q.front();
        q.pop();
        for(int j=0; j<tree[idx].link.size(); ++j)
        {
            int next = tree[idx].link[j];
            if(next == tree[idx].parent[0]) continue;
            tree[next].depth = tree[idx].depth+1;
            tree[next].root_cost = tree[idx].root_cost + tree[idx].cost[j];
            tree[next].parent.resize(16, -1);
            tree[next].parent[0] = idx;
            tree[next].parent[tree[next].parent.size()-1] = 1;
            q.push(next);
        }
    }
}

int ancestor(int n, int exp)
{
    if(n == 1) return 1;
    if(tree[n].parent[exp] == -1){
       tree[n].parent[exp] = ancestor(ancestor(n, exp-1), exp-1);
    }
    return tree[n].parent[exp];
}

int common_ancestor(int a, int b)
{
    if(a == b) return a;
    if(tree[a].depth < tree[b].depth) return common_ancestor(a, ancestor(b, log2(tree[b].depth - tree[a].depth)));
    if(tree[b].depth < tree[a].depth) return common_ancestor(ancestor(a, log2(tree[a].depth - tree[b].depth)), b);
    int k = log2(tree[a].depth);
    while (k > 0)
    {
        int aa=ancestor(a, k), ba=ancestor(b, k);
        if(aa != ba) return common_ancestor(aa, ba);
        --k;
    }
    return common_ancestor(tree[a].parent[0], tree[b].parent[0]);
}

int main()
{
    scanf("%d", &N);
    tree.resize(N+1);
    for(int i=0; i<N-1; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        tree[a].link.push_back(b);
        tree[a].cost.push_back(c);
        tree[b].link.push_back(a);
        tree[b].cost.push_back(c);
    }
    build_tree();
    scanf("%d", &M);
    for(int i=0; i<M; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", tree[a].root_cost + tree[b].root_cost - 2*tree[common_ancestor(a,b)].root_cost);
    }
    return 0;
}