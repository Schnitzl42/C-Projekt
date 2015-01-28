#include <string>
#include <list>
#include <iostream>
#include "Article.h"
#ifndef RSSFEED_H
#define RSSFEED_H

using namespace std;

class RssFeed{
  string url;
  list<Article> articles;
  string data;
  public:
    RssFeed(string url_param);
    list<Article> getArticles();
    void printArticles();
    string getUrl();

};
#endif
