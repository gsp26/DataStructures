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
    if(root == NULL)
        return root;

    int x = root->data;
    struct Node *temp ;
    temp = root->next;
    struct Node * prev = root;
    struct Node * t1 = NULL;
    while(temp != NULL)
    {
        if(x == temp->data)
        {
            t1 = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete t1;
        }
        else
        {
            prev = temp;
            x = temp->data;
            temp = temp->next;
        }
    }
    return root;

}

struct Node * remAllDups(struct Node * root)
{
    if(root == NULL)
        return root;

    int x = root->data;
    struct Node * temp = root->next;
    struct Node * newRoot = NULL;
    struct Node * prev, *t1 *lu;
    prev = root;
    while(temp != NULL)
    {
        if(x == temp->data)
        {
            if(newRoot == NULL || newRoot == temp || newRoot->data == temp->data)
            {
                newRoot = temp->next;
                delete prev;
                prev = NULL;
            }
            t1 = temp->next;
            delete temp;
            delete prev;
            temp = t1;
            if(lu != NULL)
                lu->next = temp;
        }
        else
        {
            if(prev == NULL)
            {
                x = temp->data;
                prev = temp;
                temp = temp->next;
            }
            else
            {
                x = temp->data;
                lu = prev;
                prev->next = temp;
                prev = temp;
                temp = temp->next;
            }
        }
    }
    return newRoot;

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



