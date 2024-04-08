#include <iostream>
#include <sstream>
#include "prefix_tree.h"
#include "queue.cpp"

/**
 * Inserts a string into the Prefix Tree starting from the current node.
 * If the characters in the string do not exist in the tree, they are added.
 *
 * @param s The string to insert into the Prefix Tree.
 */
void PrefixTree::Node::insert(std::string s) {
    // Start from the current node
    PrefixTree::Node *current = this;

    // Loop through each character in the string
    for (const char *str = s.c_str(); *str; str++) {
        // Get the current character
        char current_char = *str;

        // If the character exceeds the size of the 'next' array, resize it
        if ((size_t) current_char >= current->next.size()) {
            current->next.resize(current_char + 1);
        }

        // If the next node for the current character exists, move to that node
        if (current->next[current_char] != nullptr) {
            current = current->next[current_char];
        }
        // If the next node for the current character does not exist, create it
        else {
            current = current->next[current_char] = new PrefixTree::Node();
        }
    }

    // Ensure the 'next' array has at least one element
    if (current->next.size() < 1) current->next.resize(1);

    // If the first element of 'next' is not initialized, create it
    if (current->next[0] == nullptr) current->next[0] = new PrefixTree::Node;
}

/**
 * Traverses the Prefix Tree to a node whose value is equal to that of the
 * inputted string, starting from the current node. 
 *
 * @param s The string to traverse to into the Prefix Tree.
 * @return the current node in the tree with a value of the inputted string. 
 */
const PrefixTree::Node* PrefixTree::Node::traverse(std::string s) const {
    // Start from the current node
    const PrefixTree::Node* current = this;

    // Loop through each character in the string
    for (const char *str = s.c_str(); *str; str++) {
        // Get the current character
        char current_char = *str;

        // If the size of the current character is bigger than the next
        // character...
        if ((size_t)current_char >= current->next.size()) {
            return nullptr; // ...then the string s does not exist in the tree.
        }

        // If the next character in the string exists in the tree. 
        if (current->next[current_char] != nullptr) {
            current = current->next[current_char];
        }

        else return nullptr;
    }
    
    return current;
}

/**
 * Looks up whetther a certain node with a specific string value exists in 
 * the Prefix Tree or not.
 *
 * @param s The string to lookup if it exists in the tree.
 * @return a boolean indicating if there exists a node in the tree with a value
 * of s (true) or not (false).
 */
bool PrefixTree::Node::lookup(std::string s) const {
    // get the last node in the Prefix Tree whose value is the string s.
    const PrefixTree::Node* last_node = traverse(s);

    return (last_node != nullptr) && (last_node->next[0] != nullptr);
}

/**
 * Destructor for the Node struct.
 */
PrefixTree::Node::~Node() {
    // Loop to delete all child nodes stored in the 'next' vector.
    for (PrefixTree::Node* _child : next) {
        PrefixTree::Node *child = _child;
        child = nullptr;
        delete child;
    }
}

/**
 * Destructor for the prefix Tree.
 */
PrefixTree::~PrefixTree() {
    PrefixTree::Node *root = _root;
    root = nullptr;
    delete root;
}

/**
 * Retrieves a list of completions from the prefix tree, up to a specified limit.
 *
 * @details This function traverses the prefix tree from the current node, collecting 
 * completions along the way. It utilizes a breadth-first search algorithm to explore all 
 * possible paths from the current node, stopping either when the limit of completions is 
 * reached or when all possible paths have been explored.
 *
 * @param completions A reference to a vector to store the completions.
 * @param limit The maximum number of completions to retrieve.
 * @return The number of completions retrieved.
 */
