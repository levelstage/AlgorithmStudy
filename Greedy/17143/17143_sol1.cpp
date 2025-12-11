// 17143 낚시왕
// 구현이 좀 까다로운데 문제 자체는 쉬움.

#include <cstdio>
#include <vector>

using namespace std;

struct same
{
    bool alive;
    int r, c, s, d, z;
};

int R, C, M, map[101][101];
vector<same> sames;

void input()
{
    scanf("%d %d %d", &R, &C, &M);
    sames.resize(M+1);
    for(int i=1; i<=M; i++){
        same tmp;
        scanf("%d %d %d %d %d", &tmp.r, &tmp.c, &tmp.s, &tmp.d, &tmp.z);
        tmp.alive = 1;
        sames[i] = tmp;
        map[tmp.r][tmp.c] = i;
    }
    return;
}

void move(same &a)
{
    if(!a.alive) return;
    map[a.r][a.c] = 0;
    int nr = a.r, nc = a.c, nd = a.d;
    if(a.d <= 2){
        int ns = a.s % (2*R - 2);
        if(a.d == 1){
            nr -= ns;
        }
        else{
            nr += ns;
        }
        while(nr <= 0 || nr > R)
        {
            if(nr <= 0) {
                nr = 2 - nr;
                nd = 2;
            }
            if(nr > R){
                nr = 2*R - nr;
                nd = 1;
            }
        }
    }
    else{
        int ns = a.s % (2*C - 2);
        if(a.d == 4){
            nc -= ns;
        }
        else{
            nc += ns;
        }
        while(nc <= 0 || nc > C)
        {
            if(nc <= 0) {
                nc = 2 - nc;
                nd = 3;
            }
            if(nc > C){
                nc = 2*C - nc;
                nd = 4;
            }
        }
    }
    a.c = nc; a.r = nr; a.d = nd;
    return;
}

int solve()
{
    int res=0;
    for(int x=1; x<=C; x++)
    {
        for(int y=1; y<=R; y++){
            if(map[y][x] > 0){
                res += sames[map[y][x]].z;
                sames[map[y][x]].alive = 0;
                map[y][x] = 0;
                break;
            }
        }
        for(int i=1; i<=M; i++) move(sames[i]);
        for(int i=1; i<=M; i++){
            if(!sames[i].alive) continue;
            if(map[sames[i].r][sames[i].c] > 0){
                if(sames[map[sames[i].r][sames[i].c]].z > sames[i].z){
                    sames[i].alive = 0;
                    continue;
                }
                else{
                    sames[map[sames[i].r][sames[i].c]].alive = 0;
                }
            }
            map[sames[i].r][sames[i].c] = i;
        }
        
    }
    return res;
}

int main()
{
    input();
    printf("%d", solve());
    return 0;
}