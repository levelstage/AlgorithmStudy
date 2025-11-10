// 14888 연산자 끼워넣기
// _min, _max 제대로 설정 안해서 한번 틀림 ㅡㅡ;

// +15658 연산자 끼워넣기(2)도 똑같은 코드로 풀림.

#include <iostream>

using namespace std;

int _min = 1000000001, _max = -1000000001, N;
int seq[11], op[4];

void input()
{
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>seq[i];
    }
    for(int i=0; i<4; i++){
        cin>>op[i];
    }
    return;
}

void dfs(int depth, int num)
{
    if(depth == N){
        if(num > _max) _max = num;
        if(num < _min) _min = num;
        return;
    }
    if(op[0] > 0){
        op[0]--;
        dfs(depth+1, num+seq[depth]);
        op[0]++;
    }
    if(op[1] > 0){
        op[1]--;
        dfs(depth+1, num-seq[depth]);
        op[1]++;
    }
    if(op[2] > 0){
        op[2]--;
        dfs(depth+1, num*seq[depth]);
        op[2]++;
    }
    if(op[3] > 0){
        op[3]--;
        dfs(depth+1, num/seq[depth]);
        op[3]++;
    }
    return;
}

int main()
{
    input();
    dfs(1, seq[0]);
    cout<<_max<<endl;
    cout<<_min<<endl;
}