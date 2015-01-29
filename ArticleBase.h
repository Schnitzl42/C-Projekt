#include <string>
#include <iostream>
#ifndef ARTICLEBASE_H
#define ARTICLEBASE_H

using namespace std;

class ArticleBase {
  protected:
    string title;
    string description;

  public:
    ArticleBase(string title, string description);
    ArticleBase() = default;
    virtual void ToString();
    void printTitle();
    friend bool operator< (const ArticleBase &left, const ArticleBase &right);

    string getTitle();
    string getDescreption();

    //calls the subclasses info() info in case
    virtual string info();
};
#endif
