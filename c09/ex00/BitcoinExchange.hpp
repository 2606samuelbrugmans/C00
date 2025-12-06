#pragma once
#include <map>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib> 
#include <cctype> 
#include <algorithm>

class BitcoinExchange {
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	void loadData(const std::string& filename);
	double getExchangeRate(const std::string& date) const;
	int formatCheck(const std::string& date, double rate);
private:
	std::map<std::string, double> data;
	int daysInMonth(int year, int month) const;
	std::string trim(const std::string& s) const;
	
	int compareDates(const std::string& date1, const std::string& date2) const;
};
class DataNotFoundException : public std::runtime_error {
public:
	DataNotFoundException(const std::string& message)
		: std::runtime_error(message) {}
};
class FileOpenException : public std::runtime_error {
public:
	FileOpenException(const std::string& message)
		: std::runtime_error(message) {}
};
class InvalidDataFormatException : public std::runtime_error {
public:
	InvalidDataFormatException(const std::string& message)
		: std::runtime_error(message) {}
};
