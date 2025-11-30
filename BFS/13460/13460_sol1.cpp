// 13460 구슬 탈출 2
// 두 동전을 약간 좀 맵게 바꾼 느낌. 그닥 안 어려웠음.

#include <cstdio>
#include <queue>
#include <string>

using namespace std;

int N, M;
char inp[11][11];
bool vis[11][11][11][11];
pair<int, int> bf, rf;

struct state
{
    int time, bx, by, rx, ry;
};

state make_state(int time, int bx, int by, int rx, int ry)
{
    state tmp;
    tmp.time = time;
    tmp.bx = bx;
    tmp.by = by;
    tmp.rx = rx;
    tmp.ry = ry;
    return tmp;
}

void input()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        scanf("%s", inp[i]);
        for(int j=0; j<M; j++){
            if(inp[i][j] == 'R'){
                rf.first = i;
                rf.second = j;
            }
            if(inp[i][j] == 'B'){
                bf.first = i;
                bf.second = j;
            }
        }
    }
    return;
}

pair<int, int> roll(int x, int y, int xv, int yv, int ax, int ay)
{
    bool met=0;
    while(1)
    {
        int nx = x+xv, ny = y+yv;
        if(nx < 0 || nx >= M || ny < 0 || ny >= N) break;
        if(inp[ny][nx] == '#') break;
        if(inp[ny][nx] == 'O') return make_pair(-1, -1);
        if(nx == ax && ny == ay) met = 1;
        x = nx;
        y = ny;
    }
    return make_pair(x-met*xv, y-met*yv);
}

int bfs()
{
    queue<state> q;
    q.push(make_state(0, bf.second, bf.first, rf.second, rf.first));
    while(!q.empty())
    {
        state st = q.front();
        q.pop();
        if(st.time >= 10) continue;
        int xv[4] = {0, 0, -1, 1}, yv[4] = {-1, 1, 0, 0};
        for(int k=0; k<4; k++){
            pair<int, int> nb, nr;
            nb = roll(st.bx, st.by, xv[k], yv[k], st.rx, st.ry);
            nr = roll(st.rx, st.ry, xv[k], yv[k], st.bx, st.by);
            if(nb.first == -1) continue;
            if(nr.first == -1) return st.time+1;
            if(vis[nb.first][nb.second][nr.first][nr.second]) continue;
            vis[nb.first][nb.second][nr.first][nr.second] = 1;
            q.push(make_state(st.time+1, nb.first, nb.second, nr.first, nr.second)); 
        }
    }
    return -1;
}

int main()
{
    input();
    printf("%d\n", bfs());
    return 0;
}