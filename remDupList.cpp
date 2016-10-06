#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node * next;
};

struct Node * insert(struct Node* root, int data)
{
    if(root == NULL)
    {
        struct Node * temp = new Node;
        temp->data = data;
        temp->next = NULL;
        return temp;
    }
    else
    {
        if(data <= root->data)
        {
                struct Node * t1 = new Node;
                t1->data = data;
                t1->next = root;
                root = t1;
                return root;
        }
        else
        {
            struct Node * prev = root;
            struct Node * temp = root->next;
            while(temp!=NULL)
            {
                if(data <= temp->data )
                {
                    struct Node * t1 = new Node;
                    t1->data = data;
                    t1->next = temp;
                    prev->next = t1;
                    break;
                }
                else
                {
                    prev = temp;
                    temp = temp->next;
                }
            }
            if(temp == NULL)
            {
                struct Node * t1 = new Node;
                t1->data = data;
                t1->next = NULL;
                prev->next = t1;
            }
            return root;
        }
    }
}

void printList(struct Node * root)
{
    struct Node * temp = root;
    while(temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << "\n" << endl;
}
struct Node * remDup(struct Node * root)
{
    if(root == NULL && root->next == NULL)
        return root;

    struct Node * prev = root;
    struct Node * start = NULL;
    struct Node * temp = root->next;
    int x = prev->data;
    while(temp != NULL)
    {
        if(x == temp->data)
        {
            struct Node * t1 = temp->next;
            delete temp;
            if(prev == start)
                start = NULL;
            delete prev;
            if(start)
                start->next = NULL;
            prev = NULL;
            temp = t1;
        }
        else
        {
            if(start == NULL && prev != NULL)
            {
                start = prev;
            }
            else if( prev == NULL && start == NULL)
            {
                start = temp;
            }
            else if(start->next == NULL)
                start->next = temp;
            else
            {
                struct Node * n1 = start->next;

                while(n1->next != NULL)
                    n1 = n1->next;

                n1->next = temp;
            }
            prev = temp;
            x = temp->data;
            temp = temp->next;
        }
    }
    return start;
}
            



int main()
{
    cout << "Linked list in sorted order with duplicates>>>>>>" <<endl;
    struct Node * root = NULL;
    root = insert(root,10);
    root = insert(root,40);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,20);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,40);
    root = insert(root,45);
    root = insert(root,45);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,50);
    root = insert(root,47);
    root = insert(root,47);
    root = insert(root,47);
    root = insert(root,47);
    root = insert(root,55);
    root = insert(root,55);
    root = insert(root,55);

    printList(root);
    root = remDup(root);
    cout << "After Removing Dups >>  " << endl;
    printList(root);



    return 0;
}



