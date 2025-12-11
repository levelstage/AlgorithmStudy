// 16566 카드 게임

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, K;
vector<int> hand, inp, route;

void input()
{
    scanf("%d %d %d", &N, &M, &K);
    hand.assign(M, 0);
    route.assign(M, 0);
    inp.assign(K, 0);
    for(int i=0; i<M; i++){
        scanf("%d", &hand[i]);
        route[i] = i;
    }
    for(int i=0; i<K; i++){
        scanf("%d", &inp[i]);
    }
    sort(hand.begin(), hand.end());
    return;
}

int trace(int n)
{
    if(n < 0) return -1;
    if(route[n] == n){
        route[n] = n+1;
        return n;
    }
    return route[n] = trace(route[n]);
}

int find(int v, int s, int e)
{
    int i=(s+e)/2;
    if(hand[i] > v){
        if(i == 0) return trace(0);
        if(hand[i-1] <= v) return trace(i);
        return find(v, s, i-1);
    }
    return find(v, i+1, e);
}

int main()
{
    input();
    for(int i=0; i<K; i++)
    {
        printf("%d\n", hand[find(inp[i], 0, M-1)]);
    }
    return 0;
}