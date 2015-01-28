#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include "Article.h"


using namespace std;

//template<typename V>
class XMLParser{
  //V value;
  public:
  template<typename T>
  static string cutXmlItem(string data, T match);
  static void parseData(string data, list<Article> &articles);
};
