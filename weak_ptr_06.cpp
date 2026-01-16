#include <memory>

class Widget : public std::enable_shared_from_this<Widget> {
public:
    std::weak_ptr<Widget> get_weak() 
    {
        return weak_from_this(); // C++17
    }
};
