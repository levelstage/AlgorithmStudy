// 1562 계단 수
// 이렇게 고민할 문제가 아니었다... 제미나이랑 말싸움 하느라 2시간 날림ㅋㅋㅋㅋ

#include<cstdio>

using namespace std;

int N;
int dt[4][10][100];
bool vis[4][10][100];

int solve(bool zero, bool nine, int num, int len)
{
    if(num > 9 || num < 0) return 0;
    if(num == 0) zero = 1;
    if(num == 9) nine = 1;
    if(len == 1){
        if(zero && nine) return 1;
        return 0;
    }
    if(!vis[2*zero + nine][num][len]){
        vis[2*zero + nine][num][len] = 1;
        dt[2*zero + nine][num][len] = (solve(zero, nine, num+1, len-1) + solve(zero, nine, num-1, len-1)) % 1000000000;
    }
    return dt[2*zero + nine][num][len];
}

int main()
{
    scanf("%d", &N);
    int res = 0;
    for(int i=1; i<=9; i++){
        res = (res + solve(0,0,i,N)) % 1000000000;
    }
    printf("%d", res);
    return 0;
}