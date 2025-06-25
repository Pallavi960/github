#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int maxx=INT_MIN;
        int minn=INT_MAX;
        int i=0;
        while(intervals[i][1]<newInterval[0] && i<intervals.size())
            {
                ans.push_back({intervals[i][0],intervals[i][1]});
                i++;
            }
            while(intervals[i][0]<newInterval[1] && i<intervals.size())//second will be start  before ending the f
            {
                newInterval[0]=max(intervals[i][1],newInterval[1]);
                newInterval[1]=min(intervals[i][0],newInterval[0]);
                i++;
            }
            ans.push_back(newInterval);
            while( i<intervals.size())
            {
                ans.push_back({intervals[i][0],intervals[i][1]});
                i++;
            }


        return ans;
}


int main()
{
    vector<vector<int>>a={{1,3},{6,9}};
    vector<int>b={2,5};

    vector<vector<int>>ans=insert(a,b);
    int current=0;
    for(int i=0;i<ans.size();i++)
    {
       /* cout<<ans[current][i];
        if(i==ans[0].size())
        {

            current++;
            i=-1;
        }*/
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}
