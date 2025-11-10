// 14889 스타트와 링크
// 그냥 아무렇게나 푼 풀이 (느림)
#include <iostream>
#include <list>

using namespace std;

int N, arr[20][20] = {0};

void input()
{
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }
}

int min(int a, int b)
{
    return a<b ? a:b;    
}

int search(int depth, list<int> team1, list<int> team2)
{
    if(team1.size() > (N/2) || team2.size() > (N/2)) return 100000;
    if(depth == N){
        int sum1 = 0, sum2 = 0;
        for(list<int>::iterator i1=team1.begin(); i1 != team1.end(); i1++){
            for(list<int>::iterator i2=team1.begin(); i2 != i1; i2++){
                sum1 += (arr[*i1][*i2] + arr[*i2][*i1]);
            }
        }
        for(list<int>::iterator i1=team2.begin(); i1 != team2.end(); i1++){
            for(list<int>::iterator i2=team2.begin(); i2 != i1; i2++){
                sum2 += (arr[*i1][*i2] + arr[*i2][*i1]);
            }
        }
        return sum1 > sum2 ? sum1 - sum2 : sum2 - sum1; 
    }
    list<int> tt1(team1);
    list<int> tt2(team2);
    tt1.push_back(depth);
    tt2.push_back(depth);
    return min(search(depth+1, tt1, team2), search(depth+1, team1, tt2));
}

int main(){
    input();
    list<int> team1, team2;
    cout<<search(0, team1, team2)<<endl;
    return 0;
}