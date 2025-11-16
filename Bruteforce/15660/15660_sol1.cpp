// 15660 테트로미노 2
// 노력과 우직함의 승리;;

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct mino
{
    int x=0, y=0;
    vector<pair<int, int>> xys;  
};
int N, M, board[1000][1000];
bool vis[1000][1000];
vector<mino> v;

mino make_mino(int x1, int y1, int x2, int y2, int x3, int y3)
{
    mino tmp;
    tmp.xys.push_back(make_pair(x1,y1));
    tmp.xys.push_back(make_pair(x2,y2));
    tmp.xys.push_back(make_pair(x3,y3)); 
    return tmp;
}

bool valid(int x, int y)
{
    if (x < 0 || x >= M || y < 0 || y >= N) return 0;
    if (vis[y][x]) return 0;
    return 1;
}

int summino(mino &m)
{
    int sum = board[m.y][m.x];
    for(int i=0; i<3; i++){
        int nx = m.xys[i].first + m.x, ny = m.xys[i].second + m.y;
        if(!valid(nx, ny)) return 0;
        sum+=board[ny][nx];
    }
    return sum;
}

void stretch(vector<mino> &res, mino seed, int len)
{
    if(len == 1){
        res.push_back(seed);
        return;
    }
    int xv[4] = {0, 0, -1, 1}, yv[4] = {-1, 1, 0, 0}; 
    pair<int, int> pos = seed.xys.back();
    for(int k=0; k<4; k++){
        if(xv[k] * seed.xys[0].first == -1) continue;
        if(yv[k] * seed.xys[0].second == -1) continue;
        int nx = pos.first + xv[k], ny = pos.second + yv[k];
        if(seed.xys.size() >= 2){
            if(nx == seed.xys[seed.xys.size()-2].first && ny == seed.xys[seed.xys.size()-2].second) continue;
        }
        mino tmp = seed;
        tmp.xys.push_back(make_pair(nx, ny));
        stretch(res, tmp, len-1);
    }
    return;
}

void push_all_sides()
{
    int xv[4] = {0, 0, -1, 1}, yv[4] = {-1, 1, 0, 0};
    for(int k=0; k<4; k++){
        // 1+3 조합
        mino seed;
        seed.xys.push_back(make_pair(xv[k], yv[k]));
        stretch(v, seed, 3);
        // stretch 불가능한 T (1+3)
        if(xv[k] == 0){
            v.push_back(make_mino(0,yv[k], -1,yv[k], 1,yv[k]));
            v.push_back(make_mino(0,yv[k], 0,yv[k]*2, 1,yv[k]));
            v.push_back(make_mino(0,yv[k], -1,yv[k], 0,yv[k]*2));
        }
        else{
            v.push_back(make_mino(xv[k], 0, xv[k], -1, xv[k], 1));
            v.push_back(make_mino(xv[k], 0, xv[k]*2, 0, xv[k], 1));
            v.push_back(make_mino(xv[k], 0, xv[k], -1, xv[k]*2, 0));
        }
        //1 + 2 + 1 조합 
        vector<mino> tmp;
        stretch(tmp, seed, 2);

        for(int i=0; i<tmp.size(); i++){
            for(int j=0; j<4; j++){
                if(j == k) continue;
                // 겹치는 케이스 ㅁ은
                if((abs(tmp[i].xys[1].first-xv[j]) + abs(tmp[i].xys[1].second-yv[j])) == 1) continue;
                tmp[i].xys.push_back(make_pair(xv[j], yv[j]));
                v.push_back(tmp[i]);
            }
        }
        // 여기서 따로 처리
        v.push_back(make_mino(0,yv[k/2],yv[k%2],0,yv[k/2],yv[k%2]));
        //1 + 1 + 1 + 1 조합(ㅗ)
        seed.xys.clear();
        for(int i=0; i<4; i++){
            if(i==k) continue;
            seed.xys.push_back(make_pair(xv[i], yv[i]));
        }
        v.push_back(seed);
    }
    return;
}

void input()
{
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>board[i][j];
        }
    }
    // 가능한 모든 테트로미노의 경우의 수 하드코딩
    //Z
    v.push_back(make_mino(1,0,1,1,2,1));
    v.push_back(make_mino(0,-1,1,-1,1,-2));
    //S
    v.push_back(make_mino(1,0,1,-1,2,-1));
    v.push_back(make_mino(0,1,1,1,1,2));
    //L
    v.push_back(make_mino(0,1,0,2,1,2));
    v.push_back(make_mino(0,-1,1,-1,2,-1));
    v.push_back(make_mino(1,0,1,1,1,2));
    v.push_back(make_mino(1,0,2,0,2,-1));
    //J
    v.push_back(make_mino(1,0,1,-1,1,-2));
    v.push_back(make_mino(0,1,1,1,2,1));
    v.push_back(make_mino(0,-1,0,-2,1,-2));
    v.push_back(make_mino(1,0,2,0,2,1));
    //ㅡㅣ
    v.push_back(make_mino(1,0,2,0,3,0));
    v.push_back(make_mino(0,1,0,2,0,3));
    //ㅁ
    v.push_back(make_mino(1,0,0,1,1,1));
    //ㅗ ㅏ ㅜ ㅓ
    v.push_back(make_mino(1,0,1,-1,2,0));
    v.push_back(make_mino(0,1,1,1,0,2));
    v.push_back(make_mino(1,0,1,1,2,0));
    v.push_back(make_mino(1,0,1,-1,1,1));
    return;
}

mino best4()
{
    int big = 0;
    mino res;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(vis[i][j]) continue;
            for(int k=0; k<v.size(); k++){
                v[k].x = j; v[k].y = i;
                int sum = summino(v[k]);
                if(sum > big){
                    big = sum;
                    res = v[k];
                }
            }
        }
    }
    return res;
}

void stamp(mino &m, bool value)
{
    vis[m.y][m.x] = value;
    for(int k=0; k<3; k++){
        vis[m.y+m.xys[k].second][m.x+m.xys[k].first] = value;
    }
    return;
}

int best8()
{
    mino b1 = best4();
    stamp(b1, 1);
    mino b2 = best4();
    stamp(b1, 0);
    int res = summino(b1) + summino(b2);
    v.clear();
    push_all_sides();
    for(int i=-1; i<3; i++){
        int x1 = b1.x, y1 = b1.y;
        if(i != -1){
            x1 += b1.xys[i].first;
            y1 += b1.xys[i].second;
        }
        for(int s1=0; s1<v.size(); s1++){
            v[s1].x = x1; v[s1].y = y1;
            int sum1 = summino(v[s1]);
            stamp(v[s1], 1);
            for(int j=i+1; j<3; j++){
                int x2 = b1.x + b1.xys[j].first, y2 = b1.y + b1.xys[i].second;
                if(vis[y2][x2] == 1) continue;
                for(int s2=0; s2<v.size(); s2++){
                    v[s2].x = x2; v[s2].y = y2;
                    int sum2 = summino(v[s2]);
                    if(sum1 + sum2 > res) res = sum1 + sum2;
                }
            }
            v[s1].x = x1; v[s1].y = y1;
            stamp(v[s1],0);
        }
    }
    return res;
}

int main()
{
    input();
    cout<<best8()<<endl;
    return 0;
}