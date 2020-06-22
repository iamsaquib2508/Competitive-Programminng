#include<bits/stdc++.h>

using namespace std;

class shore
{
public:
    int man, rak;
    shore(){}
    shore(int a, int b)
    {
        man=a, rak=b;
    }
    bool valid()
    {
        return (man>=rak);
    }

};

class state
{
s
};

bool visited(shore a)
{
    return false;
}

void solutionprint(state *s)
{
    if(s->parent!=NULL)
    {
        solutionprint(s->parent);
    }
    s->print();
}

int call(int man, int rak, int kap)
{
    shore a=shore(man,rak), b=shore(0,0);
    state source=(a,b,true);
    if(!source.valid()) throw 1;
    queue<state> q;
    q.push(source);
    while(!q.empty())
    {
        status cur=q.top();
        q.pop();
        if(visited(cur)) continue;
        if(q==goal) return 0; //??
        else if(cur.boat_at_start)
        {
            ffrr(thiskap,1,kap)
            {
                int sendable_man=min(thiskap,cur.startshore.man);

                ffrr(mansend,0,sendable_man)
                {
                    raksend=thiskap-mansend;
                    if(raksend>cur.startshore.rak) continue;
                    state temp=cur;
                    temp.boat_at_start=0;

                    temp.startshore.man-=mansend;
                    temp.startshore.rak-=raksend;

                    temp.goalshore.man+=mansend;
                    temp.goalshore.rak+=raksend;
                    temp.str=//
                    if(temp.valid()) q.push(temp);
                }
            }
        }
        else if(!cur.boat_at_start)
        {
            ffrr(thiskap,1,kap)
            {
                int sendable_man=min(thiskap,cur.goalshore.man);

                ffrr(mansend,0,sendable_man)
                {
                    raksend=thiskap-mansend;
                    if(raksend>cur.goalshore.rak) continue;
                    state temp=cur;
                    temp.boat_at_start=1;

                    temp.goalshore.man-=mansend;
                    temp.goalshore.rak-=raksend;

                    temp.startshore.man+=mansend;
                    temp.startshore.rak+=raksend;
                    if(temp.valid()) q.push(temp);
                }
            }
        }
    }
}

int main()
{
    int m, r, k;
    while(true)
    {
        cin >> m >> r >> k;
        if(m==0 && r==0 && k==0) break;
        try{
            cout << call(m,r,k) << endl;
        }catch(int i)
        {
            cout << "Impossible\n";
        }
    }
    return 0;
}
