// 1644 소수의 연속합

#include <cstdio>
#include <queue>

using namespace std;

int N;
bool table[4000001];

int next_prime(int n)
{
    if(n%2 == 1) n+=2;
    else n++;
    int i;
    for(i=n; i<=4000000; i++){
        if(!table[i]) break;
    }
    return i;
}

void fill_table()
{
    table[1] = 1;
    for(int j=4; j<=4000000; j+=2) table[j] = 1;
    for(int i=3; i<=4000000; i+=2){
        if(table[i]) continue;
        for(int j=i*3; j<=4000000; j+=i) table[j] = 1;
    }
    return;
}

int solve()
{
    queue<int> q;
    int sum=0, res=0;
    for(int i=2; i<=N; i=next_prime(i)){
        while (sum + i > N)
        {
            sum -= q.front();
            q.pop();
        }
        sum+=i;
        q.push(i);
        if(sum == N) res++; 
    }
    return res;
}

int main()
{
    scanf("%d", &N);
    fill_table();
    printf("%d", solve());
    return 0;
}