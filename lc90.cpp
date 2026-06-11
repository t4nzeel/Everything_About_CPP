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
ListNode* merger2SortedList(ListNode* l1,ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->val <= l2->val){
        l1->next=merger2SortedList(l1->next,l2);
        return l1;
    }
    else{
        l2->next=merger2SortedList(l1,l2->next);
        return l2;
    }
    return NULL;
}
ListNode* partAndMerge(int start,int end,vector<ListNode*>&lists){
    if(start>end) return NULL;
    if(start==end) return lists[start];
    int mid=start+((end-start)/2);
    ListNode* l1=partAndMerge(start,mid,lists);
    ListNode* l2=partAndMerge(mid+1,end,lists);
    return merger2SortedList(l1,l2);
}
ListNode* mergeKLists(vector<ListNode*>& lists){
    int k=lists.size();
    if(k==0) return NULL;
    return partAndMerge(0,k-1,lists);
}
ListNode* createLL(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}
void printLL(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main(){
    vector<ListNode*> lists;

    lists.push_back(createLL({1, 4, 5}));
    lists.push_back(createLL({1, 3, 4}));
    lists.push_back(createLL({2, 6}));

    // Merge all lists
    ListNode* result = mergeKLists(lists);

    // Print result
    printLL(result);
}