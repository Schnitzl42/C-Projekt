#include <string>
#include <iostream>
#include "ArticleBase.h"

using namespace std;

ArticleBase::ArticleBase(string title, string description) : title(title), description(description){}

void ArticleBase::ToString(){
  cout << title << endl << description << endl;
}

bool operator< (const ArticleBase &left, const ArticleBase &right)
{
    return left.title < right.title;
}

string ArticleBase::getTitle(){
  return title;
}

string ArticleBase::getDescreption(){
 return description;
}

void ArticleBase::printTitle(){
  cout << title << endl;
}

string ArticleBase::info(){
    return "title: "+title + "\n description: " + description + "\n";
}
