#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++){
    cin>>v[i];
}
sort(v.begin(),v.end());
int needed_val;  
needed_val=v[(n)/2];
long long ans=0;
for(int i=0;i<n;i++){
    ans=ans+abs(v[i]-needed_val);
}
cout<<ans;
return 0;
}