// 6603 로또
// 좀 쉬운편이었음.
#include <iostream>
#define N 6
using namespace std;
int arr[12];
bool vis[12];

void print(int k)
{
    for(int i=0; i<k; i++){
        if(vis[i]){
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
}

void dfs(int k, int depth, int count)
{
    if(count == N)
    {
        print(k);
        return;
    }
    if(k - depth == N - count){
        for(int i=depth; i<k; i++)vis[i] = 1;
        print(k);
        for(int i=depth; i<k; i++)vis[i] = 0;
        return;
    }
    
    vis[depth] = 1;
    dfs(k, depth+1, count+1);
    vis[depth] = 0;
    dfs(k, depth+1, count);
}

int main()
{
    int k = 1;
    while (k != 0)
    {
        cin>>k;
        for(int i=0; i<k; i++){
            cin>>arr[i];
        }
        if(k!=0){
            dfs(k, 0, 0);
            cout<<endl;
        }
    }
    
}