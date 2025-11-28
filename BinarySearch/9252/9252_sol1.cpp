// 9252 LCS 2
// 그 긴거(가장 긴 증가하는 부분수열)를 응용해서 해결.

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string s1, s2, ans[1001];
vector<int> idxs[26], last;

void input()
{
    cin>>s1>>s2;
    for(int i=0; i<s2.length(); i++)
    {
        idxs[s2[i] - 'A'].push_back(i+1);
    }
    return;
}

int boundary(vector<int> &v, int x, int s, int e)
{
    if(e<s) return -1;
    int i = (s+e)/2;
    if(i == v.size()) return -1;
    if(v[i] > x){
        if(i==0) return 0;
        if(v[i-1] <= x) return i;
        return boundary(v, x, s, i-1);
    }
    return boundary(v, x, i+1, e);
}

int search()
{
    int len=0;
    for(int i=0; i<s1.length(); i++){
        for(int j=len; j>=0; j--){
            int x = boundary(idxs[s1[i] - 'A'], last[j], 0, idxs[s1[i] - 'A'].size());
            if(x == -1) continue;
            if(last[j+1] > idxs[s1[i]-'A'][x] || last[j+1] == 0){
                last[j+1] = idxs[s1[i]-'A'][x];
                ans[j+1] = ans[j] + s1[i];
            }
        }
        if(last[len+1] != 0) len++;
    }
    return len;
}

int main()
{
    input();
    last.assign(s1.length()+1, 0);
    int length = search(); 
    cout<<length<<endl;
    if(length>0)cout<<ans[length]<<endl;
    return 0;
}