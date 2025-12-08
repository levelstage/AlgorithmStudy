// 16724 피리 부는 사나이
// 진짜 개빨리풀었네

#include <cstdio>
#include <vector>

using namespace std;

int N, M; 
char map[1001][1001];
int group[1001][1001];

void input()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        scanf("%s", map[i]);
    }
    return;
}

int surf(int g, int x, int y)
{
    if(group[y][x] == 0){
        group[y][x] = g;
        switch (map[y][x])
        {
        case 'U':
            group[y][x] = surf(g, x, y-1);
            break;
        
        case 'D':
            group[y][x] = surf(g, x, y+1);
            break;
        case 'L':
            group[y][x] = surf(g, x-1, y);
            break;
        case 'R':
            group[y][x] = surf(g, x+1, y);
            break;
        }
    }
    return group[y][x];
}

int solve()
{
    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(surf(ans+1, j, i) == ans+1) ans++;
        }
    }
    return ans;
}

int main()
{
    input();
    printf("%d", solve());
    return 0;
}