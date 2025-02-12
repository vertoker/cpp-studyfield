#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

class StrBlobPtr;

class StrBlob {
public:
    using size_type = std::vector<std::string>::size_type;
    friend class StrBlobPtr;

    inline StrBlobPtr begin()
        { return StrBlobPtr(*this); }
    inline StrBlobPtr end()
        { return StrBlobPtr(*this, data->size()); }

    StrBlob()
        : data(std::make_shared<std::vector<std::string>>()) { }
    StrBlob(std::initializer_list<std::string> il)
        : data(std::make_shared<std::vector<std::string>>(il)) { }

    inline size_type size() const noexcept { return data->size(); }
    inline bool empty() const noexcept { return data->empty(); }

    inline void push_back(const std::string &t) { data->push_back(t); }
    inline void pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    inline std::string& front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    inline std::string& back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    inline const std::string& front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    inline const std::string& back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    inline void check(size_type i, const std::string& msg) const noexcept
        { if (i >= data->size()) throw std::out_of_range(msg); }
    
    std::shared_ptr<std::vector<std::string>> data;
};

class StrBlobPtr {
public:
    StrBlobPtr()
        : curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0)
        : wptr(a.data), curr(sz) { }
    
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }

    std::string& deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    StrBlobPtr& incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

private:
    std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string &msg) const {
        auto ret = wptr.lock();
        if (!ret) throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }

    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};

#include <fstream>
#include <iostream>

int main()
{
    std::ifstream ifs("../data/book.txt");
    StrBlob blob;
    for (std::string str; std::getline(ifs, str); )
        blob.push_back(str);
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
        std::cout << pbeg.deref() << std::endl;
}