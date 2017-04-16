#include <iostream>
#include <stack>
#include <algorithm>
 
using namespace std;

class mypoint 
{
	public:
	    int x, y;
	    bool operator < (mypoint b) {
	        if (y != b.y)
	            return y < b.y;
	        return x < b.x;
	    }
};

mypoint pivot;

int Orient(mypoint a, mypoint b, mypoint c) {
    int val = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
      if (val == 0)
        return 0;
    return (val > 0) ? -1 : 1;
}

int Dist_Sq(mypoint a, mypoint b)  {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool polar_order(mypoint a, mypoint b)  {
    int order = Orient(pivot, a, b);
    if (order == 0)
        return Dist_Sq(pivot, a) < Dist_Sq(pivot, b);
    return (order == -1);
}

int main()  {
   
   int n;cin>>n;
    mypoint ConvexArray[n];
    for(int i=0;i<n;i++) cin>>ConvexArray[i].x>>ConvexArray[i].y;

    stack<mypoint> ConvexHull;

    if (n >= 3) {
	    int least_y = 0;
	    for (int i = 1; i < n; i++)
	        if (ConvexArray[i] < ConvexArray[least_y])
	            least_y = i;

	    mypoint temp = ConvexArray[0];
	    ConvexArray[0] = ConvexArray[least_y];
	    ConvexArray[least_y] = temp;

	    pivot = ConvexArray[0];
	    sort(ConvexArray + 1, ConvexArray + n, polar_order);

	    ConvexHull.push(ConvexArray[0]);
	    ConvexHull.push(ConvexArray[1]);
	    ConvexHull.push(ConvexArray[2]);

	    for (int i = 3; i < n; i++) {
	        mypoint top = ConvexHull.top();
	        ConvexHull.pop();
	        while (Orient(ConvexHull.top(), top, ConvexArray[i]) != -1)   {
	            top = ConvexHull.top();
	            ConvexHull.pop();
	        }
	        ConvexHull.push(top);
	        ConvexHull.push(ConvexArray[i]);
	    }
	}

    while (!ConvexHull.empty())   {
        mypoint p = ConvexHull.top();
        ConvexHull.pop();
		cout << "(" <<p.x << ", " <<p.y << ")\n";
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
(0, 4)
(5, 6)
(2, -1)
(-5, -4)
*/