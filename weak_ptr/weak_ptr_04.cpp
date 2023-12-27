#include <memory>
#include <string>
#include <iostream>

using namespace std;

class Dog {
	std::weak_ptr<Dog> mp_friend;   //köpeğin arkadaşını tutacak
	std::string m_name;
public:
	Dog(std::string name) : m_name(std::move(name))
	{
		std::cout << "kopek " << m_name << " olusturuldu" << std::endl;
	}

	~Dog() {
		std::cout << "kopek " << m_name << " oyundan cikiyor" << std::endl;
	}

	void bark()
	{
		cout << m_name << " havliyor" << endl;
	}

	void make_friend(shared_ptr<Dog> x)
	{
		mp_friend = x;
		cout << m_name << " " << x->m_name << " ile arkadas oldu" << endl;
	}

	void show_friend() const
	{
		if (!mp_friend.expired()) {
			cout << "benim arkadasim : " << mp_friend.lock()->m_name << endl;
		}
		else {
			cout << "bir arkadasim yok " << endl;
		}
	}
};


int main()
{
	shared_ptr<Dog> sp1(make_shared<Dog>("shiva"));
	shared_ptr<Dog> sp2(make_shared<Dog>("peggy"));

	sp1->make_friend(sp2);
	sp2->make_friend(sp1);

	sp1->show_friend();
	sp2 = nullptr;
	sp1->show_friend();
}
