#include <vector>

#ifndef PrefixTree_h
#define PrefixTree_h

class PrefixTree {
private:
    struct Node {
        std::vector<PrefixTree::Node *> next;

        ~Node();

        void insert(std::string s);
        const Node *traverse(std::string s) const;
        bool lookup(std::string s) const;
        size_t get_completions(std::vector<std::string>& completions, size_t limits) const;
    } *_root;

    const Node *traverse(std::string s) const { return _root->traverse(s); }

public:
    PrefixTree() : _root(new Node()) {}
    ~PrefixTree();

    void insert(std::string s) { _root->insert(s); }
    bool lookup(std::string s) const { return _root->lookup(s); }
    size_t get_completions(std::string s, std::vector<std::string>& completions, size_t limits) const;
    size_t sort(std::vector<std::string>& vec) const;

    std::string serialize(size_t limit) const;
    std::ostream& operator<<(std::ostream& os) { return os << serialize(100); }
};
#endif
