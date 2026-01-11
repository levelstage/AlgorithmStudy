// 1708 볼록 껍질
// 기하 문제에서는 항상 오버플로우를 조심하자. 그거 하나 못찾아서 생고생함.
// 그리고 반시계방향이 양수다! 맨날 헷갈리네.

#include<cstdio>
#include<queue>
#include<stack>

using namespace std;

int N, minX;
vector<pair<int, int>> xys;

struct upper_theta
{
    bool operator()(pair<int, double> &a, pair<int, double> &b)
    {
        if(a.second == b.second) {
            if(xys[a.first].first == xys[b.first].first) return xys[a.first].second > xys[b.first].second;
            return xys[a.first].first > xys[b.first].first;
        }
        return a.second < b.second;
    }
};


priority_queue<pair<int, double>, vector<pair<int, double>>, upper_theta> q;
stack<int> ans;

void input()
{
    scanf("%d", &N);
    xys.resize(N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &xys[i].first, &xys[i].second);
        if(xys[i].first == xys[minX].first){
            minX = xys[i].second > xys[minX].second ? i : minX;
        }
        else if(xys[i].first < xys[minX].first) minX = i; 
    }
    return;
}

void clockwise_enqueue()
{
    for(int i=0; i<N; i++){
        if(i == minX) continue;
        int dx = xys[i].first - xys[minX].first, dy = xys[i].second - xys[minX].second;
        // (1, 0)과의 외적은 dy와 같음. 또한 sin^2 x는 -90~0도에서 감소함수, 0~90도에서 증가함수이므로, 음수쪽을 뒤집으면 각도에 대한 증가함수가 됨.
        double theta = (double)(dy<0 ? -1: 1) * ((long long int)dy*dy) / ((long long int)dx*dx + (long long int)dy*dy); 
        q.push(make_pair(i, theta));
    }
    return;
}

long long int cross_product(pair<int, int> &v1, pair<int, int> &v2)
{
    return (long long int)v1.first * v2.second - (long long int)v2.first * v1.second;
}

void solve()
{
    //printf("minx: %d\n", minX);
    ans.push(minX);
    ans.push(q.top().first);
    q.pop();
    q.push(make_pair(minX, -1.1));
    while (!q.empty())
    {
        int self = ans.top();
        ans.pop();
        int prev = ans.top();
        int next = q.top().first;
        pair<int, int> prev_to_self = make_pair(xys[self].first - xys[prev].first, xys[self].second - xys[prev].second);
        pair<int, int> prev_to_next = make_pair(xys[next].first - xys[prev].first, xys[next].second - xys[prev].second);
        //printf("size=%d, (%d, %d) => (%d, %d), cp: %d\n", ans.size(), xys[self].first, xys[self].second, xys[next].first, xys[next].second, cross_product(prev_to_self, prev_to_next));
        long long int cp = cross_product(prev_to_self, prev_to_next);
        if(cp < 0){
            ans.push(self);
            ans.push(next);
            q.pop();
        }
        else if(cp == 0)
        {
            ans.push(next);
            q.pop();
        }
    }
    return;
}

int main()
{
    input();
    clockwise_enqueue();
    solve();
    printf("%d\n", ans.size()-1);
    return 0;
}