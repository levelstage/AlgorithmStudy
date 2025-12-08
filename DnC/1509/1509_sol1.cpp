// 1509 팰린드롬 분할
// 시간초과... D&C로 푸는게 아닌거같다.

#include <iostream>
#include <string>

using namespace std;

string inp;
int d[2500][2500];
bool vis[2500][2500];

int min(int a, int b) { return a<b ? a:b; }

bool check(int s, int e)
{
    if(d[s][e] == 1 || e<s) return 1;
    if(vis[s][e]) return 0;
    vis[s][e] = 1;
    if(inp[s] != inp[e]) return 0;
    if(check(s+1, e-1)) return d[s][e]=1;
    return 0;
}

int solve(int s, int e)
{
    if(d[s][e] == 0){
        if(check(s,e)) return 1;
        d[s][e] = solve(s, s) + solve(s+1, e);
        for(int i=s+1; i<e; i++){
            d[s][e] = min(d[s][e], solve(s, i) + solve(i+1, e));
        }
    }
    return d[s][e];
}

int main()
{
    cin>>inp;
    for(int i=0; i<inp.length(); i++) d[i][i] = 1;
    cout<<solve(0, inp.length()-1)<<endl;
    return 0;
}