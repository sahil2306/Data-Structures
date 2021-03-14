1) Detect Cycle : https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return NULL;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        do{
            if(fast->next==NULL || fast->next->next==NULL){
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
        }while(slow!=fast);
        
        fast = head;
        
        int count=0;
        
        if(slow==fast){
            return fast;
        }
        
        while(slow->next!=fast->next){
            count++;
            slow = slow->next;
            fast = fast->next;
        }
        return fast->next;
    }
};

2) Return the node where the cycle begins : https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return NULL;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        do{
            if(fast->next==NULL || fast->next->next==NULL){
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
        }while(slow!=fast);
        
        fast = head;
        
        int count=0;
        
        if(slow==fast){
            return fast;
        }
        
        while(slow->next!=fast->next){
            count++;
            slow = slow->next;
            fast = fast->next;
        }
        return fast->next;
    }
};