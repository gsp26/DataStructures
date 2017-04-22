#include<iostream>
#include<stack>

using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
};

void  insertBST(node ** root,int data)
{
    if(*root == NULL)
    {
        node * temp = new node;
        temp->left = NULL;
        temp->right = NULL;
        temp->data = data;
        *root = temp;
        return;
    }
    node * temp = *root;
    node * prev;
    while(temp != NULL)
    {
        prev = temp;
        if ( temp->data < data)
            temp = temp->right;
        else
            temp = temp->left;
    }
    node * t1 = new node;
    t1->left = NULL;
    t1->right = NULL;
    t1->data = data;
    if(prev->data < data)
        prev->right = t1;
    else
        prev->left = t1;

}

void inOrder(node * root)
{
    if(root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void inOrderWR(node * root)
{
    node *current = root;
    if(current == NULL)
        return ;
    stack<node *> st;
    st.push(current);
    current = current->left;
    while(!st.empty())
    {
        if(current != NULL)
        {
            st.push(current);
            current = current->left;
        }
        else
        {
            current = st.top();
            cout << current->data << " ";
            current = current->right;
            st.pop();
            if(current)
            {
                st.push(current);
                current = current->left;
            }
        }

    }
}




int main()
{
    cout << "Inorder traversal without Recursion >>>> "  << endl;
    node * tree = NULL;
    insertBST(&tree,10);
    insertBST(&tree,11);
    insertBST(&tree,12);
    insertBST(&tree,14);
    insertBST(&tree,1);
    insertBST(&tree,9);
    insertBST(&tree,6);
    insertBST(&tree,3);
    insertBST(&tree,2);
    insertBST(&tree,4);
    insertBST(&tree,5);
    insertBST(&tree,7);
    cout << "\nINORDER traversal with recursion >>>> " << endl;
    inOrder(tree);
    cout << "\nINORDER traversal without recursion >>>> " << endl;
    inOrderWR(tree);
    cout << "\n\n";

    return 0;
}
