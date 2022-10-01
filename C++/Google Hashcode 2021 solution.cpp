//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <map>
#define ll long long
using namespace std;

int main()
{


	fstream f1, f2;
	f1.open("a.txt", ios::in);
	f2.open("a_out.txt", ios::out);

	ll duration,intersection,street,cars,bonus;
    f1>>duration>>intersection>>street>>cars>>bonus;

    vector<ll>beg(street),end(street),time_street(street);
    vector<string>street_name(street);

    for(ll i=0;i<street;i++)
    {
        f1>>beg[i]>>end[i]>>street_name[i]>>time_street[i];
    }

    vector<pair<ll,vector<string> > >car_description;
    for(ll i=0;i<cars;i++)
    {
        ll p;
        f1>>p;
        vector<string>temp(p);
        for(ll j=0;j<p;j++)
        {
            f1>>temp[j];
        }
        car_description.push_back(make_pair(p,temp));
    }

    vector<vector<string> >ans(intersection);
    map<string,ll>m;
    for(ll i=0;i<car_description.size();i++)
    {
        pair<ll,vector<string> >ar=car_description[i];
        ll p=ar.first;
        vector<string>s=ar.second;
        ll begining=0;
        ll ending=0;
        string ans_name="";
        for(ll k=0;k<s.size();k++)
        {
            for(ll j=0;j<street;j++)
            {
                //f2<<" j : "<<street_name[j]<<"\n";
                if(street_name[j]==s[k])
                {
                    ans_name=street_name[j];
                    begining=beg[j];
                    ending=end[j];
                }
            }
            if(m.find(ans_name)!=m.end())
                continue;
            ans[ending].push_back(ans_name);
            m[ans_name]++;
        }
    }

    ll sz=0;
    for(ll i=0;i<intersection;i++)
    {
        if(ans[i].empty())
        {
            sz++;
        }
    }

    f2<<intersection-sz<<"\n";
    for(ll i=0;i<intersection;i++)
    {
        if(ans[i].empty())
            continue;
        f2<<i<<"\n";
        f2<<ans[i].size()<<"\n";
        for(int j=0;j<ans[i].size();j++)
        {
            f2<<ans[i][j]<<" "<<1<<"\n";
        }
    }

	f1.close();
	f2.close();

	return 0;
}
