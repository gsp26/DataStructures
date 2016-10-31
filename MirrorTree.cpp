#include<iostream>

using namespace std;


struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * insert(struct node * root,int data)
{
    if(root == NULL)
    {
        struct node * temp = new struct node;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else
    {
        //insert in binary fashion 
        struct node * temp = root;
        struct node * prev = temp;
        while(temp != NULL)
        {
            prev = temp;
            if(temp->data < data)
                temp = temp->right;
            else
                temp = temp->left;
        }
        struct node * t1 = new struct node;
        t1->data = data;
        t1->left = NULL;
        t1->right = NULL;
        if(prev->data < data)
            prev->right = t1;
        else
            prev->left = t1;

        return root;
    }
}

void display(struct node * root)
{
    //Inorder display of tree
    if(root == NULL)
        return;

    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

void swapChilds(struct node * root)
{
    struct node * temp = root->left;
    root->left = root->right;
    root->right = temp;
}


void mirrorImage(struct node * root)
{
    if(root->left == NULL && root->right == NULL)
        return;

     mirrorImage(root->left);
     swapChilds(root);
     mirrorImage(root->left);
}


int main()
{
    cout << "program to print mirror image of a tree >>>> " << endl;

    struct node * root;
    root = insert(root,30);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,50);
    root = insert(root,10);
    root = insert(root,35);
    root = insert(root,25);

    display(root);
    cout << "\n\nMirror Image of this tree>>\n" << endl;
    mirrorImage(root);
    display(root);


    cout << "\n\n" << endl;

    return 0;
}


    


