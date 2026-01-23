// 16287 Parcel
// 아무거나 2개씩 묶어서 더하는 전략. 생각해보니 이분탐색도 필요없음.

#include <cstdio>
#include <vector>

using namespace std;

vector<int> left, right, set;

int W, N;

void fill_pairs()
{
    for(int i=0; i<N; ++i)
    {
        for(int j=i+1; j<N; ++j)
        {
            int sum = set[i]+set[j];
            if(sum >= W) continue;
            if(left[sum] == -1 || left[sum] > j) left[sum] = j;
            if(right[sum] < i) right[sum] = i; 
        }
    }
}

void solve()
{
    for(int i=2; i<=W-2; ++i)
    {
        if(left[i] > -1 && right[W-i] > left[i])
        {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
    return;
}

int main()
{
    scanf("%d %d", &W, &N);
    set.resize(N);
    left.assign(W, -1);
    right.assign(W, -1);
    for(int i=0; i<N; ++i)
    {
        scanf("%d", &set[i]);
    }
    fill_pairs();
    solve();
    return 0;
}