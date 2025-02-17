#include <string>
#include <vector>
#include <memory>

#include <iostream>
#include <fstream>
#include <map>
#include <set>

class QueryResult;

class TextQuery {
public:
    using LineNo = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string&) const;

private:
    std::shared_ptr<std::vector<std::string>> input;
    std::map<std::string, std::shared_ptr<std::set<LineNo>>> result;
};

class QueryResult {
public:
    friend std::ostream& print(std::ostream &, const QueryResult&);
    
    QueryResult(const std::string &s, std::shared_ptr<std::set<TextQuery::LineNo>> set, 
        std::shared_ptr<std::vector<std::string>> v) 
        : word(s), nos(set), input(v) { }
    
private:
    std::string word;
    std::shared_ptr<std::set<TextQuery::LineNo>> nos;
    std::shared_ptr<std::vector<std::string>> input;
};

std::ostream& print(std::ostream &, const QueryResult&);

#include <sstream>
#include <algorithm>

TextQuery::TextQuery(std::ifstream &ifs) : input(new std::vector<std::string>)
{
    LineNo lineNo{ 0 };
    for (std::string line; std::getline(ifs, line); ++lineNo)
    {
        input->push_back(line);
        std::istringstream line_stream(line);

        for (std::string text, word; line_stream >> text; word.clear())
        {
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            auto &nos = result[word];

            if (!nos)
                nos.reset(new std::set<LineNo>);
            nos->insert(lineNo);
        }
    }
}

QueryResult TextQuery::query(const std::string& str) const
{
    static std::shared_ptr<std::set<LineNo>> nodata(new std::set<LineNo>);
    auto found = result.find(str);

    if (found == result.end())
        return QueryResult(str, nodata, input);
    else return QueryResult(str, found->second, input);
}

std::ostream& print(std::ostream &out, const QueryResult& qr)
{
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << std::endl;
    for (auto i : *qr.nos)
        out << "\t(line " << i+1 << ") " << qr.input->at(i) << std::endl;
    return out;
}


void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main()
{
    std::ifstream file("../data/storyDataFile.txt");
    runQueries(file);
}