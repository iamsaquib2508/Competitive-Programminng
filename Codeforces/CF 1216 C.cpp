#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int mn(int a, int b)
{
    if(a<b) return a;
    return b;
}

class vec
{
public:
    int x, y;
    vec(){}
    vec(int xx, int yy) {x=xx; y=yy;}
};

bool solve(vec w1, vec w2, vec b1, vec b2, vec b3, vec b4)
{
    if(b1.x<=w1.x && w2.x<=b2.x)
    {
        if(b1.y<=w1.y && w2.y<=b2.y) return true;
    }
    if(b3.x<=w1.x && w2.x<=b4.x)
    {
        if(b3.y<=w1.y && w2.y<=b4.y) return true;
    }
    if(b1.x<=w1.x && w2.x<=b2.x && b3.x<=w1.x && w2.x<=b4.x)
    {
        if(b1.y<=w1.y && b3.y<=b2.y && w2.y<=b4.y) return true;
    }
    if(b1.y<=w1.y && w2.y<=b2.y && b3.y<=w1.y && w2.y<=b4.y)
    {
        if(b1.x<=w1.x && b3.x<=b2.x && w2.x<=b4.x) return true;
    }
    return false;
}

int main()
{
    while(1)
    {
        vec w1, w2, b1, b2, b3, b4;
        cin >> w1.x >> w1.y >> w2.x >> w2.y;
        cin >> b1.x >> b1.y >> b2.x >> b2.y;
        cin >> b3.x >> b3.y >> b4.x >> b4.y;

        if(solve(w1, w2, b1, b2, b3, b4) || solve(w1, w2, b3, b4, b1, b2)) cout << "NO\n";
        else cout << "YES\n";
        break;
    }

}
