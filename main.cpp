#include <iostream>
#include <vector>
#include <fstream>
#include "Wordlist.h"

using namespace std;

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
    string contents((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();
    
    cout << contents;

    return 0;
}


// http://stackoverflow.com/questions/195323/what-is-the-most-elegant-way-to-read-a-text-file-with-c
