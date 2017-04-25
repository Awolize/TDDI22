#include "Wordlist.h"
#include <iterator>
#include <utility>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <algorithm>

using namespace std;

void Wordlist::insertword(string word)
{
    bool truetyp{true};
    map<string,int>::iterator it;
    it = Wordsinlist.find(word); 
    if((it == Wordsinlist.end()))
    {
	Wordsinlist[word] = sizeofmap;	
	sizeofmap++;
    }
    
    if (freq.size() == 0)
    {
	freq.push_back(std::make_pair(1, word)); 
    }
    else
    {
	for (size_t i{0}; i < freq.size(); ++i)
	{
	    truetyp = true;
	    if (freq.at(i).second == word)
	    {
		freq.at(i).first++;
		truetyp = false;
		break;
	    }
	}
	if(truetyp)
	{
	    freq.push_back(std::make_pair(1, word)); 
	}	
    }
}

void Wordlist::reversinglist()
{
    for( map<string, int>::iterator it=Wordsinlist.begin(); it!=Wordsinlist.end(); ++it)
    {
	reverselist[(*it).second] = (*it).first;
    }
}

void Wordlist::outputwordsalfa()
{
    for( map<string, int>::iterator it=Wordsinlist.begin(); it!=Wordsinlist.end(); ++it)
    {
	cout << (*it).first << ": " << (*it).second << endl;
    }
}
 
void Wordlist::outputwordsbyvalue()
{   
    reversinglist();
    for( map<int, string>::iterator it=reverselist.begin(); it!=reverselist.end(); ++it)
    {
	cout << (*it).second << endl;
    }
}

void Wordlist::outputwordsbyfreq()
{
    sort(freq.begin(), freq.end()); 
    for (int i{(int)freq.size()-1}; i >= 0; i--)
    {
	cout << freq.at(i).first << ": " << freq.at(i).second  << endl;
    }
}
