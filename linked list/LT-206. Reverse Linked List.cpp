/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 class Solution {
  public:
      
      // ✅ 1st Method: Recursive
      ListNode* ReverseRecursive(ListNode* curr, ListNode* prev) {
          if (curr == NULL) return prev;
          ListNode* fut = curr->next;
          curr->next = prev;
          return ReverseRecursive(fut, curr);
      }
  
      // ✅ 2nd Method: Iterative
      ListNode* ReverseIterative(ListNode* head) {
          ListNode* curr = head;
          ListNode* prev = NULL;
          ListNode* fut = NULL;
  
          while (curr != NULL) {
              fut = curr->next;
              curr->next = prev;
              prev = curr;
              curr = fut;
          }
  
          return prev;  // New head
      }
  
      // Choose which method you want to use
      ListNode* reverseList(ListNode* head) {
          // return ReverseRecursive(head, NULL);
          return ReverseIterative(head);
      }
  };