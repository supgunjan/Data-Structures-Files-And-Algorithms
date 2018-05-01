#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;
class node
{
public:
    int data;
    node *left,*right;
    node()
    {
        left=right=NULL;
    }
    node(int x)
    {
        data=x;
        left=right=NULL;
    }
};

class BST
{
public:
    node *create();
    node* insert1(node *root,int a);
    int search1(node *root,int a);
    node *mirror(node *root);
    node *inordersucc(node *root)
    {
        node *p=root;
        while(p->left!=NULL)
            p=p->left;
        return p;
    }

    void print(node *root);
    node *delete1(node *root,int a);
};
node* BST::insert1(node *root,int a)
{
    node *p,*q,*r;
    p=new node(a);
    if(root==NULL)
    {
        root=p;
        return root;
    }
    q=root;
    while(q!=NULL)
    {
        r=q;
        if(a>q->data)
            q=q->right;
        else
            q=q->left;
    }
    if(a>r->data)
        r->right=p;
    else
        r->left=p;
    return root;
}
node *BST::create()
{
    node *root;
    int n,i,j;
    root=NULL;
    cout<<"\nEnter the no. of nodes: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter the value of node "<<i+1<<" :";
        cin>>j;
        root=insert1(root,j);
    }
    return root;
}
node *BST::mirror(node *root)
{
    node *p,*q;
    p=root;
    if(p!=NULL)
    {
        q=p->left;
        p->left=mirror(p->right);
        p->right=mirror(q);
    }
    return root;
}
void BST::print(node *root)
{
    int i,j;
    queue<node *>b;
    node *p;
    b.push(root);
    while(!b.empty())
    {
        i=b.size();
        while(i--)
        {
            p=b.front();
            b.pop();
            if(p->left!=NULL)
                b.push(p->left);
            if(p->right!=NULL)
                b.push(p->right);
            cout<<p->data<<" ";
        }
    }
}
int BST::search1(node *root,int a)
{
    node *p=root;
    while(p!=NULL)
    {
        if(p->data==a)
            return 0;
        if(p->data<a)
            p=p->right;
        else
            p=p->left;
    }
    return -1;
}

node *BST::delete1(node *root,int a)
{
    node  *temp;
    if(root==NULL)
        return root;
    if(a<root->data)
        root->left=delete1(root->left,a);
    else if(a>root->data)
        root->right=delete1(root->right,a);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            delete (root);
            return temp;
        }
        temp=inordersucc(root->right);
        root->data=temp->data;
        root->right= delete1(root->right,temp->data);
    }
    return root;
}

int main()
{
    node *root,*root1;
    BST t;
    int a,b;
    do
    {
        cout<<"\n1.Create BST\n2.Insert\n3.Delete\n4.Search\n5.Display Level wise\n6.Mirror Image\n7.Exit";
        cout<<"\nEnter choice: ";
        cin>>a;
        switch(a)
        {
        case 1:
            root=t.create();
            break;
        case 2:
            cout<<"\nEnter data to insert: ";
            cin>>b;
            root=t.insert1(root,b);
            break;
        case 3:
            cout<<"/nEnter data to delete: ";
            cin>>b;
            root=t.delete1(root,b);
            break;
        case 4:
            cout<<"\nEnter data to search: ";
            cin>>b;
            b=t.search1(root,b);
            if(b==-1)
                cout<<"\nNot Found";
            else
                cout<<"\nFound";
            break;
        case 5:
            t.print(root);
            break;
        case 6:
            root1=t.mirror(root);
            t.print(root1);
            root=t.mirror(root1);
            break;
        default:
            cout<<"\nWrong Choice";
            break;
        }
    }while(a!=7);
}
