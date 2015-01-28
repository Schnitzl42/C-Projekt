#include <string>
#include <iostream>
#include "ArticleBase.h"
#ifndef ARTICLE_H
#define ARTICLE_H

using namespace std;

class Article : public ArticleBase{
  string author;
  string date;
  string link;

  public:
    Article(string title, string description, string author, string date, string link);
    Article() = default;
    virtual void ToString();
    friend bool operator< (const Article &left, const Article &right);

    string getAuthor();
    string getDate();
    string getLink();
    //calls the subclasses info() info in case
    virtual string info();	//override (c++ 11 gcc 4.7.)
};
#endif
