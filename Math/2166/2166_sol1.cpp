// 2166 다각형의 넓이
// 걍 적분임 ㅇㅇ;

#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>

using namespace std;

int N;
vector<pair<int, int>> xys;

void input()
{
    cin>>N;
    for(int i=0; i<N; i++){
        pair<int, int> xy;
        cin>>xy.first>>xy.second;
        xys.push_back(xy);
    }
    return;
}

double integral(int s, int e)
{
    double sum = 0;
    pair<int, int> prev = xys[s];
    int i = (s+1) % N;
    while(1)
    {
        sum += (double)(prev.second + xys[i].second) / 2 * (xys[i].first - prev.first);
        prev = xys[i];
        if(i == e) break;
        i = (i+1) % N;
    }
    sum += (double)(xys[e].second + xys[s].second) / 2 * (xys[s].first - xys[e].first);
    return sum;
}

int main()
{
    input();
    cout<<fixed<<setprecision(1);
    cout<<abs(integral(0, N-1))<<endl;
    return 0;
}