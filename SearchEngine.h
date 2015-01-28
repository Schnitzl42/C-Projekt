#include <string>
#include <list>
#include <iostream>
#include <vector>
#include <set>
#include "RssHandler.h"
#include "Article.h"

using namespace std;

class SearchEngine{

  //RssHandler handler;
  static vector<string> parseKeywords(const string& keywords);
  

  public:
    //SearchEngine(RssHandler handler);
    static set<Article> filterFor(RssHandler handler, string keywords);
};
