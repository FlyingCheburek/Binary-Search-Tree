#ifndef NODE_HPP
#define NODE_HPP
namespace BSTree {
    template<typename T>
    struct Node final {
        const T data;
        Node<T>* left, *right;
        explicit Node(const T data, Node<T>* left = nullptr, Node<T>* right = nullptr) noexcept : 
            data(data), left(left), right(right) {  }
        
    };
}
#endif