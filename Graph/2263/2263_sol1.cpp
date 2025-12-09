// 2263 트리의 순회
// 그래서 인오더 퍼스트오더 프리오더가 뭔데 씹덕아

#include<cstdio>
#include<vector>

using namespace std;

int N;
vector<int> in, post;

void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int tmp;
        scanf("%d", &tmp);
        in.push_back(tmp);
    }
    for(int i=0; i<N; i++){
        int tmp;
        scanf("%d", &tmp);
        post.push_back(tmp);
    }
}

void solve(int is, int ie, int ps, int pe)
{
    printf("%d ", post[pe]);
    if(is == ie) return;
    int root;
    for(root=is; root<=ie; root++)
        if(in[root] == post[pe]) break;
    if(root != is)solve(is, root-1, ps, ps+(root-is-1));
    if(root != ie)solve(root+1, ie, pe-1 - (ie-root-1), pe-1);
    return;
}

int main()
{
    input();
    solve(0, N-1, 0, N-1);
    return 0;
}