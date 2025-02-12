#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <iostream>

class StrBlob
{
public:
    using size_type = std::vector<std::string>::size_type;

    StrBlob()
        : data(std::make_shared<std::vector<std::string>>()) { }
    explicit StrBlob(std::initializer_list<std::string> init)
        : data(std::make_shared<std::vector<std::string>>(init)) { }

    inline size_type size() const noexcept { return data->size(); }
    inline bool empty() const noexcept { return data->empty(); }

    inline void push_back(const std::string& str) { return data->push_back(str); }
    void pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    std::string& front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    std::string& back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    const std::string& front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const std::string& back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    void check(size_type i, const std::string& msg) const {
        if (i >= data->size())
            throw std::out_of_range(msg);
    }

    std::shared_ptr<std::vector<std::string>> data;
};

int main()
{
    const StrBlob csb{ "hello", "world", "pezy" };
    StrBlob sb{ "hello", "world", "Mooophy" };

    std::cout << csb.front() << " " << csb.back() << std::endl;
    sb.back() = "pezy";
    std::cout << sb.front() << " " << sb.back() << std::endl;
}
