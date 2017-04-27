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

    vector<pair<string, int>> word_temp;
    vector<pair<int, string>> freq_temp;

    occurrence.push_back(word);

    if (wordsinlist.size() == 0)
    {
	wordsinlist.push_back(std::make_pair(word,1)); 
	//cout << "hej";
    }
    else
    {
	//cout << wordsinlist.size();
	
	for_each(wordsinlist.begin(), wordsinlist.end(), [&truetyp1, &word, &word_temp](pair<string, int> vec)
		 {
		     truetyp1 = true;

		     // cout << "hejsan";
		     if(vec.first == word)
		     {
			 
			 
			 cout << vec.second << endl;
			 truetyp1 = false;
			 
//			 return 0;
		     }
		     
		 });
	if(truetyp1)
	{
	    
	    wordsinlist.push_back(std::make_pair(word,1)); 
	}	
	copy(word_temp.begin(), word_temp.end(), wordsinlist.begin());
    }
    
    if (freq.size() == 0)
    {
	freq.push_back(std::make_pair(1, word)); 
    }
    else
    {
	for_each(freq.begin(), freq.end(), [&truetyp, &word](pair<int, string> vec1)
		 {
		     truetyp = true;
		     if(vec1.second == word)
		     {
			 //cout << vec1.first << endl;
			 vec1.first++;
			 truetyp = false;
			 //return 0;
		     }
		     
		 });
	if(truetyp)
	{
	    freq.push_back(std::make_pair(1, word)); 
	}
	//else if (
    }
}

void Wordlist::outputwordsalfa() // -a
{
    size_word();
    size_t temp{longest_word};
    temp = longest_word;
    sort(wordsinlist.begin(), wordsinlist.end(), less<pair<string, int>>()); 
    for_each(wordsinlist.begin(), wordsinlist.end(), [&temp](pair<string, int> text)
	     {
		 cout << left << setw(temp) << text.first << " " << text.second  << endl;
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
    size_word();
    size_t temp{longest_word};
    sort(freq.begin(), freq.end(), greater<pair<int, string>>()); 

    for_each(freq.begin(), freq.end(), [&temp](pair<int, string> text)
	     {
		 cout << setw(temp) << text.second << " " << text.first  << endl;
	     });
}

void Wordlist::size_word()
{
    size_t temp{longest_word};
    for_each(freq.begin(), freq.end(), [&temp](pair<int, string> word)
	     {
		 if(word.second.size() > temp)
		     temp = word.second.size();
	     });
    longest_word = temp;
}
