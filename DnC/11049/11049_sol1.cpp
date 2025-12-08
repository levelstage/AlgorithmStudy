// 11049 행렬 곱셈 순서

#include <iostream>
#include <vector>

using namespace std;

int N, dt[500][500];
vector<int> exp;

void input()
{
    cin>>N;
    for(int i=0; i<N; i++){
        int t1, t2;
        cin>>t1>>t2;
        if(i == 0) exp.push_back(t1);
        exp.push_back(t2);
        if(i != 0)dt[i-1][i] = exp[i-1] * exp[i] * exp[i+1]; 
    }
    return;
}

int min(int a, int b) {return a<b ? a:b;}

int solve(int s, int e)
{
    if(s != e && dt[s][e] == 0){
        dt[s][e] = solve(s, s) + solve(s+1, e) + exp[s] * exp[s+1] * exp[e+1];
        for(int i=s+1; i<e; i++){
            dt[s][e] = min(dt[s][e], solve(s, i) + solve(i+1, e) + exp[s] * exp[i+1] * exp[e+1]);
        }
    }
    return dt[s][e];
}

int main()
{
    input();
    printf("%d\n", solve(0, N-1));
    return 0;
}