#include "node.hpp"
#include <iostream>
#include <stdexcept>
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
        const Node<T>* search_aux(Node<T>* root, const T& data) const noexcept {
            if (root == nullptr) return nullptr;
            if (root->data == data) return root;
            if (root->data > data) return search_aux(root->left, data);
            return search_aux(root->right, data);
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
        inline bool empty() const noexcept { return root == nullptr; }
        inline void insert(const T data) { 
            if (search(data)) throw std::invalid_argument("Duplicate values are not allowed.");
            insert_aux(root, data); 
        } 
        inline const Node<T>* search(const T data) const noexcept { return search_aux(root, data); }
        friend std::ostream& operator<<(std::ostream& out, const Tree& tree) {
            if (tree.root == nullptr) 
                return out << "[]";
            tree.display_aux(tree.root, out);
            return out;
        }
        friend Tree<T>& operator>>(Tree& tree, const T data) {
            tree.insert(data);
            return tree;
        }
    };
}
#endif