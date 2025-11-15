// 15972 물탱크
// 만점을 노려보자.
// 똑같이 BFS
// 우선순위 큐를 활용해서 수위가 낮은 애부터 물을 뺐더니 중복이 크게 줄어들었다.

#include<iostream>
#include<queue>

using namespace std;

struct event
{
    int x, y, idx;
};

int N, M, H, level[1000][1000], minlevel[1000][1000], hole[1000][1000][4];
int inv[4] = {1,0,3,2}, xv[4] = {0, 0, -1, 1}, yv[4] = {-1, 1, 0, 0};

struct compare
{
    bool operator() (event& a, event& b)
    {
        return level[a.y][a.x] > level[b.y][b.x];
    }
};

priority_queue<event, vector<event>, compare> q;

int min(int a, int b) {return a<b ? a:b;}
int max(int a, int b) {return a>b ? a:b;}

event make_event(int x, int y, int idx)
{
    event tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.idx = idx;
    return tmp;
}

void input()
{
    cin>>N>>M>>H;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            level[i][j] = H;
        }
    }
    for (int i = 0; i <= N; i++)
    {
        for(int j = 0; j<M; j++){
            int tmp;
            cin>>tmp;
            if(i==0){
                hole[i][j][0] = tmp;
                if(tmp!=-1) {
                    level[i][j] = min(tmp, level[i][j]);
                    q.push(make_event(j, i, 0));
                }
            }
            else if(i == N){
                hole[i-1][j][1] = tmp;
                if(tmp!=-1) {
                    level[i-1][j] = min(tmp, level[i-1][j]);
                    q.push(make_event(j, i-1, 1));
                }
            }
            else{
                hole[i-1][j][1] = tmp;
                hole[i][j][0] = tmp;
            }
        }
    }
    for (int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            int tmp;
            cin>>tmp;
            if(j==0){
                hole[i][j][2] = tmp;
                if(tmp!=-1) {
                    level[i][j] = min(tmp, level[i][j]);
                    q.push(make_event(j, i, 2));
                }
            }
            else if(j == M){
                hole[i][j-1][3] = tmp;
                if(tmp!=-1) {
                    level[i][j-1] = min(tmp, level[i][j-1]);
                    q.push(make_event(j-1, i, 3));
                }
            }
            else{
                hole[i][j-1][3] = tmp;
                hole[i][j][2] = tmp;
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            minlevel[i][j] = H;
            for(int k=0; k<4; k++){
                minlevel[i][j] = min(minlevel[i][j], hole[i][j][k]);
            }
        }
    }
    return;
}


void solve()
{
    while(!q.empty())
    {
        event ev = q.top();
        int x = ev.x, y = ev.y, idx = ev.idx;
        for(int i=0; i<4; i++){
            if(hole[y][x][i] == -1) continue;
            int nx = x+xv[i], ny = y+yv[i];
            if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if(level[ny][nx] == minlevel[ny][nx]) continue;
            if(level[y][x] < level[ny][nx] && hole[y][x][i] < level[ny][nx]) {
                level[ny][nx] = max(level[y][x], hole[y][x][i]);
                q.push(make_event(nx, ny, inv[i]));
            }
        }
        q.pop();
    }
    return;
}

void print()
{
    int sum=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            sum+=level[i][j];
        }
    }
    cout<<sum<<endl;
    return;
}

int main()
{
    input();
    solve();
    print();
    return 0;
}