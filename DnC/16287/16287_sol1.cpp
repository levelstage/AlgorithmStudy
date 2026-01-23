// 16287 Parcel
// 아무거나 2개씩 묶어서 더하는 전략. 하지만 시간초과로 실패

#include <cstdio>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> pairs;
vector<int> set;

int W, N;

void fill_pairs()
{
    for(int i=0; i<N; ++i)
    {
        for(int j=i+1; j<N; ++j)
        {
            if(set[i] + set[j] >= W) continue;
            pairs[set[i] + set[j]].push_back(make_pair(i, j));
        }
    }
}

void solve()
{
    for(int i=2; i<=W/2; ++i)
    {
        for(int j=0; j<pairs[i].size(); ++j)
        {
            for(int k=0; k<pairs[W-i].size(); ++k)
            {
                if(pairs[i][j].first == pairs[W-i][k].first || pairs[i][j].first == pairs[W-i][k].second || pairs[i][j].second == pairs[W-i][k].first || pairs[i][j].second == pairs[W-i][k].second) continue;
                printf("YES");
                return;
            }
        }
    }
    printf("NO\n");
    return;
}

int main()
{
    scanf("%d %d", &W, &N);
    set.resize(N);
    pairs.resize(W);
    for(int i=0; i<N; ++i)
    {
        scanf("%d", &set[i]);
    }
    fill_pairs();
    solve();
    return 0;
}