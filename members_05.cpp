#include <memory>
#include <iostream>
#include "person.h"

int main()
{
	using std::cout;
	{
		auto sp1 = std::make_shared<Person>("Necati", "Ergin");
		cout << *sp1 << '\n';
		cout << "sp1.use_count() = " << sp1.use_count() << '\n';
		cout << "press any key to continue ";
		(void)getchar();
		{
			auto sp2 = sp1;
			cout << *sp2 << '\n';
			cout << "sp1.use_count() = " << sp1.use_count() << '\n';
			cout << "sp2.use_count() = " << sp2.use_count() << '\n';
			cout << "press any key to continue ";
			(void)std::getchar();
			{
				auto sp3 = sp2;
				cout << *sp3 << '\n';
				cout << "sp1.use_count() = " << sp1.use_count() << '\n';
				cout << "sp2.use_count() = " << sp2.use_count() << '\n';
				cout << "sp3.use_count() = " << sp3.use_count() << '\n';
				cout << "press any key to continue ";
				(void)getchar();
			}
		}
		cout << "sp1.use_count() = " << sp1.use_count() << '\n';
	}
	cout << "main is still running\n";
}
