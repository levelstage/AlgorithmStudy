// 17387 선분 교차 2
// 좀 더 스마트하게 풀어보자. 부동소수점 계산을 곰셈으로 전환(없다는 뜻)

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool is_between(long long int v, long long int a, long long int b)
{
    return (a<=v && v<=b) || (b<=v && v<=a);
}

int main()
{
    long long int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);
    if(x1 > x2){
        long long int tmp;
        tmp = x1;
        x1 = x2;
        x2 = tmp;
        tmp = y1;
        y1 = y2;
        y2 = tmp;
    }
    if(x3 > x4){
        long long int tmp;
        tmp = x3;
        x3 = x4;
        x4 = tmp;
        tmp = y3;
        y3 = y4;
        y4 = tmp;
    }
    if(x1 == x2 && x3 == x4){
        printf("%d\n", (x1 == x3) && (is_between(y1, y3, y4) || is_between(y2, y3, y4) || is_between(y3, y1, y2) || is_between(y4, y1, y2)));
        return 0;
    }
    if(x1 == x2){
        printf("%d\n", is_between(x1, x3, x4) && is_between(y3*(x4-x3) + (y4-y3)*(x1-x3), y1*(x4-x3), y2*(x4-x3)));
        return 0;
    }
    if(x3 == x4){
        printf("%d\n", is_between(x3, x1, x2) && is_between(y1*(x2-x1) + (y2-y1)*(x3-x1), y3*(x2-x1), y4*(x2-x1)));
        return 0;
    }
    if(is_between(x3, x1, x2) || is_between(x4, x1, x2) || is_between(x1, x3, x4) || is_between(x2, x3, x4)){
        vector<long long int> xs = {x1, x2, x3, x4};
        sort(xs.begin(), xs.end());
        long long int l1, l2, r1, r2;
        l1 = y1 * (x4-x3) * (x2-x1) + (y2-y1) * (x4-x3) * (xs[1] - x1);
        l2 = y3 * (x4-x3) * (x2-x1) + (y4-y3) * (x2-x1) * (xs[1] - x3);
        r1 = y1 * (x4-x3) * (x2-x1) + (y2-y1) * (x4-x3) * (xs[2] - x1);
        r2 = y3 * (x4-x3) * (x2-x1) + (y4-y3) * (x2-x1) * (xs[2] - x3);
        if(l1 == l2 || r1 == r2){
            printf("1\n");
            return 0;
        }
        if(l1 > l2 && r1 < r2)
        {
            printf("1\n");
        }
        else if (l1 < l2 && r1 > r2)
        {
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    else{
        printf("0\n");
    }
    return 0;
}