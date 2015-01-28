#include <string>
#include <iostream>
#include "Article.h"

using namespace std;

Article::Article(string title, string description, string author, string date, string link) : ArticleBase(title, description), author(author), date(date), link(link){}

void Article::ToString(){
  cout << title << endl << description << endl << author << endl << date << endl << link <<endl;
}

bool operator< (const Article &left, const Article &right)
{
    return left.title < right.title;
}

string Article::getAuthor(){
  return author;
}

string Article::getDate(){
 return date;
}

string Article::getLink(){
 return link;
}

string Article::info(){
    return "title: "+title + "\ndescription: " + description + "\nauthor: " + author + "\ndate: " + date + "\nlink: " + link + "\n";
}
