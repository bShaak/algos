
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//ascii only
bool allUniqueCharacters(string &s)
{
	bool a[128];//128 ascii chars
	memset(a, false, 128);
	char tmp;
	for(auto it = s.begin(); it != s.end(); it++)
	{
		tmp = *it;
		if(a[tmp])
			return false;
		a[tmp] = true;
	}
	return true;
}

bool allUniqueCharactersNoMem(string &s)
{
	char tmp;
	unsigned size = s.size();
	for(unsigned i = 0; i < size; i++)
	{
		tmp = s[i];
		for(unsigned j = i+1; j < size; j++)
		{
			if(tmp == s[j])
				return false;
		}
	}
	return true;
}

void stringReverse(char *s)
{
	int size = strlen(s);
	char *left = s;
	char *right = s + size-1;

	while(left < right)
	{
		char tmp = *right;
		*right = *left;
		*left = tmp;
		left++;
		right--;
	}
}

void removeDuplicates(string &s)
{
	unsigned length = s.size();
	char tmp;
	for(unsigned i = 0; i < length; i++)
	{
		tmp = s[i];
		length = s.size();
		for(unsigned j = i+1; j < length; j++)
		{
			if(tmp == s[j])
			{
				s.erase(j, 1);
				j--;
			}
		}
	}
}
//edge cases s1 > s2 or s2 > s1
//normal s1 same length as s2
bool isAnagram(string &s1, string &s2)
{
	unsigned size1 = s1.size();
	unsigned size2 = s2.size();
	unsigned i = 0;
	unsigned j = 0;

	reverse(s2.begin(), s2.end());
	cout << s2 << endl;
	while(i < size1 && j < size2)
	{
		//skip spaces
		while(s1[i] == ' ')
		{
			i++;
		}
		while(s2[j] == ' ')
		{
			j++;
		}
		//if one string is finished while the other still has characters
		if((i > size1 && j < size2) || (i < size1 && j > size2))
			return false;
		//if the characters differ
		if(s1[i] != s2[j])
		{
			return false;
		}
	}
	return true;
}

void replaceSpaces(string s)
{
	
}

int main()
{
	string s1("race car");
	string s2("race car");

	if(isAnagram(s1, s2))
	{
		cout << "hell yea" << endl;
	}
	else
	{
		cout << "fuck" << endl;
	}
	
}