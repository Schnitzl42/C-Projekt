#include <string>
#include <iostream>
#include <curl/curl.h>
#include <fstream>
#include <memory>
#include "RssHandler.h"

using namespace std;

RssHandler::RssHandler(string filename){
  shared_ptr<ifstream> filep;
  ifstream file;
  file.open(filename);
  string url;
  if(file.is_open()){
    while(getline(file, url)){
      urls.push_back(url);
      //cout << url << endl;
      feeds.push_front(url);
    }
  }
  file.close();
}

list<RssFeed> RssHandler::getFeeds(){
  return feeds;
}

void RssHandler::printUrls(){
  auto iter = urls.begin();
  cout << "urls" << endl;
  cout << urls.size() << endl;


  while(iter != urls.end()){
    cout << *iter << endl;
    iter++;
  }
}


RssFeed RssHandler::getFirstFeed(){
    return feeds.front();
}

void RssHandler::printAllTitles(){
  for(auto iter = feeds.begin(); iter != feeds.end(); iter++){
    iter->printArticles();
    cout << "=========================="<< endl;
  }

/*list<Article> RssHandler::getAllArticles(){
  list<Article> articles;
  for(auto feedIter = handler.getFeeds().begin(); feedIter != handler.getFeeds().end(); feedIter++){
     for(auto )
  }
  for_each(handler.getFeeds().begin(), handler.getFeeds().end(),
            [&articles](RssFeed f){articles.merge(f.getArticles());});
  return articles;
}*/

}
