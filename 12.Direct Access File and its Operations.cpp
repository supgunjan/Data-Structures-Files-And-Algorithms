#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#define table_size 10
#define h(x,i) (x+i)%table_size
using namespace std;
class record{
	public:
	int rollno, marks, chain;
	char *name;
    record()
	{
		rollno = marks = chain = -1;
		name = new char[20];
	}
    void display();
};
void insert();
void show_record();
void disp_header();
int traverse( fstream& fp, int loc );
int append( fstream& fp, int rollno, int inc );
void search_record();
//-------------------//

int main()
{
	record a;
	//creating memory space in file record.bin
	ofstream fp("record.txt", ios::binary);
	for( int i = 0 ; i < table_size ; i++ )
	{
		fp.write( (char*)&a, sizeof(a) );
	}
	fp.close();
	//ends

	int ch;

	do{
		cout << "\n_____FILE-HASHING_____\n1.Insert\n2.display\n3.Search\n4.Exit\n--->";
		cin >> ch;

		switch(ch)
		{
			case 1://inserting
				insert();
				break;

			case 2://displaying
				disp_header();
				show_record();
				break;

			case 3://searching
				search_record();
				break;
		}

	}while( ch != 4 );

	return 0;
}

void disp_header()
{
	cout << setfill('-') << setw(1) << "+" << setw(5) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+"
		<< setw(5) << "-" << setw(1) << "+" << setw(5) << "-" << setw(1) << "+" << endl;

	cout << setfill(' ') << setw(1) << "|" << setw(5) << "ROLL" << setw(1) << "|" << setw(15) << "NAME" << setw(1) << "|"
		<< setw(5) << "MARKS" << setw(1) << "|" << setw(5) << "CHAIN" << setw(1) << "|" << endl;
}
void record::display()
{
	cout << setfill('-') << setw(1) << "+" << setw(5) << "-" << setw(1) << "+" << setw(15) << "-" << setw(1) << "+"
		<< setw(5) << "-" << setw(1) << "+" << setw(5) << "-" << setw(1) << "+" << endl;

	cout << setfill(' ') << setw(1) << "|" << setw(5) << rollno << setw(1) << "|" << setw(15) << name << setw(1) << "|"
		<< setw(5) << marks << setw(1) << "|" << setw(5) << chain << setw(1) << "|" << endl;
}
//----------------------------------------//

//traversing the chain when synonym data is found
int traverse( fstream& fp, int loc )
{
	int flag = 1;
	record temp;
	while( flag )
	{
		fp.seekg( loc*sizeof(temp), ios::beg );
		fp.read( (char*)&temp, sizeof(temp) );
		if( temp.chain == -1 )
		{
			flag = 0;
		}
		else
		{
			loc = temp.chain;
		}
	}
	return loc;
}
int append( fstream& fp, int rollno, int inc )
{
	int flag = 1, loc;
	record in;
	while(flag)
	{
		loc = h(rollno, inc);
		fp.seekg( loc*sizeof(in), ios::beg );
		fp.read( (char*)&in, sizeof(in) );
		if( in.rollno == -1 || h(in.rollno, 0) == h(rollno, 0) )
		{
			flag = 0;
		}
		else
		{
			++inc;
		}
	}
	return loc;
}
void insert()
{
	fstream fp("record.txt",ios::out|ios::ate|ios::in);
	fp.seekg(0,ios::end);
	record in, out;
	int loc, end, inc = 0;
    cout << "\nRollno: ";
	cin >> in.rollno;
	cin.ignore();
	cout << "Name: ";
	cin.getline( in.name, 20 );
	cout << "Marks: ";
	cin >> in.marks;
    loc = h(in.rollno, 0);
    fp.seekg( loc*sizeof(out), ios::beg );
	fp.read( (char*)&out, sizeof(out) );

	if( out.rollno == -1 )
	{	cout << "\nHello" << endl;
		fp.seekp( loc*sizeof(in), ios::beg );
		fp.write( (char*)&in, sizeof(in) );
	}
	else if( h(out.rollno, 0) == loc )
	{
		end = traverse( fp, loc );
		cout << "End: " << end;
		inc = end;

		loc = append( fp, in.rollno, abs(h(in.rollno, 0)-end) + 1 );
		cout << "Loc: " << loc << endl;

		fp.seekg( loc*sizeof(in), ios::beg );
		fp.write( (char*)&in, sizeof(in) );

		fp.seekg( end * sizeof(in), ios::beg );
		fp.read( (char*)&out, sizeof(out) );
		out.chain = loc;

		fp.seekg( end * sizeof(in), ios::beg );
		fp.write( (char*)&out, sizeof(out) );

	}
	else
	{
		loc = append( fp, in.rollno, inc );
		end = -1;

		fp.seekg( loc * sizeof(in), ios::beg );
		fp.read( (char*)&out, sizeof(out) );

		if( h(in.rollno, 0) == h(out.rollno, 0) )
		{
			end = traverse( fp, loc );
			inc = end;
			loc = append( fp, in.rollno, abs(h(in.rollno, 0)-end) + 1 );
			fp.seekg( end * sizeof(in), ios::beg );
			fp.read( (char*)&out, sizeof(out) );
			out.chain = loc;
			fp.seekg( end * sizeof(in), ios::beg );
			fp.write( (char*)&out, sizeof(out) );
		}
		fp.seekg( loc*sizeof(in), ios::beg );
		fp.write( (char*)&in, sizeof(in) );

	}

	fp.close();
}

//searching a record
void search_record()
{
	fstream fp("record.txt", ios::in | ios::out | ios::binary );
	record in, out;
	int rollno, loc;
	cout << "\nRollno to search: ";
	cin >> rollno;

	loc = h(rollno, 0);

	fp.seekg( loc*sizeof(in), ios::beg );
	fp.read( (char*)&in, sizeof(in) );

	while(1)
	{
		if( in.rollno == rollno )
		{
			disp_header();
			in.display();
			fp.close();
			return;
		}
		if( in.chain != -1 )
		{
			loc = in.chain;
			fp.seekg( loc*sizeof(in), ios::beg );
			fp.read( (char*)&in, sizeof(in) );
		}
		else{
			break;
		}
	}

	cout << "\nRECORD NOT FOUND.....\n";
	fp.close();
}
//----------------------------------------//

//reading the records from file and displaying using class function declared above
void show_record()
{
	fstream fp("record.txt");
	record out;

	while( fp.read( (char*)&out, sizeof(out) ) )
	{
		out.display();
	}
    fp.close();
}









