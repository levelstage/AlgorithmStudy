// 6549 히스토그램에서 가장 큰 직사각형
// 테스트케이스를 주는 문제에서는 초기화를 꼭 신경 쓸 수 있도록 하자.

#include <cstdio>
#include <queue>

using namespace std;

vector<int> H, tree;
int N, pad;
long long int ans;
queue<pair<int, int>> q;

void build_tree()
{
    int i=pad;
    while (i>1)
    {
        for(int j=i; j<i*2; j+=2)
        {
            if(H[tree[j]] < H[tree[j+1]]) tree[j/2] = tree[j];
            else tree[j/2] = tree[j+1];
        }
        i/=2;
    }
    return;
}

int get_min(int s, int e)
{
    if(s==e) return s;
    int res = 0;
    s+=pad-1;
    e+=pad-1;
    while (s <= e)
    {
        if(s%2 == 1){
            if(H[res] > H[tree[s]]){
                res = tree[s];
            }
            ++s;
        }
        if(e%2 == 0){
            if(H[res] > H[tree[e]]){
                res = tree[e];
            }
            --e;
        }
        s/=2;
        e/=2;
    }
    return res;
}

void solve()
{
    q.push(make_pair(1, N));
    while (!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        int len = t.second - t.first + 1, min = get_min(t.first, t.second);
        ans = (long long int)len * H[min] > ans ? (long long int)len * H[min] : ans; 
        if(min > t.first) q.push(make_pair(t.first, min-1));
        if(min < t.second) q.push(make_pair(min+1, t.second));
    }
    return;
}

int main()
{
    while (1)
    {
        scanf("%d", &N);
        if(N == 0) break;
        ans = 0;
        pad = 1;
        while (pad<N) pad*=2;
        H.assign(pad+1, 0);
        tree.assign(pad*2+1, 0);
        H[0] = 1000000001;
        for(int i=1; i<=N; ++i) {
            scanf("%d", &H[i]);
            tree[pad+i-1] = i;
        }
        build_tree();
        solve();
        printf("%lld\n", ans);
    }
    
    return 0;
}