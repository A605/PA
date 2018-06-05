/*
* @Author: Aleksandar Trailovic
* Klasse: 4BHIF
* @Date: 29.05.18
*
*/

using namespace std;

#include <string>;
#include <iostream>;
#include <vector>;

class ListItem
{
public:
	ListItem();
	ListItem(string e, bool c);
	~ListItem();

	void setchecked(bool t) {
		this->checked = t;
	}

	string getEntry(void) {
		return this->entry;
	}

private:
	string entry;
	bool checked;

};

ListItem::ListItem() {

}

ListItem::ListItem(string e, bool c)
{
	entry = e;
	checked = c;
}

ListItem::~ListItem()
{
}




class TodoList
{
public:
	vector<ListItem> items;
	TodoList();
	~TodoList();

	void addItem(ListItem item) {
		this->items.push_back(item);
	}

	/*void checkItem(string entry) {
	for (ListItem &item : this->items)
	{
	if (item.getEntry == entry)
	{
	item.setchecked(true);
	}
	}
	}*/

private:

};

TodoList::TodoList()
{
}

TodoList::~TodoList()
{
}




class ShoppingItem : public ListItem
{
public:
	ShoppingItem(string e, bool c, int a);
	~ShoppingItem();

private:
	int amount;
	string entry;
	bool checked;

};

ShoppingItem::ShoppingItem(string e, bool c, int a)
{
	this->entry = e;
	this->checked = c;
	this->amount = a;
}

ShoppingItem::~ShoppingItem(){
}




class ShoppingList
{
public:
	vector<ShoppingItem> sitems;
	ShoppingList();
	~ShoppingList();

	void addItem(ShoppingItem item) {
		this->sitems.push_back(item);
	}

	vector<ShoppingItem>::iterator It;
	/*void checkItem(string entry) {
		for (ShoppingItem &item : this->sitems)
		{
			if (item.getEntry == entry) {
				item.setchecked(true);
			}
		}
	}*/

private:

};

ShoppingList::ShoppingList()
{
}

ShoppingList::~ShoppingList()
{
}


int main() {
	return 0;
}