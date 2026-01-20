// 2618 경찰차
// 플레4 치고는 쉬운 DP 문제

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int N, W;
vector<pair<int, int>> c;
vector<vector<int>> dt;

int len(int from, int to, int zero)
{
    pair<int, int> v1, v2;
    if(from == 0) v1 = make_pair(zero, zero);
    else v1 = c[from];
    v2 = c[to];
    return abs(v1.first - v2.first) + abs(v1.second - v2.second);
}

int solve(int a, int b)
{
    if(a==W || b==W) return 0;
    if(dt[a][b] < 0)
    {
        int next = a>b ? a+1:b+1;
        int r_a = solve(next, b) + len(a, next, 1);
        int r_b = solve(a, next) + len(b, next, N);
        dt[a][b] = r_a < r_b ? r_a : r_b;
    }
    return dt[a][b];
}

void out_dt()
{
    int a=0, b=0;
    for(int i=1; i<W; ++i)
    {
        if(dt[i][b] + len(a, i, 1) < dt[a][i] + len(b, i, N)){
            printf("1\n");
            a = i;
        }
        else{
            printf("2\n");
            b = i;
        }
    }
    if(len(a, W, 1) < len(b, W, N)){
        printf("1\n");
    }
    else printf("2\n");
    return;
}

int main()
{
    scanf("%d", &N);
    scanf("%d", &W);
    c.resize(W+1);
    for(int i=1; i<=W; i++){
        scanf("%d %d", &c[i].first, &c[i].second);
    }
    dt.resize(W);
    for(int i=0; i<W; i++){
        dt[i].assign(W, -1);
    }
    printf("%d\n", solve(0,0));
    out_dt();
    return 0;
}