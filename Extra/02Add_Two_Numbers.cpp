/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored
in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as
a linked list.
*/
#include<iostream>


 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode * l){
    ListNode* temp = l;

    while (temp != nullptr)
    {
        std::cout<<temp->val<<"  ";
        temp = temp->next;
    }
    std::cout<<std::endl;;
}
ListNode * reverse(ListNode * l){
    if(l == nullptr || l->next == nullptr ){
        return l;
    }
    ListNode * newHead = reverse(l->next);
    l->next->next = l;
    l->next = nullptr;
    return newHead;

}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode * ans= nullptr;
    int sum = 0 ;
    int carry = 0 ;
    int count = 0 ;
    while(l1 != nullptr && l2 != nullptr){
        sum = carry + l1->val + l2->val ;
        carry = sum / 10;
        sum = sum>=10 ? sum%10 : sum ;
        ans = new ListNode(sum,ans);
        l1 = l1->next;
        l2 = l2->next;
        count++;
    }
    while(l1 != nullptr){
        sum = carry + l1->val;
        carry = sum / 10;
        sum = sum>=10 ? sum%10 : sum ;
        ans = new ListNode(sum,ans);
        l1 = l1->next;
    }
    while(l2 != nullptr){
        sum = carry + l2->val;
        carry = sum / 10;
        sum = sum>=10 ? sum%10 : sum ;
        ans = new ListNode(sum,ans);
        l2 = l2->next;
    }
    if(carry != 0 ){
        ans = new ListNode(carry,ans);
    }
    return reverse(ans);

}

int main(){
    ListNode *n1 = new ListNode(4);
   // n1 = new ListNode(3,n1);
    // n1 = new ListNode(3,n1);
    // n1 = new ListNode(4,n1);
    // n1 = new ListNode(5,n1);
    ListNode *n2 = new ListNode(2);
    //n2 = new ListNode(9,n2);
    // n2 = new ListNode(8,n2);
    auto c = addTwoNumbers(n1,n2);
    print(n1);
    print(n2);
    print(c);

    std::cout<<"Working.";
    return 0 ;
}
