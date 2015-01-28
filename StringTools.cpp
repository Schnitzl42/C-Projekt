#include <sstream>
#include <iostream>
#include "StringTools.h"

using namespace std;

vector<string> StringTools::splitString(const string& in)
{
    //cout << in << cout;
    vector<string> kws;
    std::istringstream iss(in);
    do{
      string s;
      iss >> s;
      //cout << s << endl;
      kws.push_back(s);
    }while(iss);
    //last word is always \n or something useless
    kws.pop_back();
    return kws;
}
