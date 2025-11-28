// 12100 2048(Easy)
// 뭔가 한번에 맞추니까 김빠진다.

#include <cstdio>
#include <queue>

using namespace std;

int N, ans;
vector<int> arr;
queue<pair<int,vector<int>>> boards;

void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int tmp;
            scanf("%d", &tmp);
            if(tmp > ans) ans = tmp;
            arr.push_back(tmp);
        }
    }
    return;
}

vector<int> press_up(vector<int> &v)
{
    vector<int> res(N*N);
    for(int j=0; j<N; j++){
        int c=0, q=-1;
        for(int i=0; i<N; i++){
            if(v[i*N+j] == 0) continue;
            if(q<0) q = i;
            else if(v[q*N+j] == v[i*N+j]){
                res[c*N+j] = v[i*N+j]*2;
                if(res[c*N+j] > ans) ans = res[c*N+j];
                q = -1;
                c++;
            }
            else{
                res[c*N+j] = v[q*N+j];
                q = i;
                c++;
            }
        }
        if(q >= 0){
            res[c*N+j] = v[q*N+j];
            c++;
        }
        while (c<N)
        {
            res[c*N+j] = 0;
            c++;
        }
    }
    return res;
}
vector<int> press_down(vector<int> &v)
{
    vector<int> res(N*N);
    for(int j=0; j<N; j++){
        int c=N-1, q=-1;
        for(int i=N-1; i>=0; i--){
            if(v[i*N+j] == 0) continue;
            if(q<0) q = i;
            else if(v[q*N+j] == v[i*N+j]){
                res[c*N+j] = v[i*N+j]*2;
                if(res[c*N+j] > ans) ans = res[c*N+j];
                q = -1;
                c--;
            }
            else{
                res[c*N+j] = v[q*N+j];
                q = i;
                c--;
            }
        }
        if(q >= 0){
            res[c*N+j] = v[q*N+j];
            c--;
        }
        while (c>=0)
        {
            res[c*N+j] = 0;
            c--;
        }
    }
    return res;
}

vector<int> press_left(vector<int> &v)
{
    vector<int> res(N*N);
    for(int i=0; i<N; i++){
        int c=0, q=-1;
        for(int j=0; j<N; j++){
            if(v[i*N+j] == 0) continue;
            if(q<0) q = j;
            else if(v[i*N+q] == v[i*N+j]){
                res[i*N+c] = v[i*N+j]*2;
                if(res[i*N+c] > ans) ans = res[i*N+c];
                q = -1;
                c++;
            }
            else{
                res[i*N+c] = v[i*N+q];
                q = j;
                c++;
            }
        }
        if(q >= 0){
            res[i*N+c] = v[i*N+q];
            c++;
        }
        while (c<N)
        {
            res[i*N+c] = 0;
            c++;
        }
    }
    return res;
}

vector<int> press_right(vector<int> &v)
{
    vector<int> res(N*N);
    for(int i=0; i<N; i++){
        int c=N-1, q=-1;
        for(int j=N-1; j>=0; j--){
            if(v[i*N+j] == 0) continue;
            if(q<0) q = j;
            else if(v[i*N+q] == v[i*N+j]){
                res[i*N+c] = v[i*N+j]*2;
                if(res[i*N+c] > ans) ans = res[i*N+c];
                q = -1;
                c--;
            }
            else{
                res[i*N+c] = v[i*N+q];
                q = j;
                c--;
            }
        }
        if(q >= 0){
            res[i*N+c] = v[i*N+q];
            c--;
        }
        while (c>=0)
        {
            res[i*N+c] = 0;
            c--;
        }
    }
    return res;
}



void bfs()
{
    boards.push(make_pair(0, arr));
    while (!boards.empty())
    {
        pair<int, vector<int>> tmp = boards.front();
        boards.pop();
        if(tmp.first >= 5) continue;
        boards.push(make_pair(tmp.first+1, press_down(tmp.second)));
        boards.push(make_pair(tmp.first+1, press_up(tmp.second)));
        boards.push(make_pair(tmp.first+1, press_left(tmp.second)));
        boards.push(make_pair(tmp.first+1, press_right(tmp.second)));
    }
    return;
}

int main()
{
    input();
    bfs();
    printf("%d\n", ans);
    return 0;
}