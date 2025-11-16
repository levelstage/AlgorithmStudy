// 2098 외판원 순회
// 물탱크를 풀고 와서 얘는 쉬웠음 그래도

#include<iostream>
#include<queue>

using namespace std;

int N, W[16][16], dt[65536][16];

struct route
{
    int x, length, vis;
};

struct comp
{
    bool operator() (route &a, route &b)
    {
        return a.length > b.length;
    }
};

priority_queue<route, vector<route>, comp> q;

route make_route(int x, int length, int vis)
{
    route tmp;
    tmp.x = x; tmp.length = length; tmp.vis = vis;
    return tmp;
}

void input()
{
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>W[i][j];
        }
    }
}

int bfs()
{
    q.push(make_route(0,0,0));
    while(!q.empty())
    {
        route r = q.top();
        q.pop();
        if(r.vis == (1<<N)-1) return r.length;
        if(r.vis == (1<<N)-2) {
            if(W[r.x][0] == 0) continue;
            q.push(make_route(0, r.length+W[r.x][0], r.vis+1));
            continue;
        }
        for(int i=1; i<N; i++){
            if(W[r.x][i] == 0) continue;
            if((r.vis>>i) % 2 == 1) continue;
            if(dt[r.vis+(1<<i)][i] != 0 && dt[r.vis+(1<<i)][i] <= r.length+W[r.x][i]) continue;
            dt[r.vis+(1<<i)][i] = r.length+W[r.x][i];
            q.push(make_route(i, r.length+W[r.x][i], r.vis+(1<<i)));
        }
    }
    return 1234;
}

int main()
{
    input();
    cout<<bfs()<<endl;
    return 0;
}