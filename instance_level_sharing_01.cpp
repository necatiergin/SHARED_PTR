// instance-level shared state

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class NameList {
public:
    using container_type = std::vector<std::string>;

    // Her zaman gecrli kaynak: bos liste ile basla
    NameList()
        : sptr_(std::make_shared<container_type>()) {}

    NameList(std::initializer_list<std::string> list)
        : sptr_(std::make_shared<container_type>(list)) {
    }

    void add(const std::string& name)
    {
        sptr_->push_back(name);
    }

    void remove(const std::string& name)
    {
        auto& v = *sptr_;
        v.erase(std::remove(v.begin(), v.end(), name), v.end());
    }

    void sort()
    {
        std::sort(sptr_->begin(), sptr_->end());
    }

    std::size_t size() const
    {
        return sptr_->size();
    }

    void print(const char* tag = "") const
    {
        std::cout << tag << " [owners=" << sptr_.use_count() << "] : ";
        for (const auto& s : *sptr_) 
            std::cout << s << ' ';
        std::cout << '\n';
    }

    // Paylasim grubundan kop: artik bu nesne kendi listesini kullanır
    void detach() 
    {
        if (!sptr_.use_count() > 1) {
            sptr_ = std::make_shared<container_type>(*sptr_); // deep copy
        }
    }

private:
    std::shared_ptr<container_type> sptr_;
};

int main() 
{
    NameList x{ "ali", "gul", "eda", "naz" };
    NameList y = x;
    NameList z = y;

    x.print("x");
    y.print("y");
    z.print("z");

    std::cout << "---- group-1 tarafindan paylasilan degisimler----\n";
    x.add("nur");
    y.add("tan");
    z.sort();
    z.print("z after sort");
    x.print("x after add");
    y.remove("gul");
    x.print("x after remove(gul) via y");
    y.print("y after remove");

    std::cout << "\n==== yeni paylasim grubu ====\n";
    NameList a{ "mert", "tunc", "kaya", "okan", "sarp" };
    NameList b = a;
    NameList c = a;

    a.print("a");
    b.print("b");
    c.print("c");

    std::cout << "---- c'yi ayir sonra degistir ----\n";
    c.detach();
    c.add("bora");
    a.remove("kaya");

    a.print("remove(kaya) dan sonra a");
    b.print("remove(kaya)'dan sonra b");
    c.print("detach+add(bora) dan sonra c");
}
