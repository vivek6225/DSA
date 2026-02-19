
//T.C. = O(N log k)
//S.C. = O(K)
class Solution {
  public:
     
    Node* merge(Node* head1, Node* head2) {
        // Base case: agar koi ek NULL ho jaaye
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }

        // Agar head1 chhota/equal hai
        if (head1->data <= head2->data) {
            head1->bottom = merge(head1->bottom, head2);
            return head1;
        }
        // Warna head2 chhota hai
        else {
            head2->bottom = merge(head1, head2->bottom);
            return head2;
        }
    }

    Node* flatten(Node* root) {

        if (root == NULL || root->next == NULL)
            return root;

        Node *head1, *head2, *head3;

        while (root->next) {
            head1 = root;
            head2 = root->next;
            head3 = root->next->next;

            // next pointers ko tod do (flatten me kaam nahi aate)
            head1->next = NULL;
            head2->next = NULL;

            // Do lists merge karo
            root = merge(head1, head2);

            // Baaki lists ko wapas jod do
            root->next = head3;
        }

        return root;
    }
};
