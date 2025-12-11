// 20303 할로윈의 양아치

#include <cstdio>
#include <queue>

using namespace std;

int N, M, K;
vector<int> candies, group, head, mass, dt;

int root(int n)
{
    if(group[n] == n) return n;
    return group[n] = root(group[n]);
}

void input()
{
    scanf("%d %d %d", &N, &M, &K);
    candies.assign(N+1, 0);
    group.assign(N+1, 0);
    for(int i=1; i<=N; i++) {
        scanf("%d", &candies[i]);
        group[i] = i;
    }
    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        int ar = root(a), br= root(b);
        if(ar < br) group[br] = ar;
        else group[ar] = br;
    }
    return;
}

void gather()
{
    int x=0;
    mass.assign(N+1, 0);
    for(int i=1; i<=N; i++){
        int r = root(group[i]);
        mass[r]++;
        if(r > x){
            head.push_back(r);
            x = r;
        }
        else{
            candies[r] += candies[i];
        }
    }
    return;
}

int solve()
{
    dt.assign(K, 0);
    for(int i=0; i<head.size(); i++){
        for(int j=K-1; j>=mass[head[i]]; j--){
            if(dt[j] < dt[j-mass[head[i]]] + candies[head[i]]){
                dt[j] = dt[j-mass[head[i]]] + candies[head[i]];
            }
        }
    }
    return dt[K-1];
}

int main()
{
    input();
    gather();
    printf("%d", solve());
    return 0;
}