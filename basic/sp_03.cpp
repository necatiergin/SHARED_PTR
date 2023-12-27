#include <iostream>
#include <memory>
#include "date.h"

int main()
{
	std::cout << "main basladi\n";
	std::shared_ptr<Date> spx;

	{
		auto sp = std::make_shared<Date>(23, 12, 1987);
		spx = sp;
		std::cout << *sp << "\n";
		std::cout << "ayin " << sp->month_day() << ". gunu\n";
		std::cout << "use count = " << sp.use_count() << "\n";
		//cout << boolalpha << sp.unique() << "\n";
	}
	std::cout << "bir tusa basin "; (void)std::getchar();
	std::cout << "main devam ediyor\n";
}
