// 16197 두 동전
#include<iostream>
#define END 10

using namespace std;

int N, M;
int X1, X2, Y1, Y2;
char map[20][20];

int min(int a, int b)
{
    return a<b ? a:b;
}

bool valid(int y, int x)
{
    if(0 <= y && y < N && 0 <= x && x < M)return 1;
    return 0;
}

void input()
{
    X1 = Y1 = -1;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
            if(map[i][j] == 'o'){
                if(Y1==-1){
                    Y1 = i;
                    X1 = j;
                }
                else{
                    Y2 = i;
                    X2 = j;
                }
            }
        }
    }
}

int dfs(int depth, int y1, int x1, int y2, int x2)
{
    int yv[4] = {-1, 1, 0, 0}, xv[4] = {0, 0, -1, 1}, res = END+1;
    if(depth > END)return depth;
    for(int i=0; i<4; i++){
        int ny1 = y1+yv[i], nx1 = x1+xv[i], ny2 = y2+yv[i], nx2 = x2+xv[i];
        if(!valid(ny1,nx1) || !valid(ny2, nx2)){
            if(valid(ny1, nx1) == valid(ny2, nx2)) continue;
            return depth;
        }
        if(map[ny1][nx1] == '#' && map[ny2][nx2] == '#') continue;
        if(map[ny1][nx1] == '#'){
            ny1 = y1;
            nx1 = x1;
        }
        if(map[ny2][nx2] == '#'){
            ny2 = y2;
            nx2 = x2;
        }
        if(nx1 == nx2 && ny1 == ny2) continue;
        res = min(res, dfs(depth+1, ny1, nx1, ny2, nx2));
    }
    return res;
}

int main()
{
    input();
    int res = dfs(1, Y1, X1, Y2, X2);
    if(res > END) res = -1;
    cout << res << endl;
}