#include "Wordlist.h"
#include <iterator>
#include <utility>
#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

void Wordlist::Insertword()
{
    Wordsinlist[1200] = "kristoffer";
    Wordsinlist[1201] = "kristoffer1";
    Wordsinlist[1202] = "kristoffer2";
    Wordsinlist[1203] = "kristoffer3";
    Wordsinlist[1204] = "kristoffer4";
}

void Wordlist::outputwords()
{
    for( map<int, string>::iterator ii=Wordsinlist.begin(); ii!=Wordsinlist.end(); ++ii)
    {
	cout << (*ii).first << ": " << (*ii).second << endl;
    }
}
