#include<iostream>
#include<queue>

using namespace std;

struct node
{
    int data;
    struct node * left;
    struct node * right;
};


struct node * newNode(int data)
{
    struct node * temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
}

struct node * insert(struct node * root,int data)
{
    if(root == NULL)
    {
        struct node * temp = newNode(data);
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    struct node *temp = root;
    struct node * prev = NULL;
    while(temp!=NULL)
    {
        prev = temp;
        if(data > temp->data)
            temp = temp->right;
        else
            temp = temp->left;
    }
    struct node * t1 = newNode(data);
    if(prev->data > data)
        prev->left = t1;
    else
        prev->right = t1;

    return root;
}


void inorderTraverssal(struct node* root)
{
    if(root == NULL)
        return;

    inorderTraverssal(root->left);
    cout << root->data << " ";
    inorderTraverssal(root->right);

}

void levelOrderTraversal(struct node *root)
{
    queue<struct node*> tq;
    tq.push(root);
    while(!tq.empty())
    {
        struct node * temp = tq.front();
        tq.pop();
        if(temp->left != NULL)
            tq.push(temp->left);
        if(temp->right != NULL)
            tq.push(temp->right);
        cout << temp->data << " ";
    }

    cout << "\n\n";
}

int height(struct node * root)
{
    if(root == NULL)
        return 0;
    else
    {
        //compute height of each subtree 
        int lheight = height(root->left);
        int rheight = height(root->right);

        //use the larger one
        if(lheight > rheight)
            return lheight +1;
        else
            return rheight+1;
    }
}

void printGivenLevel(struct node* root,int level)
{
    if(root == NULL)
        return;
    if(level == 1)
        cout << root->data << " ";
    else if(level > 1)
    {
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}


void printLevelOrder(struct node * root)
{
    int h = height(root);
    for(int i=1;i<=h;i++)
        printGivenLevel(root,i);
}





int main()
{
    cout << "Level order Traversal >>>> " << endl;

    struct node* tree;
    tree = insert(tree,10);
    tree = insert(tree,11);
    tree = insert(tree,12);
    tree = insert(tree,8);
    tree = insert(tree,9);
    tree = insert(tree,2);
    tree = insert(tree,13);
    tree = insert(tree,70);

    inorderTraverssal(tree);

    cout << "\n\n" << endl;
    cout << "Level order of this tree -- " << endl;
    levelOrderTraversal(tree);

    cout << "Level order of this tree without using queue-- " << endl;
    printLevelOrder(tree);
    cout << "\n\n" << endl;

    return 0;

}




