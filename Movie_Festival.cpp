#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p2.second>p1.second;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
vector<pair<int,int>>v;
for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    v.push_back({x,y});
}
sort(v.begin(),v.end(),cmp);
int end=0,ans=0;
for(int i=0;i<n;i++){
    if(v[i].first>=end){
        ans++;
        end=v[i].second;
        }
}
cout<<ans<<endl;
return 0;
}