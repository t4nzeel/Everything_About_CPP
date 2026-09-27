#include<bits/stdc++.h>
using namespace std;
/*vector<int> pre_MAX(vector<int>&v){
    int n=v.size();
    vector<int>pM(n);
    pM[0]=v[0];
    for(int i=1;i<n;i++){
        pM[i]=max(pM[i-1],v[i]);
    }
    return pM;
}
vector<int> suff_MAX(vector<int>&v){
    int m=v.size();
    vector<int>sM(m);
    sM[m-1]=v[m-1];
    for(int i=m-2;i>=0;i--){
        sM[i]=max(sM[i+1],v[i]);
    }
    return sM;
}*/
int trap(vector<int>& height){
    /*vector<int>p_m=pre_MAX(height);
    vector<int>s_m=suff_MAX(height);
    int total=0;
    for(int i=0;i<height.size();i++){
        int left_Max=p_m[i];
        int right_Max=s_m[i];
        if(height[i]<left_Max && height[i]<right_Max) total+=min(left_Max,right_Max)-height[i];
    }
    return total;*/
    int n=height.size();
    int l=0,r=n-1,lM=0,rM=0,ans=0;
    while(l<r){
        if(height[l]<=height[r]){
            if(lM>height[l])ans+=lM-height[l];
            else lM=height[l];
            l++;
        }
        else{
            if(rM>height[r])ans+=rM-height[r];
            else rM=height[r];
            r--;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x:v)cin>>x;
    int ans=trap(v);
    cout<<ans<<endl;
}