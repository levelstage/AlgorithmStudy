// 12015 가장 긴 증가하는 부분 수열 2
// 걍 n log n <- 신임
#include<iostream>
using namespace std;

int len=0;

int N;
int arr[1000000], last[1000001];

int getlb(int s, int e, int num)
{
    int i = (s+e) / 2;
    if(last[i] == num) return i;
    if(last[i] < num){
        if(last[i+1] > num) return i+1;
        return getlb(i+1, e, num);
    }
    return getlb(s, i-1, num);
}

void update(int i, int num)
{
    if(num > last[len]){
        len++;
        last[len] = num;
    }
    else if(num < last[1]) last[1] = num;
    else last[getlb(1,len,num)] = num;
    return;
}

void input()
{
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        update(i, arr[i]);
    }
    return;
}

int main()
{
    input();
    cout<<len<<endl;
}