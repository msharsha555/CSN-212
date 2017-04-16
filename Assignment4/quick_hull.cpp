#include <bits/stdc++.h>
using namespace std;

struct mypoint
{
    int x, y;
};
bool Compare(mypoint a, mypoint b)
{  
    return (a.x<b.x);
}
int Orient(mypoint p, mypoint q, mypoint r)
{   
    return (q.y - p.y)*(r.x - q.x)-(q.x - p.x)*(r.y - q.y);
}
void PartialHull(vector<mypoint> &arr, vector<mypoint> &result, mypoint P1, mypoint Pn)
{
    vector<mypoint> s1 = vector<mypoint>();   
    for (vector<mypoint>::iterator it = arr.begin(); it < arr.end(); it++)
    {  
        if (Orient(P1,Pn,*it) > 0)
        {    
            
            s1.push_back(*it); 
        }
    }
    if (s1.empty())
    {    
       
        result.push_back(P1);
    } 
    else 
    {    
        float maxDist = 0;  
        mypoint pmax;   
        float dist; 
        float length = sqrt(pow(P1.x - Pn.x, 2) + pow(P1.y - Pn.y, 2)); 
        for (vector<mypoint>::iterator it = s1.begin(); it < s1.end(); it++)
        {
            dist = Orient(P1,Pn,*it) / length; 
            if (dist > maxDist)
            {    
                
                maxDist = dist;
                pmax = *it;
            }
        }
        
        vector<mypoint> s11 = vector<mypoint>();  
        vector<mypoint> s12 = vector<mypoint>();  
        for (vector<mypoint>::iterator it = s1.begin(); it < s1.end(); it++)
        {
          
            if (Orient(P1,pmax,*it) > 0)
            {  
            
                s11.push_back(*it);
            } 
            else if (Orient(pmax,Pn,*it) > 0)
            {   
                
                s12.push_back(*it);
            }
        }
        PartialHull(s11, result, P1, pmax);
        PartialHull(s12, result, pmax, Pn); 
    }
}
int main(){
    int n;
    cin>>n;
    vector<mypoint> P = vector<mypoint>();   
    vector<mypoint> upper = vector<mypoint>();    
    vector<mypoint> lower = vector<mypoint>();   
    for (int i=0;i<n;i++)
    {   
        mypoint p;
        cin>>p.x>>p.y;
        P.push_back(p);
    }
    sort(P.begin(),P.end(),Compare);
    PartialHull(P, upper, P[0], P[n-1]);  
    PartialHull(P, lower, P[n-1], P[0]); 
    sort(upper.begin(),upper.end(),Compare); 
    sort(lower.begin(),lower.end(),Compare);
    for (vector<mypoint>::iterator it = upper.begin(); it < upper.end(); it++)
    {  
       
        cout <<"("<< (*it).x<< ", " << (*it).y<<")" << endl;
    }
    for (vector<mypoint>::iterator it = lower.end()-1; it >= lower.begin(); it--)
    {
        
        cout <<"("<< (*it).x<< ", " << (*it).y<<")" << endl;
    }
   
    return 0;
}
/*
Input:
6
5 6
1 1
0 4
2 -1 
-5 -4
1 2

Output:
(-5, -4)
(2, -1)
(5, 6)
(0, 4)

*/