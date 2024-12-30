#include <memory>
#include <iostream>
#include "date.h"

int main()
{
	using std::cout;

	auto sptr = std::make_shared<Date>(12, 5, 1987);
	std::weak_ptr<Date> wp{ sptr };

	cout << "sptr.use_count() = " << sptr.use_count() << '\n';
	cout << "wp.use_count()   = " << wp.use_count() << '\n';

	sptr.reset();

	cout << "sptr.use_count() = " << sptr.use_count() << '\n';
	cout << "wp.use_count()   = " << wp.use_count() << '\n';

	try {
		std::shared_ptr<Date> spx(wp); //throws std::bad_weak_ptr
		cout << *spx << '\n';
	}
	//catch (const exception& ex) {
	catch (const std::bad_weak_ptr& ex) {
		cout << "hata yakalandi : " << ex.what() << '\n';
	}
}
