
all:
	g++ Main.cpp RssHandler.cpp RssFeed.cpp ArticleBase.cpp Article.cpp XMLParser.cpp SearchEngine.cpp StringTools.cpp -lcurl -std=c++0x -o UltimateRssCrawler
clean:
	rm -rf UltimateRssCrawler
