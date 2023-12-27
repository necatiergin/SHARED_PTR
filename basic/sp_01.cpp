#include <memory>
#include <iostream>
#include "person.h"

int main()
{
	using namespace std;
	{
		auto sp1 = make_shared<Person>("Necati", "Ergin");
		cout << *sp1 << '\n';
		cout << "sp1.use_count() = " << sp1.use_count() << '\n';
		cout << "bir tusa basin ";
		(void)getchar();
		{
			auto sp2 = sp1;
			cout << *sp2 << '\n';
			cout << "sp1.use_count() = " << sp1.use_count() << '\n';
			cout << "sp2.use_count() = " << sp2.use_count() << '\n';
			cout << "bir tusa basin ";
			(void)getchar();
			{
				auto sp3 = sp2;
				cout << *sp3 << '\n';
				cout << "sp1.use_count() = " << sp1.use_count() << '\n';
				cout << "sp2.use_count() = " << sp2.use_count() << '\n';
				cout << "sp3.use_count() = " << sp3.use_count() << '\n';
				cout << "bir tusa basin ";
				(void)getchar();
			}
		}
		cout << "sp1.use_count() = " << sp1.use_count() << '\n';
	}
	std::cout << "main devam ediyor\n";
}
