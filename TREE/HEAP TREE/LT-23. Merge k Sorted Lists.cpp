//----------------Better Approach-------------------------------
// T.C = O(N log k)
// S.C = O(log k)
class Solution {
public:
    // Merge two sorted linked lists
    ListNode* mergeTwo(ListNode* head1, ListNode* head2) {
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }

        if (head1->val <= head2->val) {
            head1->next = mergeTwo(head1->next, head2);
            return head1;
        } else {
            head2->next = mergeTwo(head1, head2->next);
            return head2;
        }
    }

    // Divide & Conquer merge from index start to end
    ListNode* mergeRange(vector<ListNode*>& lists, int start, int end) {
        if (start > end) return NULL;        // no list
        if (start == end) return lists[start]; // single list

        int mid = start + (end - start) / 2;

        ListNode* left = mergeRange(lists, start, mid);
        ListNode* right = mergeRange(lists, mid + 1, end);

        return mergeTwo(left, right);        // merge two halves
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return NULL;

        return mergeRange(lists, 0, n - 1);
    }
};
//----------------Brute force approach-------------------------------
//T.C = O(N * k)
//S.C = O(N)

class Solution {
public:
    // Merge two sorted linked lists (recursive)
    ListNode* merge(ListNode* head1, ListNode* head2) {
        // Base case
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }

        // Choose smaller node and recurse
        if (head1->val <= head2->val) {
            head1->next = merge(head1->next, head2);
            return head1;   // return current head of merged list
        } else {
            head2->next = merge(head1, head2->next);
            return head2;   // return current head of merged list
        }
    }

    // Merge K sorted lists one by one
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;

        ListNode* head = NULL;

        // Pairwise merge: merge current result with each list
        for (int i = 0; i < lists.size(); i++) {
            head = merge(head, lists[i]);
        }

        return head;
    }
};