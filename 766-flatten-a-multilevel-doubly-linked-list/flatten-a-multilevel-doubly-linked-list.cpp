class Solution {
public:

    Node* flatten(Node* head) {
        if (head == nullptr)
            return nullptr;

        flattenAndGetTail(head);

        return head;
    }

    Node* flattenAndGetTail(Node* head) {

        Node* curr = head;
        Node* last = head;

        while (curr != nullptr) {

            Node* next = curr->next;

            // Agar child hai
            if (curr->child != nullptr) {

                Node* child = curr->child;

                // Child list ko recursively flatten karo
                Node* childTail = flattenAndGetTail(child);

                // curr -> child
                curr->next = child;
                child->prev = curr;

                // child pointer hata do
                curr->child = nullptr;

                // child ka tail -> original next
                childTail->next = next;

                if (next != nullptr) {
                    next->prev = childTail;
                }

                last = childTail;
            }
            else {
                last = curr;
            }

            curr = next;
        }

        return last;
    }
};