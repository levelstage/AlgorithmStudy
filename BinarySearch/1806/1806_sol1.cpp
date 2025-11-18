// 1806 부분합
// 이제 진짜 이런 문제는 너무 쉬워짐. 그 긴거 & 놀이공원이 진짜 GOAT.

#include<iostream>
#include<vector>
using namespace std;

int N, S;
vector<int> arr;

int getbest(int length)
{
    if(length==0) return 0;
    int res = 0, sum = 0;
    for(int j = 0; j<length; j++){
        sum+=arr[j];
    }
    res = sum;
    for(int i=1; i<=N-length; i++){
        sum += (arr[i+length-1] - arr[i-1]);
        res = sum > res ? sum:res;
    }
    return res;
}

int search(int s, int e)
{
    int i=(s+e)/2;
    int now  = getbest(i);
    if(now >= S){
        int left = getbest(i-1);
        if(left < S) return i;
        return search(s, i-1);
    }
    if(i == N) return 0;
    return search(i+1, e);
}

void input()
{
    cin>>N>>S;
    arr.reserve(N);
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
}

int main()
{
    input();
    cout<<search(1, N)<<endl;
    return 0;
}
