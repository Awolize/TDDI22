#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <locale>
#include "Wordlist.h"

using namespace std;

void clean_word(string & word)
{
    word.erase(remove_if(word.begin(), word.end(), [](char c)
			 {
			     return (c == '/') || (c == '!') || (c == '"') || (c == '\'') || (c == '(') || (c == ')') || (c == '?') || (c == ';') || (c == ',') || (c == ':')  || (c == '.');
			 }), word.end());
}
bool valid_word(string word)
{
    if (word.size() < 3)
	return false;
    
    bool is_alpha{true};
    for_each(word.begin(), word.end(), [&is_alpha](char c)
	     {
		 if (!isalpha(c) || c != '-')
		     is_alpha = false;
	     });

    if (!is_alpha)
	return false;

return true;
    }

int main(int argc, char* argv[])
{

/* 
   --- ARG Table ---
    if (argc == 1);
        cout << "Error: No arguments given." << endl;
        cout << "Usage: a.out FILE [-a] [-f] [-o N]" << endl;
    else if (argc == 2)
        cout << "Error: Second argument missing or invalid." << endl;
        cout << "Usage: a.out FILE [-a] [-f] [-o N]" << endl;
    else if (arc == 3)
    {
        if (argv == -a);
        else if (argv == -f);
        else error
    } 
    else if (argc == 4)  
    { 
         if (argv == -o);
         {
   	     if (argv == int);
	     else error;
         }
	 else error
    }
    else error;
*/
    string filename = argv[1];
    if (std::string::npos != filename.find(".txt"))
	cout << "Found .txt" << endl;

    ifstream fin(filename); 
    vector<string> words;

    for_each(istream_iterator<string>(fin), istream_iterator<string>(), [&words](string word) {
	    clean_word(word);
	    if(valid_word(word))
	    {
		words.push_back(word);
	    }
	});

    fin.close();
    
    for_each(words.begin(), words.end(), [](string word) {
	    cout << word << endl;
	});

    return 0;
}


// http://stackoverflow.com/questions/195323/what-is-the-most-elegant-way-to-read-a-text-file-with-c
