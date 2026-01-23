// 16287 Parcel
// 4, 2+2, 3+1로 나눠서 생각해보는 전략. 하지만 이것도 시간초과.

#include <cstdio>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> homo, diff;
vector<int> set;

int W, N;

void fill_pairs()
{
    for(int i=0; i<N; ++i)
    {
        for(int j=i+1; j<N; ++j)
        {
            if(set[i] + set[j] >= W) continue;
            if(set[i] < W/4 && set[j] < W/4) homo[set[i]+set[j]].push_back(make_pair(i, j));
            else if(set[i] > W/4 && set[j] > W/4) homo[set[i]+set[j]].push_back(make_pair(i, j));
            else if(set[i] == W/4 && set[j] == W/4) homo[set[i]+set[j]].push_back(make_pair(i, j));
            else diff[set[i]+set[j]].push_back(make_pair(i, j));
            
        }
    }
}

void solve()
{
    for(int i=2; i<W/2; ++i)
    {
        if(!homo[i].empty() && !homo[W-i].empty()){
            printf("YES\n");
            return;
        }
    }
    for(int i=2; i<=W-2; ++i){
        for(int j=0; j<homo[i].size(); ++j)
        {
            for(int k=0; k<diff[W-i].size(); ++k)
            {
                if(homo[i][j].first == diff[W-i][k].first || homo[i][j].first == diff[W-i][k].second || homo[i][j].second == diff[W-i][k].first || homo[i][j].second == diff[W-i][k].second) continue;
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
    return;
}

int main()
{
    int same_cnt=0;
    scanf("%d %d", &W, &N);
    set.resize(N);
    homo.resize(W);
    diff.resize(W);
    for(int i=0; i<N; ++i)
    {
        scanf("%d", &set[i]);
        if(W%4 == 0 && set[i] == W/4)++same_cnt;
    }
    if(same_cnt >= 4){
        printf("YES\n");
        return 0;
    }
    fill_pairs();
    solve();
    return 0;
}