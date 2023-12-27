#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


//name_list.h

using svector = std::vector<std::string>;

class NameList {
public:
	NameList() = default;
	NameList(std::initializer_list<std::string> list) : sptr{ new svector{list} } {}
	
	void add(const std::string& name)
	{
		sptr->push_back(name);
	}
	
	void remove(const std::string& name)
	{
		sptr->erase(std::remove(sptr->begin(), sptr->end(), name), sptr->end());
	}
	
	size_t size()const
	{
		return sptr->size();
	}

	void print()const
	{
		for (const auto& s : *sptr)
			std::cout << s << " ";
		std::cout << "\n";

	}
	
	void sort()
	{
		std::sort(sptr->begin(), sptr->end());
	}

private:
	std::shared_ptr<std::vector<std::string>> sptr;
};

int main()
{
	NameList x{ "ali", "gul", "eda", "naz" };
	NameList y = x;
	NameList z = y;

	x.add("nur");
	y.add("tan");
	std::cout << "listede " << x.size() << " isim var\n";
	z.sort();
	x.print();
	y.remove("gul");
	z.print();
	
	std::cout << "bir tusa basin "; std::getchar();

	NameList a{ "mert", "tunc" ,"kaya", "okan" ,"sarp" };
	NameList b = a;
	NameList c = a;

	b.add("esen");
	c.add("bora");
	a.remove("kaya");
	std::cout << "listede " << a.size() << " isim var\n";
	b.sort();
	c.print();
	getchar();
}
