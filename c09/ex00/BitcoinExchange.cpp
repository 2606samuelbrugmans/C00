#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
std::string BitcoinExchange::trim(const std::string& date) const {
    const std::string whitespace = " \t";
    size_t start = date.find_first_not_of(whitespace);
    if (start == std::string::npos)
        return ""; 
    size_t end = date.find_last_not_of(whitespace);
    return date.substr(start, end - start + 1);
}
int BitcoinExchange::daysInMonth(int year, int month) const
{
	if (month == 1 || month == 3 || month == 5 ||
		month == 7 || month == 8 || month == 10 || month == 12)
		return 31;

	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;

	if (month == 2) {
		if (year % 400 == 0) return 29;
		else if (year % 100 == 0) return 28;
		else if (year % 4 == 0) return 29;
		return 28;
	}
	return -1;
}

int BitcoinExchange::formatCheck(const std::string& date, double rate) {
	std::string year_str, month_str, day_str;

	std::string trimmed_date = trim(date);
	if (trimmed_date.length() != 10 || trimmed_date[4] != '-' || trimmed_date[7] != '-') {
		std::cerr << "the format of the date is incorrect here is the required format: YYYY-MM-DD" << std::endl;
		return 0;
	}
	for (size_t i = 0; i < trimmed_date.length(); ++i) {
		if (i == 4 || i == 7) continue;
		if (!std::isdigit(static_cast<unsigned char>(trimmed_date[i]))) {
			std::cerr << "non number found at " << i << std::endl;
			return 0;
		}
	}
	std::istringstream splited(trimmed_date);
	std::string part;
	int count = 0;
	while (std::getline(splited, part, '-')) {
		if (splited.fail()) {
			return 0;
		}
		int date_convert = std::atoi(part.c_str());
		if (count == 0)
		{
			year_str = part;
		}
		else if (count == 1)
		{
			month_str = part;
			if (date_convert < 1 || date_convert > 12)
				std::cerr << "Error: month has to be between 1 and 12" << std::endl;
		}
		else if (count == 2)
		{
			int max_days = daysInMonth(std::atoi(year_str.c_str()), std::atoi(month_str.c_str()));
			if (date_convert < 1 || date_convert > max_days)
				std::cerr << "Error: day has to be possible" << std::endl;
		}
		count++;
	}
	if (rate < 0) {
		std::cerr << "Error: rate can't be negative" << std::endl;
	}
	return 1;
}
void BitcoinExchange::loadData(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw FileOpenException("Could not open file: " + filename);
	}
	std::string line;
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date;
		double rate;
		if (std::getline(ss, date, ',') && ss >> rate)
		{
			data[date] = rate;
		}
	}
	file.close();
}
int BitcoinExchange::compareDates(const std::string& date1, const std::string& date2) const{
	if (date1 < date2) return -1;
	if (date1 > date2) return 1;
	return 0;
}
double BitcoinExchange::getExchangeRate(const std::string& date) const {
	if (data.empty())
		throw DataNotFoundException("No exchange data loaded");
	std::map<std::string, double>::const_iterator it = data.lower_bound(date);
	if (it != data.end() && it->first == date) {
		return it->second;
	}
	if (it == data.begin()) {
		// no earlier date available
		throw DataNotFoundException("No suitable exchange rate found for the given date");
	}
	// take the previous entry (closest earlier date)
	--it;
	return it->second;
}