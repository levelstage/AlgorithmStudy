// 보석 도둑
// cin을 빼먹다니 미친거 아니야?

#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

struct greater_first
{
    bool operator()(pair<int,int> &a, pair<int,int> &b)
    {
        return a.first > b.first;
    }
};

int N, K;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater_first> jews;
priority_queue<int, vector<int>, greater<int>> bags;
priority_queue<int> hubo;

void input()
{
    cin>>N>>K;
    for(int i=0; i<N; i++){
        int m, v;
        cin>>m>>v;
        jews.push(make_pair(m, v));
    }
    for(int i=0; i<K; i++){
        int b;
        cin>>b;
        bags.push(b);
    }
    return;
}

long long int solve()
{
    long long int res=0;
    int sv=0;
    while(!jews.empty())
    {
        int m = jews.top().first, v = jews.top().second;
        if(bags.top() < m){
            res += sv;
            bags.pop();
            if(bags.empty())break;
            if(hubo.empty()) sv = 0;
            else{
                sv = hubo.top();
                hubo.pop();
            }
            continue;
        }
        if(sv < v){
            hubo.push(sv);
            sv=v;
        }
        else hubo.push(v);
        jews.pop();
    }
    if(!bags.empty()){
        res += sv;
        bags.pop();
    }
    int remain = bags.size();
    for(int i=0; i<remain; i++){
        if(hubo.empty())break;
        res+=hubo.top();
        hubo.pop();
    }
    return res;
}

int main()
{
    input();
    cout<<solve()<<endl;
    return 0;
}