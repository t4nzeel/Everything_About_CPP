#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
    vector<int>ans;
    vector<vector<int>>adj(numCourses);
    vector<int>indegree(numCourses,0);
    queue<int>q;
    for(auto &p:prerequisites){
        int course=p[0],pre=p[1];
        adj[pre].push_back(course);
        indegree[course]++;
    }
    for(int i=0;i<numCourses;i++){
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int c=q.front();
        q.pop();
        ans.push_back(c);
        for(int next:adj[c]){
            indegree[next]--;
            if(indegree[next]==0)q.push(next);
        }
    }
    if(ans.size()==numCourses)return ans;
    return {};
}
int main(){
    vector<vector<int>>v={{1,0},{2,0},{3,1},{3,2}};
    vector<int>ans=findOrder(4,v);
    for(int &x:ans)cout<<x<<" ";
    cout<<endl;
}