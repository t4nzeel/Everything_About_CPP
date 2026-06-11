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
ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* slow=head;
    ListNode* fast=head;
    for(int i=0;i<n;i++) fast=fast->next;
    if(fast==NULL) return head->next;
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    } 
    ListNode* delNode=slow->next;
    slow->next=slow->next->next;
    delete delNode;
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
int main(){
    vector<int>v={1,2,3,4,5};
    ListNode* Head=convert_Arr_2_LL(v);
    ListNode* Head1=removeNthFromEnd(Head,2);
    printList(Head1);
}