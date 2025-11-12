// 1933 스카이라인
// 어쩔 브루트포스

#include <iostream>
#include <queue>

using namespace std;

struct column
{
    long long int l, h;
};

queue<column> q;


column colbylh(long long int l, long long int h)
{
    column res;
    res.l = l;
    res.h = h;
    return res;
}

long long int nextl(int i, int count)
{
    if(i == count-1) return 1000000001;
    return q.front().l;
}

void update(long long int l, long long int h, long long int r)
{
    int count = q.size();
    bool shown = 0;
    for(int i=0; i<count; i++){
        column col = q.front();
        q.pop();
        if(col.l < l || col.l > r) q.push(col);
        if(col.l <= l && l < nextl(i, count)){
            if(col.l == l && col.h > h)q.push(col);
            else if(col.h < h) {
                shown = 1;
                q.push(colbylh(l, h));
            }
        }
        if(l < col.l && col.l < r)
        {
            if(col.h > h){
                q.push(col);
                shown = 0;
            }
            else if(col.h < h && !shown){
                q.push(colbylh(col.l, h));
                shown = 1;
            }
        }
        if(col.l <= r && r < nextl(i, count) && col.h < h){
            q.push(colbylh(r, col.h));
        }
    }
}

void input()
{
    int N;
    long long int l, h, r;
    cin >> N;
    q.push(colbylh(1,0));
    for(int i=0; i<N; i++)
    {
        cin>>l>>h>>r;
        update(l,h,r);
    }
    return;
}

void print()
{
    while(!q.empty())
    {
        if(q.front().l == 1 && q.front().h == 0){
            q.pop();
            continue;
        }
        cout<<q.front().l<<" "<<q.front().h<<" ";
        q.pop();
    }
    return;
}

int main()
{
    input();
    print();
    return 0;
}


