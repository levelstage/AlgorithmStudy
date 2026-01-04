// 2042 구간 합 구하기
// lld 주의! 진짜 깔끔하게 풀었는데 ㄲㅂ

#include <cstdio>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<long long int>> v;

long long int sum(int s, int e)
{
    long long int res = 0;
    while (s <= e)
    {
        int depth = v.size()-1;
        while(!(s+(1<<depth)-1 <= e && s % (1<<depth) == 0)) depth--;
        int idx = s >> depth;
        res += v[depth][idx];
        s += (1<<depth);
    }
    return res;
}

void change(int idx, long long int value)
{
    v[0][idx] = value;
    for(int depth=1; depth<v.size(); depth++)
    {
        idx/=2;
        v[depth][idx] = v[depth-1][idx*2] + v[depth-1][idx*2+1];
    }
    return;
}

vector<long long int> zip(vector<long long int> &origin)
{
    vector<long long int> res;
    for(int i=0; i<origin.size(); i+=2){
        res.push_back(origin[i] + origin[i+1]);
    }
    return res;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    vector<long long int> l1;
    for(int i=0; i<N; i++){
        long long int tmp;
        scanf("%lld", &tmp);
        l1.push_back(tmp);
    }
    int n_bin = 1;
    while(n_bin <= N) n_bin *= 2;
    for(int i=N; i<n_bin; i++) l1.push_back(0);
    v.push_back(l1);
    while(v.back().size() > 1)
    {
        v.push_back(zip(v.back()));
    }
    for(int i=0; i<M+K; i++){
        int a, b;
        long long int c;
        scanf("%d %d %lld", &a, &b, &c);
        if(a == 1){
            change(b-1, c);
        }
        else{
            printf("%lld\n", sum(b-1, c-1));
        }
    }
    return 0;
}