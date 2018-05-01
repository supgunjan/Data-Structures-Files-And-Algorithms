#include<bits/stdc++.h>
using namespace std;

class file
{
	fstream fin,fout;
	string name,add,branch;
	int rn,count=0;
	public :
	    file()
	    {

	       fout.open("student.txt",ios::out);
	       fout.close();
	    }

	void insert()
	{
		cout<<"Enter Name  : ";
		cin>>name;
		cout<<"Enter branch  : ";
		cin>>branch;
		cout<<"Enter Roll No.  : ";
		cin>>rn;
		cout<<"Enter Address  : ";
		cin>>add;
		fout.open("student.txt",ios::app);
		{
			fout<<rn<<" "<<name<<" "<<branch<<" "<<add<<endl;
			count++;
		}
		fout.close();

	}
	void display()
	{
		fin.open("student.txt",ios::in);
		for(int i=0;i<count;i++)
		{
			fin>>rn>>name>>branch>>add;
			cout<<rn<<" "<<name<<" "<<branch<<" "<<add<<endl;
		}
		fin.close();
	}
	void search()
	{
		int rollno,flag=0;
		cout<<"Enter Roll No. to be searched for..";
		cin>>rollno;
		fin.open("student.txt",ios::in);
		for(int i=0;i<count;i++)
		{
			fin>>rn>>name>>branch>>add;
			if(rn==rollno)
			{
				cout<<rn<<" "<<name<<" "<<branch<<" "<<add<<endl;
				flag=1;
			}

		}
		fin.close();
		if(flag==0)
		{
			cout<<"Data Not found";
		}
	}

	void delete1()
	{
		int rollno,flag=0;
		cout<<"Enter Roll No. to be searched for..";
		cin>>rollno;
		fin.open("student.txt",ios::in);
		fout.open("temp.txt",ios::out);
		for(int i=0;i<=count;i++)
		{
			fin>>rn>>name>>branch>>add;
			if(rn==rollno)
			{
				flag=1;
				count--;
			}
			else
			fout<<rn<<" "<<name<<" "<<branch<<" "<<add<<endl;

		}
		fin.close();
		fout.close();
		if(flag==0)
		{
			cout<<"Data Not found";
		}
		fin.open("temp.txt",ios::in);
		fout.open("student.txt",ios::out);
		for(int i=0;i<count;i++)
		{
			fin>>rn>>name>>branch>>add;
			fout<<rn<<" "<<name<<" "<<branch<<" "<<add<<endl;

		}
		fin.close();
		fout.close();

	}
};

int main()
{
	int op;
	file f;
	do
	{
		cout<<"Press\n1.Insert Data\n2.Display Specific Data\n3.Display Complete Data\n4.Delete\n5.Exit";
		cin>>op;
		switch(op)
		{
			case 1 : f.insert();
						break;
			case 2 : f.search();
						break;
			case 3 : f.display();
						break;
            case 4 : f.delete1();

		}
	}while(op!=5);

}
