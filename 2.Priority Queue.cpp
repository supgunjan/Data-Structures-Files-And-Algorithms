#include<iostream>
using namespace std;

struct node
{
	string name;
	int data;
	struct node *next;
};

class priority_queue
{
	node *head = new(node);
	public :
	priority_queue()
	{
		head = NULL;
	}
	void insert(node * temp)
	{
		if(head == NULL)
		{
			head = temp;
		}
		else
		{
			if(head->data > temp->data)
			{
				temp->next = head;
				head = temp;
			}
			else
			{
				node *curr = head;
				while(curr->data <= temp->data)
				{
					if(curr->next == NULL || curr->next->data > temp->data)
						break;
					curr = curr->next;
				}
				temp->next = curr->next;
				curr->next = temp;
			}
		}
	}
	void display()
	{
		node *curr = head;
		int serial = 1;
		while(curr != NULL)
		{
			cout << serial << " " << curr->data << " " << curr->name << "\n";
			serial++;
			curr = curr->next;
		}
	}
};



int main()
{
	priority_queue pq;
	int choice;
	do
	{
		cout << "press 1 to enter the patient\npress 2 to display queue\npress 3 to exit\n";
		cin >> choice;
		switch(choice)
		{
			case 1 :
			 {
				int type;
				cout << "press 1 for critical patient\npress 2 for medium patient\npress 3 for general patient\n";
				cin >> type;
				node *temp = new(node);
				temp->next = NULL;
				temp->data = type;
				cout << "Enter the name of patient\n";
				cin >> temp->name;
				pq.insert(temp);
				cout << "Data successfully entered\n";
			}
			break;
			case 2 : 
			{
				cout << "Displaying the queue of patient\n";
				pq.display();
			}
			break;
			case 3 :
					return 0;
			break;
			default : cout << "Please enter valid choice\n";
		}
	}while(choice != 3);


	return 0;
}
