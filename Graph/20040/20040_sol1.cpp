// 20040 사이클 게임
// Union-Find도 여러모로 익숙해진듯

#include<cstdio>

using namespace std;

int N, M, root[500000];

int search(int idx)
{
    if(root[idx] == idx) return idx;
    return root[idx] = search(root[idx]);
}

int main()
{
    int ans = 0;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) root[i] = i;
    for(int j=1; j<=M; j++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(ans > 0) continue;
        int ar = search(a), br = search(b);
        if(ar == br) ans = j;
        else if(ar < br){
            root[br] = ar;
        }
        else{
            root[ar] = br;
        }
    }
    printf("%d\n", ans);
    return 0;
}