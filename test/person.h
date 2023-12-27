#pragma once

#include <ostream>
#include <string>

class Person {

public:
	Person(std::string name, std::string surname) :
		m_name{ std::move(name) }, m_surname{ std::move(surname) } {}
	friend std::ostream& operator<<(std::ostream& os, const Person& p)
	{
		return os << p.m_name << ' ' << p.m_surname;
	}

	auto operator<=>(const Person& p)const = default;
	Person& set_name(const std::string& name)
	{
		m_name = name;
		return *this;
	}

	std::string get_name()const { return m_name; }
	std::string get_surname()const { return m_surname; }
private:
	std::string m_name;
	std::string m_surname;
};
