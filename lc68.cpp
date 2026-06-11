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
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
ListNode* Add_2_nos(ListNode* l1,ListNode* l2){
    ListNode* dummyNode=new ListNode(-1);
    ListNode* curr=dummyNode;
    ListNode* t1=l1;
    ListNode* t2=l2;
    int carry=0;
    while(t1!=NULL || t2!=NULL){
        int sum=carry;
        if(t1) sum+=t1->val;
        if(t2) sum+=t2->val;
        ListNode* newNode=new ListNode(sum%10);
        carry=sum/10;
        curr->next=newNode;
        curr=curr->next;
        if(t1) t1=t1->next;
        if(t2) t2=t2->next;
    }
    if(carry){
        ListNode* newNode=new ListNode(carry);
        curr->next=newNode;
    }
    return dummyNode->next;
}
int main(){
    vector<int>v1={9,9,9,9,9,9,9};
    ListNode* Head1=convert_Arr_2_LL(v1);
    vector<int>v2={9,9,9,9};
    ListNode* Head2=convert_Arr_2_LL(v2);
    ListNode* Sum=Add_2_nos(Head1,Head2);
    printList(Sum);
}