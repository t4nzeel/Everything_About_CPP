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
int Add_Helper(ListNode* temp){
    if(temp==NULL) return 1;
    int carry=Add_Helper(temp->next);
    temp->val+=carry;
    if(temp->val<10) return 0;
    temp->val=0;
    return 1;
}
ListNode* Add_One(ListNode* head){
    int carr=Add_Helper(head);
    if(carr==1){
        ListNode* newNode=new ListNode(1);
        newNode->next=head;
        head=newNode;
    }
    return head;
}
int main(){
    vector<int>v={4,5,6};
    ListNode* Head=convert_Arr_2_LL(v);
    ListNode* Head1=Add_One(Head);
    printList(Head1);
}