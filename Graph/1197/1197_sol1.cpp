//1197 최소 스패닝 트리
// 크루스칼 알고리즘(?)을 어쩌다보니 직접 구현함. Union-Find가 어쩌구 하는데 솔직히 잘 모르겠다.

#include<iostream>
#include<queue>

using namespace std;

struct tree
{
    tree *parent;
    int size, idx;
};

struct edge
{
    int v1, v2, cost;
};

struct lower_cost
{
    bool operator()(edge &a, edge &b)
    {
        return a.cost > b.cost;
    }
};

priority_queue<edge, vector<edge>, lower_cost> q;
vector<tree> trees;
tree *group[10001];
int V, E;

edge make_edge(int v1, int v2, int cost)
{
    edge tmp;
    tmp.v1 = v1;
    tmp.v2 = v2;
    tmp.cost = cost;
    return tmp;
}

tree new_tree()
{
    tree tmp;
    tmp.size = 2;
    tmp.parent = nullptr;
    return tmp;
}

tree *get_root(tree &x)
{
    tree* tmp = &x;
    while (tmp->parent != nullptr)
    {
        tmp = tmp->parent;
    }
    return tmp;
}

void input()
{
    cin>>V>>E;
    for(int i=0; i<E; i++){
        int v1, v2, cost;
        cin>>v1>>v2>>cost;
        q.push(make_edge(v1, v2, cost));
    }
    return;
}

int solve()
{
    int res = 0;
    while(!q.empty())
    {
        edge e = q.top();
        q.pop();
        int v1 = e.v1, v2 = e.v2, cost = e.cost;
        if(group[v1] == nullptr && group[v2] == nullptr){
            trees.push_back(new_tree());
            group[v1] = &trees.back();
            group[v2] = &trees.back();
            res += cost;
            if(trees.back().size == V) return res;
        }
        else if(group[v1] == nullptr && group[v2] != nullptr){
            tree *root = get_root(*group[v2]);
            root->size++;
            group[v1] = root;
            res += cost;
            if(root->size == V) return res;
        }
        else if(group[v1] != nullptr && group[v2] == nullptr){
            tree *root = get_root(*group[v1]);
            root->size++;
            group[v2] = root;
            res += cost;
            if(root->size == V) return res;
        }
        else{
            tree *r1 = get_root(*group[v1]), *r2 = get_root(*group[v2]);
            if(r1 == r2) continue;
            r1->size+=r2->size;
            r2->parent = r1;
            res += cost;
            if(r1->size == V) return res;
        }
    }
    return 0;
}


int main()
{
    trees.reserve(10001);
    input();
    if(V == 1){
        cout<<0<<endl;
        return 0;
    }
    cout<<solve()<<endl;
    return 0;
}