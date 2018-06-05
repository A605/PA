/*
* @Author: Aleksandar Trailovic
* Klasse: 4BHIF
* @Date: 29.05.18
* @Desc: Verbesserung der Praktischen Arbeit
*/


#include <string>
#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;


class ListItem
{

protected:
    // F�r die Vererbung: protected
	string entry;
	bool checked;

public:
    // Konstruktor
	ListItem(string entry)
	{
		this->entry = entry;
		this->checked = false;
	}

	// Set-Methoden
    void setEntry(string entry)
    {
		this->entry = entry;
	}

	void setChecked()
    {
	    this->checked = true;
	}


	// Get-Methoden
	string getEntry()
    {
		return entry;
	}

    bool getChecked()
    {
		return checked;
	}


	// Operator-�berladung
	friend ostream& operator<<(ostream &os, const ListItem& item)
	{
		os << setw(26) << item.entry << setw(3) << "[";
	    if (item.checked == true) {
		    os << "X]";
	    } else {
		    os << " ]";
	    }
	    return os;
	}
};



//--------------------------------------------------------------------------------
class ShoppingItem : public ListItem
{

private:
    // Zus�tzliche Eigenschaft
	int amount;

public:
	// Konstruktor
	ShoppingItem(int amount, string entry) : ListItem(entry)
	{
		this->amount = amount;
	}


    // Operator-�berladung
	friend ostream& operator<<(ostream &os, const ShoppingItem& item) {
		os << setw(3) << item.amount << " x " << setw(20) << item.entry << setw(3) << "[";

	if (item.checked == true) {
		os << "X]";
	}
	else {
		os << " ]";
	}


	return os;
	}
};



//--------------------------------------------------------------------------------
class TodoList
{

private:
    // Vector f�r die ListItems
	vector<ListItem> items;

public:
	
	// Konstruktor
	TodoList() 
	{
		this->items = vector<ListItem>();
	}

	// Hinzuf�gen von Items
	void addItem(ListItem item) {
		this->items.push_back(item);
	}


	// Checked-Value fuer spezielles Item auf true setzen
	void checkItem(string entry) {

		for (size_t i = 0; i < this->items.size(); i++)
	    {
		    if (this->items[i].getEntry() == entry) {
			    this->items[i].setChecked();
		    }
	    }

	}

    // Operator-�berladung
	friend ostream& operator<<(ostream &os, const TodoList& list)
	{
		for (size_t i = 0; i < list.items.size(); i++)
	    {
		    os << list.items[i] << endl;
	    }

	    return os;
	}
};






//--------------------------------------------------------------------------------
class ShoppingList
{

private:
	// Vector f�r alle Items
	vector<ShoppingItem> items;
public:
	// Konstruktor
	ShoppingList()
	{
		this->items = vector<ShoppingItem>();
	}


	// Hinzuf�gen eines Items
	void addItem(ShoppingItem item) {
		this->items.push_back(item);
	}


	// Checked-Value fuer spezielles Item auf true setzen
	void checkItem(string entry) {
		for (vector<ListItem>::size_type  i = 0; i != this->items.size(); i++)
	    {
		    if (this->items[i].getEntry() == entry) {
			    this->items[i].setChecked();
		    }
	    }

	}

    // Operator-�berladung
	friend ostream & operator<<(ostream & os, const ShoppingList & list)
	{
		for (vector<ListItem>::size_type i = 0; i < list.items.size(); i++)
	    {
		    os << list.items[i] << endl;
	    }   

	    return os;
	}

};




//--------------------------------------------------------------------------------
int main() {
    // Test TodoList
	TodoList todolist = TodoList();
	todolist.addItem(ListItem("Erste Aufgabe"));
	todolist.addItem(ListItem("Zweite Aufgabe"));
	todolist.checkItem("Zweite Aufgabe");
    // Ausgabe TodoList
    cout << todolist << endl;


    // Test ShoppingList
	ShoppingList shoppinglist = ShoppingList();
	shoppinglist.addItem(ShoppingItem(3, "Aepfel"));
	shoppinglist.addItem(ShoppingItem(1, "Birnen"));
	shoppinglist.addItem(ShoppingItem(2, "Toastbrot"));
	shoppinglist.addItem(ShoppingItem(2, "Zwetschken"));
    shoppinglist.checkItem("Birnen");
	shoppinglist.checkItem("Datteln");
    // Ausgabe Shoppinglist
	cout << shoppinglist << endl;
	return 0;
}
