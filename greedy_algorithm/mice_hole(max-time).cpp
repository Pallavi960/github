#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int min_time(vector<int>&a,vector<int>&b)
{
    int n=a.size()-1;
    sort(a.begin(),a.end());//O(log(N))
    sort(b.begin(),b.end());//O(log(N))
    int min_time=INT_MIN;
    for(int i=0;i<=n;i++)//O(N)
    {
        min_time=max(min_time,b[i]-a[n-i]);//here b[i]-a[i] is the time taken by mice to reach the hole
    }
    return min_time;
}



int main()
{
    vector<int>mice={4,-4,2};
    vector<int>hole={4,0,5};
    cout<<min_time(mice,hole);
    return 0;
}

