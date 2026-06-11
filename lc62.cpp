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
ListNode* reverseList(ListNode* head){
    // Iterative method :-

    /*ListNode* temp=head;
    ListNode* prev=NULL;
    while(temp){                         // while(temp!=NULL)---> same thing.
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;*/

    // Recursive Method :-
    
    if(head==NULL || head->next==NULL) return head;
    ListNode* newHead=reverseList(head->next);
    ListNode* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
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
    ListNode* Head1=reverseList(Head);
    printList(Head1);
}