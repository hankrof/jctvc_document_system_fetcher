#ifndef CRAWLER_H
#define CRAWLER_H
#include <curl/curl.h>
#include <cassert>
#include <memory>
#include <string>
class Crawler
{
public:
	Crawler(std::string url = std::string());
	virtual ~Crawler() = 0;
	Crawler(const Crawler&) = delete;
	Crawler& operator=(const Crawler&) = delete;
	virtual bool connect() = 0;
	const std::string& getContent() const;
protected:
	std::string _url;
	std::string _content;
};

class HTMLCrawler : public Crawler
{
public:
	HTMLCrawler(std::string url);
	bool connect();
private:
	void init();
	std::unique_ptr<CURL, decltype(&curl_easy_cleanup)> _curl;
};
#endif