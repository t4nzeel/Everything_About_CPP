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
ListNode* middleNode(ListNode* head){
    /*if(head==NULL || head->next==NULL) return head;
    int cnt=0;
    ListNode* temp1=head;
    while(temp1){
        temp1=temp1->next;
        cnt++;
    }
    int x=cnt/2;
    int c=0;
    ListNode* temp2=head;
    while(c<x){
        temp2=temp2->next;
        c++;
    }
    head=temp2;
    return head;*/

    // Tortoise-Hare Method :-

    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
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
  vector<int>v={1};
  ListNode* Head=convert_Arr_2_LL(v);
  ListNode* Head1=middleNode(Head);
  printList(Head1);
}