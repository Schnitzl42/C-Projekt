#include <string>
#include <iostream>
#include <curl/curl.h>
#include <memory>
#include "XMLParser.h"

using namespace std;


void XMLParser::parseData(string data, list<Article> &articles){
  //shared pointer on data
  //auto datap = make_shared<string>(data);
  size_t posStart = 0;
  size_t posEnd = 0;
  string item;
  //cout << data << endl;
  posStart = data.find("<item>", posStart);
  posEnd = data.find("</item>", posStart);
  while(posEnd != data.npos){

    //item = data.substr(posStart + 6, posEnd-posStart-6);
    //use shared pointer on item
    unique_ptr<string> item(new string(cutXmlItem<string>(data.substr(posStart, data.npos), "item")));

    //cout << posStart << endl;
    //cout << posEnd << endl;
    //cout << item << endl;
    Article a(cutXmlItem<string>(*item, "title"), cutXmlItem<string>(*item, "description"),
	      cutXmlItem<string>(*item, "author"),cutXmlItem<string>(*item, "pubDate"),
              cutXmlItem<string>(*item, "link"));
    articles.push_front(a);
    //a.ToString();
    //RssFeed::articles.add(x);
    //description
    //author;
    //date;
    //link;
    posStart = data.find("<item>", posEnd);
    posEnd = data.find("</item>", posStart);
    //cout << "start: " << posStart;
    //cout << " end: " << posEnd << endl;


    //posStart = find (data, "<item", posStart);
    //posEnd = find (data, "</item", posStart);
    //substring (posStart, posEnd, item);

  }
}

template<typename T>
string XMLParser::cutXmlItem(string data, T match){
  size_t posStart = 0;
  size_t posEnd = 0;
  string temp = "<" + match + ">";
  posStart = data.find(temp, posStart);
  posEnd = data.find("</"+match+">", posStart);

  if(posEnd == posStart){
    return "";
  }
  //cout << posStart << endl;
  //cout << posEnd << endl;
  //cout << item << endl;

  return data.substr(posStart + match.size() + 2 , posEnd-posStart- match.size() -2);
}
