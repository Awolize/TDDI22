#include "Wordlist.h"
#include <iterator>
#include <utility>
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

void Wordlist::insertword(string word)
{
    std::map<string,int>::iterator it;
    it = Wordsinlist.find(word); 
    if((it == Wordsinlist.end()))
    {
	Wordsinlist[word] = sizeofmap;	
	sizeofmap++;
    }
    if (std::find(freq.at(0).first(), freq.at(0).end(), word) != freq.at(0).first())
    {
	cout << "pepesi";
    }
    else 
	freq.push_back(std::make_pair(word, 1)); 
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
	cout << (*it).first << ": " << (*it).second << endl;
    }
}

void Wordlist::outputwordsbyfreq()
{

    cout << freq.at(0).second;

}

