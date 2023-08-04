/**
 * @file BST.h
 * @brief Header file for Binary Search Tree (BST) implementation.
 * @details The BST class provides functionality to store ordered weather measurement values such as wind speeds,
 * temperatures, and solar radiation levels. It uses BSTs for fast search times (O(log n)) to efficiently calculate
 * statistics like mean and standard deviation (O(n)) by traversing the tree. The BST class also supports insertion,
 * in-order, pre-order, and post-order traversals, tree deletion, and search operations.
 * @author Mohsin Ali Khan
 * @date 26/07/2023
 * @version 04
 * @bug All the bugs have been fixed to the best of my knowledge
 */

#ifndef BST_H
#define BST_H

#include <iostream>
#include <stack>

using namespace std;

template<typename T>
struct node
{
    /**
     * @brief Default constructor for a node.
     */
    node() : data(T()), left(nullptr), right(nullptr)
    {
    }

    T data; ///< Data stored in the node.
    node* left; ///< Pointer to the left child node.
    node* right; ///< Pointer to the right child node.
};

template <class T>
class BST
{
public:
    /**
     * @brief Constructor for the BST class.
     */
    BST();

    /**
     * @brief Destructor for the BST class.
     */
    ~BST();

    /**
     * @brief Inserts a new data element into the BST.
     * @param data The data to be inserted.
     */
    void Insert(T &data);

    /**
     * @brief Performs in-order traversal of the BST and applies a callback function to each node's data.
     * @param fptr Pointer to the callback function that takes a reference to the data element.
     */
    void InOrder(void(*fptr)(T&));

    /**
     * @brief Performs pre-order traversal of the BST and applies a callback function to each node's data.
     * @param fptr Pointer to the callback function that takes a reference to the data element.
     */
    void PreOrder(void(*fptr)(T&));

    /**
     * @brief Performs post-order traversal of the BST and applies a callback function to each node's data.
     * @param fptr Pointer to the callback function that takes a reference to the data element.
     */
    void PostOrder(void(*fptr)(T&));

    /**
     * @brief Deletes the entire BST.
     */
    void DeleteTree();

    /**
     * @brief Searches for a specific data element in the BST.
     * @param data The data to be searched for.
     * @return True if the data element is found, false otherwise.
     */
    bool Search(T &data);

    /**
     * @brief Overloaded assignment operator to copy the content of one BST to another.
     * @param that The BST to be copied from.
     * @return Reference to the newly copied BST.
     */
    BST<T>& operator= (const BST<T>& that);

    /**
     * @brief Copy constructor to create a deep copy of another BST.
     * @param thatTree The BST to be copied.
     */
    BST(const BST<T>& thatTree);

    /**
     * @brief Get the size (number of nodes) of the BST.
     * @return The size of the BST.
     */
    int size();

    /**
     * @brief Performs in-order traversal of the BST and applies a callback function to each node's data.
     * @tparam Callback The type of the callback function.
     * @param callback The callback function that takes a reference to the data element.
     */
    template <typename Callback>
    void InOrder(Callback callback);

private:
    node<T>* root; ///< Pointer to the root node of the BST.

    /**
     * @brief Helper function to calculate the size of the BST starting from a given node.
     * @param parent Pointer to the root node of the subtree.
     * @return The size of the subtree.
     */
    int size(node<T>* parent);

    /**
     * @brief Helper function to perform in-order traversal of the BST starting from a given node.
     * @tparam Callback The type of the callback function.
     * @param parent Pointer to the root node of the subtree.
     * @param callback The callback function that takes a reference to the data element.
     */
    template <typename Callback>
    void InOrder(node<T>* parent, Callback callback);

    /**
     * @brief Helper function to insert a new data element into the BST starting from a given node.
     * @param parent Pointer to the root node of the subtree.
     * @param data The data to be inserted.
     */
    void Insert(node<T>* parent, T &data);

    /**
     * @brief Helper function to perform in-order traversal of the BST starting from a given node and apply a callback function.
     * @param parent Pointer to the root node of the subtree.
     * @param fptr Pointer to the callback function that takes a reference to the data element.
     */
    void InOrder(node<T>* parent, void(*fptr)(T&));

    /**
     * @brief Helper function to perform pre-order traversal of the BST starting from a given node and apply a callback function.
     * @param parent Pointer to the root node of the subtree.
     * @param fptr Pointer to the callback function that takes a reference to the data element.
     */
    void PreOrder(node<T>* parent, void(*fptr)(T&));

    /**
     * @brief Helper function to perform post-order traversal of the BST starting from a given node and apply a callback function.
     * @param parent Pointer to the root node of the subtree.
     * @param fptr Pointer to the callback function that takes a reference to the data element.
     */
    void PostOrder(node<T>* parent, void(*fptr)(T&));

    /**
     * @brief Helper function to delete the entire BST starting from a given node.
     * @param parent Pointer to the root node of the subtree.
     */
    void DeleteTree(node<T>* &parent);

    /**
     * @brief Helper function to search for a specific data element in the BST starting from a given node.
     * @param parent Pointer to the root node of the subtree.
     * @param data The data to be searched for.
     * @return True if the data element is found, false otherwise.
     */
    bool Search(node<T>* &parent, T &data);

    /**
     * @brief Helper function to create a deep copy of the BST starting from a given node.
     * @param thisTree Pointer to the root node of the new BST.
     * @param thatTree Pointer to the root node of the BST to be copied.
     */
    void Copy(node<T>* &thisTree, node<T>* thatTree);

    /**
     * @brief Helper function to perform post-order traversal of the BST starting from a given node and delete nodes.
     * @param parent Pointer to the root node of the subtree.
     */
    void Destruct(node<T>* parent);
};

