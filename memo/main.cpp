
// C++ program to find the second last node
// of a linked list in single traversal
 
#include <iostream>
using namespace std;
 
// Link list node
struct Node {
    int data;
    struct Node* next;
};
 
// Function to find the second last
// node of the linked list
Node findSecondLastNode(struct Node* head)
{
    struct Node* temp = head;
 
    // If the list is empty or contains less
    // than 2 nodes
    if (temp == NULL || temp->next == NULL)
        // return -1;
 
    // Traverse the linked list
    while (temp != NULL) {
 
        // Check if the current node  is the
        // second last node or not
        if (temp->next->next == NULL)
            return *temp;
 
        // If not then move to the next node
        temp = temp->next;
    }
}
 
// Function to push node at head
void push(struct Node** head_ref, int new_data)
{
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
// Driver code
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    /* Use push() function to construct
    the below list 8 -> 23 -> 11 -> 29 -> 12 */
    push(&head, 12);
    push(&head, 29);
    push(&head, 11);
    push(&head, 23);
    push(&head, 8);
 
    cout << findSecondLastNode(head).data << endl;
 
    return 0;
}