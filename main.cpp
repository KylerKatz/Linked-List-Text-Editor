#include <iostream>
#include <string>
using namespace std;

struct node
{
	string data;
	node *next;
};

class LinkedList
{
private:
	node *head;
	node *tail;

public:
	LinkedList();
	void insertEnd(string text);
	void insertAt(int index, string text);
	void deleteAt(int index);
	void editAt(int index, string text);
	void print();
	void search(string text);
	string removeQuotes(string text);
	int getListSize();
};

int main()
{

	bool keepRunning = true;
	string action;
	LinkedList obj;
	/*
	cout << "Please select an action " << endl;
	cout << "Type 'insertEnd' followed by the text you would like to insert to insert text at the end of the document. " << endl;
	cout << "Type 'insert' follwed by the line number you would like to insert at followed by the text, to insert text at a specific line in the document. " << endl;
	cout << "Type 'delete' followed by the line number to delete a specific line in the document. " << endl;
	cout << "Type 'edit' followed by the line number of the text you would like to edit. Then enter the new text to edit a specific line in the document. " << endl;
	cout << "Type 'print' to print out the document. " << endl;
	cout << "Type 'search' followed by the word(s) you want to find to search the document for a specific word(s). " << endl;
	cout << "Type 'quit' to end the program. " << endl;

	*/
	while (keepRunning == true)
	{

		cin >> action;

		if (action == "insertEnd" || action == "insert" || action == "delete" || action == "edit" || action == "print" || action == "search" || action == "quit")
		{

			if (action == "insertEnd")
			{

				// Insert end
				string textEnd;
				getline(cin, textEnd);

				if (textEnd != "" && textEnd.length() < 80)
				{
					obj.insertEnd(obj.removeQuotes(textEnd));
				}
			}

			if (action == "insert")
			{

				// Insert at
				string indexAt;
				cin >> indexAt;
				string textAt;
				getline(cin, textAt);

				if (indexAt != "" && textAt != "" && textAt.length() < 80)
				{
					obj.insertAt(stoi(indexAt), obj.removeQuotes(textAt));
				}
			}

			if (action == "delete")
			{

				// Delete
				string deleteLine;
				getline(cin, deleteLine);

				if (deleteLine != "")
				{
					obj.deleteAt(stoi(deleteLine));
				}
			}

			if (action == "edit")
			{

				// Edit
				string editLine;
				cin >> editLine;
				string newText;
				getline(cin, newText);

				if (editLine != "" && newText != "" && newText.length() < 80)
				{
					obj.editAt(stoi(editLine), obj.removeQuotes(newText));
				}
			}

			if (action == "print")
			{
				obj.print();
			}

			if (action == "search")
			{

				// Search
				string search;
				getline(cin, search);

				if (search != "" && search.length() < 80)
				{
					obj.search(obj.removeQuotes(search));
				}
			}

			if (action == "quit")
			{
				keepRunning = false;
			}
		}
	}

	return 0;
}

LinkedList::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
}

void LinkedList::insertEnd(string text)
{
	node *temp = new node;
	temp->data = text;
	temp->next = nullptr;

	// If the list is empty, add the text at the head
	if (head == nullptr)
	{
		head = temp;
		tail = temp;
		temp = nullptr;
	}
	// If there is a node, then use the tail ptr to add the text after it
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void LinkedList::insertAt(int index, string text)
{
	// Check if index is out of bounds

	// If you want to insert between nodes
	if (index <= getListSize())
	{

		node *temp = new node;
		node *prev = new node;
		node *cur = new node;

		// Assign the temp data the string that will be inserted
		temp->data = text;
		cur = head;

		// Go to the correct position in the list
		if (index > 1)
		{
			for (int i = 1; i < index; i++)
			{
				prev = cur;

				cur = cur->next;
			}

			// Insert the new node between the previous and the current node
			prev->next = temp;
			temp->next = cur;
		}

		else
		{

			temp->next = head;
			head = temp;
		}
		if (index != 1)
		{
		}
	}
	// If you want to insert a node at the end
	else if (index == getListSize() + 1)
	{

		insertEnd(text);
	}

	else
	{
		//cout << "not found" << endl;
	}
}

void LinkedList::deleteAt(int index)
{
	if (index <= getListSize())
	{
		node *curr = new node;
		node *temp = new node;
		node *prev = new node;
		curr = head;

		int total = getListSize();
		// Delete the Head with a size of 1
		if (index == 1 && total == 1)
		{

			delete head;
			head = nullptr;
		}

		// Delete Head
		if (index == 1 && total > 1)
		{
			temp = head;

			if (total != 1)
			{
				head = head->next;
			}
			delete temp;
		}

		// Delete a node between Head and Tail
		if (index > 1 && index < total)
		{
			// Search for the correct index
			for (int i = 1; i < index; i++)
			{
				prev = curr;
				curr = curr->next;
			}

			prev->next = curr->next;

			delete curr;
		}

		// Deleting tail
		if (index == total && total != 1)
		{
			curr = head;
			while (curr->next != nullptr)
			{
				prev = curr;
				curr = curr->next;
			}

			tail = prev;
			prev->next = nullptr;
			delete curr;
		}
	}

	// Index is bigger then the size of the list
	else
	{
		//cout << "not found" << endl;
	}
}

void LinkedList::editAt(int index, string text)
{
	// Check if index is out of bounds
	if (index <= getListSize())
	{

		node *temp = new node;
		node *curr = new node;

		temp->data = text;
		curr = head;

		for (int i = 0; i < index - 1; i++)
		{
			curr = curr->next;
		}

		// Replace the text that is there now with the new text

		curr->data = temp->data;
	}

	else
	{
		//cout << "not found" << endl;
	}
}

void LinkedList::print()
{
	node *curr = new node;
	int line = 1;
	curr = head;

	if (getListSize() == 0)
	{
		//cout << "not found" << endl;
	}

	if (getListSize() == 1)
	{
		cout << line << " " << curr->data << endl;
	}

	if (getListSize() > 1)
	{
		for (int i = 0; i < getListSize(); i++)
		{
			cout << line << " " << curr->data << endl;

			curr = curr->next;
			line++;
		}
	}
}

void LinkedList::search(string text)
{
	node *curr = new node;
	curr = head;
	int line = 1;

	bool notFound = true;

	while (curr != nullptr)
	{

		if (curr->data.find(text) != string::npos)
		{

			cout << line << " " << curr->data << endl;
			notFound = false;
		}

		line++;
		curr = curr->next;
	}

	if (notFound == true)
	{
		cout << "not found" << endl;
	}
}

string LinkedList::removeQuotes(string text)
{
	text.erase(0, 2);
	text.erase(text.end() - 1);

	return text;
}

int LinkedList::getListSize()
{
	int size = 0;
	node *curr = new node;

	curr = head;

	while (curr != nullptr)
	{
		size++;
		curr = curr->next;
	}

	return size;
}
