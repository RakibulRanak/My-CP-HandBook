#include<bits/stdc++.h>
using namespace std;


struct node {
    int val;
    node* next;
    node():val(0), next(nullptr) {}
    node(int x): val(x), next(nullptr) {}
    node(int x, node* next): val(x), next(next) {}
};

void printList(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
// here head changes, so updated head address is returned
void insertAtFirstRef(node** head, int val)
{
    //head is the own address of the variable "head" and *head is the address pointer it points
    // in this way, *head = head for other functions without address passing
    *head = new node(val, *head);
}
node* insertAtFirst(node* head, int val)
{
    return new node(val, head);
}

void insertAtLast(node* head, int x)
{
    if (head == NULL)
    {
        cout << "List is empty!! Insert at first" << endl;
        return;
    }
    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node* cur = new node(x);
    temp->next = cur;
}
// if reference of a node is given
void insertAfterANode(node* givenNode, int val)
{
    node* temp = new node(val);
    temp->next = givenNode->next;
    givenNode->next = temp;
}

node* insertNth(int val, int position, node* head) {
    //create new node.
    node* temp = new node(val);

    if (head == NULL) {
        //if head is null and position is zero then exit.
        if (position != 0)
            return NULL;
        else  //node set to the head.
            return temp;
    }

    if (head != NULL && position == 0)
        return new node(val, head);

    node* current = head;
    node* previous = NULL;

    int i = 0;
    while (i < position) {
        previous = current;
        current = current->next;
        if (current == NULL)
            break;
        i++;
    }
    if (i == position) {
        temp->next = current;
        previous->next = temp;
    }
    return head;
}
//update a index or replace a value is easy
//delete
void deleteNodeAtInd(int ind, node** head)
{
    if (ind == 0)
        *head = (*head)->next;
    node* temp = *head;
    int i = 0;
    while (i + 1 < ind)
    {
        temp = temp->next;
        i++;
    }
    temp->next = temp->next->next;
}
void deleteFromLast(node* head)
{
    node* temp = head;
    if (temp->next == NULL)
    {
        cout << "Delete from first please!"; // see the immediate above function ind == 0
        return;
    }
    //at least 2 items
    while (temp->next->next != NULL)
        temp = temp->next;
    temp->next = NULL;
}
void updateAt(node* head, int ind, int val)
{
    node* temp = head;
    int i = 0;
    while (i < ind)
    {
        temp = temp->next;
        i++;
    }
    temp->val = val;
}

int main()
{
    node* head = NULL;
    insertAtLast(head, 3);
    head = insertAtFirst(head, 3);
    head = insertAtFirst(head, 2);
    insertAtLast(head, 4);
    head = insertNth(10, 0, head);
    head = insertNth(10, 0, head);
    insertAtFirstRef(&head, 3);
    printList(head);
    deleteNodeAtInd(2, &head);
    deleteFromLast(head);
    printList(head);
    updateAt(head, 3, 100);
    printList(head);
}