#pragma once

template <class T>
struct nod {
public:
    int cnt = 0; // nr de copii
    T info;
    nod** children;
};

template <class T>
class Tree {
    nod<T>* root;
public:
    Tree() {
        this->root = nullptr;
    }

    void add_node(nod<T>*& parent, const T& value) {
        if (parent == nullptr) {
            parent = new nod<T>;
            parent->info = value;
            parent->children = nullptr;
            this->root = parent;
        }
        else {
            nod<T>** new_children = new nod<T>*[parent->cnt + 2];

            for (int i = 0; i < parent->cnt; i++) {
                new_children[i] = parent->children[i];
            }

            new_children[parent->cnt] = new nod<T>;
            new_children[parent->cnt]->info = value;
            new_children[parent->cnt]->children = nullptr;
            new_children[parent->cnt]->cnt = 0;
            new_children[parent->cnt + 1] = nullptr;

            delete[] parent->children;
            parent->children = new_children;
            parent->cnt++;
        }
    }

    void get_node(nod<T>* parent, const T& value) {
        if (parent == nullptr) {
            return this->root;
        }
        else {
            for (int i = 0; i < parent->cnt; i++) {
                if (parent->children[i]->info == value) {
                    return parent->children[i]->info;
                }
            }
            return nullptr;
        }
    }

    void print(nod<T>* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->info << " ";

        for (int i = 0; i < node->cnt; i++) {
            print(node->children[i]);
        }
    }

    nod<T>* find(nod<T>* node, const T& value, int (*callback)(T, T)) {
        if (node == nullptr)
            return nullptr;
        if (callback(node->info, value)) {
            return node;
        }

        for (int i = 0; i < node->cnt; i++) {
            nod<T>* p = find(node->children[i], value, callback);
            if (p)
                return p;
        }

        return nullptr;
    }

    void insert(nod<T>*& parent, int index, const T& value) {
        nod<T>** p = new nod<T>*[parent->cnt + 1];
        p[parent->cnt] = new nod<T>;
        for (int i = 0; i < index; i++) {
            p[i] = parent->children[i];
        }
        for (int i = index + 1; i < parent->cnt + 1; i++) {
            p[i] = parent->children[i - 1];
        }
        delete[] parent->children;
        nod<T>* k = new nod<T>;
        k->info = value;
        k->children = nullptr;
        p[index] = k;
        parent->children = p;
        parent->cnt++;

    }

    void sort(nod<T>*& parent, int (*callback)(T, T)) {
        for (int i = 0; i < parent->cnt - 1; i++) {
            for (int j = i + 1; j < parent->cnt; j++) {
                if (callback(parent->children[i]->info, parent->children[j]->info) == -1) {
                    std::swap(parent->children[i], parent->children[j]);
                }
                else if (callback == nullptr) {
                    if (parent->children[i]->info > parent->children[j]->info) {
                        std::swap(parent->children[i], parent->children[j]);
                    }
                }
            }
        }
    }

    /*not implemented*/
    /*
    int count(nod<T>* node) {
        int count = 0;
        while (node->children[count] != nullptr) {
            count++;
        }
        return count;
    }
    */

    int count(nod <T>* node) {
        int c = 0;
        if (node == nullptr) {
            return 0;
        }
        for (int i = 0; node->children[i] != nullptr; i++) {
            c++;
            c += count(node->children[i]);
        }
        return c;
    }

    ~Tree() {
        delete_node(this->root);
    }

private:
    void delete_node(nod<T>* node) {
        if (node == nullptr)
            return;
        for (int i = 0; i < node->cnt; i++) {
            delete_node(node->children[i]);
        }
        delete[] node->children;
        delete node;
    }
};
