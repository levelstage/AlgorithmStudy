// 15973 두 박스
// 가장 경우의 수가 많은 facecheck를 던지는게 핵심이다.

#include<iostream>
#include<utility>

using namespace std;

int atop, aleft, aright, abottom;
int btop, bleft, bright, bbottom;

bool nullcheck()
{
    if(aleft>bright||bleft>aright||abottom>btop||bbottom>atop) return 1;
    return 0;
}

bool pointcheck()
{
    if(atop==bbottom && (aleft==bright||aright==bleft))return 1;
    if(abottom==btop && (aleft==bright||aright==bleft))return 1;
    return 0;
}

bool linecheck()
{
    if(atop==bbottom||btop==abottom)
    {
        if(aleft == bleft || aright == bright) return 1;
        if((aleft<bleft && bleft<aright) || (bleft<aleft&&aleft<bright)) return 1;
    }
    if(aleft==bright||bleft==aright)
    {
        if(atop == btop || abottom == bbottom) return 1;
        if((abottom<btop && btop<atop) || (bbottom < atop && atop < btop)) return 1;
    }
    return 0;
}

int main()
{
    cin>>aleft>>abottom>>aright>>atop;
    cin>>bleft>>bbottom>>bright>>btop;

    if(nullcheck()) cout<<"NULL";
    else if(linecheck()) cout<<"LINE";
    else if(pointcheck()) cout<<"POINT";
    else cout<<"FACE";
    return 0;
}