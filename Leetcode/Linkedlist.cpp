#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;


struct node
{
	string data;
	node * nextnode;
};


void addnodefirst(node *& head, node *& last, string data);
bool isempty(node * head);
void remove(node *& head, node *& last);
void insert(node *& head, node *& last, string data);
void display(node * todisplay);



int main()
{
	node * head = NULL;//head pointer
	node * last = NULL;//tail pointer
	
	addnodefirst(head, last, "quinn");
	insert(head, last, "tyler");
	display(head);
	remove(head, last);
	cout << "\n";
	display(head);
	remove(head, last);
	cout << "\n";
	display(head);
	return 0;
}



void addnodefirst(node *& head, node *& last, string data)
{
	node * temp = new node;
	temp->data = data;
	temp->nextnode = NULL;

	head = temp;
	last = temp;


}
bool isempty(node * head)
{
	if (head == NULL)
	{
		return true; 
	}
	return false; 
}
void remove(node *& head, node *& last)
{
	if (isempty(head))
	{
		cout << "the list is empty" << endl;
	}
	else if (head == last)
	{
		delete head; 
		head == NULL;
		last == NULL;
	}
	else
	{
		node *temp = head;
		head = head->nextnode;
		delete temp; 
	}
}
void insert(node *& head, node *& last, string data)
{
	if (isempty(head) == true)
	{
		addnodefirst(head,last,data);
	}
	else
	{
		node * temp = new node;
		temp->data = data;
		temp->nextnode = NULL;


		last->nextnode = temp;
		last = temp;
	}

}
void display(node * todisplay)
{
	if (isempty(todisplay))
	{
		cout << "the list is empty" << endl;
	}
	else
	{
		cout << "the list contains : \n";
		while (todisplay != NULL)
		{
			cout << todisplay->data << endl;
			todisplay = todisplay->nextnode;
		}
	}



}