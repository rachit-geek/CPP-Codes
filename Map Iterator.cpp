#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
	//freopen("inp.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>t;
    for(int k=1;k<=t;k++){
		cout<<"Case #"<<k<<": ";
		int n;
		cin>>n;
		vector<vector<int> > v;
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end());
		unordered_map<int,int> mymap;
		int ma=0;
		for(int i=0;i<v.size();i++)
		{
			mymap[v[i][0]+v[i][1]]=max(mymap[v[i][0]+v[i][1]],mymap[v[i][0]]+v[i][1]);
			ma=max(ma,mymap[v[i][0]+v[i][1]]);
			mymap[v[i][0]]=max(mymap[v[i][0]],mymap[v[i][0]-v[i][1]]+v[i][1]);
			ma=max(mymap[v[i][0]],ma);
		}
		cout<<ma<<endl;
    }
    return 0;
}
