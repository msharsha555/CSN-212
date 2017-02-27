#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef pair<int,int> vec;

bool ins(int a, int max)
{
	if(a<0 || a>max)
		return false;
	else
		return true;
}

class AvoidRoads
{
public:
	long long numWays(int wid, int ht, vector <string> bad);
};

long long AvoidRoads::numWays(int wid, int ht, vector <string> bad)
{	
	set< pair<vec,vec> > badss;
	set<vec> found;
	found.insert(vec(0,0));
	for(int i=0; i<bad.size(); ++i)
	{
		vec a,b;
		stringstream ss(bad[i]);
		ss >> a.first >> a.second >> b.first >> b.second;
		bad.insert( pair<vec,vec>(a,b));
		bad.insert( pair<vec,vec>(b,a));
	}

	vector< vector<long long> > area;
	vector<long long> row;
	row.assign(wid+1,0);
	area.assign(ht+1,row);

	area[0][0] = 1;

	for(int i=0; i<=ht; ++i)
	{
		for(int j=0; j<=wid; ++j)
		{
			for(int k=-1; k<=1; k+=2)
			{
				if(ins(i+k,ht) && bad.find(pair<vec,vec>(vec(i,j),vec(i+k,j)))==bad.end())
					area[i][j] += area[i+k][j];
				if(ins(j+k,wid) && bad.find(pair<vec,vec>(vec(i,j),vec(i,j+k)))==bad.end())
					area[i][j] += area[i][j+k];
			}
		}
	}

	return area[ht][wid];
}

int main()
{
	AvoidRoads ARoads;
	int a0;
	int a1;
	vector <string> a2;
	a0=35;
	a1=31;
	//a2.push_back("0 0 0 1");
	//a2.push_back("6 6 5 6");
	long long num = ARoads.numWays(a0,a1,a2);
	return 0;
}
