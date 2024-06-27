#pragma once
#define CURL_STATICLIB
#include "curl/curl.h"
#include <string>
#include <iostream>
#include <stdexcept>

class HTTPclient {
public:
	HTTPclient();		//constructor
	~HTTPclient();		//destructor

	void SetOption(CURLoption option, std::string parameter);
	void SetURL(std::string URL);
	void AddHeader(std::string header);
	void PUTrequest(std::string resource);

	struct curl_slist* HeadersList;

private:
	CURL* curl;
	
};