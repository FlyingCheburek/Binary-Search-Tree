#include "node.hpp"
#include <iostream>
#ifndef TREE_HPP
#define TREE_HPP 
namespace BSTree {
    template<typename T>
    class Tree final {
    private:
        Node<T>* root;
        Node<T>* insert_aux(Node<T>*& root, const T& data) noexcept {
            if (root == nullptr) {
                root = new Node<T>(data);
                return root;
            }
            if (data < root->data)
                root->left = insert_aux(root->left, data);
            else
                root->right = insert_aux(root->right, data);
            return root;
        }
        void display_aux(Node<T>* root, std::ostream& out) const noexcept {
            if (root != nullptr) {
                display_aux(root->left, out);
                out << "[" << root->data << "]\n";
                display_aux(root->right, out);
            }
        }
    public:
        Tree() noexcept : root(nullptr) {}
        Tree(const T root_data) noexcept : root(new Node<T>(root_data)) {} 
        inline void insert(const T data) noexcept { insert_aux(root, data); } 
        friend std::ostream& operator<<(std::ostream& out, const Tree& tree) {
            if (tree.root == nullptr) 
                return out << "[]";
            tree.display_aux(tree.root, out);
            return out;
        }
    };
}
#endif