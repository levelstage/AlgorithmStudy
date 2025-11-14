// 2467 용액
// 엣지 케이스;;;;

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int N;
vector<int> acid;
queue<int> alca;

void input()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp>0) acid.push_back(tmp);
        else alca.push(-tmp);
    }
    sort(acid.begin(), acid.end());
    return;
}

int optacid(int v, int s, int e)
{
    int i = (s+e)/2;
    if(acid[i] == v) return acid[i];
    if(acid[i] < v){
        if(i == acid.size() - 1) return acid[i];
        if(acid[i+1] == v) return acid[i+1];
        if(acid[i+1] > v) return abs(acid[i]-v) < abs(acid[i+1]-v) ? acid[i] : acid[i+1];
        return optacid(v, i+1, e);
    }
    if(i==0) return acid[i];
    if(acid[i-1] == v) return acid[i-1];
    if(acid[i-1] < v) return abs(acid[i]-v) < abs(acid[i-1]-v) ? acid[i] : acid[i-1];
    return optacid(v, s, i-1);
}

pair<int, int> solve()
{
    int minx = 2000000001, m1=0, m2=0;
    pair<int, int> res;
    if(acid.size() >= 2){
        minx = acid[0] + acid[1];
        res.first = acid[0];
        res.second = acid[1];
    }
    while (!alca.empty())
    {
        if(!acid.empty()){
            int partner = optacid(alca.front(), 0, acid.size()-1);
            if(alca.front() == partner){
                return make_pair(-alca.front(), partner);
            }
            if(minx > abs(alca.front() - partner)){
                minx = abs(alca.front() - partner);
                res.first = -alca.front();
                res.second = partner;
            }
        }
        if(m1 == 0 || m1 > alca.front()) {
            m2 = m1;
            m1 = alca.front();
        }
        else if(m2 == 0 || m2 > alca.front()){
            m2 = alca.front();
        }
        alca.pop();
    }
    if(m1 != 0 && m2 != 0 && m1+m2 < minx){
        return make_pair(-m2, -m1);
    }
    return res;
}

int main()
{
    input();
    pair<int, int> ans = solve();
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}
    