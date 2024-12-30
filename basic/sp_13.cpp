#include <memory>
#include <string>
#include <list>
#include "nutility.h"

using Sptr = std::shared_ptr<std::string >;

int main()
{
	std::list<Sptr> mylist;
	for (int i = 0; i < 10; ++i) {
		mylist.emplace_back(new std::string{ random_name() });
	}

	for (auto sptr : mylist)
		std::cout << *sptr << " ";
	std::cout << "\n\n";

	std::vector<Sptr> svec;

	for (auto sp : mylist) {
		svec.push_back(sp);
	}

	//
	for (auto sp : svec) {
		*sp += "can";
	}

	std::cout << "\n";

	for (auto sptr : mylist)
		std::cout << *sptr << " ";
}
