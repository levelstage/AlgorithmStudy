// 1106 호텔


#include <iostream>
#include <queue>

using namespace std;

struct city
{
    int cost, value;
};

city make_city(int cost, int value)
{
    city tmp;
    tmp.cost = cost;
    tmp.value = value;
    return tmp;
}

struct small_cost
{
    bool operator() (city &a, city&b)
    {
        return a.cost > b.cost;
    }
};


priority_queue<city, vector<city>, small_cost> ans;

int C, N;
city top;
vector<city> cities;
int vis[100001];

void input()
{
    cin>>C>>N;
    top.cost = 1;
    for(int i=0; i<N; i++){
        int cost, value;
        cin>>cost>>value;
        cities.push_back(make_city(cost, value));
    }
    return;
}

int solve()
{
    ans.push(make_city(0, 0));
    while(!ans.empty())
    {
        city task = ans.top();
        ans.pop();
        if(task.value >= C) return task.cost;
        for(int i=0; i<N; i++){
            if(task.value + cities[i].value > vis[task.cost+cities[i].cost]){
                vis[task.cost+cities[i].cost] = task.value + cities[i].value;
                ans.push(make_city(task.cost+cities[i].cost, task.value + cities[i].value));
            }
        }
    }
    return 0;
}

int main()
{
    input();
    cout<<solve()<<endl;
    return 0;
}