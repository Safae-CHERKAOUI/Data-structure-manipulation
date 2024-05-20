#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

template<typename Container>
class DataStructure {
public:
    // Insert function
    static void insertElement(Container& container, const typename Container::value_type& element, int position) {
        auto itr = container.begin();
        std::advance(itr, position);
        container.insert(itr, element);
    }

    // Access function
    static void accessElement(const Container& container, const typename Container::value_type& element) {
        
        bool found = false;
        for (auto it = container.begin(); it != container.end(); it++) {
            if (*it == element) {
                found = true;
                std::cout << "Element found!" << std::endl;
                break;
            }
        }
        
        if (!found) {
            std::cout << "Element not found!" << std::endl;
        }
    }

    // Erase function
    static void eraseElement(Container& container, int position) {
        auto it = container.begin();
        advance( it, position);
        container.erase(it);
        std::cout<<"Element deleted!"<<std::endl;
    }

    // Print function
    static void printContainer(const Container& container) {
        for (const auto& elem : container) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

// Specialization for maps
template<typename Key, typename Value>
class DataStructure<std::map<Key, Value>> {
public:
    // Insert function
    static void insertElement(std::map<Key, Value>& container, const std::pair<const Key, Value>& element) {
        container.insert(element);
    }

    // Access function
    static void accessElement(const std::map<Key, Value>& container, const std::pair<const Key, Value>& element) {
        auto it = container.find(element.first);
        
        if (it != container.end()) { 
            std::cout << "Element found!" << std::endl;
        } else { 
            std::cout << "Element not found!" << std::endl;
        }
}

    // Erase function
    static void eraseElement(std::map<Key, Value>& container, const std::pair<const Key, Value>& element) {
        auto it = container.find(element.first);
        if (it != container.end()) {
            container.erase(it);
            std::cout<<"Element deleted!"<<std::endl;
        }
    }

    // Print function
    static void printContainer(const std::map<Key, Value>& container) {
        for (const auto& elem : container) {
            std::cout << "{" << elem.first << ":" << elem.second << "} ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Test with vector
    std::vector<int> vec = {1,15,8};
    DataStructure<std::vector<int>>::insertElement(vec, 5, 1);
    DataStructure<std::vector<int>>::insertElement(vec, 10, 0);
    std::cout << "Vector: ";
    DataStructure<std::vector<int>>::printContainer(vec);

    DataStructure<std::vector<int>>::accessElement(vec,5);
    DataStructure<std::vector<int>>::eraseElement(vec, 1);
    

    // Test with set
    std::set<int> s;
    DataStructure<std::set<int>>::insertElement(s, 5,0);
    DataStructure<std::set<int>>::insertElement(s, 10,0);
    std::cout << "Set: ";
    DataStructure<std::set<int>>::printContainer(s);

    DataStructure<std::set<int>>::accessElement(s,10);
    DataStructure<std::set<int>>::eraseElement(s, 1);

    // Test with map
    std::map<std::string, int> m;
    DataStructure<std::map<std::string, int>>::insertElement(m, std::make_pair("a", 1));
    DataStructure<std::map<std::string, int>>::insertElement(m, std::make_pair("b", 2));
    std::cout << "Map: ";
    DataStructure<std::map<std::string, int>>::printContainer(m);


    DataStructure<std::map<std::string, int>>::accessElement(m,std::make_pair("b",2));
    DataStructure<std::map<std::string, int>>::eraseElement(m,std::make_pair("b",2));


    // Test with list
    std::list<int> l = {2,9};
    DataStructure<std::list<int>>::insertElement(l,4,2);
    DataStructure<std::list<int>>::insertElement(l,10,0);
    std::cout << "List: ";
    DataStructure<std::list<int>>::printContainer(l);

    DataStructure<std::list<int>>::accessElement(l,10);

    DataStructure<std::list<int>>::eraseElement(l, 1);

    return 0;
}
