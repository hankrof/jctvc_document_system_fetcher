#include "crawler.h"
Crawler::Crawler(std::string url)
	: _url(url)
{

}
Crawler::~Crawler()
{
	//dummy code
}
HTMLCrawler::HTMLCrawler(std::string url)
	: Crawler(url), _curl(curl_easy_init(), curl_easy_cleanup)
{
	if (_curl == nullptr)
		throw std::logic_error("Could not initialize curl library"
			"in HTMLCrawler::HTMLCrawler()");
	init();
}

const std::string& Crawler::getContent() const
{
	return _content;
}

bool HTMLCrawler::connect()
{
	CURLcode res = curl_easy_perform(_curl.get());
	return res == CURLE_OK;
}

size_t writeCallback(void *content, size_t elementSize, size_t nbElement, void *userData)
{
	std::string& concatenatedData = *reinterpret_cast<std::string*>(userData);
	size_t totalSize = elementSize * nbElement;
	std::string allocatedData;
	allocatedData.resize(totalSize);
	std::copy(reinterpret_cast<char*>(content),
		reinterpret_cast<char*>(content)+totalSize,
		allocatedData.begin());
	concatenatedData.append(std::move(allocatedData));
	return totalSize;
}

void HTMLCrawler::init()
{
	curl_easy_setopt(_curl.get(), CURLOPT_URL, _url.c_str());
	curl_easy_setopt(_curl.get(), CURLOPT_FOLLOWLOCATION, 1);
	curl_easy_setopt(_curl.get(), CURLOPT_WRITEFUNCTION, writeCallback);
	curl_easy_setopt(_curl.get(), CURLOPT_WRITEDATA, reinterpret_cast<void*>(&_content));
}