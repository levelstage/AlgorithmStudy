// 27172 수 나누기 게임
// 에라토스테네스 형님 감사합니다.

#include<cstdio>0
#include<vector>

using namespace std;

int N, score[1000001];
bool alive[1000001];
vector<int> order;

void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int x;
        scanf("%d", &x);
        order.push_back(x);
        alive[x] = 1;
    }
    return;
}

void solve()
{
    for(int i=1; i<=1000000; i++){
        if(!alive[i]) continue;
        for(int j=i*2; j<=1000000; j+=i){
            if(alive[j]){
                score[j]--;
                score[i]++;
            }
        }
    }
    return;
}

void output()
{
    for(int i=0; i<order.size(); i++)
    {
        printf("%d ", score[order[i]]);
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