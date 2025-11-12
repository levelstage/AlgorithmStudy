// 2206 벽 부수고 이동하기
// 아마 정석에 가까운 풀이? vis 때문에 약간 삽질을 좀 많이함;;

#include <iostream>
#include <string>
#include <queue>

using namespace std;

string Map[1000];
bool vis[2000000];
int yv[4] = {-1, 1, 0, 0}, xv[4] = {0, 0, -1, 1};
int N, M;

bool valid(int y, int x)
{
    return (0 <= y && y < N && 0 <= x && x < M);
}

int bfs()
{
    if(N==1 && M==1) return 1;
    int i;
    bool solved = 0;
    queue<int> q;
    q.push(N*M);
    for(i=1; i<= M*N; i++){
        int count = q.size();
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            bool breakable = now / (N*M);
            now %= N*M;
            int y = now / M, x = now % M;
            for(int j=0; j<4; j++){
                int ny = y + yv[j], nx = x + xv[j];
                if(ny == N-1 && nx == M-1){
                    solved = 1;
                    break;
                }
                if(!valid(ny,nx)) continue;
                if(Map[ny][nx] == '0'){
                    if(vis[M*ny+nx+M*N*breakable]) continue;
                    vis[M*ny+nx+M*N*breakable] = 1;
                    q.push(M*ny+nx+M*N*breakable);
                }
                else if(breakable){
                    if(vis[M*ny+nx]) continue;
                    vis[M*ny+nx] = 1;
                    q.push(M*ny+nx);
                }
            }
            if(solved) break;
            count--;
            if(count==0) break;
        }
        if(solved || q.empty()) break;
    }
    if(!solved) return -1;
    return i+1;
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
    cout<<bfs()<<endl;
}
