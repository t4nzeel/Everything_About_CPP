#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int upperBound(vector<int> &v2, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (v2[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}
int countSmallEqual(vector<vector<int>> &v1, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += upperBound(v1[i], x, n);
    }
    return cnt;
}
int median(vector<vector<int>> &v0, int m, int n) {
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < m; i++) {
        low = min(low, v0[i][0]);
        high = max(high, v0[i][n - 1]);
    }
    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(v0, m, n, mid);
        if (smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
int main(){
    int r,c,x;
    cout<<"Enter row and column : ";
    cin>>r>>c;
    vector<vector<int>>v(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"Enter value : ";
            cin>>x;
            v[i][j]=x;
        }
    }
    cout<<median(v,r,c);
}