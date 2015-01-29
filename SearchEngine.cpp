#include <string>
#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include "SearchEngine.h"
#include "StringTools.h"

using namespace std;

//SearchEngine::SearchEngine(RssHandler handler) : handler(handler){}

vector<string> SearchEngine::parseKeywords(const string& keywords){
//     auto f = //StringTools::splitString(keywords);
       auto f = [&keywords]()->vector<string>{return (keywords == "@demo") ?
 	      StringTools::splitString("Android Sicherheit") : StringTools::splitString(keywords);};
     return f();
    //return (keywords == "@demo") ?
	//      StringTools::splitString("Android Sicherheit") : StringTools::splitString(keywords);
}

set<Article> SearchEngine::filterFor(RssHandler handler, string keywords){
  vector<string> kws = SearchEngine::parseKeywords(keywords);
  cout << "Listing for:" << kws[0] << endl;

   set<Article> results;
    //cout << handler.getFeeds().size() << endl;
    auto feeds = handler.getFeeds();
     for(auto feedIter = feeds.begin(); feedIter != feeds.end(); feedIter++){
          //cout << feedIter->getUrl() << endl;
      list<Article> articles = feedIter->getArticles(); //handler.getFirstFeed().getArticles();
      //use set to avoid duplicates
    for(auto iterArticles = articles.begin(); iterArticles != articles.end(); iterArticles++){
      for(auto iterWords = kws.begin(); iterWords != kws.end(); iterWords++){
          if(iterArticles->getTitle().find(*iterWords, 0) < iterArticles->getTitle().npos){
            results.insert(*iterArticles);
            //cout << iterArticles->getTitle() << endl;
          }
        }
      }
    }
  return results;
}



