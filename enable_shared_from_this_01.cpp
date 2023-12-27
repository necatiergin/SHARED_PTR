// Eğer bir sınıfın üye fonksiyonu içinde shared_ptr ile hayatı kontrol edilen * this nesnesini gösteren 
// shared_ptr'nin kopyasını çıkartmak isterseniz sınıfınızı CRTP örüntüsü ile kalıtım yoluyla std::enable_shared_from_this
// sınıfından elde etmelisiniz

#include <memory>
#include <iostream>


using namespace std;

class Neco : public std::enable_shared_from_this<Neco> {  //CRTP
public:
	Neco()
	{
		std::cout << "Neco ctor this : " << this << "\n";
	}

	void func()
	{
		std::cout << "Neco::func() islevi : " << this << "\n";
		//ben func islevinin bir shared_ptr ile kontrol edilen dinamik Neco nesnesi icin cagrildigina eminim
		auto sptr = shared_from_this();
		std::cout << "sptr.use_count() = " << sptr.use_count() << "\n";
	}

	~Neco()
	{
		std::cout << "Neco destructor : " << this << "\n";
	}
};


int main()
{
	auto sp = make_shared<Neco>();
	sp->func();
	//Neco *p = new Neco;

	//try {
	//	p->func();
	//}
	//catch (const std::exception &ex) {
	//	std::cout << "hata yakalandi : " << ex.what() << "\n";
	//}

}
