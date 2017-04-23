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
    void Insertword();
    void outputwords();
    

private:
    std::map<int, std::string> Wordsinlist;
};



#endif
