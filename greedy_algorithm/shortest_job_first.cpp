#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int av_time(vector<int>&a)
{
    int time=0,waiting_time=0;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
    {

        waiting_time+=time;//added every persons wating time
        time+=a[i];//current time
    }

    return (waiting_time/a.size());//average waiting time for one person
}



int main()
{
    vector<int>a={4,3,7,1,2};
    cout<<av_time(a);

    return 0;
}
