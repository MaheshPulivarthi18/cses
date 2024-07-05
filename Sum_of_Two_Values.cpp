#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,target;
cin>>n>>target;
vector<pair<int,int>>v;
for(int i=0;i<n;i++){
   int x;
   cin>>x;
   v.push_back({x,i+1});
}
sort(v.begin(),v.end());
int l=0,r=n-1;
pair<int,int>ans={-1,-1};
while(l<r){
    int sum=v[l].first+v[r].first;
    if(sum==target){
        if(v[r].second>v[l].second){
            ans={v[l].second,v[r].second};
        }
        else{
        ans={v[r].second,v[l].second};
        }
        break;
    }
    else if(sum>target){
       r--;
    }
    else{
       l++;
    }
}
if(ans.first==-1) cout<<"IMPOSSIBLE"<<endl;
else{
    cout<<ans.first<<" "<<ans.second<<endl;
}
return 0;
}