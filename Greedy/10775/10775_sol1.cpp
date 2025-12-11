// 10775 공항
// 사실 굉장히 쉬운 문제였다?! 경로 압축의 위대함.

#include <stdio.h>
#include <vector>

using namespace std;

int G, P;
vector<int> inp, arr;

void input()
{
    scanf("%d", &G);
    scanf("%d", &P);
    inp.reserve(P);
    arr.reserve(G+1);
    for(int i=0; i<=G; i++) arr.push_back(i);
    for(int i=0; i<P; i++){
        int g;
        scanf("%d", &g);
        inp.push_back(g);
    }
}

int assign(int n)
{
    if(arr[n] == n){
        arr[n] = n-1;
        return n;
    }
    return arr[n] = assign(arr[n]);
}

int main()
{
    int res=0;
    input();
    for(int i=0; i<P; i++){
        if(assign(inp[i]) == 0) break;
        res++;
    }
    printf("%d\n", res);
    return 0;
}