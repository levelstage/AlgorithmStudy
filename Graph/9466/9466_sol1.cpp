// 9466 텀 프로젝트
// 재귀가 10만층까지 깊어질 수 있긴 하다. 재귀 스택이 널널하지 않은 환경이었으면 틀렸을지도 모름.

#include <iostream>
#include <queue>

using namespace std;

int T, N, ans;
vector<bool> vis, check;
vector<int> arr;

void input()
{
    cin>>N;
    arr.assign(N+1, 0);
    vis.assign(N+1, 0);
    check.assign(N+1, 0);
    for(int i=1; i<=N; i++){
        cin>>arr[i];
    }
    return;
}

int trace_loop(int num)
{
    vis[num] = 1;
    if(num == arr[num] || check[arr[num]]) return arr[num];
    if(vis[arr[num]]){
        ans++;
        return -1;
    }
    check[num] = 1;
    int loop = trace_loop(arr[num]);
    check[num] = 0;
    if(loop == arr[num] || loop == -1){
        ans++;
        return -1;
    }
    return loop;
}

void solve()
{
    for(int i=1; i<=N; i++){
        if(vis[i]) continue;
        trace_loop(i);
    }
    cout<<ans<<endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for(int i=0; i<T; i++){
        input();
        ans = 0;
        solve();
    }
    return 0;
}