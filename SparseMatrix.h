#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <cstddef>

class SparseMatrix {
private:
    struct Node {
        int row;
        int col;
        double value;
        Node* next;
        
        Node(int r, int c, double v) : row(r), col(c), value(v), next(nullptr) {}
    };
    
    Node* head;
    size_t count;
    
    // Helper function to find a node or its insertion point
    Node* findNode(int row, int col, Node** prev = nullptr) const {
        Node* current = head;
        Node* previous = nullptr;
        
        while (current && (current->row < row || (current->row == row && current->col < col))) {
            previous = current;
            current = current->next;
        }
        
        if (prev) *prev = previous;
        return current;
    }
    
public:
    SparseMatrix() : head(nullptr), count(0) {}
    
    ~SparseMatrix() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void set(int row, int col, double value) {
        Node* prev = nullptr;
        Node* current = findNode(row, col, &prev);
        
        if (current && current->row == row && current->col == col) {
            if (value != 0.0) {
                current->value = value;
            } else {
                if (prev) prev->next = current->next;
                else head = current->next;
                delete current;
                count--;
            }
        } else if (value != 0.0) {
            Node* newNode = new Node(row, col, value);
            newNode->next = current;
            if (prev) prev->next = newNode;
            else head = newNode;
            count++;
        }
    }
    
    double get(int row, int col) const {
        Node* current = findNode(row, col);
        if (current && current->row == row && current->col == col) {
            return current->value;
        }
        return 0.0;
    }
    
    size_t nonZeroCount() const {
        return count;
    }
};

#endif // SPARSE_MATRIX_H