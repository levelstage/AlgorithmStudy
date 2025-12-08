// 2342 댄스 댄스 레볼루션
// 제목보고 살짝 기대했는데 평범한 DP문제였다.

#include <cstdio>
#include <vector>

using namespace std;

int dt[100000][5][5];
vector<int> v;

int min(int a, int b) {return a<b ? a:b;}

void input()
{
    int inp;
    scanf("%d", &inp);
    while (inp != 0)
    {
        v.push_back(inp);
        scanf("%d", &inp);
    }
    return;
}

int cost(int a, int b)
{
    if(a*b == 0) return 2;
    if(a-b == 2 || a-b == -2) return 4;
    return 3;
}

int dfs(int depth, int l, int r)
{
    if(depth == v.size()) return 0;
    if(dt[depth][l][r] == 0){
        if(v[depth] == l || v[depth] == r) dt[depth][l][r] = dfs(depth+1, l, r) + 1;
        else{
            dt[depth][l][r] = min(dfs(depth+1, v[depth], r) + cost(l, v[depth]), dfs(depth+1, l, v[depth]) + cost(r, v[depth]));
        }
    }
    return dt[depth][l][r];
}

int main()
{
    input();
    printf("%d\n", dfs(0,0,0));
    return 0;
}