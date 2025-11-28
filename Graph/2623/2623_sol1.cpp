// 2623 음악 프로그램
// 결국 뭐였던 걸까? Set 활용이 중점인가?

#include <cstdio>
#include <set>
#include <queue>

using namespace std;

int N, M, depth[1001];
bool vis[1001];
set<int> s[1001];

struct lower_first
{
    bool operator() (pair<int, int> &a, pair<int, int> &b){
        return a.first > b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, lower_first> out;

int max(int a, int b) {return a>b ? a:b;}

void input()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        int k;
        scanf("%d", &k);
        vector<int> temp;
        temp.assign(k,0);
        for(int j=0; j<k; j++){
            scanf("%d", &temp[j]);
            for(int l=0; l<j; l++) s[temp[j]].insert(temp[l]);
        }
    }
    return;
}

int dfs(int num)
{
    if(vis[num] == 1) return 1001;
    if(depth[num] == 0){
        for(set<int>::iterator iter = s[num].begin(); iter != s[num].end(); iter++){
            vis[num] = 1;
            depth[num] = max(depth[num], dfs(*iter));
            vis[num] = 0;
        }
        depth[num]++;
    }
    return depth[num];
}

bool enqueue_output()
{
    for(int i=1; i<=N; i++){
        int d = dfs(i);
        if(d >= 1001) return 0;
        out.push(make_pair(d, i));
    }
    return 1;
}

void dequeue_output()
{
    while(!out.empty())
    {
        printf("%d\n", out.top().second);
        out.pop();
    }
    return;
}

int main()
{
    input();
    if(enqueue_output()){
        dequeue_output();
    }
    else{
        printf("0");
    }
    return 0;
}