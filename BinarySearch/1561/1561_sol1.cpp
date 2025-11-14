// 1561 놀이공원
// 음음 역시 난 틀리지 않았어.

#include<iostream>

using namespace std;

long long int N; 
int M, att[10000];

void input()
{
    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>att[i];
    }
}

long long int getoffed(long long int t)
{
    if(t<0) return 0;
    long long int sum = 0;
    for(int i=0; i<M; i++){
        sum+=(t/att[i]+1);
    }
    return sum;
}

long long int toe(long long int s, long long int e)
{
    long long int t = (s+e)/2, p = getoffed(t);
    if(p >= N){
        if(t == 0) return 0;
        else if(getoffed(t-1) < N) return t;
        return toe(s, t-1);
    }
    return toe(t+1, e); 
}

int findlast(long long int t)
{
    int delta = N - getoffed(t-1), res=0;
    for(int i=0; i<M; i++){
        if(t % att[i] == 0){
            delta--;
            res = i+1;
        }
        if(delta == 0) break;
    }
    return res;
}

int main()
{
    input();
    cout<<findlast(toe(0,N/M * 30))<<endl;
}