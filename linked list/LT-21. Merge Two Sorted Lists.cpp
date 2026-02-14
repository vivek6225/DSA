
// T.C: O(n + m)
// S.C: O(n + m)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {

        // Base case:
        // Agar koi ek list NULL ho jaye,
        // to dusri list ko directly return kar do (kyunki wo already sorted hai)
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }

        // Case 1:
        // Agar head1 ka value chhota ya equal hai,
        // to head1 ko result ka part banao
        if (head1->val <= head2->val) {

            // head1 ke next ko merge karo baaki lists ke saath
            head1->next = mergeTwoLists(head1->next, head2);

            // head1 ko merged list ka head bana ke return karo
            return head1;
        } 
        // Case 2:
        // Agar head2 ka value chhota hai,
        // to head2 ko result ka part banao
        else {

            // head2 ke next ko merge karo baaki lists ke saath
            head2->next = mergeTwoLists(head1, head2->next);

            // head2 ko merged list ka head bana ke return karo
            return head2;
        }
    }
};