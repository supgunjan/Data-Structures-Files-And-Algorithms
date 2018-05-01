#include<bits/stdc++.h>
using namespace std;

int k=0;
class fb
{
    public :
    string name;
    fb * next;
};

class node
{   public :
    fb * next;
    string name;
    string dob;
    int com;
} head[100];
int visited[20];


void create ()
{
  int i,j,n;
  string st,name,dob;
  int c,flag=0;
  cout<<"\nEnter number of nodes\n";
  cin>>k;
  for(i=0;i<k;i++){
        flag=0;
        cout<<"Enter the Name , DOB in DD/MM/YYYY format and Number of Comments for node number "<<i+1<<endl;
        cin>>name>>dob>>c;
        head[i].name=name;
        head[i].dob=dob;
        head[i].com=c;
        head[i].next=NULL;

        a: cout<<"\nPress 1 to add a friend of "<<head[i].name;
        cout<<"\nPress 2 to continue\n";
        cin>>n;
        if(n==1){
            cout<<"\nEnter the Name of friend\n";
            fb * temp = new fb;
            fb * t;
            temp->next=NULL;
            cin>>temp->name;
            if(flag==0){
                head[i].next=temp;
                t=temp;
                flag=1;
          }
            else{
                t->next=temp;
                t=temp;
            }
            goto a;
        }
      if(n==2)
      {
          continue;
      }
  }
}

void maxi()
{
    int i,l=head[0].com,h=l;
    string st1=head[0].name, st2=head[0].name;
    for(i=1;i<k;i++)
    {
        if(head[i].com>h)
        {
            h=head[i].com;
            st1=head[i].name;
        }
        if(head[i].com<l)
        {
            l=head[i].com;
            st2=head[i].name;
        }
    }
    cout<<"Max Comments "<<h<<" Name "<<st1; cout<<endl;
    cout<<"Min Comments "<<l<<" Name "<<st2; cout<<endl;
}

void birthday(int m)
{
    int i,flag=0;
    for(i=0;i<k;i++)
    {
        if(head[i].dob[3]+head[i].dob[4]-'0'-'0'==m)
        {
            flag=1;
            cout<<head[i].name<<endl;
        }
    }
    if(flag==0)
    {
        cout<<"No birthdays this month\n";
    }
}

void DFS(string name){
    int flag = 0,i;
    for(i=0;i<k;i++){
        if(head[i].name==name)
            {
                flag=1;
                fb *t=head[i].next;
                while(t!=NULL)
                    {
                        cout<<t->name<<" ";
                        t=t->next;
                    }
            }
    }
    if(flag==0)
    cout<<"No such person exists\n";
}

int main()
{

    int ch,n,i,m,flag=0;
    string name;

    while(1){
        cout<<"\n----------Facebook Network----------\n";
        cout<<"\n1. Create network ";
        cout<<"\n2. Display friends of a specific user";
        cout<<"\n3. Display user with max and min comments";
        cout<<"\n4. Find out the birthday's in this month";
        cout<<"\n5. Exit\n";
        cin>>n;

        switch(n){
            case 1: create();
                    break;

            case 2: cout<<"\nEnter name of user\n";
                    cin>>name;
                    DFS(name);
                    break;

            case 3: maxi();
                    break;

            case 4: cout<<"Enter birthday month\n";
                    cin>>m;
                    birthday(m);
                    break;

            case 5: return 0;

     }
}
}
