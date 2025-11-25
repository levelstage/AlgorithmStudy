// 17387 선분 교차 2
// 선형대수학을 이용해서 풀어봄(부동소수점 이슈가 날 수 있음.) + div by 0 도 해결해야 함. 일단 이건 아닌듯.

#include <cstdio>

using namespace std;

struct point
{
    double x, y;
    bool operator==(point &other)
    {
        return (x == other.x) && (y == other.y);
    }
};

struct line
{
    double a, b, c;
};

line get_line(point &s, point &e)
{
    // y = ((y2 - y1)/(x2 - x1))(x - x1) + y1
    // (x2-x1)y = (y2-y1)(x-x1) + (x2-x1)y1
    // (y2-y1)x - (x2-x1)y = (y2-y1)x1 - (x2-x1)y1
    line tmp;
    tmp.a = (e.y - s.y);
    tmp.b = -(e.x - s.x);
    tmp.c = (e.y - s.y) * s.x - (e.x - s.x) * s.y;
    return tmp;
}

point get_intersection(line &first, line &second)
{
    // a1 b1 | c1
    // a2 b2 | c2
    double b1, c1, b2, c2;
    b1 = first.b / first.a; c1 = first.c / first.a;
    b2 = second.b - (second.a * b1); c2 = second.c - (second.a * c1);
    c2 /= b2; c1 -= (b1 * c2);
    point res;
    res.x = c1; res.y = c2;
    return res;
}

bool is_between(point p, point s, point e)
{
    if((s.x <= p.x && p.x <= e.x) || (e.x <= p.x && p.x <= s.x))
    {
        if((s.y <= p.y && p.y <= e.y) || (e.y <= p.y && p.y <= s.y)) return 1;
    }
    return 0;
}

int main()
{
    point s1, e1, s2, e2;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
    s1.x = (double)x1; s1.y = (double)y1;
    e1.x = (double)x2; e1.y = (double)y2;
    s2.x = (double)x3; s2.y = (double)y3;
    e2.x = (double)x4; e2.y = (double)y4;
    line l1, l2;
    l1 = get_line(s1, e1);
    l2 = get_line(s2, e2);
    if(l1.a / l1.b == l2.a / l2.b){
        if(l1.c / l1.b == l2.c / l2.b){
            printf("%d\n", is_between(s1, s2, e2) || is_between(e1, s2, e2) || is_between(s2, s1, e1) || is_between(e2, s1, e1));
        }
        else printf("0\n");
        return 0;
    }
    point its = get_intersection(l1, l2);
    printf("%d\n", (is_between(its, s1, e1) && is_between(its, s2, e2)));
    return 0;
}