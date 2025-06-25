#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int min_time(vector<int>&a,vector<int>&b)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int min_time=INT_MIN;
    for(int i=0;i<a.size();i++)
    {
        min_time=max(min_time,b[i]-a[i]);
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
