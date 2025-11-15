// 12015 가장 긴 증가하는 부분 수열 2
// 우선순위 큐를 사용해서 시간을 줄여 보았다.
// 최악의 경우 n제곱이긴 함. (내림차순으로 정렬된 경우...)
// 역시 안됨

#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[1000000];

struct less_second
{
    bool operator()(pair<int,int> &a, pair<int,int> &b)
    {
        return a.second < b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, less_second> q;

int maxlen(int n)
{
    int res = 1;
    queue<pair<int, int>> tmp;
    while(!q.empty())
    {
        if(q.top().first < n) {
            res = q.top().second + 1;
            break;
        }
        tmp.push(q.top());
        q.pop();

    }
    while(!tmp.empty())
    {
        q.push(tmp.front());
        tmp.pop();
    }
    return res;
}

void input()
{
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        q.push(make_pair(arr[i], maxlen(arr[i])));
    }
    return;
}

int main()
{
    input();
    cout<<q.top().second<<endl;
    return 0;
}

