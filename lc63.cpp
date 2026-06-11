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
/*int check_Palindrome(int x){
    int c=x;
    int s=0;
    while(c>0){
        int r=c%10;
        s=(s*10)+r;
        c=c/10;
    }
    return s;
}
bool isPalindrome(ListNode* head){
    ListNode* temp=head;
    int s1=0;
    while(temp){
        s1=(s1*10)+(temp->val);
        temp=temp->next;
    }
    if(s1==check_Palindrome(s1)) return true;
    return false;
}*/
ListNode* reverse_LL(ListNode* head){
    ListNode* prev=NULL;
    ListNode* temp=head;
    while(temp){
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
bool isPalindrome(ListNode* head){
    if(head==NULL || head->next==NULL) return true;
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* NewHead=reverse_LL(slow->next);
    ListNode* first=head;
    ListNode* second=NewHead;
    while(second){
        if(first->val!=second->val){
            reverse_LL(NewHead);
            return false;
        }
        second=second->next;
        first=first->next;
    }
    reverse_LL(NewHead);
    return true;
}
int main(){
    vector<int>v={1,3,3,1};
    ListNode* Head=convert_Arr_2_LL(v);
    if(isPalindrome(Head)) cout<<"Yes";
    else cout<<"No";
}