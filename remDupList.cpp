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

    struct Node * prev = NULL;
    struct Node *t1 = NULL;
    struct Node *t2 = NULL;
    struct Node *lu = NULL;
    struct Node *newRoot = NULL;;
    struct Node *temp = root;;
    if(temp->next == NULL)
        return temp;
    while(temp != NULL)
    {
        if(temp->next != NULL)
        {
            if(temp->data == temp->next->data)
            {
                t1 = temp->next->next;
                int x = temp->data;
                delete temp->next;
                delete temp;
                while(t1 != NULL)
                {
                    if(t1->data == x)
                    {
                        t2 = t1->next;
                        delete t1;
                        t1 = t2;
                    }
                    else
                        break;
                }
                temp = t1;
            }
            else
            {
                if(newRoot == NULL)
                {
                    newRoot = temp;
                    //newRoot->next = temp->next;
                }
                if(lu != NULL)
                    lu->next = temp;
                lu = temp;
                temp = temp->next;
            }
        }
        else
            break;
    }
    if(lu != NULL)
        lu->next = NULL;
    return newRoot;

}




int main()
{
    cout << "Linked list in sorted order with duplicates>>>>>>" <<endl;
    struct Node * root = NULL;
    root = insert(root,2);
    root = insert(root,3);
    root = insert(root,8);
    root = insert(root,8);
    root = insert(root,10);
    root = insert(root,11);
    root = insert(root,11);
    root = insert(root,12);
    root = insert(root,15);
    root = insert(root,18);
    root = insert(root,19);

    printList(root);
    root = remAllDups(root);
    cout << "After Removing Dups >>  " << endl;
    printList(root);



    return 0;
}



