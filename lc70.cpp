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
/*int no_of_nodes(ListNode* temp1){
    int c=0;
    while(temp1){
        temp1=temp1->next;
        c++;
    }
    return c;
}
ListNode* reverseNodes(ListNode* head){
    ListNode* temp=head;
    ListNode* prev=NULL;
    while(temp){
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}*/
ListNode* Find_Nth_node(ListNode* temp,int k){
    int c=1;
    while(temp){
        if(c==k) return temp;
        c++;
        temp=temp->next;
    }
    return temp;
}
ListNode* rotateRight(ListNode* head, int k){
    /*if (!head || !head->next || k == 0) return head;
    ListNode* temp=head;
    int c=1;
    int count=no_of_nodes(head);
    k=k%count;
    if (k == 0) return head;
    while(c!=(count-k)){
        temp=temp->next;
        c++;
    }
    ListNode* nextNode=temp->next;
    temp->next=NULL;
    head=reverseNodes(head);
    nextNode=reverseNodes(nextNode);
    ListNode* temp2=head;
    while(temp2->next){
        temp2=temp2->next;
    }
    temp2->next=nextNode;
    head=reverseNodes(head);
    return head;*/
    if(head==NULL || head->next==NULL || k==0) return head;
    ListNode* tail=head;
    int len=1;
    while(tail->next){
        len++;
        tail=tail->next;
    }
    if(k%len==0) return head;
    k=k%len;
    tail->next=head;
    ListNode* newLastNode=Find_Nth_node(head,len-k);
    head=newLastNode->next;
    newLastNode->next=NULL;
    return head;
}
int main(){
     vector<int>v={1,2,3,4,5};
    ListNode* Head=convert_Arr_2_LL(v);
    int k;
    cout<<"Enter k = ";
    cin>>k;
    ListNode* Head1=rotateRight(Head,k);
    printList(Head1);
}