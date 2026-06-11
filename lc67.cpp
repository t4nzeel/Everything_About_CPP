#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* convert_Arr_2_LL(vector<int>v2){
    ListNode* head=new ListNode(v2[0]);
    ListNode* mover=head;
    for(int i=1;i<v2.size();i++){
        ListNode* temp=new ListNode(v2[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
ListNode* find_Middle(ListNode* head){
    ListNode* fast=head->next;
    ListNode* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* merge2Lists(ListNode* list1,ListNode* list2){
    ListNode* dummy=new ListNode(-1);
    ListNode* temp=dummy;
    while(list1!=NULL && list2!=NULL){
        if(list1->val < list2->val){
            temp->next=list1;
            temp=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            temp=list2;
            list2=list2->next;
        }
    }
    if(list1) temp->next=list1;
    else temp->next=list2;
    return dummy->next;
}
ListNode* sortLL(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* mid=find_Middle(head);
    ListNode* right=mid->next;
    mid->next=nullptr;
    ListNode* left=head;
    left=sortLL(left);
    right=sortLL(right);
    return merge2Lists(left,right);
}
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    vector<int>v={2,1,2,0,1,0};
    ListNode* Head=convert_Arr_2_LL(v);
    ListNode* Head1=sortLL(Head);
    printList(Head1);
}