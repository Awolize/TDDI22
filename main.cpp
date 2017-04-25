#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <locale>
#include "Wordlist.h"

using namespace std;

void clean_word(string & word)
{
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    size_t str_f = word.find_first_not_of("\"\'(");
    word.erase(0, str_f);
    size_t str_l = word.find_last_not_of("!?;,:.\"\')");
    word.erase(str_l+1, word.length());    
 
    for (unsigned int i{0}; i < word.length(); i++)
    {
	if(word[i] == '\'' && word[i+1] == 's')
	{
	    if(word.length() > i+3)
	    {
		if(word[i+2] == '\''  && word[i+3] == 's')
		{
		    word += "(!?;,:.\"\')";
		}
	    }
	    word.erase(remove(word.begin(), word.end(), 's'), word.end());
	    word.erase(remove(word.begin(), word.end(), '\''), word.end());
	}

        if(word[i] == '-' && word[i+1] == '-')
	{
	    word += "(!?;,:.\"\')";
	}
    }
}

bool valid_word(string word)
{
    if (word.size() < 3)
	return false;
    bool is_alpha{true};
    for_each(word.begin(), word.end(), [&is_alpha](char c)
	     {
		 if (!(isalpha(c)) && is_alpha)
		 {
		     is_alpha = false;
		     if (c == '-')
			 is_alpha = true;
		 }
	     });
    if (!is_alpha)
	return false;
    else
	return true;
}

int main(int argc, char* argv[])
{
    int outputchoser {0};
    //  --- ARG Table ---
    if (argc == 1)
	throw invalid_argument("\nError: argument missing or invalid. \n" 
			       "Usage: a.out FILE [-a] [-f] [-o]");
    if (argc == 2)
	throw invalid_argument("\nError: Second argument missing or invalid. \n" 
			       "Usage: a.out FILE [-a] [-f] [-o]");
    else if (argc == 3)
    {
	string tempstring = "-o";
        if (tempstring == "-a")
	    outputchoser = 1;
	else if (tempstring == "-o")
	    outputchoser = 2;
	else if (tempstring == "-f")
	    outputchoser = 3;
	else
	    throw invalid_argument("\nError: Third argument missing or invalid. \n" 
				    "Usage: a.out FILE [-a] [-f] [-o]");
    } 
    string filename = argv[1];
    ifstream fin(filename); 
    Wordlist test;
    for_each(istream_iterator<string>(fin), istream_iterator<string>(), [&test](string word) {
	    clean_word(word);
	    if(valid_word(word))
	    {
		test.insertword(word);
	    }
	});
    fin.close();
    if(outputchoser == 1)
	test.outputwordsalfa();
    if(outputchoser == 2)
	test.outputwordsbyvalue();
    if(outputchoser == 3)
	test.outputwordsbyfreq();
    return 0;
}
