
#include <sstream>
#include "general_tree.h"

/**
 * @brief Recursively checks if two nodes are equal.
 * 
 * @param p1 Pointer to the first node.
 * @param p2 Pointer to the second node.
 * @return true if the nodes are equal, false otherwise.
 */
bool GeneralTree::Node::is_equal(const GeneralTree::Node *p1, const GeneralTree::Node *p2) {
    if (p1 == nullptr && p2 == nullptr) return true;
    if (p1 != nullptr && p2 != nullptr) {
        if (is_equal(p1->_child, p2->_child) && is_equal(p1->_sibling, p2->_sibling)) {
        return true;
        }
    }
    return false;
}

/**
 * @brief Assignment operator for the Node class.
 * 
 * Performs a deep copy of the node.
 * 
 * @param that The node to be copied.
 * @return Reference to the copied node.
 */
const GeneralTree::Node &GeneralTree::Node::operator=(const Node& that) {
    if (this != &that) {
        _data = that._data;

        if (that._sibling != nullptr) _sibling = new Node(*that._sibling);
        else _sibling = nullptr;
        
        if (that._child != nullptr) _child = new Node(*that._child);
        else _child = nullptr;
    }
    return *this;
}

/**
 * @brief Destructor for the Node class.
 * 
 * Deletes all child and sibling nodes recursively.
 */
GeneralTree::Node::~Node() {
    Node *child = _child; Node *sibling = _sibling;
    child = nullptr; sibling = nullptr;
    delete child; delete sibling;
}

/**
 * @brief Inserts a sibling node.
 * 
 * Inserts a new sibling node at the end of the current node's sibling list.
 * 
 * @param p Pointer to the node to be inserted as a sibling.
 * @return Pointer to the inserted sibling node.
 */
GeneralTree::Node *GeneralTree::Node::insert_sibling(GeneralTree::Node *p) {
    if (_sibling == nullptr) _sibling = p;
    else {
        Node *_current = _sibling;
        while (_current->_sibling != nullptr) _current = _current->_sibling;
        _current->_sibling = p;
    }

    return p;
}

/**
 * @brief Inserts a child node.
 * 
 * Inserts a new child node at the end of the current node's child list.
 * 
 * @param p Pointer to the node to be inserted as a child.
 * @return Pointer to the inserted child node.
 */
GeneralTree::Node *GeneralTree::Node::insert_child(GeneralTree::Node *p) {
    if (_child == nullptr) _child = p; 
    else _child->insert_sibling(p);
    
    return p;
}

/**
 * @brief Equality comparison operator for the Node class.
 * 
 * @param that The node to compare with.
 * @return true if the nodes are equal, false otherwise.
 */
bool GeneralTree::Node::operator==(const GeneralTree::Node &that) const {
    return is_equal(this, &that);
}

/**
 * @brief Inequality comparison operator for the Node class.
 * 
 * @param that The node to compare with.
 * @return true if the nodes are not equal, false otherwise.
 */
bool GeneralTree::Node::operator!=(const GeneralTree::Node &that) const {
    return !is_equal(this, &that);
}

/**
 * @brief Generates a string representation of the node and its children.
 * 
 * @return A string representation of the node and its children.
 */
std::string GeneralTree::Node::to_string() const {
    std::stringstream repr;
    repr << _data << " :";

    Node *current = _child;
    while (current != nullptr) {
        repr << " " << current->get_data();
        current = current->_sibling;  // Traverse siblings, not child nodes
    }

    repr << std::endl;

    if (_child != nullptr) {
        repr << "# Child of " << _data << std::endl;
        repr << _child->to_string();
    } 

    if (_sibling != nullptr) {
        repr << "# Next sib of " << _data << std::endl;
        repr << _sibling->to_string();
    }
    
    return repr.str();
}

/**
 * @brief Construct a new General Tree object.
 * 
 * Initializes an empty tree with a root node.
 */
GeneralTree::GeneralTree() {
    _root = new Node; 
    _root->set_data("ROOT");
    _root->_sibling = nullptr;
    _root->_child = nullptr;
}

/**
 * @brief Destroy the General Tree object.
 * 
 * Deletes the root node and all its descendants recursively.
 */
GeneralTree::~GeneralTree() {
    GeneralTree::Node *root = _root;
    root = nullptr;
    delete root;
}

/**
 * @brief Assignment operator for the General Tree class.
 * 
 * Performs a deep copy of the tree.
 * 
 * @param that The tree to be copied.
 * @return Reference to the copied tree.
 */
GeneralTree &GeneralTree::operator=(const GeneralTree &that) {
    if (this != &that) {
        // Delete the existing tree
        delete _root;
        _root = nullptr;

        // Deep copy the tree from the RHS
        if (that._root != nullptr)  _root = new Node(*that._root);
    }
    return *this;
}

/**
 * @brief Equality comparison operator for the General Tree class.
 * 
 * @param that The tree to compare with.
 * @return true if the trees are equal, false otherwise.
 */
bool GeneralTree::operator==(const GeneralTree &that) const {
    if (_root == that._root) return true;
    if (_root != nullptr && that._root != nullptr && *_root == *(that._root)) return true;
    return false;
}

/**
 * @brief Inequality comparison operator for the General Tree class.
 * 
 * @param that The tree to compare with.
 * @return true if the trees are not equal, false otherwise.
 */
bool GeneralTree::operator!=(const GeneralTree &that) const {
    return !(*this == that);
}

/**
 * @brief Generates a string representation of the tree.
 * 
 * @return A string representation of the tree.
 */
std::string GeneralTree::to_string() const {
    std::stringstream repr;

    repr << "# Tree rooted at " << _root->get_data() << std::endl;
    repr << "# The following lines are of the form:" << std::endl;
    repr << "#   node: child1 child2..." << std::endl;
    repr << _root->to_string() << "# End of Tree" << std::endl;

    return repr.str();
}
