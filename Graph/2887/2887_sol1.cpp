// 2887 행성 터널
// 진짜 실력이 많이 늘긴 했구나 하고 느껴짐

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct edge
{
    int a, b, cost;
};

struct lower_cost
{
    bool operator()(edge &a, edge &b)
    {
        return a.cost > b.cost;
    }
};


int N;
vector<int> mass, group;
vector<pair<int, int>> co[3];
priority_queue<edge, vector<edge>, lower_cost> q;
void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        co[0].push_back(make_pair(x, i));
        co[1].push_back(make_pair(y, i));
        co[2].push_back(make_pair(z, i));
        group.push_back(i);
        mass.push_back(1);
    }
    return;
}

void init()
{
    for(int j=0; j<=2; j++)sort(co[j].begin(), co[j].end());
    for(int i=1; i<N; i++){
        for(int j=0; j<=2; j++){
            edge tmp;
            tmp.a = co[j][i-1].second;
            tmp.b = co[j][i].second;
            tmp.cost = co[j][i].first - co[j][i-1].first;
            q.push(tmp);
        }
    }
    return;
}

int root(int n)
{
    if(n == group[n]) return n;
    return group[n] = root(group[n]);
}

long long int solve()
{
    long long int res=0;
    while(!q.empty())
    {
        edge e = q.top();
        q.pop();
        if(root(e.a) == root(e.b)) continue;
        if(mass[group[e.a]] >= mass[group[e.b]]){
            res = res + e.cost;
            mass[group[e.a]] += mass[group[e.b]];
            if(mass[group[e.a]] == N) break;
            group[group[e.b]] = group[group[e.a]];
        }
        else{
            res = res + e.cost;
            mass[group[e.b]] += mass[group[e.a]];
            if(mass[group[e.b]] == N) break;
            group[group[e.a]] = group[group[e.b]];
        }
    }
    return res;
}

int main()
{
    input();
    init();
    printf("%lld", solve());
    return 0;
}