#include "Wordlist.h"
#include <iterator>
#include <utility>
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

void Wordlist::insertword(string word)
{
    // insertwordfreq(word);
    std::map<string,int>::iterator it;
    it = Wordsinlist.find(word);
    if((it == Wordsinlist.end()))
    {
	Wordsinlist[word] = sizeofmap;
	
	sizeofmap++;
    }
    freqlist[temptest].push_back(word);
    temptest++;
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
    
    for( map<int, std::vector<std::string >>::iterator it=freqlist.begin(); it!=freqlist.end(); it++)
    {
	cout << (*it).first << ": " << (*it).second.at(0) << endl;
    }


}

