#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <memory>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>

class Wordlist
{
public:
    void insertword(std::string);
    void outputwordsalfa();
    void outputwordsbyvalue();
    void outputwordsbyfreq();
private:
    void reversinglist();
    void insertwordfreq(std::string);
    std::map<int, std::string> freqlist;
    std::map<int, std::string> reverselist;
    std::map<std::string, int> Wordsinlist;
    int sizeofmap {0};
    int freqtempnr {0};
};



#endif

/*      
   ▄▀▀▀▀ ▄▀▀▀▀▄  █    █ █    █ █    █ █    █ ▅ ▄▀▀▀▀ █    █
   █     █    █  █▚  ▞█ █▚  ▞█ █    █ █▚   █   █     █▚  ▞█
   █     █    █  █ ▚▞ █ █ ▚▞ █ █    █ █ ▚  █ █ ▀███▄ █ ▚▞ █
   █     █    █  █    █ █    █ █    █ █  ▚ █ █     █ █    █  
   ▀▄▄▄▄ ▀▄▄▄▄▀  █    █ █    █ ▀▄▄▄▄▀ █   ▚█ █ ▄▄▄▄▀ █    █
*/
     
     
