#include "Wordlist.h"
#include <iterator>
#include <utility>
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

void Wordlist::insertword(string word)
{
    insertwordfreq(word);
    std::map<string,int>::iterator it;
    it = Wordsinlist.find(word);
    if((it == Wordsinlist.end()))
    {
	Wordsinlist[word] = sizeofmap;
	sizeofmap++;
    }
}

void Wordlist::insertwordfreq(string word)
{
    freqlist[freqtempnr] = word;
    freqtempnr++;
    
}

void Wordlist::reversinglist()
{
    for( map<string, int>::iterator iii=Wordsinlist.begin(); iii!=Wordsinlist.end(); ++iii)
    {
	reverselist[(*iii).second] = (*iii).first;
    }
}


void Wordlist::outputwordsalfa()
{
    for( map<string, int>::iterator ii=Wordsinlist.begin(); ii!=Wordsinlist.end(); ++ii)
    {
	cout << (*ii).first << ": " << (*ii).second << endl;
    }
}
 
void Wordlist::outputwordsbyvalue()
{   
    reversinglist();
    for( map<int, string>::iterator iiii=reverselist.begin(); iiii!=reverselist.end(); ++iiii)
    {
	cout << (*iiii).first << ": " << (*iiii).second << endl;
    }
}

void Wordlist::outputwordsbyfreq()
{
    for( map<int, string>::iterator iiiii=freqlist.begin(); iiiii!=freqlist.end(); ++iiiii)
    {
	cout << (*iiiii).first << ": " << (*iiiii).second << endl;
    }
}


/*


*/
