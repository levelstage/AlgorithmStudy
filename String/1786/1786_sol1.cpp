// 1786 찾기
// 문제에서 답을 거의 다 준셈이나 마찬가지인데, 인덱싱하는게 비직관적이라 좀 오래걸렸음.

#include <iostream>
#include <vector>

using namespace std;

char T[1000002], P[1000002];
int K[1000002];
vector<int> ans;

void preprocess()
{
    int i=1, j=0;
    while (P[i+j] != 0)
    {
        int top=i+j;
        if(P[top] == P[j])
        {
            ++j;
            K[top] = j;
        }
        else if(j==0) ++i;
        else{
            j = K[j-1];
            i = top - j;
        }
    }
    
}

void solve()
{
    int i=0, j=0;
    while (T[i+j] != '\0')
    {
        int top = i+j;
        if(T[top] == P[j])
        {
            ++j;
            if(P[j] == '\0'){
                ans.push_back(i+1);
                j = K[j-1];
                i = top - j + 1;
            }
        }
        else if(j==0) ++i;
        else{
            j = K[j-1];
            i = top - j;
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin.getline(T, sizeof(T));
    cin.getline(P, sizeof(P));
    
    preprocess();
    solve();

    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    return 0;
}