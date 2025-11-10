// 14500 테트로미노

#include <iostream>

using namespace std;

int map[500][500], N, M;

int max(int a, int b)
{
    return a>b ? a:b;
}

bool valid(int y, int x)
{
    if(0 <= y && y < N && 0 <= x && x < M)return 1;
    return 0;
}

int dfs(int depth, int y, int x, int yv, int xv, int sum)
{
    int res = 0;
    sum += map[y][x];
    if(depth == 4) return sum;
    if(depth == 2 && valid(y, x+xv) && valid(y+yv, x)){
        res = sum + map[y][x+xv] + map[y+yv][x];
    }
    if(valid(y, x+xv))res = max(res, dfs(depth+1, y, x+xv, yv, xv, sum));
    if(valid(y+yv, x))res = max(res, dfs(depth+1, y+yv, x, yv, xv, sum));
    return res;
}

int nemo()
{
    int res = 0;
    for(int i=0; i<N-1; i++){
        for(int j=0; j<M-1; j++){
            res = max(res, map[i][j] + map[i+1][j] + map[i][j+1] + map[i+1][j+1]);
        }
    }
    return res;
}

int mino(int yv, int xv)
{
    int res = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            res = max(res, dfs(1,i,j,yv,xv,0));
        }
    }
    return res;
}

void input()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
}

int main()
{
    input();
    int res = nemo();
    res = max(res, mino(1,1));
    res = max(res, mino(1, -1));
    res = max(res, mino(-1, 1));
    cout<<res<<endl;
    return 0;
}