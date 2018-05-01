#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    char data;
    node *right,*left;
    node()
    {
    left=right=NULL;
    }
    node(char c)
    {
       data=c;
       left=right=NULL;
    }
};
class exptree
{
    public:
        node *create_post(char []);
        void rec_pre(node *root);
        void rec_in(node *root);
        void nonrec_pre(node *root);
        void nonrec_in(node *root);
};
node *exptree::create_post(char exp[])
{
    int i;
    node *p,*q,*r,*root;
    stack<node *>s;
    char ch,c;
    for(i=0;exp[i]!='\0';i++)
    {
       c=exp[i];
       if(isalnum(c))
       {
           p=new node(c);
           s.push(p);
       }
       else
       {
           q=s.top();
           s.pop();
           r=s.top();
           s.pop();
           p=new node(c);
           p->left=r;
           p->right=q;
           s.push(p);
       }
    }
    root=s.top();
    s.pop();
    return root;
}
void exptree::rec_pre(node *root)
{
    if(root!=NULL)
	{
		cout<<root->data<<" ";
		rec_pre(root->left);
        rec_pre(root->right);
	}
}
void exptree::rec_in(node *root)
{
    if(root!=NULL)
	{
		rec_in(root->left);
		cout<<root->data<<" ";
		rec_in(root->right);
	}
}
void exptree::nonrec_pre(node *root)
{
    node *p;
    p=root;
    stack<node *>s;
    while(p!=NULL)
    {
       cout<<p->data<<" ";
       s.push(p);
       p=p->left;
    }
    while(!s.empty())
    {
        p=s.top();
        s.pop();
        p=p->right;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            s.push(p);
            p=p->left;
        }
    }
}
void exptree::nonrec_in(node *root)
{
    node *p;
    p=root;
    stack<node *>s;
    while(p!=NULL)
    {
        s.push(p);
        p=p->left;
    }
    while(!s.empty())
    {
        p=s.top();
		s.pop();
		cout<<p->data<<" ";
		p=p->right;
		while(p!=NULL)
        {
            s.push(p);
            p=p->left;
        }
    }
}
int main()
{
    int i,j,ch;
    char exp[30];
    exptree w;
    node *root,*root1;
    do
    {
       cout<<"\nenter your choice:\n1.create postorder exp tree\n2.non recursive traversal\n3.recursive traversal\n4.exit";
       cin>>ch;
       switch(ch)
       {
       case 1:
           {cout<<"\nenter postfix expression : ";
           cin>>exp;
           root=w.create_post(exp);
           break;}
       case 2:
           {cout<<"\n1.preorder\n2.inorder\n";
           cin>>i;
           if(i==1)
           w.nonrec_pre(root);
           else if(i==2)
           w.nonrec_in(root);
           else
            cout<<"\ntry again !";
           break;}
       case 3: {cout<<"\n1.preorder\n2.inorder\n";
           cin>>j;
           if(j==1)
		 		w.rec_pre(root);
		 	else if(j==2)
		 		w.rec_in(root);
		 	else
		 		cout<<"\ntry again";s
		 	break;}
       }
    }while(ch!=4);
}
