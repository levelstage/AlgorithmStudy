// 11689 GCD(n, k) = 1
// AC 나오긴 함... 잠깐 뭔가 이상한데?

#include<cstdio>
#include<cmath>

long long int N;

bool arr[1000002];

void solve()
{
    // sqrt(N)보다 큰 유일한 소인수가 존재한다면 그걸 처리하기 위해.
    long long int last = N;
    // 유일한 짝수 2 처리
    for(int j=4; j<sqrt(N+1); j+=2) arr[j] = 1;
    if(N%2 == 0){
        while(last % 2 == 0) last /= 2;
        N /= 2;
    }
    
    // 나머지는 2씩 스텝하면서 처리 가능.

    // <이상한 부분> N이 점점 줄어들지만, 놀랍게도 문제 없음. (하한선이 존재한다.)
    // i와 i를 곱할 때 나타나는 오버플로우에 주의!
    for(int i=3; i<sqrt(N)+1; i+=2){
        if(arr[i]) continue;
        for(long long int j=(long long int)i*i; j<sqrt(N+1); j+=i) arr[j] = 1;
        if(N % i != 0) continue;
        while(last % i == 0) last /= i;
        N /= i;
        N*=(i-1);
    }
    if(last > 1){
        N/=last;
        N*=(last-1);
    }
    return;
}

int main()
{
    scanf("%lld", &N);
    solve();
    printf("%lld\n", N);
    return 0;
}