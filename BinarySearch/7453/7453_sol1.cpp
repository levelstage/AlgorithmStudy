// 7453 합이 0인 네 정수
// 풀이는 맞았는데, 마지막에 %lld 아니고 %d로 출력하는 바람에 ㅋㅋ;;

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> v[4], combined[2];

void input()
{
    scanf("%d", &N);
    for(int i=0; i<4; i++) v[i].assign(N, 0);
    for(int i=0; i<N; i++)
    {
        scanf("%d %d %d %d", &v[0][i], &v[1][i], &v[2][i], &v[3][i]);
    }
    return;
}

void combine_array(vector<int> &res, vector<int> &a, vector<int> &b)
{
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            res.push_back(a[i]+b[j]);
        }
    }
    sort(res.begin(), res.end());
    return;
}

int left_bound(vector<int> &where, int value, int s, int e)
{
    if(s > e) return -1;
    int i = (s+e) / 2;
    if(where[i] == value){
        if(i == 0) return 0;
        if(where[i-1] != value) return i;
    }
    if(where[i] < value) return left_bound(where, value, i+1, e);
    return left_bound(where, value, s, i-1);
}

int right_bound(vector<int> &where, int value, int s, int e)
{
    if(s > e) return -1;
    int i = (s+e) / 2;
    if(where[i] == value){
        if(i == where.size()-1) return where.size()-1;
        if(where[i+1] != value) return i;
    }
    if(where[i] > value) return right_bound(where, value, s, i-1);
    return right_bound(where, value, i+1, e);
}

long long int solve()
{
    long long int res = 0;
    combine_array(combined[0], v[0], v[1]);
    combine_array(combined[1], v[2], v[3]);
    for(int i=0; i<combined[0].size(); i++){
        int l, r;
        l = left_bound(combined[1], -combined[0][i], 0, combined[1].size() - 1);
        r = right_bound(combined[1], -combined[0][i], 0, combined[1].size() - 1);
        if(l == -1 || r == -1) continue;
        res += (r - l + 1);
    }
    return res;
}

int main()
{
    input();
    printf("%lld\n", solve());
    return 0;
}