#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
vector<int>v;
vector<int>v1;
for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    v.push_back(x);
    v1.push_back(y);
}
sort(v.begin(),v.end());
sort(v1.begin(),v1.end());
int ans=0,maxi=0;
int i=0,j=0;
while(i<n && j<n){
   if(v[i]<v1[j]){
    ans++;
    i++;
    maxi=max(maxi,ans);
   }
   else{
    ans--;
    j++;
    maxi=max(maxi,ans);
   }
}
cout<<maxi<<endl;
return 0;
}