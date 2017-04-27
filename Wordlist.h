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
    void outputwordsbyvalue(size_t);
    void outputwordsbyfreq();
    void size_word();
private:
    void reversinglist();
    std::vector<std::pair<int, std::string>> freq;
    std::vector<std::pair<std::string, int>> wordsinlist;
    std::vector<std::string> occurrence;
    size_t longest_word{0};
};



#endif
