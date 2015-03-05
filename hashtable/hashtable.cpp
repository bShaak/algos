#include <iostream>
#include <string>
#include <list>

const int tableSize = 127;

class hashtable
{
public:
	struct pair
	{
		std::string key;
		int value;
	};

	void add(std::string &key, int value)
	{
		pair p;
		p.key = key;
		p.value = value;

		unsigned index = hash(key);
		aList[index].push_back(p);
	}

	int lookup(std::string &s)
	{
		std::list<pair> l = lookup_private(s);
		if(l.size() > 0)
		{
			for(auto itr = l.begin(); itr != l.end(); ++itr)
			{
				if((*itr).key == s)
					return (*itr).value;
			}
		}
		return -1;//return -1 if not found
	}

	void remove(std::string &s)
	{
		unsigned index = hash(s);
		std::list<pair> & l = aList[index];
		for(auto itr = l.begin(); itr != l.end(); )
		{
			if((*itr).key == s)
			{
				itr = l.erase(itr);
				return;
			}
			else
				++itr;
		}
	}

	void replace(std::string &s, int value)
	{
		unsigned index = hash(s);
		std::list<pair> & l = aList[index];
		for(auto itr = l.begin(); itr != l.end(); )
		{
			if((*itr).key == s)
			{
				(*itr).value = value;
				return;
			}
			else
				++itr;
		}
	}


private:
	std::list<pair> aList[tableSize];

	unsigned hash(std::string &key)
	{
		unsigned h = 0;
		for(auto itr = key.begin(); itr != key.end(); ++itr)
		{
			h = (h << 4) + *itr;
		}
		return h % tableSize;
	}

	std::list<pair> const & lookup_private(std::string &s)
	{
		unsigned index = hash(s);
		return aList[index];
	}
};

int main()
{
	hashtable hTable;
	std::string s("beed");
	std::string s1("test");

	std::cout << s << std::endl;
	std::cout << s1 << std::endl;

	hTable.add(s, 1);
	hTable.add(s1, 100);

	int tmp = hTable.lookup(s);
	std::cout << tmp << std::endl;

	tmp = hTable.lookup(s1);
	std::cout << tmp << std::endl;

	hTable.remove(s1);

	tmp = hTable.lookup(s1);
	std::cout << tmp << std::endl;

	hTable.replace(s, 15);
	tmp = hTable.lookup(s);
	std::cout << tmp << std::endl;
}



