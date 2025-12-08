// 1509 팰린드롬 분할
// 이것도 D&C라고 할 수 있나? 일단 겨우 풀긴함.

#include <iostream>
#include <string>

using namespace std;

string inp;
int d[2500];
bool pal[2500][2500], vis[2500][2500];

int min(int a, int b) { return a<b ? a:b; }

bool check(int s, int e)
{
    if(pal[s][e] == 1 || e<s) return 1;
    if(vis[s][e]) return 0;
    vis[s][e] = 1;
    if(inp[s] != inp[e]) return 0;
    if(check(s+1, e-1)) return pal[s][e]=1;
    return 0;
}

int solve(int e)
{
    if(e == 0) return 1;
    if(d[e] == 0){
        if(check(0, e)) return d[e]=1;
        d[e] = solve(e-1) + 1;
        for(int i=e-1; i>=1; i--){
            if(check(i, e)) d[e] = min(d[e], solve(i-1) + 1);
        }
    }
    return d[e];
}

int main()
{
    cin>>inp;
    cout<<solve(inp.length()-1)<<endl;
    return 0;
}