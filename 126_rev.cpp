#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
void pus(node **head, int val)
{
    node *temp = new node();
    temp->data = val;
    temp->next = *head;
    *head = temp;
}

void reverse(node **head)
{
    node *prev = NULL, *curr = *head, *next = curr->next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

node *rev(node **head, node *prev)
{
    if (*head == NULL)
    {
        return prev;
    }
    node *t = rev(&((*head)->next), *head);
    (*head)->next = prev;
    return t;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    node *head = NULL;
    int n;
    cin >> n;
    cout << "tim " << n << "\n";
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        pus(&head, t);
    }
    print(head);
    reverse(&head);
    cout << "rev\n";
    print(head);
    head = rev(&head, NULL);
    cout << "rec rev\n";
    print(head);
    return 0;
}
