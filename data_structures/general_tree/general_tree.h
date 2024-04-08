#include <iostream>
#include <vector>

#ifndef GeneralTree_h
#define GeneralTree_h

class GeneralTree {
private:
struct Node {
    std::string _data;
    Node *_sibling, *_child;

    static bool is_equal(const Node *p1, const Node *p2);
    const Node &operator=(const Node& that);

    Node(std::string s = "") : _data(s), _sibling(nullptr), _child(nullptr) {}
    Node(const Node &that) { this->operator=(that); }
    ~Node();

    std::string get_data() const { return _data; }
    void set_data(std::string s) { _data = s; }

    Node *insert_sibling(Node *p);
    Node *insert_child(Node *p);

    bool operator==(const Node &that) const;
    bool operator!=(const Node &that) const;

    std::string to_string() const;
};

Node *_root;

public:
    GeneralTree();
    ~GeneralTree();
    GeneralTree(const GeneralTree& that) { *this = that; }

    bool operator==(const GeneralTree &that) const;
    bool operator!=(const GeneralTree &that) const;
    GeneralTree &operator=(const GeneralTree &that);
    
    std::string to_string() const;
};
#endif
