#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include "RssFeed.h"
#ifndef RSSHANDLER_H
#define RSSHANDLER_H

using namespace std;

class RssHandler{
  vector<string> urls;
  list<RssFeed> feeds;
  public:
    RssHandler(string filename);
    //RssHandler();
    void printUrls();
    RssFeed getFirstFeed();
    list<RssFeed> getFeeds();
    //list<Article> getAllArticles();
    void printAllTitles();
};
#endif
