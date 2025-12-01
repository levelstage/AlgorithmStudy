// 2568 전깃줄-2
// 멍청하게 최소 개수 출력 안해서 3번이나 틀림... 하지만 결국 맞았죠.

#include<cstdio>
#include<queue>
#include<stack>

using namespace std;

struct lower_first
{
    bool operator() (pair<int, int> &a, pair<int, int> &b)
    {
        return a.first > b.first;
    }
};


priority_queue<pair<int, int>, vector<pair<int, int>>, lower_first> q;
queue<int> out;
vector<pair<int, int>> last, memory;
int N;

int find_last(int v, int s, int e)
{
    int i = (s+e)/2;
    if(last[i].first > v){
        if(i == 0) return 0;
        if(last[i-1].first <= v) return i;
        return find_last(v, s, i-1);
    }
    if(i == last.size()-1) return last.size();
    if(last[i+1].first > v) return i+1;
    return find_last(v, i+1, e);
}

void input()
{
    scanf("%d",&N); 
    for(int i=0; i<N; i++){
        pair<int, int> tmp;
        scanf("%d %d", &tmp.first, &tmp.second);
        q.push(tmp);
    }
    return;
}

void solve()
{
    int idx = 0;
    while (!q.empty())
    {
        pair<int, int> tmp = q.top();
        out.push(tmp.first);
        q.pop();
        int d = 0;
        if(!last.empty())d = find_last(tmp.second, 0, last.size()-1);
        if(d == last.size()){
            last.push_back(make_pair(tmp.second, idx));
        }
        else{
            last[d] = make_pair(tmp.second, idx);
        }
        if(d == 0) memory.push_back(make_pair(tmp.first, -1));
        else memory.push_back(make_pair(tmp.first, last[d-1].second)); 
        idx++;
    }
    return;
}

void output()
{
    stack<int> ans;
    pair<int, int> tmp = memory[last.back().second];
    while(1)
    {
        ans.push(tmp.first);
        if(tmp.second == -1) break;
        tmp = memory[tmp.second];
    }
    printf("%d\n", out.size() - ans.size());
    while(!out.empty())
    {
        if(!ans.empty()){
            if(ans.top() == out.front()){
                ans.pop();
                out.pop();
                continue;
            }
        }
        printf("%d\n", out.front());
        out.pop();
    }
    return;
}

int main()
{
    input();
    solve();
    output();
    return 0;
}