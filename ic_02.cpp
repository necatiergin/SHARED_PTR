#include <memory>
#include <string>
#include <list>
#include "nutility.h"

using Sptr = std::shared_ptr<std::string >;

int main()
{
	using namespace std;

	list<Sptr> mylist;
	for (int i = 0; i < 10; ++i) {
		mylist.emplace_back(new string{ rname() });
	}

	for (auto sptr : mylist)
		cout << *sptr << " ";
	std::cout << "\n\n";

	vector<Sptr> svec;

	for (auto sp : mylist) {
		svec.push_back(sp);
	}

	//
	for (auto sp : svec) {
		*sp += "can";
	}


	for (auto sptr : mylist)
		cout << *sptr << " ";
}
