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

    // Her zaman geçerli kaynak: boş liste ile başla
    NameList()
        : sptr_(std::make_shared<container_type>()) {
    }

    NameList(std::initializer_list<std::string> list)
        : sptr_(std::make_shared<container_type>(list)) {
    }

    void add(const std::string& name) {
        sptr_->push_back(name);
    }

    void remove(const std::string& name) {
        auto& v = *sptr_;
        v.erase(std::remove(v.begin(), v.end(), name), v.end());
    }

    void sort() {
        std::sort(sptr_->begin(), sptr_->end());
    }

    std::size_t size() const {
        return sptr_->size();
    }

    void print(const char* tag = "") const {
        std::cout << tag << " [owners=" << sptr_.use_count() << "] : ";
        for (const auto& s : *sptr_) std::cout << s << ' ';
        std::cout << '\n';
    }

    // Paylaşım grubundan kop: artık bu nesne kendi listesini kullanır
    void detach() {
        if (!sptr_.unique()) {
            sptr_ = std::make_shared<container_type>(*sptr_); // deep copy
        }
    }

private:
    std::shared_ptr<container_type> sptr_;
};

int main() {
    NameList x{ "ali", "gul", "eda", "naz" };
    NameList y = x;
    NameList z = y;

    x.print("x");
    y.print("y");
    z.print("z");

    std::cout << "---- group-1 shared modifications ----\n";
    x.add("nur");
    y.add("tan");
    z.sort();
    z.print("z after sort");
    x.print("x after add");
    y.remove("gul");
    x.print("x after remove(gul) via y");
    y.print("y after remove");

    std::cout << "\n==== new sharing group ====\n";
    NameList a{ "mert", "tunc", "kaya", "okan", "sarp" };
    NameList b = a;
    NameList c = a;

    a.print("a");
    b.print("b");
    c.print("c");

    std::cout << "---- detach c, then mutate ----\n";
    c.detach();          
    c.add("bora");       
    a.remove("kaya");    

    a.print("a after remove(kaya)");
    b.print("b after remove(kaya)");
    c.print("c after detach+add(bora)");
}
