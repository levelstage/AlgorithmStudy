// 13334 철로
// 찾는 게 아니라 안되는 애를 빼는게 핵심이었음;;
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, d, valid_n;
vector<int> first, second;

void input()
{
    scanf("%d", &n);
    vector<int> t1(n), t2(n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &t1[i], &t2[i]);
    }
    scanf("%d", &d);
    valid_n = n;
    for(int i=0; i<n; i++){
        int h = t1[i], o=t2[i];
        if(abs(o-h) <= d){
            first.push_back(min(h, o));
            second.push_back(max(h, o));
        }
        else valid_n--;
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());   
    return;
}

int search(int s, int e, int v)
{
    int i = (s+e) / 2;
    if(s>e) return -1;
    if(second[i] > v){
        if(i == 0) return 0;
        if(second[i-1] <= v) return i;
        return search(s, i-1, v);
    }
    return search(i+1, e, v);
}

int solve()
{
    int res=0;
    for(int i=0; i<valid_n; i++){
        int tmp = valid_n - i;
        int bigger = search(0, second.size() - 1, first[i] + d);
        if(bigger != -1) tmp = tmp - (valid_n - bigger);
        res = max(res, tmp);
    }
    return res;
}

int main()
{
    input();
    printf("%d\n", solve());
    return 0;
}