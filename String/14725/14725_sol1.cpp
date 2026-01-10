// 14725 개미굴

#include<iostream>
#include<string>
#include<map>
using namespace std;

struct tree
{
    map<string, tree> subtree;
};

tree hole;

int N;

void input()
{
    cin>>N;
    for(int i=0; i<N; ++i){
        int k;
        cin>>k;
        tree *now = &hole;
        for(int j=0; j<k; ++j){
            string inp;
            cin>>inp;
            now = &(now->subtree[inp]);
        }
    }
    return;
}

void output_tree(tree &x, int depth)
{
    for(auto iter : x.subtree)
    {
        for(int i=0; i<depth; i++) cout<<"--";
        cout<<iter.first<<endl;
        output_tree(iter.second, depth+1);
    }
    return;
}

int main()
{
    input();
    output_tree(hole, 0);
    return 0;
}
