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
ListNode* reverse_subNodes(ListNode* t2){
    ListNode* prev=NULL;
    while(t2){
        ListNode* front=t2->next;
        t2->next=prev;
        prev=t2;
        t2=front;
    }
    return prev;
}
ListNode* find_Kth_Node(ListNode* temp,int k){
    k-=1;
    while(k>0 && temp!=NULL){
        k--;
        temp=temp->next;
    }
    return temp;
}
ListNode* reverseKGroup(ListNode* head,int k){
    ListNode* temp=head;
    ListNode* prevLast=NULL;
    while(temp){
        ListNode* KthNode=find_Kth_Node(temp,k);
        if(KthNode==NULL){
            if(prevLast) prevLast->next=temp;
            break;
        }
        ListNode* nextNode=KthNode->next;
        KthNode->next=NULL;
        reverse_subNodes(temp);
        if(temp==head){
            head=KthNode;
        }
        else{
            prevLast->next=KthNode;
        }
        prevLast=temp;
        temp=nextNode;
    }
    return head;
}
int main(){
    vector<int>v={1,2,3,4,5};
    ListNode* Head=convert_Arr_2_LL(v);
    int k;
    cout<<"Enter k = ";
    cin>>k;
    ListNode* Head1=reverseKGroup(Head,k);
    printList(Head1);
}