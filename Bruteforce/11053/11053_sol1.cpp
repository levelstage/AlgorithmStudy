// 11053 가장 긴 증가하는 부분 수열 1
// N이 매우 작기 때문에 브루트 포스 가능.

#include<iostream>

using namespace std;

int N;
int arr[1000], dt[1000];
void input()
{
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    return;
}
int solve()
{
    int res = 1; 
    for(int i=N-1; i>=0; i--){
        dt[i] = 1;
        for(int j = i+1; j<N; j++){
            if(arr[i] < arr[j]) {
                if(dt[j] + 1 > dt[i]) dt[i] = dt[j] + 1;
            }
        }
        if(dt[i] > res) res = dt[i];
    }
    return res;
}

int main()
{
    input();
    cout<<solve()<<endl;
}
