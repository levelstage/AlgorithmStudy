// 9527 1의 개수 세기
// 어렵진 않았음.

#include<cstdio>

using namespace std;

long long int A, B;

long long int count(long long int x)
{
    if(x==0) return 0;
    int len=0;
    while(x > 0){
        x>>=1;
        len++;
    }
    return ((long long int)1<<(len-1)) * len;
}

long long int solve(long long int n, int c)
{
    if(n == 0) return 0;
    long long int x = 1;
    while((x << 1) < n){
        x<<=1;
    }
    return solve(n-x, c+1) + count(x-1) + c*x;
}

int main()
{
    scanf("%lld %lld", &A, &B);
    printf("%lld", (solve(B+1, 0) - solve(A, 0)));
    return 0;
}