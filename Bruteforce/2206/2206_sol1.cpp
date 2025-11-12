// 2206 벽 부수고 이동하기

#include <iostream>
#include <string>
using namespace std;
int N, M;
string Map[1000];
bool vis[1000][1000];

int min(int a, int b)
{
    return a<b ? a:b;
}

bool valid(int y, int x)
{
    if(0 > y || y >= N || 0 > x || x >= M)return 0;
    return 1;
}

int dfs(int depth, int y, int x, bool breakable)
{
    int yv[4] = {-1, 1, 0, 0}, xv[4] = {0, 0, -1, 1}, res = 10000001;
    if(y == N-1 && x == M-1) return depth;
    for(int i=0; i<4; i++){
        int ny=y+yv[i], nx=x+xv[i];
        if(valid(ny, nx)){
            if(!vis[ny][nx] && Map[ny][nx] == '0') {
                vis[ny][nx] = 1;
                res = min(res, dfs(depth+1, ny, nx, breakable));
                vis[ny][nx] = 0;
            }
            else if(!vis[ny][nx] && breakable) {
                vis[ny][nx] = 1;
                res = min(res, dfs(depth+1, ny, nx, 0));
                vis[ny][nx] = 0;
            }
        }
    }
    return res;
}

void input()
{
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>Map[i];
    }
    return;
}

int main()
{
    input();
    int res = dfs(1,0,0,1);
    cout<<(res==10000001 ? -1 : res)<<endl;
    return 0;
}
