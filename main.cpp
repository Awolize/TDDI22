#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <locale>
#include "Wordlist.h"
// Hej
using namespace std;

void clean_word(string & word)
{
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    size_t str_f = word.find_first_not_of("\"\'(");
    word.erase(0, str_f);
    size_t str_l = word.find_last_not_of("!?;,:.\"\')");
    word.erase(str_l+1, word.length());    
 
    for_each(word.begin(), word.end(), [&word](unsigned int i)
	     {
		 if(word[i] == '\'' && word[i+1] == 's')
		 {
		     if(word.length() > i+3)
		     {
			 if(word[i+2] == '\''  && word[i+3] == 's')
			     word += "(!?;,:.\"\')";
		     }
		     word.erase(remove(word.begin(), word.end(), 's'), word.end());
		     word.erase(remove(word.begin(), word.end(), '\''), word.end());
		 }
		 if(word[i] == '-' && word[i+1] == '-')
		     word += "(!?;,:.\"\')";
	     });
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

int Check_args(vector<string> & args, int & argc, size_t & N)
{ 
    if (argc == 2) 	
    {
	cout << ("Error: Second argument missing or invalid. \n" 
		 "Usage: a.out FILE [-a] [-f] [-o N]\n") << endl;
	return 1;
    }
    if (argc == 3 || args.at(2) == "-o")
    {
        if (args.at(2) == "-a")
	    return 2;
	else if (argc == 4 && args.at(2) == "-o" && stoi(args.at(3)) >= 0)
	{
	    N = stoi(args.at(3));
	    return 3;
	}
	else if (args.at(2) == "-f")
	    return 4;
	else if (args.at(2) == "-o")
	{
	    cout << ("Error: Fourth argument missing or invalid. \n" 
		     "Usage: a.out FILE [-a] [-f] [-o N]\n") << endl;
	    return 1;
	}
	else	
	{
	    cout << ("Error: Third argument missing or invalid. \n" 
		     "Usage: a.out FILE [-a] [-f] [-o N]\n") << endl;
	    return 1;
	}
    } 
    else if (argc > 3) 	
    {
	cout << ("Error: Too many arguments. \n" 
		 "Usage: a.out FILE [-a] [-f] [-o N]\n") << endl;
	return 1;
    }
    else
    {
	cout << ("Error: Third argument missing or invalid. \n" 
		 "Usage: a.out FILE [-a] [-f] [-o N]\n") << endl;
	return 1;
    }

}

int main(int argc, const char* argv[])
{
    int outputchooser {0};
    size_t N{0};
    //  --- ARG Table ---
    if (argc == 1) 	
    {
	cout << ("Error: No arguments given. \n" 
		 "Usage: a.out FILE [-a] [-f] [-o N]\n") << endl;
	return 1;
    }

    vector<string> args(argv,argv + argc);

    outputchooser = Check_args(args, argc, N);
    
    if (outputchooser == 1)
	return 1;

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

    if(outputchooser == 2)
	test.outputwordsalfa();
    else if(outputchooser == 3)
	test.outputwordsbyvalue( N );
    else if(outputchooser == 4)
	test.outputwordsbyfreq();
    return 0;
}
