// 2239 스도쿠
// 설마 이게 최선인가 했는데 진짜 최선이었음;;
#include<iostream>

using namespace std;

int ans[9][9], rowv[9], colv[9], squv[3][3];

bool dfs(int x, int y)
{
    if(y == 9) return 1;
    if(ans[y][x] != 0) return dfs((x+1) % 9, y + (x+1)/9);
    for(int i=1; i<=9; i++){
        if((rowv[y]>>i) % 2 == 1) continue;
        if((colv[x]>>i) % 2 == 1) continue;
        if((squv[y/3][x/3]>>i) % 2 == 1) continue;
        rowv[y] += 1<<i;
        colv[x] += 1<<i;
        squv[y/3][x/3] += 1<<i;
        ans[y][x] = i;
        if(dfs((x+1) % 9, y + (x+1)/9)) return 1;
        rowv[y] -= 1<<i;
        colv[x] -= 1<<i;
        squv[y/3][x/3] -= 1<<i;
        ans[y][x] = 0;
    }
    return 0;
}

void input()
{
    for(int i=0; i<9; i++){
        int tmp;
        cin>>tmp;
        for(int j=8; j>=0 && tmp>0; j--){
            int n = tmp%10;
            tmp/=10;
            if(n == 0) continue;
            ans[i][j] = n;
            rowv[i] += 1<<n;
            colv[j] += 1<<n;
            squv[i/3][j/3] += 1<<n;
        }
    }
    return;
}

void print()
{
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return;
}

int main()
{
    input();
    dfs(0,0);
    print();
    return 0;
}