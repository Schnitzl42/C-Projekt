#include <string>
#include <iostream>
#include <curl/curl.h>
#include <set>
#include <fstream>
#include <algorithm>
#include "RssHandler.h"
#include "XMLParser.h"
#include "SearchEngine.h"

using namespace std;

main(){
  cout << "The ultimate RSS Crawler! (Version 0.1)" << endl;
  RssHandler handler("rss_source.txt");
  //SearchEngine engine();

  cout << "Enter filter strings (seperated by space): ";
  string kw;
  getline(cin, kw);

  auto as = SearchEngine::filterFor(handler, kw);
  //cout << as.size() << endl;

  list<Article> list;
  for(auto iter = as.begin(); iter != as.end(); iter++){
    list.push_back(*iter);
    //iter->printTitle();	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }
//   for(auto iter = list.begin(); iter != list.end(); iter++){
//     iter->printTitle();
//   }
//    for_each(list.begin(), list.end(), [](Article a){cout << a.getTitle() << endl;});

  for(auto iter = list.begin(); iter != list.end(); iter++){
    iter->printTitle();
  }

  //handler.printUrls();
  //handler.printAllTitles();
  //handler.getFirstFeed();
}
