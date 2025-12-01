// 14003 가장 긴 증가하는 부분 수열 5
// 그 긴거의 최종진화. 그래도 풀었죠?

#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int N;
vector<pair<int, int>> last; 
vector<pair<int, int>> memory;

int find_last(int v, int s, int e)
{
    int i = (s+e)/2;
    if(last[i].first >= v){
        if(i == 0) return 0;
        if(last[i-1].first < v) return i;
        return find_last(v, s, i-1);
    }
    if(i == last.size()-1) return last.size();
    if(last[i+1].first >= v) return i+1;
    return find_last(v, i+1, e);
}

void output()
{
    printf("%d\n", last.size());
    stack<int> ans;
    pair<int, int> top = memory[last[last.size()-1].second];
    ans.push(top.first);
    while (top.second != -1)
    {
        top = memory[top.second];
        ans.push(top.first);
    }
    while(!ans.empty()) {
        printf("%d ", ans.top());
        ans.pop();
    }
    return;
}

int main()
{
    scanf("%d", &N);
    last.reserve(N);
    memory.reserve(N);
    int tmp;
    scanf("%d", &tmp);
    last.push_back(make_pair(tmp, 0));
    memory.push_back(make_pair(tmp, -1));
    for(int i=1; i<N; i++){
        scanf("%d", &tmp);
        int idx = find_last(tmp, 0, last.size()-1);
        if(idx == last.size()) last.push_back(make_pair(tmp, i));
        else{
            last[idx].first = tmp;
            last[idx].second = i;
        }
        if(idx == 0)memory.push_back(make_pair(tmp, -1));
        else memory.push_back(make_pair(tmp, last[idx-1].second));
    }
    output();
    return 0;
}

