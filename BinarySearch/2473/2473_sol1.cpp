// 2473 세 용액
// 그냥 용액 좀 변형시키면 바로 풀림 ㅇㅇ;

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int N, zeros;
long long int minv = 4000000000;
vector<long long int> neg, pos, ans;

void input()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp==0) zeros++;
        if(tmp>0) pos.push_back(tmp);
        if(tmp<0) neg.push_back(-tmp);
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    return;
}

int complement(vector<long long int> &v, int x, int s, int e)
{
    int i = (s+e)/2;
    if(v[i] == x) return v[i];
    if(v[i] < x){
        if(i == v.size() - 1) return v[i];
        if(v[i+1] == x) return v[i+1];
        if(v[i+1] > x) return abs(v[i]-x) < abs(v[i+1]-x) ? v[i] : v[i+1];
        return complement(v, x, i+1, e);
    }
    if(i==0) return v[i];
    if(v[i-1] == x) return v[i-1];
    if(v[i-1] < x) return abs(v[i]-x) < abs(v[i-1]-x) ? v[i] : v[i-1];
    return complement(v, x, s, i-1);
}

int sign(int num, int positive)
{
    return positive ? num : -num;
}

void search3(vector<long long int> &get3, bool positive)
{
    vector<long long int> tmp;
    tmp.assign(3, 0);
    if(get3.size() + zeros < 3) return;
    for(int i=0; i<3-zeros; i++) tmp[i] = sign(get3[i], positive);
    if(abs(tmp[0]+tmp[1]+tmp[2]) < minv){
        minv = abs(tmp[0]+tmp[1]+tmp[2]);
        ans = tmp;
    }
    return;
}

void search21(vector<long long int> &get2, vector<long long int> &get1, bool positive)
{
    if(get2.size() + zeros < 2 || get1.empty()) return;
    vector<long long int> tmp;
    tmp.assign(3, 0);
    for(int i=0; i<zeros; i++) get2.push_back(0);
    for(int i=0; i<get2.size()-1; i++){
        tmp[0] = sign(get2[i], positive);
        for(int j=i+1; j<get2.size(); j++){
            tmp[1] = sign(get2[j], positive);
            tmp[2] = sign(complement(get1, get2[i] + get2[j], 0, get1.size()-1), !positive);
            if(abs(tmp[0]+tmp[1]+tmp[2]) < minv){
                minv = abs(tmp[0]+tmp[1]+tmp[2]);
                ans = tmp;
            }
        }
    }
    for(int i=0; i<zeros; i++) get2.pop_back();
    return;
}

int main()
{
    input();
    if(zeros > 2){
        cout<<"0 0 0"<<endl;
        return 0;
    }
    ans.assign(3, 0);
    search3(neg, 0);
    search3(pos, 1);
    search21(neg, pos, 0);
    search21(pos, neg, 1);
    sort(ans.begin(), ans.end());
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    return 0;
}