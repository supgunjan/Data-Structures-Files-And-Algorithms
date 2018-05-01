#include<bits/stdc++.h>
using namespace std;

#define size 26

class node{
    string name;
    int tele_no;
    node *next;
    public:
    node(){
        name = "";
        tele_no = -1;
        next =NULL;
    }
    friend class hashassign;
};

class hashassign{
    node arr[size];
    int k ;
    public:
    hashassign(){
        k = 0;
    }
    void inse(string , int);
    void sear(string);
    void display();
};

int func(string name){
    int pos;
    int x;
    x = name[0];
    if(x>=65 && x<=90)
        pos = x -65;
    else if(x>=97 && x<=122)
        pos = x - 97;
    return pos;
}

void hashassign::inse(string name , int tele){
    int pos = func(name);
    if(arr[pos].tele_no == -1){
        arr[pos].tele_no = tele;
        arr[pos].name = name;
    }
    else{
            node *p;
            p = new node();
            p->tele_no = tele;
            p->name = name;
            if(arr[pos].next == NULL){
                arr[pos].next = p;
            }
            else{
                node *n = arr[pos].next;
                while(n->next!=NULL)
                    n = n->next;
                n->next = p;
            }
    }
}

void hashassign::sear(string name){
    int pos;
    pos = func(name);
    if(arr[pos].tele_no == -1){
            cout<<"Not found\n";
            return;
    }
    else{
        if(arr[pos].name == name){
            cout<<"\n"<<name<<":"<<arr[pos].tele_no;
            return;
        }
        node *p;
        p = arr[pos].next;
        while(p!=NULL){
            if(p->name == name){
                    cout<<"\n"<<name<<":"<<p->tele_no<<"\n";
                    return;
            }
            p=p->next;
        }
        cout<<"Not Found\n";
    }
}

void hashassign::display(){
    int i;
    node *p;
    for(i = 0;i<size;i++)
    {
        cout<<arr[i].name<<"\t"<<arr[i].tele_no<<"\n";
        if(arr[i].next!=NULL){
            p = arr[i].next;
            while(p!=NULL){
                cout<<p->name<<"\t"<<p->tele_no<<"\n";
                p=p->next;
            }
        }
    }
}


int main(){
    hashassign obj;
    int i;
    string name;
    int tele;
    while(1){
        cout<<"1. Insert\n";
        cout<<"2. Search\n";
        cout<<"3. Display\n";
        cout<<"4. Quit\n";
        cout<"Enter Your Choice\n";
        cin>> i ;
        switch(i){

        case 1: cout<<"Enter the name: \n";
                cin>>name;
                cout<<"Enter the telephone number : \n";
                cin>>tele;
                obj.inse(name,tele);
                break;
        case 2: cout<<"Enter the name to be searched\n";
                cin>>name;
                obj.sear(name);
                break;
        case 3: obj.display();
                break;
        case 4: return 0;
        }
    }
}
