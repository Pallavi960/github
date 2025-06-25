#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution{
public:
    int min_platform(vector<int>&arrive,vector<int>&departed)
    {
       /* vector<pair<int,char>>temp;
        for(int i=0;i<arrive.size();i++)
        {
           temp.push_back({arrive[i],'A'}) ;
           temp.push_back({departed[i],'D'}) ;
        }
        sort(temp.begin(),temp.end());
        int maxx=INT_MIN,c=0;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i].second=='A')
            {
                c++;

            }
            else{
                c--;
            }
            maxx=max(maxx,c);
        }
       return maxx;*/
       // Bruth approch
       /* int max_count=INT_MIN;
        for(int i=0;i<arrive.size();i++)
        {
            int start=arrive[i],end=departed[i],c=1;

            for(int j=i+1;j<departed.size();j++)
            {
                if(arrive[j]>start && departed[j]<end)
                {
                    c++;
                }
            }
            max_count=max(max_count,c);
        }
        return max_count;*/
        sort(arrive.begin(),arrive.end());
        sort(departed.begin(),departed.end());
        int i=0,j=0,c=0,maxx=INT_MIN;
        while(i<arrive.size() && j<departed.size())
        {
            if(arrive[i]<departed[j])
            {
                c++;
                maxx=max(maxx,c);
               i++;
            }
            else{
                c--;
                j++;
            }
        }

        return maxx;

    }

};





int main()
{
    vector<int>arrive={900, 940, 950, 1100, 1500, 1800};
    vector<int>departed={910, 1120, 1130,1200, 1900, 2000};
    solution s;
    int ans=s.min_platform(arrive,departed);
    cout<<ans;

    return 0;
}
