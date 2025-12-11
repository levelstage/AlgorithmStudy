// 28707 배열 정렬
// vis 처리하는 로직이 솔직히 만족스럽지는 않음.

#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

struct mani
{
    int a, b, cost;
};

struct task 
{
    vector<int> arr;
    int cost, code;
};

struct lower_cost
{
    bool operator()(task &a, task &b)
    {
        return a.cost > b.cost;
    }
};


int N, M;
mani sws[10];
bool vis[90000000];
priority_queue<task, vector<task>, lower_cost> q;

task input()
{
    task t;
    scanf("%d", &N);
    t.arr.assign(N+1, 0);
    for(int i=1; i<=N; i++) scanf("%d", &t.arr[i]);
    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        scanf("%d %d %d", &sws[i].a, &sws[i].b, &sws[i].cost);
        if(sws[i].a > sws[i].b){
            int tmp = sws[i].a;
            sws[i].a = sws[i].b;
            sws[i].b = tmp;
        }
    }
    int n=1;
    t.code = 0;
    for(int i=N; i>=1; i--){
        t.code += n*i;
        n *= 10;
    }
    t.cost = 0;
    return t;
}

bool sorted(vector<int> &v)
{
    int x=v[0];
    for(int i=1; i<v.size(); i++)
    {
        if(v[i] < x) return 0;
        x = v[i];
    }
    return 1;
}

int swap_code(int code, int a, int b)
{
    int res = 0, n=1, na, nb;
    for(int i=N; i>=1; i--){
        if(i == b){
            na = (code%10);
            nb = n;
        }
        else if(i == a){
            res+=na*n;
            res+=(code%10)*nb;
        }
        else res += (code % 10) * n;
        n*=10;
        code/=10;
    }
    return res;
}

int bfs()
{
    while(!q.empty())
    {
        task t = q.top();
        q.pop();
        if(vis[t.code]) continue;
        if(sorted(t.arr)) return t.cost;
        vis[t.code] = 1;
        for(int i=0; i<M; i++)
        {
            task next;
            next.arr = t.arr;
            int tmp = next.arr[sws[i].a];
            next.arr[sws[i].a] = next.arr[sws[i].b];
            next.arr[sws[i].b] = tmp;
            next.cost = t.cost + sws[i].cost;
            next.code = swap_code(t.code, sws[i].a, sws[i].b);
            if(vis[next.code]) continue;
            q.push(next);
        }
    }
    return -1;
}

int main()
{
    q.push(input());
    printf("%d", bfs());
    return 0;
}