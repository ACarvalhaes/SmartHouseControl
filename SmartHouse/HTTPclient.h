#pragma once
#define CURL_STATICLIB
#include "curl/curl.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>

class HTTPclient {
public:
	HTTPclient();		//constructor
	~HTTPclient();		//destructor

	void SetOption(CURLoption option, std::string parameter);
	void SetURL(std::string URL);
	void AddHeader(std::string header);
	void PUTrequest(std::string resource);
	void GETrequest(std::ofstream& responseFile);

	struct curl_slist* HeadersList;

private:
	CURL* curl;

	static size_t IgnoreWriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata);
	static size_t FileWriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata);
	
};