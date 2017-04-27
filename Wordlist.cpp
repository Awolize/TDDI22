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
    occurrence.push_back(word);

    if (wordsinlist.size() == 0)
    {
	wordsinlist.push_back(std::make_pair(word,1)); 
    }
    else
    {
	vector<pair<string, int>> word_temp{wordsinlist};
	int i{0};
	bool found{false};
	for_each(wordsinlist.begin(), wordsinlist.end(), [&found, &word, &word_temp, &i](pair<string, int> p)
		 {
		     if(p.first == word)
		     {
			 word_temp.at(i).second++;
			 found = true;
		     }
		     ++i;
		 });
	wordsinlist = word_temp;
	if(found == false)
	{
	    wordsinlist.push_back(std::make_pair(word, 1)); 
	}
    }

    
    if (freq.size() == 0)
    {
	freq.push_back(std::make_pair(1, word)); 
    }
    else
    {
	vector<pair<int, string>> freq_temp{freq};
	int i{0};
	bool found{false};
	for_each(freq.begin(), freq.end(), [&found, &word, &freq_temp, &i](pair<int, string> p)
		 {
		     if(p.second == word)
		     {
			 freq_temp.at(i).first++;
			 found = true;
		     }
		     ++i;
		 });
	freq = freq_temp;
	if(found == false)
	{
	    freq.push_back(std::make_pair(1, word)); 
	}
    }
}
// -------------------------------



/*

   else
    {
	vector<pair<int, string>> freq_temp{freq};

	int i{0};
	bool found{false};
	for_each(freq.begin(), freq.end(), [&found, &word, &freq_temp, &i](pair<int, string> vec1)
		 {
		     
		     found = false;
		     if(vec1.second == word)
		     {
			 freq_temp.at(i).first++;
			 found = true;
			 return 0;
		     }
		     i++;
		 });
	freq = freq_temp;
	if(!found)
	    freq.push_back(std::make_pair(1, word)); 
	
    }


  page  3
  the   2
  body  1
  title 1
*/
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
