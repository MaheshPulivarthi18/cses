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
long long ans=1;
for(int i=0;i<n;i++){
    if(ans>=v[i]){
       ans=ans+v[i];
    }
    else{
        break;
    }
}
cout<<ans;
return 0;
}