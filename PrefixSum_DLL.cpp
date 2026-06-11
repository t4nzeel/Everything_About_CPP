#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
ListNode* convert_Arr_2_DLL(vector<int>&v2){
    ListNode* head=new ListNode(v2[0]);
    ListNode* prev=head;
    for(int i=1;i<v2.size();i++){
        ListNode* temp=new ListNode(v2[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
vector<vector<int>> findPairsWithGivenSum(ListNode* head, int t){
    vector<vector<int>>v;
    ListNode* left=head;
    ListNode* right=head;
    while(right->next) right=right->next;
    while(left!=right && right->next!=left){   //while(left->val < right->val)
        int sum=left->val+right->val;
        if(sum==t){
            v.push_back({left->val,right->val});
            left=left->next;
            right=right->prev;
        }
        else if(sum<t) left=left->next;
        else right=right->prev;
    }
    return v;
}
int main(){
     vector<int>v={1,2,4,5,6,8,9};
    ListNode* Head=convert_Arr_2_DLL(v);
    int x;
    cout<<"Enter target value : ";
    cin>>x;
    vector<vector<int>>v1=findPairsWithGivenSum(Head,x);
    for (int i = 0; i < v1.size(); i++) {
    cout << "(" << v1[i][0] << ", " << v1[i][1] << ")\n";
}
}