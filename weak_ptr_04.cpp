#include <memory>
#include <string>
#include <iostream>

class Dog {
	std::weak_ptr<Dog> mp_friend;   //pointer to dog's friend
	std::string m_name;
public:
	Dog(std::string name) : m_name(std::move(name))
	{
		std::cout << "dog " << m_name << " is in the game\n";
	}

	~Dog()
	{
		std::cout << "dog " << m_name << " is out of the game\n";
	}

	void bark()
	{
		std::cout << m_name << " is barking\n";
	}

	void make_friend(std::shared_ptr<Dog> x)
	{
		mp_friend = x;
		std::cout << m_name << " made friend with " << x->m_name << '\n';
	}

	void show_friend() const
	{
		if (!mp_friend.expired()) {
			std::cout << "my friend: " << mp_friend.lock()->m_name << '\n';
		}
		else {
			std::cout << "I don't have any friends\n";
		}
	}
};

int main()
{
	auto sp1(std::make_shared<Dog>("shiva"));
	auto sp2(std::make_shared<Dog>("peggy"));

	sp1->make_friend(sp2);
	sp2->make_friend(sp1);

	sp1->show_friend();
	sp2 = nullptr;
	sp1->show_friend();
}
