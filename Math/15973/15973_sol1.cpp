#include<iostream>
#include<utility>

using namespace std;

int atop, aleft, aright, abottom;
int btop, bleft, bright, bbottom;
int apoints[4][2] , bpoints[4][2];

bool between(int low, int high, int value)
{
    return low < value && value < high; 
}

bool facecheck()
{
    for(int i=0; i<4; i++){
        if(between(bleft, bright, apoints[i][0]) && between(btop, bbottom, apoints[i][1])) return 1;
        if(between(aleft, aright, bpoints[i][0]) && between(atop, abottom, bpoints[i][1])) return 1;
    }
    if(atop >= btop && abottom <= btop) return 1;
    if(btop >= atop && bbottom <= atop) return 1;
    if(aleft >= bleft && aright <= bleft) return 1;
    if(bleft >= aleft && bright <= aleft) return 1;
    if(atop == btop && abottom == bbottom) return 1;
    if(aleft == bleft && aright == bright) return 1;
    return 0;
}

bool linecheck()
{
    if(atop == btop || abottom == btop || atop == bbottom || abottom == bbottom){
        if(aleft >= bright || bleft >= aright);
        else return 1;
    }
    if(aleft == bleft || aright == bleft || aleft == bright || aright == bright){
        if(atop <= bbottom || btop <= abottom);
        else return 1;
    }
    return 0;
}

bool pointcheck()
{
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(apoints[i][0] == bpoints[j][0] && apoints[i][1] == bpoints[j][1])return 1;
        }
    }
    return 0;
}

int main()
{
    cin>>aleft>>abottom>>aright>>atop;
    cin>>bleft>>bbottom>>bright>>btop;

    apoints[0][0] = aleft; apoints[0][1] = atop;
    apoints[1][0] = aright; apoints[1][1] = atop;
    apoints[2][0] = aleft; apoints[2][1] = abottom;
    apoints[3][0] = aright; apoints[3][1] = abottom;

    bpoints[0][0] = bleft; bpoints[0][1] = btop;
    bpoints[1][0] = bright; bpoints[1][1] = btop;
    bpoints[2][0] = bleft; bpoints[2][1] = bbottom;
    bpoints[3][0] = bright; bpoints[3][1] = bbottom;

    if(facecheck()) cout<<"FACE";
    else if(linecheck()) cout<<"LINE";
    else if(pointcheck()) cout<<"POINT";
    else cout<<"NULL";
    return 0;
}