#include<iostream>
#include<stdlib.h>
using namespace std;
 
int max(int a, int b) {  return (a > b) ? a : b; }
 
int longest(int arr[], int n)
{
   
    int Zz[n][2];
 
    for (int i = 0; i < n; i++)
        Zz[i][0] = Zz[i][1] = 1;
 
    int max_length = 1; 
 
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && Zz[i][0] < Zz[j][1] + 1)
                Zz[i][0] = Zz[j][1] + 1;
 
            if( arr[j] > arr[i] && Zz[i][1] < Zz[j][0] + 1)
                Zz[i][1] = Zz[j][0] + 1;
        }
 
        if (max_length < max(Zz[i][0], Zz[i][1]))
            max_length = max(Zz[i][0], Zz[i][1]);
    }
 
    return max_length;
}
 

int main()
{   
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++) cin>>a[i];
  cout<<longest(a,n);
    return 0;
}