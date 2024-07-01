#include "HTTPclient.h"

HTTPclient::HTTPclient()
	:HeadersList(NULL)
{
	curl = curl_easy_init();
	if (!curl)
		throw std::runtime_error("Failed to initialize CURL");

	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
}

HTTPclient::~HTTPclient() {
	curl_easy_cleanup(curl);
	curl_slist_free_all(HeadersList);
}

void HTTPclient::SetOption(CURLoption option, std::string parameter) {
	curl_easy_setopt(curl, option, parameter.c_str());
}

void HTTPclient::SetURL(std::string URL) {
	curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
}

void HTTPclient::AddHeader(std::string header) {
	HeadersList = curl_slist_append(HeadersList, header.c_str());
}

void HTTPclient::PUTrequest(std::string resource) {
	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, HeadersList);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, resource.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, IgnoreWriteCallback);


	CURLcode result = curl_easy_perform(curl);

	try {
		if (result != CURLE_OK)
			throw std::runtime_error("Error: this HTTP request was not sucessful");
	}
	catch (const std::runtime_error& error) {
		std::cout << error.what() << std::endl;
	}

}

void HTTPclient::GETrequest(std::ofstream& responseFile) {
	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, HeadersList);

	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, FileWriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseFile);

	CURLcode result = curl_easy_perform(curl);

	try {
		if (result != CURLE_OK)
			throw std::runtime_error("Error: this HTTP request was not sucessful");
	}
	catch (const std::runtime_error& error) {
		std::cout << error.what() << std::endl;
	}

}

size_t HTTPclient::IgnoreWriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata) {
	return nmemb;
}

size_t HTTPclient::FileWriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata) {
	std::ofstream* outputFile = static_cast<std::ofstream*>(userdata);	//userdata is the variable passed by the caller, in this case it's a ofstream file
	size_t totalSize = size * nmemb;
	outputFile->write(static_cast<char*>(ptr), totalSize);
	
	/*for (size_t i = 0; i < nmemb; i++)
		outputFile << ptr[i];*/

	return totalSize;
}
