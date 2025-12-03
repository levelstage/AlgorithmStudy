// 2143 두 배열의 합
// long long 조심!!

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int T, n, m;
vector<int> A, B, dt;

void input()
{
    scanf("%d", &T);
    scanf("%d", &n);
    A.reserve(n);
    for(int i=0; i<n; i++){
        int tmp;
        scanf("%d", &tmp);
        A.push_back(tmp);
    }
    
    scanf("%d", &m);
    B.reserve(m);
    for(int i=0; i<m; i++){
        int tmp;
        scanf("%d", &tmp);
        B.push_back(tmp);
    }
    return;
}

void fill_dt(vector<int> &v)
{
    for(int i=0; i<v.size(); i++){
        int sum=0;
        for(int j=0; j<=i; j++){
            sum+=v[j];
        }
        dt.push_back(sum);
        for(int j=i+1; j<v.size(); j++){
            sum-=v[j-i-1];
            sum+=v[j];
            dt.push_back(sum);
        }
    }
    return;
}

int ub(int v, int s, int e)
{
    int i=(s+e)/2;
    if(s>e) return -1;
    if(dt[i] == v){
        if(i == dt.size()-1) return i;
        if(dt[i+1] > v) return i;
        return ub(v, i+1, e);
    }
    if(dt[i] > v) return ub(v, s, i-1);
    return ub(v, i+1, e);
}

int lb(int v, int s, int e)
{
    if(s>e) return -1;
    int i=(s+e)/2;
    if(dt[i] == v){
        if(i == 0) return i;
        if(dt[i-1] < v) return i;
        return lb(v, s, i-1);
    }
    if(dt[i] > v) return lb(v, s, i-1);
    return lb(v, i+1, e);
}

long long int solve(vector<int> &v)
{
    long long int ans = 0;
     for(int i=0; i<v.size(); i++){
        int sum=0, s, e;
        for(int j=0; j<=i; j++){
            sum+=v[j];
        }
        s = lb(T-sum, 0, dt.size()-1);
        e = ub(T-sum, 0, dt.size()-1);
        if(s!=-1) ans += (e-s+1);
        for(int j=i+1; j<v.size(); j++){
            sum-=v[j-i-1];
            sum+=v[j];
            s = lb(T-sum, 0, dt.size()-1);
            if(s == -1) continue;
            e = ub(T-sum, 0, dt.size()-1);
            ans += (e-s+1);
        }
        
    }
    return ans;
}

int main()
{
    input();
    if(n>m){
        fill_dt(B);
        sort(dt.begin(), dt.end());
        printf("%lld", solve(A));
    }
    else{
        fill_dt(A);
        sort(dt.begin(), dt.end());
        printf("%lld", solve(B));
    }
    return 0;
}