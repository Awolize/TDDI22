#include "Wordlist.h"
#include <iterator>
#include <utility>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

void Wordlist::insertword(string word)
{
    bool truetyp1{true};
    bool truetyp{true};

    occurrence.push_back(word);

    if (wordsinlist.size() == 0)
    {
	wordsinlist.push_back(std::make_pair(word,1)); 
    }
    else
    {
	for (size_t i{0}; i < wordsinlist.size(); ++i)
	{
	    truetyp1 = true;
	    if (wordsinlist.at(i).first == word)
	    {
		wordsinlist.at(i).second++;
		truetyp1 = false;
		break;
	    }
	}
	if(truetyp1)
	{
	    wordsinlist.push_back(std::make_pair(word,1)); 
	}	
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

void Wordlist::outputwordsalfa() // -a
{
    sort(wordsinlist.begin(), wordsinlist.end(), less<pair<string, int>>()); 
    for_each(wordsinlist.begin(), wordsinlist.end(), [](pair<string, int> text)
	     {
		 cout << left << setw(5) << text.first << " " << text.second  << endl;
	     });
}

void Wordlist::outputwordsbyvalue( size_t N ) // -o N
{   
    size_t c{0};
    for_each(occurrence.begin(), occurrence.end(), [&N, &c](string text)
	     {
		 
		 if (text.size() + c < N)
		 {
		     cout << text << " ";
		     c = text.size() + c + 1;
		 }
		 else
		 {
		     cout << endl;
		     c = text.size() + 1;
		     cout << text << " ";
		 }
		 
	     });
    cout << endl;
}

void Wordlist::outputwordsbyfreq() // -f
{
    sort(freq.begin(), freq.end(), greater<pair<int, string>>()); 
    for_each(freq.begin(), freq.end(), [](pair<int, string> text)
	     {
		 cout << setw(5) << text.second << " " << text.first  << endl;
	     });
}

void Wordlist::Legnth_Word()
{
    cout << Longest_word;
}
