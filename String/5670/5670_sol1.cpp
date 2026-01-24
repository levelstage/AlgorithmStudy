// 5670 휴대폰 자판
// resister_str은 뭐냐!!! 아이 창피해

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct dict
{
    map<char, dict> subDict;
};

int N;
dict D;
vector<string> buffer;

void resister_str(string &str)
{
    int i=0;
    dict *curr = &D;
    while (1)
    {
        curr = &(curr->subDict[str[i]]);
        if(str[i] == '\0') break;
        ++i;
    }
    return;
}

int get_length(string &str)
{
    dict *curr = &D;
    int i=0, len=0;
    while (str[i] != '\0')
    {
        if(i==0 || curr->subDict.size() > 1) ++len; 
        curr = &(curr->subDict[str[i++]]);
    }
    return len;
}

int main()
{
    cout<<fixed<<setprecision(2);
    while (cin>>N)
    {
        buffer.clear();
        buffer.reserve(N);
        D = dict();
        string str;
        for(int i=0; i<N; ++i)
        {
            cin>>str;
            resister_str(str);
            buffer.push_back(str);
        }
        double sum=0;
        for(int i=0; i<N; ++i)
        {
            sum+=(double)get_length(buffer[i]);
        }
        cout<<(sum/N)<<endl;
    }
    return 0;
}