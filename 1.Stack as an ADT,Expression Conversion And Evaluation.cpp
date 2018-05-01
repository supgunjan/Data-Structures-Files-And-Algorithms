#include<iostream>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int size=20,a=0;
struct node
{
    char data;
    struct node* next;
};
class stak
{
    node* top;
public:
    stak(){top=NULL;}
    bool isempty()
    {
        if(top==NULL)
            return true;
        else
            return false;
    }
    void push(char c)
    {
        node* temp;
        temp=new node;
        temp->data=c;
        temp->next=top;
        top=temp;
        ++a;
    }
    char peak()
    {
        return top->data;
    }
    char pop()
    {
        char b;
        b=peak();
        node* temp=top;
        top=top->next;
        delete temp;
        --a;
        return b;
    }
    bool isfull()
    {
        if(a==20)
            return true;
        else
            return false;
    }
};
int precedence(char x)
{
    if(x=='^')
        return 3;
    else if(x=='%'||x=='*'||x=='/')
        return 2;
    else if(x=='+'||x=='-')
        return 1;
    else
        return -1;
}
void ADT()
{
    stak s;
    int ch;
    char wish,c;
    a=0;
    do
    {
        cout<<"\n Enter your Choice\n";
		cout<<"\n 1. Push";
		cout<<"\n 2. pOp";
		cout<<"\n 3. Empty";
		cout<<"\n 4. Full\n\n";
		cin>>ch;
		switch(ch)
		{
        case 1:
            if(a==20)
                cout<<"\nStack is Full\n";
            else
            {
                cout<<"Enter data: \n";
                cin>>c;
                s.push(c);
            }
            break;
        case 2:
            if(a==0)
                cout<<"\nStack is Empty\n";
            else
                cout<<"\npopped element is : \n"<<s.pop();
            break;
        case 3:
            if(s.isempty())
                cout<<"\nStack is Empty\n";
            else
                cout<<"\nStack is not Empty\n";
            break;
        case 4:
            if(s.isfull())
                cout<<"\nStack is Full\n";
            else
                cout<<"\nStack is not Full\n";
            break;
        default:
            cout<<"\nWrong Answer\n";
		}
		cout<<"\nMore operations ?\n";
		cin>>wish;
    }while(wish=='y'||wish=='Y');
}

void infix_to_postfix()
{
    a=0;
    stak q;
    q.push('\0');
    char infix[30],outfix[30],x;
    int i,j;
    char t;
    j=0;
    cout<<"\nEnter Infix Expression\n";
    cin>>infix;
    for(i=0;infix[i]!='\0';i++)
    {
        t=infix[i];
        if(isalnum(t))
            outfix[j++]=t;
        else
        {
            if(t=='(')
               q.push('(');
            else
            {
                if(t==')')
                {
                   while((x=q.pop())!='(')
                       outfix[j++]=x;
                }
                else
                {
                    while(precedence(t)<=precedence(q.peak())&&!q.isempty())
                    {
                        x=q.pop();
                        outfix[j++]=x;
                    }
                    q.push(t);
                }
            }
        }
    }
    while(!q.isempty())
    {
        x=q.pop();
        outfix[j++]=x;
    }
    cout<<"Postfix Expression : "<<outfix;
}
void infixtopostfix(char infix[],char outfix[])
{
    a=0;
    stak q;
    q.push('\0');
    char x;
    int i,j;
    char t;
    j=0;
    for(i=0;infix[i]!='\0';i++)
    {
        t=infix[i];
        if(isalnum(t))
            outfix[j++]=t;
        else
        {
            if(t=='(')
               q.push('(');
            else
            {
                if(t==')')
                {
                   while((x=q.pop())!='(')
                       outfix[j++]=x;
                }
                else
                {
                    while(precedence(t)<precedence(q.peak())&&!q.isempty())
                    {
                        x=q.pop();
                        outfix[j++]=x;
                    }
                    q.push(t);
                }
            }
        }
    }
    while(!q.isempty())
    {
        x=q.pop();
        outfix[j++]=x;
    }
}
void infix_to_prefix()
{
    char infix[30],prefix[30],temp[30],x;
    int i,j;
    cout<<"\nEnter infix expression : ";
    cin>>infix;
    for(i=strlen(infix)-1,j=0;i>=0;i--,j++)
    {
        temp[j]=infix[i];
    }
    temp[j]='\0';
    for(i=0;temp[i]!='\0';i++)
    {
        if(temp[i]=='(')
            temp[i]=')';
        else
        {
            if(temp[i]==')')
                temp[i]='(';
        }
    }
    infixtopostfix(temp,prefix);
    for(i=0,j=strlen(prefix)-1;i<j;i++,j--)
    {
        x=prefix[i];
        prefix[i]=prefix[j];
        prefix[j]=x;
    }
    cout<<"\nPrefix Expression : \n"<<prefix;
}
int evaluate(char x,int b,int c)
{
    switch(x)
    {
        case '+':return b+c;
		case '-':return b-c;
		case '*':return b*c;
		case '/':return b/c;
		case '^':return pow(b,c);
		case '%':return b%c;

    }
}
void eval_postfix()
{
    stak s;
    char  postfix[30];
    cout<<"\nEnter postfix expression : \n";
    cin>>postfix;
    int b,c,val,i;
    char x;
    for(i=0;postfix[i]!='\0';i++)
    {
        x=postfix[i];
        if(isalpha(x))
        {
            cout<<"\nEnter the value of "<<x<<" : ";
            cin>>val;
            s.push(val);
        }
        else
        {
            c=s.pop();
            b=s.pop();
            val=evaluate(x,b,c);
            s.push(val);
        }
    }
    val=s.pop();
    cout<<"\nValue of Expression = "<<val;
}
void eval_prefix()
{
    stak s;
    char  prefix[30];
    cout<<"\nEnter prefix expression : \n";
    cin>>prefix;
    int b,c,val,i;
    char x;
    for(i=strlen(prefix)-1;i>=0;i--)
    {
        x=prefix[i];
        if(isalpha(x))
        {
            cout<<"\nEnter the value of "<<x<<" : ";
            cin>>val;
            s.push(val);
        }
        else
        {
            c=s.pop();
            b=s.pop();
            val=evaluate(x,b,c);
            s.push(val);
        }
    }
    val=s.pop();
    cout<<"\nValue of Expression = "<<val;
}
int main()
{
    char wish;
	int ch;
	do{
		cout<<"\n Enter your Choice\n";
		cout<<"\n 1. stack Operations";
		cout<<"\n 2. infix tO postfix";
		cout<<"\n 3. infix t0 prefix";
		cout<<"\n 4. evaluate postfix expression";
		cout<<"\n 5. evaluate prefix expression\n\n";
		cin>>ch;
		switch(ch)
		{
			case 1:ADT();		break;

			case 2:infix_to_postfix();	break;

			case 3:infix_to_prefix();	break;

			case 4:eval_postfix();	    break;

			case 5:eval_prefix();       break;

			default:cout<<"\nwrong entry\n";
		}
		cout<<"\nmore operations ?\n";
		cin>>wish;
	}while(wish=='y'||wish=='Y');
}
