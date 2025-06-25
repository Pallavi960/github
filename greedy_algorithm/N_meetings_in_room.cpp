#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}

int meeting(vector<int>&start,vector<int>&end_t)
{
    vector<pair<int,int>>meet;
    for(int i=0;i<end_t.size();i++)
    {
        meet.push_back({start[i],end_t[i]});
    }
    sort(meet.begin(),meet.end(),comp);
    int countt=0;
    int ending=-1;
    for(int i=0;i<meet.size();i++)
    {
        if(meet[i].first>ending)
        {

            countt++;
           ending=meet[i].second;
        }
    }
    return countt;
}





int main()
{
    vector<int>start={0,1,3,5,5,8};
    vector<int>end_t={2,4,6,7,9,9};
    cout<<meeting(start,end_t);


    return 0;
}
