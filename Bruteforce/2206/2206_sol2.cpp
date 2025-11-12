// 2206 벽 부수고 이동하기
// 개선(다이나믹 프로그래밍)
// 폐기(작동안함)

#include <iostream>
#include <string>
#include <queue>
#define NUM 1000001
using namespace std;
int N, M;
string Map[1000];
int dmap[1000][1000][2], yv[4] = {-1, 1, 0, 0}, xv[4] = {0, 0, -1, 1};

struct task
{
    int y, x;
    bool breakable;
};
queue<task> tasks;

int min(int a, int b)
{
    return a<b ? a:b;
}

bool valid(int y, int x)
{
    if(0 > y || y >= N || 0 > x || x >= M)return 0;
    return 1;
}

int search(int depth, int y, int x, bool breakable)
{
    if(dmap[y][x][breakable] != 0 && dmap[y][x][breakable] < depth) return dmap[y][x][breakable];
    dmap[y][x][breakable] = depth;
    if(y == N-1 && x == M-1) return;
    for(int i=0; i<4; i++){
        int ny=y+yv[i], nx=x+xv[i];
        if(!valid(ny, nx)) continue;
        if(Map[ny][nx] == '0') {
            search(depth+1, ny, nx, breakable);
        }
        else if(breakable) {
            search(depth+1, ny, nx, 0);
        }
    }
}

void solve()
{
    dmap[N-1][M-1][0] = dmap[N-1][M-1][1] = 1;
    while(!tasks.empty())
    {
        int res = NUM;
        task t = tasks.front();
        tasks.pop();
        for(int i=0; i<4; i++){
            int ny=t.y+yv[i], nx=t.x+xv[i];
            if(!valid(ny, nx)) continue;
            if(dmap[ny][nx][t.breakable] == 0) continue;
            res = min(res, dmap[ny][nx][t.breakable]);
        }
        dmap[t.y][t.x][t.breakable] = res+1;
    }
    return;
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
    search(0,0,0,1);
    solve();
    cout<<dmap[0][0][1]<<endl;
    return 0;
}
