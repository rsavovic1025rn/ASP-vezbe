#include <bits/stdc++.h>
using namespace std;
struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while(curr != nullptr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(left==right)return head;
    ListNode* tailbegin = nullptr;
    ListNode* headmiddle = nullptr;
    ListNode* tailmiddle = nullptr;
    ListNode* headend = nullptr;
    ListNode* tail = head;
    int i = 1;
    while(tail!=nullptr){
        if(i==left-1){
            tailbegin = tail;
            tail = tail->next;
            i++;
            continue;
        }
        if(i==left){
            headmiddle = tail;
            tailmiddle = tail;
            tail = tail->next;
            i++;
            continue;
        }
        if(i==right){
            tailmiddle = tail;
            ListNode* sledeci = tail->next;
            tail->next = nullptr;
            tail = sledeci;
            i++;
            continue;
        }
        if(i==right+1){
            headend = tail;
            break;
        }
        tail = tail->next;
        i++;
    }
    if(tailbegin==nullptr){
        reverseList(headmiddle);
        headmiddle->next = headend;
        return tailmiddle;
    }
    tailbegin->next = reverseList(headmiddle);
    headmiddle->next = headend;
    return head;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head==nullptr || k==0)return head;
    int size = 0;
    ListNode* curr = head;
    while(curr!=nullptr){
        size++; curr = curr->next;
    }
    k%=size; k = size - k;
    if(k==0 || k==size)return head; //hocu da rotiram u levo,
    curr = head;
    int i = 0;
    ListNode* prev = nullptr;
    while(i<k){
        prev = curr;
        curr = curr->next;
        i++;
    }
    ListNode* tail = curr;
    ListNode* kth = tail;
    prev->next = nullptr;
    while(tail->next!=nullptr)tail=tail->next;
    tail->next = head;
    return kth;
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head;
    while(curr!=nullptr){
        ListNode* next = curr->next;
        while(next!=nullptr and next->val == curr->val){
            next = next->next;
        }
        curr->next = next;
        curr = next;
    }
    return head;
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* newhead = nullptr;
    ListNode* tail = nullptr;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr!=nullptr){
        bool ok1 = true;
        bool ok2 = true;
        if(prev != nullptr && prev->val == curr->val)ok1=false;
        if(curr->next != nullptr && curr->next->val == curr->val)ok2 = false;
        if(ok1 && ok2){
            if(newhead == nullptr){
                newhead = curr;
                tail = curr;
            }
            else{
                tail->next = curr;
                tail = curr;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    if(tail)tail->next = nullptr;
    return newhead;
}

bool isPalindrome(ListNode* head) {
    int n = 0;
    ListNode* curr = head;
    while(curr){
        n++;
        curr = curr->next;
    }
    curr = head;
    int i = 0;
    ListNode* head1 = nullptr;
    while(i<n/2){
        curr = curr->next;
        i++;
    }
    if(n%2)head1 = curr->next;
    else head1 = curr;
    head1 = reverseList(head1);
    i = 0;
    while(i<n/2){
        if(head->val != head1->val)return false;
        head = head->next;
        head1 = head1->next;
        i++;
    }
    return true;
}

ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next==nullptr)return head;
    ListNode* curr = head->next->next;
    ListNode* head1 = head->next;
    head1->next = head;
    head->next = nullptr;
    ListNode* tail = head;

    while(curr != nullptr && curr->next != nullptr){
        ListNode* sledeci = curr->next->next;
        tail->next = curr->next;
        tail->next->next = curr;
        tail = curr;
        curr = sledeci;
    }
    tail->next = curr;
    return head1;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = nullptr;
    if(list1==nullptr)return list2;
    if(list2==nullptr)return list1;
    if(list1->val < list2->val){
        head = list1;
        list1 = list1->next;
    }
    else{
        head = list2;
        list2 = list2->next;
    }
    ListNode* tail = head;
    while(list1 && list2){
        if(list1->val < list2->val){
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
        }
        else{
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
        }
    }
    while(list1){
        tail->next = list1;
        tail = tail->next;
        list1 = list1->next;
    }
    while(list2){
        tail->next = list2;
        tail = tail->next;
        list2 = list2->next;
    }
    return head;
}

ListNode* partition(ListNode* head, int x) {
    if(head==nullptr)return nullptr;
    ListNode* headless = nullptr;
    ListNode* headbigger = nullptr;
    ListNode* tailless = nullptr;
    ListNode* tailbigger = nullptr;
    ListNode* curr = head;
    while(curr){
        if(curr->val < x){
            if(headless == nullptr){
                headless = curr;
                tailless = curr;
            }
            else{
                tailless->next = curr;
                tailless = curr;
            }

        }
        else{
            if(headbigger == nullptr){
                headbigger = curr;
                tailbigger = curr;
            }
            else{
                tailbigger->next = curr;
                tailbigger = curr;
            }
        }
        curr = curr->next;
    }
    if(tailless==nullptr){
        return headbigger;
    }
    if(headbigger == nullptr){
        tailless->next = nullptr;
        return headless;
    }
    tailless->next = headbigger;
    tailbigger->next = nullptr;
    return headless;
}

int main() {
    //liste
}