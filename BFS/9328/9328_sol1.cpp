// 9328 열쇠
// 뭔가 좀 복잡하게 푼 것 같기도 하고... 풀었으니까 됐나

#include<cstdio>
#include<queue>

using namespace std;

int h, w, keys, ans, xd[4] = {0,0,-1,1}, yd[4] = {-1, 1, 0, 0};
char map[101][101];
bool vis[101][101];

queue<pair<int, int>> q, seed;

void input()
{
    scanf("%d %d", &h, &w);
    for(int i=0; i<h; i++){
        scanf("%s", map[i]);
        if(i == 0 || i == h-1){
            for(int j=0; j<w; j++){
                if(map[i][j] != '*'){
                    vis[i][j] = 1;
                    if(map[i][j] == '$') ans++;
                    seed.push(make_pair(i, j));
                } 
            }
        }
        else{
            if(map[i][0] != '*'){
                    vis[i][0] = 1;
                    if(map[i][0] == '$') ans++;
                    seed.push(make_pair(i, 0));
            }
            if(map[i][w-1] != '*'){
                    vis[i][w-1] = 1;
                    if(map[i][w-1] == '$') ans++;
                    seed.push(make_pair(i, w-1));
            }
        }
    }
    keys = 0;
    char tmp[101];
    scanf("%s", tmp);
    for(int i=0; i<101; i++){
        if(tmp[i] == '\0' || tmp[i] == '0') break;
        keys |= (1<<(tmp[i] - 'a'));
    }
    return;
}

bool bfs()
{
    int delta = 0;
    while (!q.empty())
    {
        pair<int, int> yx = q.front();
        q.pop();
        if('A' <= map[yx.first][yx.second] &&  map[yx.first][yx.second] <= 'Z'){
            if((keys >> (map[yx.first][yx.second] - 'A')) % 2 == 0){
                seed.push(yx);
                continue;
            }
        }
        if('a' <= map[yx.first][yx.second] &&  map[yx.first][yx.second] <= 'z') delta = delta | (1<<(map[yx.first][yx.second] - 'a'));
        for(int k=0; k<4; k++){
            int nx = yx.second + xd[k], ny = yx.first + yd[k];
            if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if(vis[ny][nx] || map[ny][nx] == '*') continue;
            vis[ny][nx] = 1;
            if(map[ny][nx] == '$'){
                 ans++;
            }
            q.push(make_pair(ny, nx));
        }
    }
    keys |= delta;
    return (delta > 0);
}

void init()
{
    while (!seed.empty()) seed.pop();
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            vis[i][j] = 0;
        }
    }
    return;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++){
        ans = 0;
        input();
        do
        {
            while (!seed.empty())
            {
                q.push(seed.front());
                seed.pop();
            }
        } while (bfs());
        printf("%d\n", ans);
        init();
    }
    return 0;
}