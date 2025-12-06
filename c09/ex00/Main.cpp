#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	BitcoinExchange bitcoinExchange;
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <datafile>" << std::endl;
		return 1;
	}

	try {
		bitcoinExchange.loadData("data.csv");
		std::cout << "loaded date" << std::endl;
		std::string line;
		std::ifstream file(argv[1]);
		while (std::getline(file, line)) {
			std::istringstream ss(line);
			std::string date;
			double value;
			if (std::count(line.begin(), line.end(), '|') != 1)
			{
				std::cerr << "Error: invalid format in line: \n" << line << "\nplease use only one |"<< std::endl;
				continue;
			}
			if (std::getline(ss, date, '|') && (ss >> value)) {
				std::cout << "Processing date: " << date << " with value: " << value << std::endl;
				if (bitcoinExchange.formatCheck(date, value) == 0) {
					continue;
				}
				try {
					std::cout << "Getting exchange rate for date: " << date << std::endl;
					double rate = bitcoinExchange.getExchangeRate(date);
					std::cout << date << " => " << rate <<"= " << value * rate << std::endl;
				} catch (const DataNotFoundException& e) {
					std::cerr << e.what() << std::endl;
				}
			}
		}
			

	} catch (const FileOpenException& e) {
		// Handle file open error
	} catch (const InvalidDataFormatException& e) {
		// Handle invalid data format error
	} catch (const DataNotFoundException& e) {
		// Handle data not found error
	} catch (const std::exception& e) {
		// Handle other exceptions
	}

	return 0;
}