size_t PrefixTree::Node::get_completions(std::vector<std::string> &completions, size_t limit) const {
    completions.clear();

    // Declae a struct, holding information about a node in the Tree. It holds
    // a pointer to the node itself, the string representing the string formed so far to
    // reach the node, and lastly, we define a constructor in this struct for initilizing
    // the struct's two attributes. 
    struct Continuation {
        const PrefixTree::Node* node;
        std::string string_at_node;
        Continuation(const Node* p, std::string s) : node(p), string_at_node(s) {}
    };

    // Define a variable holding the current node which, in our traversal, 
    // is the root node with an empty string. 
    Continuation root = Continuation(this, "");
    // Define a queue which we will use to push back all of our nodes and strings.
    Queue<Continuation> unprocessed_nodes;
    unprocessed_nodes.enqueue(root); // push back the root node.

    // This loop will stop if the queue is empty or if we exceed our limit.
    // Our limit is the maximum amount of possible completions we wish to retrive.
    while (!unprocessed_nodes.is_empty() && completions.size() < limit) {
        // Retrive the oldest element of the queue and then pop it from the queue
        // since we will now use it and process it.
        Continuation current = unprocessed_nodes.peek();
        unprocessed_nodes.dequeue();

        // We need this if-statement to check if we have a continuation at the 
        // current node.
        if (current.node->next[0] != nullptr) {
            // If we have a valid continuation, we add the currently formed string, so far,
            // to the completions vector.
            completions.push_back(current.string_at_node);
        }

        // Loop over all child nodes of the current node.
        for (size_t i = 1; i < current.node->next.size(); ++i) {
            // Checks if we have a child node.
            if (current.node->next[i] != nullptr) {
                // If we do have a child node, it means that we have another, new, continuation
                // that we can create. The new string would be the original, so far, formed string,
                // concatinated with the child nodes character, i.
                std::string continued_string = current.string_at_node + static_cast<char>(i);
                // Create a new continuation object with this new child node and and its new string. 
                Continuation new_continuation = Continuation(current.node->next[i], continued_string);
                // Lastly, push back this new continuation to our unprocessed_nodes vector.
                unprocessed_nodes.enqueue(new_continuation);
            }
        }
    }

    return completions.size();
}

/**
 * Looks up whether a node with a specific string value exists in the Prefix Tree or not.
 *
 * This function traverses the Prefix Tree to find a node with the specified string value.
 * If such a node exists, it retrieves completions starting from that node, up to the
 * specified limit, and stores them in the provided vector. It returns the total number
 * of completions found.
 *
 * @param s The string to look up in the tree.
 * @param completions A reference to a vector to store the completions.
 * @param limit The maximum number of completions to retrieve.
 * @return The total number of completions found.
 */
size_t PrefixTree::get_completions(std::string s, std::vector<std::string> &completions, size_t limit) const {
  const PrefixTree::Node* node = _root->traverse(s);

  if (node == nullptr) return 0;

  node->get_completions(completions, limit);

  return completions.size();
}

/**
 * Sorts the elements of the Prefix Tree and retrieves all completions.
 *
 * This function clears the provided vector and then retrieves all completions
 * from the Prefix Tree, starting from the root node, up to the maximum limit
 * allowed by SIZE_MAX. It populates the provided vector with the sorted completions
 * and returns the total number of completions found.
 *
 * @param vec A reference to a vector to store the sorted completions.
 * @return The total number of completions found.
 */
size_t PrefixTree::sort(std::vector<std::string>& vec) const {
  vec.clear();

  size_t totalCompletions = get_completions("", vec, SIZE_MAX);

  return totalCompletions;
}

/**
 * Provides a serialized string, representing the Prefix Tree and its contents
 *
 * @param limit 
 * @return a string serialization of the tree.
 */
std::string PrefixTree::serialize(size_t limit) const {
  std::stringstream repr;
  repr << "# Trie contents" << std::endl;

  std::vector<std::string> completions;
  get_completions("", completions, limit);

  for (const std::string& completion : completions) repr << completion << std::endl;
  
  if (completions.size() >= limit) repr << "..." << std::endl;

  return repr.str();
}