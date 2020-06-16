// author: a.voss@fh-aachen.de

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdexcept>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::unordered_map;
using std::initializer_list;
using std::vector;
using std::runtime_error;

// -> typedef 
typedef unsigned int index_type;
typedef string value_type;
typedef vector<string> vector_type;

// -> globale Var.
index_type next_id{100};

// -> globale Fkt.
index_type make_id() {
    return next_id++;
}

// -> class
class multi_set {

// -> Zugriffsmod.
public:

// -> map benutzen
    unordered_map<index_type,vector_type> map;
    unsigned int max_keys;
    
// -> ctor 
    multi_set(unsigned int max_keys) : max_keys(max_keys) {}
    
    index_type add(index_type id, const initializer_list<string>& list) {
// -> exceptions
        if (map.size()>=max_keys)
            throw runtime_error("too much keys");
            
        vector_type set = map[id];
// -> for, auto&, map benutzen
        for (auto& v:list)
            set.push_back(v);
        map[id]=set;
        return id;
    }

// -> überladen, init.list
    index_type add(const initializer_list<string>& list) {
        return add(make_id(),list);
    }

// -> iterator benutzen
    vector_type get(index_type id) const {
        //return map[id];
        auto it{map.find(id)};
        return (it!=map.end()) ? (*it).second : vector_type();
    }

// -> const member
    size_t size() const {
        return map.size();
    }
};

// -> vorgegeben
ostream& operator<<(ostream& os, const vector_type& v) {
    bool first{true};
    
    os << "[";
    for (auto& x:v) {
        if (first)
            first=false;
        else
            os << ",";
        os << "'" << x << "'";
    }
    os << "]";
    return os;
}

// -> op<< analog verwenden
ostream& operator<<(ostream& os, const multi_set& s) {
    bool first{true};

    os << "{";
    for (auto& kv : s.map) {
        if (first)
            first=false;
        else
            os << ",";
        os << "(" << kv.first << "," << kv.second << ")";
    }
    os << "}";
    return os;
}

int main() 
{
    cout << endl << "--- " << __FILE__ << " ---" << endl 
         << endl;
         
    multi_set set(2);
    index_type id100,id100a,id101;
    
    cout << "01|    |set|=" << set.size() << ", set:" << set << endl;
    
    id100 = set.add({"Hello"});
    cout << "02|    |set|=" << set.size() << ", set:" << set << ", id100:" << id100 << endl;
    
    id100a = set.add(id100,{"World","!"});
    cout << "03|    |set|=" << set.size() << ", set:" << set << ", id100a:" << id100a << endl;

    id101 = set.add({"a","b"});
    cout << "04|    |set|=" << set.size() << ", set:" << set << ", id101:" << id101 << endl;
    
    cout << "-----" << endl;

    auto v100 = set.get(id100);
    cout << "05|    |v100|=" << v100.size() << endl;

    auto v101 = set.get(id101);
    cout << "06|    |v101|=" << v101.size() << endl;

    auto v102 = set.get(id101+1);
    cout << "07|    |v102|=" << v102.size() << endl;

    cout << "-----" << endl;

// -> exc. fangen
    try {
        set.add({"oops"});
    } catch (const runtime_error& e) {
        cout << "08|    error: " << e.what() << endl;
    }

    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    return 0;
}
