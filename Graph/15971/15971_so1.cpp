// 15971 두 로봇
// 자료구조만 좀 알면(MAP) 굉장히 쉽게 풀 수 있음ㅇㅇ

#include<iostream>
#include<map>
#include<vector>

using namespace std;

map<int, vector<pair<int, int>>> pmap;
int N, R1, R2;

void push_path(int start, int end, int length)
{
    map<int, vector<pair<int, int>>>::iterator iter = pmap.find(start);
    if(iter == pmap.end()){
        vector<pair<int, int>> tmp;
        tmp.push_back(make_pair(end, length));
        pmap.insert(pair<int, vector<pair<int,int>>>(start, tmp));
    }
    else{
        pmap.at(start).push_back(make_pair(end, length));
    }
    return;
}

void input()
{
    cin>>N>>R1>>R2;
    for(int i=1; i<N; i++){
        int first, second, length;
        cin>>first>>second>>length;
        push_path(first, second, length);
        push_path(second, first, length);
    }
    return;
}

int search(int from, int idx, int goal, int max)
{
    if(idx == goal) return -max;
    vector<pair<int, int>> &paths = pmap.at(idx);
    for(int i=0; i<paths.size(); i++){
        if(paths[i].first == from) continue;
        int res = search(idx, paths[i].first, goal, max > paths[i].second ? max : paths[i].second) + paths[i].second;
        if(res < 1000000000) return res;
    }
    return 1000000000;
}

int main()
{
    input();
    cout<<search(R1,R1,R2,0)<<endl;
    return 0;
}