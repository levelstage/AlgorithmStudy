// 16946 벽 부수고 이동하기 4
// 풀긴했는데 최선인지는 모르겠음.

#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, dt[1000][1000], xv[4] = {1,-1,0,0}, yv[4] = {0,0,1,-1}, values[500002];
string Map[1000];
queue<pair<int,int>> yxs;

void input()
{
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>Map[i];
        for(int j=0; j<M; j++)
            if(Map[i][j] == '1') dt[i][j] = 1;
    }
    return;
}

bool vaild(int y, int x) {return 0 <= y && y < N && 0 <= x && x < M;}

void dfs(int y, int x)
{
    yxs.push(make_pair(y,x));
    for(int k=0; k<4; k++){
        int ny = y+yv[k], nx = x+xv[k];
        if(!vaild(ny,nx)) continue;
        if(dt[ny][nx] == 0){
            dt[ny][nx] = 1;
            dfs(ny, nx);
        }
    }
    return;
}

void solve()
{
    int group = 2;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(Map[i][j] == '0') continue;
            vector<int> vis;
            vis.reserve(4);
            for(int k=0; k<4; k++){
                int ny = i+yv[k], nx = j+xv[k];
                if(!vaild(ny, nx)) continue;
                if(Map[ny][nx] == '1') continue;
                if(dt[ny][nx] == 0){
                    dt[ny][nx] = group;
                    dfs(ny, nx);
                    values[group] = yxs.size();
                    while(!yxs.empty()){
                        dt[yxs.front().first][yxs.front().second] = group;
                        yxs.pop();
                    }
                    group++;
                }
                if(find(vis.begin(), vis.end(), dt[ny][nx]) != vis.end()) continue; 
                vis.push_back(dt[ny][nx]);
                dt[i][j] += values[dt[ny][nx]];
            }
        }
    }
    return;
}

void print()
{
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(Map[i][j] == '1') 
            cout<<(dt[i][j] % 10);
            else cout<<0;
        }
        cout<<endl;
    }
    return;
}

int main()
{
    input();
    solve();
    print();
    return 0;
}