// 1562 계단 수
// N < 19에서만 제대로 동작하는 바보 코드임.

#include <cstdio>

using namespace std;

int N, outside[9][100], inside[10][100];
bool vis_o[9][100], vis_i[10][100];

int fill_outside(int num, int len)
{
    if(num >= 9 || num <= 0) return 0;
    if(!vis_o[num][len]){
        vis_o[num][len] = 1;
        if(9 - num > len) outside[num][len] = 0;
        else outside[num][len] = (fill_outside(num-1, len-1) + fill_outside(num+1, len-1)) % 1000000000;
    }
    return outside[num][len];
}

int fill_inside(int num, int len)
{
    if(num > 9 || num < 0) return 0;
    if(!vis_i[num][len]){
        vis_i[num][len] = 1;
        if(9 - num > len) inside[num][len] = 0;
        else inside[num][len] = (fill_inside(num-1, len-1) + fill_inside(num+1, len-1)) % 1000000000;
    }
    return inside[num][len];
}

int solve()
{
    int tot = 0;
    for(int i=0; i<N-9; i++){
        for(int j=i+9; j<N; j++){
            long long int left=0, mid=0, right=0;
            if(i>0){
                for(int k=1; k<=8; k++){
                    left = (left + fill_outside(k, i)) % 1000000000;
                }
            }
            else left = 1;
            mid = fill_inside(1, j-i-1);
            if(j < N-1){
                for(int k=1; k<=8; k++){
                    right = (right + fill_outside(k, N-1 - j)) % 1000000000;
                }
            }
            else right = 1;
            //printf("%d %d %lld %lld %lld\n", i, j, left, mid, right);
            left = (left * mid) % 1000000000;
            left = (left * right) % 1000000000;
            if(i != 0) left = (left * 2) % 1000000000;
            tot = (tot + left) % 1000000000;
        }   
    }
    return tot;
}

int main()
{
    scanf("%d", &N);
    vis_i[9][1] = 1; inside[9][1] = 0;
    vis_i[8][1] = 1; inside[8][1] = 1;
    vis_o[8][1] = 1; outside[8][1] = 1;
    printf("%d", solve());
}