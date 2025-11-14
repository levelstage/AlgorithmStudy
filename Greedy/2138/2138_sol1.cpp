// 2138 전구와 스위치
// 아이디어는 어려운데 구현은 쉬웠음.

#include <iostream>
#include <string>

using namespace std;

int N;
bool map[100000], ans[100000];
void input()
{
    string inp;
    cin>>N;
    cin>>inp;
    for(int i=0; i<N; i++) map[i] = (inp[i] == '1');
    cin>>inp;
    for(int i=0; i<N; i++) ans[i] = (inp[i] == '1');
}

int solve(int i, bool prev, bool now)
{
    if(i == N-1){
        if((prev==now)==(map[i]==ans[i])) return now;
        return 100001;
    }
    if((prev==now)==(map[i]==ans[i])) return solve(i+1, now, 0) + now;
    return solve(i+1, now, 1) + now;
}

int min(int a, int b) { return a<b ? a:b; }

int main()
{
    int res;
    input();
    if(map[0] == ans[0]) res = min(solve(1,0,0), solve(1,1,1) + 1);
    else res = min(solve(1,0,1), solve(1,1,0)+1);
    if(res>=100001) cout<<-1<<endl;
    else cout<<res<<endl;
    return 0;
}