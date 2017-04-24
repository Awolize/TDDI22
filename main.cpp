#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <locale>
#include "Wordlist.h"

using namespace std;

void clean_word(string & word)
{
    size_t str_f = word.find_first_not_of("\"\'(");
    word.erase(0, str_f);
    size_t str_l = word.find_last_not_of("!?;,:.\"\')");
    word.erase(str_l+1, word.length());    

    char gen_s = 's';  
    for (unsigned int i{0}; i < word.length(); i++)
    {
	if(word[i] == '\'' && word[i+1] == 's')
	{
	    if(!(i+3 > word.length()))
	    {
		if(!(word[i+2] == '\'' && word[i+3] == 's'))
		    word.erase(remove(word.begin(), word.end(), gen_s), word.end());	    
	    }
	    else
		word.erase(remove(word.begin(), word.end(), gen_s), word.end());
	}

	else if(word[i] == '-' && word[i+1] == '-')
	{
	    word += "(!?;,:.\"\')";
	}
    }
    transform(word.begin(), word.end(), word.begin(), ::tolower);
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

void Communism()
{
    cout << endl <<     "▄▀▀▀▀ ▄▀▀▀▀▄  █    █ █    █ █    █ █    █ ▅ ▄▀▀▀▀ █    █ \n█     █    █  █▚  ▞█ █▚  ▞█ █    █ █▚   █   █     █▚  ▞█\n█     █    █  █ ▚▞ █ █ ▚▞ █ █    █ █ ▚  █ █ ▀███▄ █ ▚▞ █\n█     █    █  █    █ █    █ █    █ █  ▚ █ █     █ █    █\n▀▄▄▄▄ ▀▄▄▄▄▀  █    █ █    █ ▀▄▄▄▄▀ █   ▚█ █ ▄▄▄▄▀ █    █" << endl <<endl;
}

int main(int argc, char* argv[])
{
/*
    int outputchoser {0};
    //  --- ARG Table ---
    if (argc == 1);
	throw invalid_argument("\nError: argument missing or invalid. \n" 
			       "Usage: a.out FILE [-a] [-f] [-o]");
    if (argc == 2)
	throw invalid_argument("\nError: Second argument missing or invalid. \n" 
			       "Usage: a.out FILE [-a] [-f] [-o]");
    else if (argc == 3)
    {
        if (argv[3] == "-a")
	    outputchoser = 1;
	else if (argv[3] == "-o")
	    outputchoser = 2;
	else if (argv[3] == "-f")
	    outputchoser = 3;
	else
	    throw invalid_argument("\nError: Third argument missing or invalid. \n" 
				    "Usage: a.out FILE [-a] [-f] [-o]");
    } 
*/

    string filename = argv[1];
    if (std::string::npos != filename.find(".txt"))
	cout << "Found .txt" << endl << endl;

    ifstream fin(filename); 
    vector<string> words;
    Wordlist test;
    for_each(istream_iterator<string>(fin), istream_iterator<string>(), [&words,&test](string word) {
	    clean_word(word);
	    if(valid_word(word))
	    {
		words.push_back(word);
		test.insertword(word);
	    }
	});

    fin.close();
    /*
    for(int i{0}; i < words.size(); i++)
	cout << words.at(i) << endl;
    
    
    for_each(words.begin(), words.end(), [](string word) {
	    cout << word << endl;
	    
	});
    */
    
    test.outputwordsalfa();
    Communism();
    test.outputwordsbyvalue();
    return 0;
}


// http://stackoverflow.com/questions/195323/what-is-the-most-elegant-way-to-read-a-text-file-with-c
