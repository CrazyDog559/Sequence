//
//  Sequence.h
//
//
//  Created by Drew Wan on 4/22/23.
//

#ifndef Sequence_h
#define Sequence_h

#include <stdio.h>
#include <iostream>
using ItemType = std:: string;
//using ItemType = unsigned long;

class Sequence
{
  public:
    Sequence();
    ~Sequence();
    Sequence(const Sequence& other);
    Sequence& operator=(const Sequence& rhs);
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    void dump();
   
private:
    struct Node
    {
        ItemType m_value;
        Node* next;
        Node* prev;
        
    };
    
    Node* head;
    Node* tail;
    int m_size;
};

#endif /* Sequence_h */

int subsequence(const Sequence& seq1, const Sequence& seq2);

void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result);
