#include <ostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class CodeBuilder
{
    string class_name;
    vector<pair<string, string> > members;

public:
    CodeBuilder(const string &class_name) : class_name{class_name}
    {
    }

    CodeBuilder &add_field(const string &name, const string &type)
    {
        members.push_back({type, name});
        return *this;
    }

    friend ostream &operator<<(ostream &os, const CodeBuilder &obj)
    {
        os << "class " << obj.class_name << endl
           << "{" << endl;
        for (const pair<string, string> &member : obj.members)
        {
            os << "  " << member.first << " " << member.second << ";" << endl;
        }
        os << "};" << endl;
        return os;
    }
};
