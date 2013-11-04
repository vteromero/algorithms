// Copyright (c) 2013 Vicente Romero Calero
//
// Distributed under the MIT software license, see the file LICENSE
//
// Author: Vicente Romero <vteromero@gmail.com>
//
// Binary Search Tree data structure.

#ifndef BST_H_
#define BST_H_

#include <stddef.h>

template <class T>
class BSTNode
{
public:
    BSTNode(const T& value)
    {
        value_ = value;
        parent_ = NULL;
        left_ = NULL;
        right_ = NULL;
    }

    BSTNode(const T& value, BSTNode *parent)
    {
        value_ = value;
        parent_ = parent;
        left_ = NULL;
        right_ = NULL;
    }

    ~BSTNode() {}

    BSTNode<T> *parent()
    {
        return parent_;
    }

    void set_parent(BSTNode *node)
    {
        parent_ = node;
    }

    BSTNode<T> *left()
    {
        return left_;
    }

    void set_left(BSTNode *node)
    {
        left_ = node;
    }

    BSTNode<T> *right()
    {
        return right_;
    }

    void set_right(BSTNode *node)
    {
        right_ = node;
    }

    T& value()
    {
        return value_;
    }

    void set_value(const T& value)
    {
        value_ = value;
    }

private:
    T value_;
    BSTNode<T> *parent_;
    BSTNode<T> *left_;
    BSTNode<T> *right_;
};

template <class T>
class BST
{
public:
    typedef void (*BSTWalkCallback)(const T&);

    BST()
    {
        root_ = NULL;
        size_ = 0;
    }

    ~BST()
    {
        Clear();
    }

    void InOrderWalk(const BSTWalkCallback &callback)
    {
        InOrderWalkFromNode(root_, callback);
    }

    void ReverseInOrderWalk(const BSTWalkCallback &callback)
    {
        ReverseInOrderWalkFromNode(root_, callback);
    }

    void PreOrderWalk(const BSTWalkCallback &callback)
    {
        PreOrderWalkFromNode(root_, callback);
    }

    void PostOrderWalk(const BSTWalkCallback &callback)
    {
        PostOrderWalkFromNode(root_, callback);
    }

    void Insert(const T& value)
    {
        BSTNode<T> *parent = NULL;
        BSTNode<T> *last = root_;

        while(last != NULL)
        {
            parent = last;

            if(value < last->value())
                last = last->left();
            else if(value > last->value())
                last = last->right();
            else
                return;
        }

        BSTNode<T> *node = new BSTNode<T>(value, parent);

        if(parent == NULL)
            root_ = node;
        else if(value < parent->value())
            parent->set_left(node);
        else
            parent->set_right(node);

        ++size_;
    }

    void Delete(const T& value)
    {
        BSTNode<T> *node = SearchFromNode(root_, value);
        if(node == NULL)
            return;

        if(node->left() == NULL)
        {
            Transplant(node, node->right());
        }
        else if(node->right() == NULL)
        {
            Transplant(node, node->left());
        }
        else
        {
            BSTNode<T> *min = MinimumFromNode(node->right());
            BSTNode<T> *rmin = min->right();
            BSTNode<T> *lmin = min->left();

            if(min->parent() != node)
            {
                Transplant(min, rmin);
                min->set_right(node->right());
                rmin->set_parent(min);
            }

            Transplant(node, min);
            min->set_left(node->left());
            lmin->set_parent(min);
        }

        delete node;

        --size_;
    }

    T& Minimum()
    {
        BSTNode<T> *min = MinimumFromNode(root_);

        return min->value();
    }

    T& Maximum()
    {
        BSTNode<T> *max = MaximumFromNode(root_);

        return max->value();
    }

    BSTNode<T> *Search(const T& value)
    {
        return SearchFromNode(root_, value);
    }

    //TODO: T& Get(int position) {}

    void Clear()
    {
        ClearFromNode(root_);
        root_ = NULL;
        size_ = 0;
    }

    int size()
    {
        return size_;
    }

private:
    void InOrderWalkFromNode(
        BSTNode<T> *node,
        const BSTWalkCallback &callback)
    {
        if(node != NULL)
        {
            InOrderWalkFromNode(node->left(), callback);
            callback(node->value());
            InOrderWalkFromNode(node->right(), callback);
        }
    }

    void ReverseInOrderWalkFromNode(
        BSTNode<T> *node,
        const BSTWalkCallback &callback)
    {
        if(node != NULL)
        {
            ReverseInOrderWalkFromNode(node->right(), callback);
            callback(node->value());
            ReverseInOrderWalkFromNode(node->left(), callback);
        }
    }

    void PreOrderWalkFromNode(
        BSTNode<T> *node,
        const BSTWalkCallback &callback)
    {
        if(node != NULL)
        {
            callback(node->value());
            PreOrderWalkFromNode(node->left(), callback);
            PreOrderWalkFromNode(node->right(), callback);
        }
    }

    void PostOrderWalkFromNode(
        BSTNode<T> *node,
        const BSTWalkCallback &callback)
    {
        if(node != NULL)
        {
            PostOrderWalkFromNode(node->left(), callback);
            PostOrderWalkFromNode(node->right(), callback);
            callback(node->value());
        }
    }

    BSTNode<T> *MinimumFromNode(BSTNode<T> *node)
    {
        // TODO: check node != NULL && size > 0
        while(node->left() != NULL)
            node = node->left();

        return node;
    }

    BSTNode<T> *MaximumFromNode(BSTNode<T> *node)
    {
        // TODO: check node != NULL && size > 0
        while(node->right() != NULL)
            node = node->right();

        return node;
    }

    BSTNode<T> *SearchFromNode(BSTNode<T> *node, const T& value)
    {
        while(node != NULL)
        {
            if(value == node->value())
                break;
            else if(value < node->value())
                node = node->left();
            else
                node = node->right();
        }

        return node;
    }

    void Transplant(BSTNode<T> *u, BSTNode<T> *v)
    {
        BSTNode<T> *uparent = u->parent();

        if(uparent == NULL)
            root_ = v;
        else if(u == uparent->left())
            uparent->set_left(v);
        else
            uparent->set_right(v);

        if(v != NULL)
            v->set_parent(uparent);
    }

    void ClearFromNode(BSTNode<T> *node)
    {
        // Post-order cleaning
        if(node != NULL)
        {
            ClearFromNode(node->left());
            ClearFromNode(node->right());
            delete node;
        }
    }

    BSTNode<T> *root_;
    int size_;
};

#endif // BST_H_
