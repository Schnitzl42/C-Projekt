#include <string>
#include <iostream>
#include <curl/curl.h>
#include "RssFeed.h"
#include "XMLParser.h"

using namespace std;

size_t size = 0;

size_t write_to_string(void *ptr, size_t size, size_t count, void *stream) {
  ((string*)stream)->append((char*)ptr, 0, size*count);
  return size*count;
}

RssFeed::RssFeed(string url_param) : url(url_param){
  //write content of url in data
  //cout << url << endl;
  //cout << url_param << endl;
  CURL* curl;
  curl_global_init(CURL_GLOBAL_ALL); //pretty obvious
  curl = curl_easy_init();

  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &write_to_string);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    CURLcode res = curl_easy_perform(curl);
    //cout << "Variable response : " << data;
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  //parse data
  XMLParser::parseData(data, articles);
}

list<Article> RssFeed::getArticles(){
  return articles;
}

void RssFeed::printArticles(){
  for(auto iter = articles.begin(); iter != articles.end(); iter++){
    iter->printTitle();
  }
}

string RssFeed::getUrl(){
  return url;
}
