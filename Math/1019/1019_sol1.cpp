// 1019 책 페이지
// main 함수의 예외 처리 로직이 핵심.

#include <cstdio>

long long int num[10];
int N;

int pow10(int n)
{
    // n에 1 이하의 값이 들어오면 1을 return하도록 설정
    int res=1;
    for(int i=1; i<=n; i++) res*=10;
    return res;
}

void count(int d, int s, int e)
{
    for(int i=0; i<=9; i++){
        // 첫 번째 자리 수만 s~e로 제한되고 나머지는 0~9로 무제한이다.
        // 따라서 첫 번째 수에 오는 경우 pow(자릿수-1)을 기본으로 얻게 되며,
        // 모든 수는 공통으로 첫번째가 아닌 자리에 올 때 첫번째 수의 경우의 수 * pow(자릿수-2)회 등장하게 된다.
        if(i < s || i > e) num[i] += (long long)(e-s+1) * (d-1) * pow10(d-2);
        else num[i] += (long long)(e-s+1) * (d-1) * pow10(d-2) + pow10(d-1);
    }
}

int main()
{
    scanf("%d", &N);
    int div = 1, dig=1;
    // 1, 19 등은 001, 019로 처리되지 않으므로 따로 처리해주어야 한다.
    while ((long long)div * 10 <= N)
    {
        count(dig++, 1, 9);
        div*=10;
    }
    // 따라서 첫 번째 루프만큼은 0이 아닌 1부터 시작해야함.
    if(N/div > 1) count(dig, 1, N/div-1);
    num[N/div] += N%div+1;
    N%=div;
    div/=10;
    dig--;
    // 나머지는 규칙에 의해 처리한다.
    while (dig >= 1)
    {
        if(N/div > 0)count(dig, 0, N/div-1);
        num[N/div] += N%div+1;
        N%=div;
        div/=10;
        dig--;
    }
    for(int i=0; i<=9; i++) printf("%lld ", num[i]);
    printf("\n");
    return 0;
}