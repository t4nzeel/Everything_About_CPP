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
ListNode* deleteAlloccurences(ListNode* head,int k){
    ListNode* temp=head;
    while(temp){
        if(temp->val==k){
            if(temp==head){
                head=head->next;
            }
            ListNode* nextNode=temp->next;
            ListNode* prevNode=temp->prev;
            if(nextNode!=NULL) nextNode->prev=prevNode;
            if(prevNode) prevNode->next=nextNode;
            free(temp);
            temp=nextNode;
        }
        else temp=temp->next;
    }
    return head;
}
int main(){
    vector<int>v={1,2,3,4,1};
    ListNode* Head=convert_Arr_2_DLL(v);
    int x;
    cout<<"Enter no.  to be deleted : ";
    cin>>x;
    ListNode* Head1=deleteAlloccurences(Head,x);
    printList(Head1);
}