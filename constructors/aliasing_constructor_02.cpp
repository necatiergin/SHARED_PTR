/*
    shared_ptr aliasing constructor
	shared_ptr ile hayatı kontrol edilen bir sınıf nesnesinin veri elemanlarından birini
	başka bir shared_ptr nesnesinin göstermesini istiyoruz.
	Eğer bir önlem alınmaz ise sahip olan nesneyi gösteren 	shared_ptr'nin hayatı bitince elemanı gösteren shared_ptr dangling hale gelirdi.
	Buradaki problemi çözmek için shared_ptr sınıfının "aliasing ctor" denilen ctor'u ile elemana shared_ptr oluşturuyoruz:
	shared_ptr<Member> spm (spowner, spowner->mx);
*/


#include <iostream>
#include <memory>


class Member {
public:
	Member()
	{
		std::cout << "Member constructor\n";
	}

	~Member()
	{
		std::cout << "Member destructor\n";
	}
};

class Owner {
public:
	Owner()
	{
		std::cout << "Owner constructor\n";
	}

	~Owner()
	{
		std::cout << "Owner destructor\n";
	}
	Member mx;
private:

};


using namespace std;

int main()
{
	auto sp = make_shared<Owner>();

	auto spm = shared_ptr<Member>(sp, &sp->mx);

	cout << "spm.use_count() = " << spm.use_count() << "\n";
	cout << "sp.use_count()  = " << sp.use_count() << "\n";
	(void)getchar();

	sp.reset();
	cout << "after sp.reset() call\n";
	cout << "spm.use_count() = " << spm.use_count() << "\n";
	cout << "sp.use_count()  = " << sp.use_count() << "\n";
	(void)getchar();
}
