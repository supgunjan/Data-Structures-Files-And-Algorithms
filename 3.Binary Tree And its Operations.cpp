#include<iostream>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
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
class tree
{
public:
    node *create();
    node *insert1(node *root,int a);
    int depth(node *root);
    void print(node *root);
    node *copyoftree(node *root,node *p);
    node *mirror(node *root);
    void println(node *root);
};
node *tree::create()
{
    int a;
    node *p;
    cout<<"\nEnter a data(-1 for no data or null node): ";
    cin>>a;
    if(a==-1)
        return NULL;
    p=new node(a);
    cout<<"\nEnter left child of "<<a;
    p->left=create();
    cout<<"\nEnter right child of "<<a;
    p->right=create();
    return p;
}
node *tree::insert1(node *root,int a)
{
    node *p;
    char c;
    if(root==NULL)
    {
            root=new node(a);
            return root;
    }
    else if(root!=NULL)
    {
        p=root;
        while(true)
        {
            if(p->left==NULL)
            {
                cout<<"Want to insert as left child(Y/N)";
                cin>>c;
                if(c=='Y')
                {
                    p->left=new node(a);
                    return root;
                }
            }
            if(p->right==NULL)
            {
                cout<<"Want to insert as right child(Y/N)";
                cin>>c;
                if(c=='Y')
                {
                    p->right=new node(a);
                    return root;
                }
            }
            if(p->left!=NULL)
                p=p->left;
            if(p->right!=NULL)
                p=p->right;
        }
    }
}
void tree::print(node *root)
{
    node *p;
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        int s=q.size();
        while(s--)
        {
            p=q.front();
            q.pop();
            if(p->left!=NULL)
                q.push(p->left);
            if(p->right!=NULL)
                q.push(p->right);
            cout<<p->data<<" ";
        }
        cout<<"\n";
    }
}
node *tree::copyoftree(node *root,node *p)
{
    if(root!=NULL)
    {
        p=root;
        p->left=copyoftree(root->left,p->left);
        p->right=copyoftree(root->right,p->right);
    }
    return p;
}
node *tree::mirror(node *root)
{
    node *p,*q;
    q=root;
    if(q!=NULL)
    {
        p=q->left;
        q->left=mirror(q->right);
        q->right=mirror(p);
    }
    return q;
}
int tree::depth(node *root)
{
    int a,b;
    if(root==NULL)
        return 0;
    if(root->left==NULL&&root->right==NULL)
        return 1;
    a=depth(root->left);
    b=depth(root->right);
    if(a>b)
        return a+1;
    return b+1;
}
int main()
{
    tree t;
    int a;
    node *root=NULL;
    node *root1=NULL,*root2=NULL;
    int c;
    do
    {
        cout<<"\n1.Create Binary tree\n2.Print level wise\n3.Insert\n4.Depth of tree\n5.Mirror of tree\n6.Copy of tree\n7.Quit";
        cout<<"\nEnter your choice: ";
        cin>>c;
        switch(c)
        {
        case 1:
            root=t.create();
            break;
        case 2:
            t.print(root);
            break;
        case 3:
            cout<<"\nEnter data to be inserted: ";
            cin>>a;
            root=t.insert1(root,a);
            t.print(root);
            break;
        case 4:
            a=t.depth(root);
            cout<<a;
            break;
        case 5:
            root1=t.mirror(root);
            t.print(root1);
            break;
        case 6:
            root2=t.copyoftree(root,root2);
            t.print(root2);
            break;
        default:
            cout<<"/nWrong Choice";
            break;
        }
    }while(c!=7);
}
