#include <iostream>
#include <memory>
#include <queue>

using namespace std;

template<typename T>
class Tree
{
public:
	struct node
	{
		T data;
		unique_ptr<node> left;
		unique_ptr<node> right;
	};

private:
	unique_ptr<node> root;

	void Add(T nodeData, unique_ptr<node> &tRoot)
	{
		if(tRoot.get() == nullptr)
		{
			tRoot.reset(new node());
			tRoot.get()->data = nodeData;
			return;
		}
		if(nodeData > tRoot.get()->data)
			return Add(nodeData, tRoot.get()->right);
		if(nodeData < tRoot.get()->data)
			return Add(nodeData, tRoot.get()->left);
	}

	int MaxHeight(unique_ptr<Node> &n)
	{
		if(n.get() == nullptr)
			return 0;

		return std::max(MaxHeight(n.get()->left), 
			MaxHeight(n.get()->right)) + 1;
	}

	int MinHeight(unique_ptr<Node> &n)
	{
		if(n.get() == nullptr)
			return 0;

		return std::minimum(MinHeight(n.get()->left), 
			MinHeight(n.get()->right)) + 1;
	}

	void Print(unique_ptr<node> &n)
	{
		if(n.get() == nullptr)
			return;

		Print(n.get()->left);
		cout << n.get()->data << endl;
		Print(n.get()->right);
	}

public:
	Tree()
	{
		root = nullptr;
	}

	bool IsEmpty()
	{
		return root.get() == nullptr;
	}

	void Add(T nodeData)
	{
		if(root.get() == nullptr)
		{
			root.reset(new node());
			root.get()->data = nodeData;
			return;
		}
		if(nodeData > root.get()->data)
			return Add(nodeData, root.get()->right);
		if(nodeData < root.get()->data)
			return Add(nodeData, root.get()->left);
	}

	void Print()
	{
		if(IsEmpty())
			return;

		Print(root.get()->left);
		cout << root.get()->data << endl;
		Print(root.get()->right);
	}

	bool IsBalanced()
	{
		//if its balanced, then the minimum span and max span will differ by 1 or 0
		int diff = MaxHeight(root) - MinHeight(root);
		if(diff <= 1)
			return true;

		return false;
	}
};

typedef Tree<int>::node NODE;
int main()
{
	Tree<int> tree;
	tree.Add(10);
	tree.Add(12);
	tree.Add(8);

	if(tree.IsEmpty())
		cout << "Empty Tree" << endl;
	else
		cout << "Non Empty tree" << endl;

	tree.Print();

}
