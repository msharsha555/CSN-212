#include<iostream>
using namespace std;

int list(int dp[],int r,int p)
{
	int mid,l=-1;
	while(r-l-1)
	{
		mid=(l+r)/2;
		if(dp[mid]>=p)
		{
			r=mid;
		}
		else
			l=mid;
	}
	return r;
}
 
int lis(int a[],int n)
{
	int dp[n];
	int length=1;
	dp[0]=a[0];
 
	for(int i=1;i<n;i++)
	{
		if(a[i]<dp[0])
		{
			dp[0]=a[i];
		}
		else if(a[i]>dp[length-1])
		{
			dp[length]=a[i];
			length++;
		}
		else
		{
			dp[list(dp,length-1,a[i])]=a[i];
		}
	}
 
	return length;
}
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[2*n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			a[i+n]=a[i];
		}
		int max_final=0;
		for(int i=0;i<n;i++)
            max_final=max(max_final,lis(a+i,n));
        cout<<max_final<<endl;
	}
}