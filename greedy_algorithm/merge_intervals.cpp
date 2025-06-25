#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> soll(vector<vector<int>>a)
{
    sort(a.begin(),a.end());
    vector<vector<int>>ans;
    ans.push_back({a[0][0],a[0][1]});
    int j=0,start,end;
    for(int i=1;i<a.size();i++)
    {
      start=ans[j][0];end=ans[j][1];
      if(end>=a[i][0] && start<=a[i][1])
      {
         ans[j][0]=min(a[i][0],start);
         ans[j][1]=max(a[i][1],end);
      }
      else
      {
          ans.push_back({a[i][0],a[i][1]});
          j++;
      }
    }
    return ans;
}


int main()
{
    vector<vector<int>>a={{1,3},{3,6},{8,10},{15,18}};
    vector<vector<int>>ans=soll(a);
    for(int i=0;i<ans.size();i++)
    {

        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}
