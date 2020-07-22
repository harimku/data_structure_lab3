
#include <iostream>
#include <ctime>
#include <vector>
#include "ConsoleColor.h"
using namespace std;

template <typename T>
class BinarySearchTree
{
	vector<T> array;
	int size;
public:
	BinarySearchTree(int s) : size(s)
	{
		size = reSize(size);
		array.resize(size);
		for (int x = 0; x < size; x++) 
			array[x] = NULL;
	}
	int reSize(int x) 
	{
		int value = pow(x, 2);
		return value;
	}
	void insert(T x) 
	{
		int currentIndex = 0;
		cout << red << "\n-->insert: " << x << endl;
		while (true) 
		{
			if (array[currentIndex] == NULL) 
			{
				array[currentIndex] = x;
				cout << blue << "Inserted @ index: ";
				cout << ((currentIndex % 2) ? green : yellow);
				cout << currentIndex << endl;
				break;
			}
			else if (x < array[currentIndex]) 
			{
				currentIndex = (2 * currentIndex + 1);  //left side
				cout << green << " Left <<< " << currentIndex << endl;
			}
			else  
			{
				currentIndex = (2 * currentIndex + 2);  //right side
				cout << yellow << " Right >>> " << currentIndex << endl;
			}
		}
	}
	void search(T x) 
	{
		cout << red << "Search: " << x << endl;
		int currentIndex = 0;
		while (true) 
		{
			if (array[currentIndex] == NULL) 
			{
				cout << red << "Not Found" << endl;
				break;
			}
			if (array[currentIndex] == x) 
			{
				cout << blue << "Found at index: " << yellow << currentIndex << endl;
				break;
			}
			else if (x < array[currentIndex]) 
			{
				cout << green << " Left <<< " << endl;
				currentIndex = (2 * currentIndex + 1);
			}
			else 
			{
				cout << yellow << " >>> Right " << endl;
				currentIndex = (2 * currentIndex + 2);
			}
		}
	}
	void parent(int x) 
	{
		while (x != 0) 
		{
			x = (x - 1) / 2;
			cout << "---|";
		}
	}
	void inOrder(int currentIndex) 
	{
		if (array[currentIndex] != NULL) 
		{
			inOrder(2 * currentIndex + 1);
			parent(currentIndex);
			cout << array[currentIndex] << endl;
			inOrder(2 * currentIndex + 2);
		}
	}
	void preOrder(int currentIndex)
	{
		if (array[currentIndex] != NULL)
		{
			parent(currentIndex);
			cout << array[currentIndex] << " " << endl;
			preOrder(2 * currentIndex + 1);
			preOrder(2 * currentIndex + 2);
		}
	}
	void postOrder(int currentIndex) 
	{
		if (array[currentIndex] != NULL) 
		{
			postOrder(2 * currentIndex + 1);
			postOrder(2 * currentIndex + 2);
			parent(currentIndex);
			cout << array[currentIndex] << " " << endl;
		}
	}
	void reverseOrder(int currentIndex)
	{
		if (array[currentIndex] != NULL)
		{
			reverseOrder(2 * currentIndex + 2);
			parent(currentIndex);
			cout << array[currentIndex] << " " << endl;
			reverseOrder(2 * currentIndex + 1);
		}
	}
	void printArray()
	{
		int exp = 0;
		int sum = int(pow(2, exp));
		int power = sum;
		for (int i = 0; i < size; i++)
		{
			if (i == sum)
			{
				cout << red << "| " << endl;
				exp++;
				power = int(pow(2, exp));
				sum += power;
			}
			if (array[i])
			{
				(i % 2) ? cout << green << array[i] << ' ' : cout << yellow << array[i] << ' ';
			}
			else
			{
				cout << blue << "- ";
			}
		}
		cout << white << endl;
	}
};

int main() 
{
	vector<int> varray = { 42, 68, 35, 1, 70, 25, 79, 59, 63, 65 };
	int resize = varray.size() * log(varray.size());
	BinarySearchTree<int> bst(varray.size());
	for (int i = 0; i < varray.size(); i++)
		bst.insert(varray[i]);
	cout << endl;
	cout << blue << "Inorder" << yellow << endl;
	bst.inOrder(0);
	cout << blue << "Preorder" << yellow << endl;
	bst.preOrder(0);
	cout << blue << "Postorder" << yellow << endl;
	bst.postOrder(0);
	cout << blue << "\nSearch" << yellow << endl;
	bst.search(65);
	cout << "\nIn memory" << endl;
	bst.printArray();
	bst.reverseOrder(0);
}