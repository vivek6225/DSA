/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



// Time Complexity: O(n)
// Space Complexity: O(1)

//1. first check cycle.
// Move slow by 1 step and fast by 2 steps in a loop.

//2.if cycle is exit
//3. reset slow = head
// 4.Move both slow and fast one step at a time.
// the node where they meet again is in the start of cycle 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast = head,*slow = head;
          bool iscycle = false;
        while(fast != NULL && fast -> next != NULL){
            slow = slow->next;
            fast = fast->next->next;
          
            if(slow == fast ){
                iscycle = true;
                break;
                
            }
        }
       
        if(!iscycle){
            return NULL;
        }
         slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
        
        
    }
};