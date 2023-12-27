#include <memory>
#include "person.h"
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	{
		std::list<std::shared_ptr<Person>> mylist;

		mylist.emplace_back(new Person{ "Veli", "Dundar" });
		mylist.emplace_back(new Person{ "Ahmet", "Yesil" });
		mylist.emplace_back(new Person{ "Ayse", "Topal" });
		mylist.emplace_back(new Person{ "Murat", "Salih" });
		mylist.emplace_back(new Person{ "Deniz", "Akgun" });

		{
			std::vector<std::shared_ptr<Person>> myvec(mylist.begin(), mylist.end());
			////
			sort(myvec.begin(), myvec.end(), [](const auto& p1, const auto& p2) {return *p1 < *p2; });
			for (auto& s : myvec)
				std::cout << *s << '\n';
			std::cout << "bir tusa basin "; (void)getchar();
		}

		for (auto& s : mylist)
			std::cout << *s << '\n';
	}

	std::cout << "main devam ediyor\n";
}
