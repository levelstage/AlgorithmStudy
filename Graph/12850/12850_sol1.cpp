// 12850 본대 산책
// 행렬 거듭제곱으로 푸는 문제였구나... 풀이가 진짜 개신기하네. 근데 풀었잖아. 어쩌라고.

#include<cstdio>
#define NUM 1000000007

using namespace std;

int D;
long long int dt[8][8][50];
bool vis[8][8][50], path[8][8];

void init()
{
    path[0][1] = path[1][0] = 1;
    path[0][2] = path[2][0] = 1;
    path[1][2] = path[2][1] = 1;
    path[1][3] = path[3][1] = 1;
    path[2][3] = path[3][2] = 1;
    path[2][4] = path[4][2] = 1;
    path[3][4] = path[4][3] = 1;
    path[3][5] = path[5][3] = 1;
    path[4][5] = path[5][4] = 1;
    path[4][7] = path[7][4] = 1;
    path[5][6] = path[6][5] = 1;
    path[6][7] = path[7][6] = 1;
    return;
}

long long solve(int depth, int s, int e, int d)
{
    if(d == 1){
        return path[s][e];
    }
    if(s>e){
        int tmp=s;
        s = e;
        e = tmp;
    }
    if(!vis[s][e][depth]){
        vis[s][e][depth] = 1;
        for(int i=0; i<8; i++){
            long long int t1 = solve(depth+1, s, i, d/2) % NUM, t2 = 0;
            if(d % 2 == 0){
                t2 = solve(depth+1, i, e, d/2) % NUM;
            }
            else{
                for(int j=0; j<8; j++){
                    t2 = (t2 + solve(depth+1, i, j, d/2) * path[j][e]) % NUM; 
                }
            }
            dt[s][e][depth] = (dt[s][e][depth] + ((t1 * t2) % NUM)) % NUM;
        }
    }
    return dt[s][e][depth];
}

int main()
{
    scanf("%d", &D);
    init();
    printf("%lld", solve(0,0,0,D));
    return 0;
}