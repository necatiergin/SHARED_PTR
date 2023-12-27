#include <memory>
#include <iostream>
#include "date.h"

int main()
{
	using namespace std;
	auto sptr = make_shared<Date>(12, 5, 1987);
	weak_ptr<Date> wp{ sptr };

	cout << "sptr.use_count() = " << sptr.use_count() << "\n";
	cout << "wp.use_count()   = " << wp.use_count() << "\n";

	sptr.reset();

	cout << "sptr.use_count() = " << sptr.use_count() << "\n";
	cout << "wp.use_count()   = " << wp.use_count() << "\n";

	try {
		shared_ptr<Date> spx(wp); //throws std::bad_weak_ptr
		cout << *spx << "\n";
	}
	//catch (const exception& ex) {
	catch (const std::bad_weak_ptr& ex) {
		cout << "hata yakalandi : " << ex.what() << "\n";
	}
}
