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
ListNode* oddEvenList(ListNode* head){
    /*if(!head) return NULL; 
    if(!head->next) return head;
    int cnt=3;
    ListNode* Odd=new ListNode(head->val);
    ListNode* temp1=head->next;
    ListNode* temp2=Odd;
    ListNode* Even=new ListNode(head->next->val);
    ListNode* temp3=head->next->next;
    ListNode* temp4=Even;
    while(temp3){
        if(cnt%2!=0){
            temp2->next=new ListNode(temp3->val);
            temp2=temp2->next;
        }
        else{
            temp4->next=new ListNode(temp3->val);
            temp4=temp4->next;
        }
        temp3=temp3->next;
        cnt++;
    }
    temp2->next=Even;
    return Odd;*/
    if(head==NULL || head->next==NULL) return head;
    ListNode* odd=head;
    ListNode* even=head->next;
    ListNode* evenHead=head->next;
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
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
    ListNode* Head1=oddEvenList(Head);
    printList(Head1);
}