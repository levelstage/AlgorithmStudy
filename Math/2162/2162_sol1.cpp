// 2162 선분 그룹
// 그냥 선분 교차 처리하는게 헬임

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct seg
{
    pair<int, int> a, b;
};

int N, group[3001], depth[3001];
vector<seg> inp;

int cross(const pair<int, int> &a, const pair<int, int> &b)
{
    int x = a.first * b.second - b.first * a.second;
    if(x == 0) return 0;
    if(x > 0) return 1;
    return -1;
}

pair<int, int> tovec(pair<int, int> &s, pair<int, int> &e)
{
    return make_pair(e.first - s.first, e.second - s.second);
}

bool check(seg s1, seg s2)
{
    pair<int, int> v1 = tovec(s1.a, s1.b), v2 = tovec(s2.a, s2.b);
    int x1 = cross(v1, tovec(s1.a, s2.a)) * cross(v1, tovec(s1.a, s2.b));
    int x2 = cross(v2, tovec(s2.a, s1.a)) * cross(v2, tovec(s2.a, s1.b));
    if(x1 > 0 || x2 > 0) return 0;
    if(x1 == 0 && x2 == 0){
        if(max(s1.a.first, s1.b.first) < min(s2.a.first, s2.b.first) || max(s2.a.first, s2.b.first) < min(s1.a.first, s1.b.first)) return 0;
        if(max(s1.a.second, s1.b.second) < min(s2.a.second, s2.b.second) || max(s2.a.second, s2.b.second) < min(s1.a.second, s1.b.second)) return 0;
    }
    return 1;
}

int root(int n)
{
    if(group[n] == n) return n;
    return group[n] = root(group[n]);
}

void init()
{
    for(int i=1; i<=N; i++){
        group[i] = i;
        depth[i] = 1;
    }
    return;
}

pair<int, int> solve()
{
    int cnt=0, amo=1;
    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            if(check(inp[i], inp[j]) && root(i) != root(j)){
                if(depth[root(i)] >= depth[root(j)]){
                    depth[root(i)] += depth[root(j)];
                    group[root(j)] = root(i);
                    if(amo < depth[root(i)]) amo = depth[root(i)];
                }
                else{
                    depth[root(j)] += depth[root(i)];
                    group[root(i)] = root(j);
                    if(amo < depth[root(j)]) amo = depth[root(j)];
                }
            }
        }
    }
    for(int i=1; i<=N; i++)if(root(i) == i) cnt++;
    return make_pair(cnt, amo);
}

int main()
{
    scanf("%d", &N);
    inp.reserve(N+1);
    seg tmp;
    inp.push_back(tmp);
    for(int i=1; i<=N; i++){
        scanf("%d %d %d %d", &tmp.a.first, &tmp.a.second, &tmp.b.first, &tmp.b.second);
        inp.push_back(tmp);
    }
    init();
    pair<int, int> ans = solve();
    printf("%d\n%d", ans.first, ans.second);
    return 0;
}