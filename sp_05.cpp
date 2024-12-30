#include <iostream>
#include <memory>
#include "date.h"

int main()
{
	std::cout << "main started running\n";
	std::shared_ptr<Date> spx;

	{
		auto sp = std::make_shared<Date>(23, 12, 1987);
		spx = sp;
		std::cout << *sp << '\n';
		std::cout << "month day is: " << sp->month_day() << '\n';
		std::cout << "use count = " << sp.use_count() << '\n';
		//cout << boolalpha << sp.unique() << '\n';
	}
	(void)std::getchar();
	std::cout << "main is still running\n";
}