template <class T>
int BST<T>::size()
{
    return size(root);
}

template <class T>
int BST<T>::size(node<T>* parent)
{
    if (parent == nullptr)
        return 0;
    else
        return(size(parent->left) + 1 + size(parent->right));
}

template <class T>
BST<T>::BST(const BST<T>& thatTree)
{
    if(thatTree.root == nullptr)
    {
        root = nullptr;
    }
    else
    {
        Copy(root, thatTree.root);
    }
}

template <class T>
void BST<T>::Copy(node<T>* &thisTree, node<T>* thatTree)
{
    if(thatTree == nullptr)
        thisTree  = nullptr;
    else
    {
        thisTree = new node<T>;
        thisTree->data = thatTree->data;
        Copy(thisTree->left, thatTree->left);
        Copy(thisTree->right, thatTree->right);
    }
}

template <class T>
BST<T>& BST<T>::operator=(const BST<T>& that)
{
    if(this != &that)
    {
        if(that.root == nullptr)
        {
            root = nullptr;
        }
        else
            Copy(root, that.root);
    }
    return *this;
}

template <class T>
BST<T>::~BST()
{
    if(root != nullptr)
    {
        Destruct(root);
    }
}

template <class T>
void BST<T>::Destruct(node<T>* parent)
{
    if(parent != nullptr)
    {
        if( (parent->left == nullptr) && (parent->right == nullptr) )
        {
            delete parent;
            parent = nullptr;
        }
        else
        {
            Destruct(parent->left);
            Destruct(parent->right);
        }
    }
}

template<typename T>
BST<T>::BST()
    : root(nullptr)
{

}

template <class T>
void BST<T>::Insert(T &data)
{
    if(root == nullptr)
    {
        node<T>* temp = new node<T>;
        temp->data = data;
        temp->left = temp->right = nullptr;
        root = temp;
    }
    else
    {
        Insert(root, data);
    }
}

template <class T>
void BST<T>::Insert(node<T>* parent, T &data)
{
    if(data < parent->data)
    {
        if(parent->left == nullptr)
        {
            node<T>* temp = new node<T>;
            temp->data = data;
            temp->left = temp->right = nullptr;
            parent->left = temp;
        }
        else
        {
            Insert(parent->left, data);
        }
    }
    else
    {
        if(data > parent->data)
        {
            if(parent->right == nullptr)
            {
                node<T>* temp = new node<T>;
                temp->data = data;
                temp->right = temp->left = nullptr;
                parent->right = temp;
            }
            else
            {
                Insert(parent->right, data);
            }
        }
    }
}

template <class T>
void BST<T>::InOrder(void(*fptr)(T&))
{
    if (root == nullptr)
        return;

    std::stack<node<T>*> nodesStack;
    node<T>* current = root;

    while (!nodesStack.empty() || current != nullptr)
    {
        if (current != nullptr)
        {
            nodesStack.push(current);
            current = current->left;
        }
        else
        {
            current = nodesStack.top();
            nodesStack.pop();
            fptr(current->data);
            current = current->right;
        }
    }
}

template <class T>
void BST<T>::PreOrder(void(*fptr)(T&))
{
    if (root == nullptr)
        return;

    std::stack<node<T>*> nodesStack;
    nodesStack.push(root);

    while (!nodesStack.empty())
    {
        node<T>* current = nodesStack.top();
        nodesStack.pop();

        fptr(current->data);

        if (current->right)
            nodesStack.push(current->right);

        if (current->left)
            nodesStack.push(current->left);
    }
}

template <class T>
void BST<T>::PostOrder(void(*fptr)(T&))
{
    if (root == nullptr)
        return;

    std::stack<node<T>*> nodesStack1;
    std::stack<node<T>*> nodesStack2;

    nodesStack1.push(root);

    while (!nodesStack1.empty())
    {
        node<T>* current = nodesStack1.top();
        nodesStack1.pop();

        nodesStack2.push(current);

        if (current->left)
            nodesStack1.push(current->left);

        if (current->right)
            nodesStack1.push(current->right);
    }

    while (!nodesStack2.empty())
    {
        node<T>* current = nodesStack2.top();
        nodesStack2.pop();

        fptr(current->data);
    }
}

template <class T>
void BST<T>::DeleteTree()
{
    if(root != nullptr)
    {
        DeleteTree(root);
    }
}

template <class T>
void BST<T>::DeleteTree(node<T>* &parent)
{
    if (parent != nullptr)
    {
        DeleteTree(parent->left);
        DeleteTree(parent->right);
        delete parent;
        parent = nullptr;
    }
}

template <class T>
bool BST<T>::Search(T &data)
{
    if (root != nullptr)
    {
        if(root-> data != data)
        {
            return Search(root,data);
        }
        else
        {
            data = root->data;
            return true;
        }
    }
    else
    {
        return false;
    }
}
template <class T>
template <typename Callback>
void BST<T>::InOrder(Callback callback)
{
    InOrder(root, callback);
}
template <class T>
template <typename Callback>
void BST<T>::InOrder(node<T>* parent, Callback callback)
{
    if(parent != nullptr)
    {
        InOrder(parent->left, callback);
        callback(parent->data);
        InOrder(parent->right, callback);
    }
}
template <class T>
bool BST<T>::Search(node<T>* &parent,T &data)
{
    if(parent!=nullptr)
    {
        if (data == parent-> data)
        {
            data = parent->data;
            return true;
        }
        else
        {
            if (data < parent-> data)
            {
                return Search(parent->left,data);
            }
            else
            {
                if (data > parent-> data)
                {
                    return Search( parent-> right,data);
                }
            }
        }
    }

    return false;
}

#endif // BST_H
