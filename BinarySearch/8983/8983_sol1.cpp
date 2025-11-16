// 8983 사냥꾼
// 역시 이진탐색.

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int M, N, L, guns[100000];

int min(int a, int b){return a<b ? a:b;}

int getdx(int s, int e, int x)
{
    int i = (s+e) / 2;
    if(guns[i] == x)return 0;
    if(guns[i] > x){
        if(i == 0) return abs(x-guns[i]);
        if(guns[i-1] <= x) return min(abs(x-guns[i]), abs(x-guns[i-1]));
        return getdx(s, i-1, x);
    }
    if(i == M-1) return abs(x-guns[i]);
    if(guns[i+1] >= x) return min(abs(x-guns[i]), abs(x-guns[i+1]));
    return getdx(i+1, e, x);
}

bool accessible(int x, int y)
{
    int dist = getdx(0, M-1, x) + y;
    return dist <= L;
}

int main()
{
    int res = 0;
    cin>>M>>N>>L;
    for(int i=0; i<M; i++) cin>>guns[i];
    sort(guns, guns+M);
    for(int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        res += accessible(x,y);
    }
    cout<<res<<endl;
}