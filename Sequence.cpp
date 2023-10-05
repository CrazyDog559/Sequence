//
//  Sequence.cpp
//  
//
//  Created by Drew Wan on 4/22/23.
//

#include "Sequence.h"

Sequence :: Sequence() {
    //set to 0 or null
    m_size = 0;
    head = nullptr;
    tail = nullptr;
}
Sequence :: ~Sequence () {
    //setting temp to head then deleting
    Node* temp = head;
    while(temp != tail) {
        Node* next = temp -> next;
        delete temp;
        temp = next;
    }
    delete temp;
}



Sequence :: Sequence (const Sequence& other) {
    //set head and tail to null
    head = nullptr;
    tail = nullptr;
    m_size = 0;
    //set a temp
    Node* temp;
    temp = other.head;
    
    if (other.head == nullptr) {
        //head and tail null
        head = tail = NULL;
        return;
    } else {
        int i = 0;
        //loop
        while (temp != other.tail) {
            //std::cout << temp -> m_value << std::endl;
            //insert value at i pos
            insert(i,temp -> m_value);
            temp = temp -> next;
            i++;
        }
        //insert once more cuz ends at tail
        insert(i,temp -> m_value);
    }
   
   
    
}
//operator
Sequence& Sequence :: operator=(const Sequence& rhs) {
    if(this != &rhs) {
        Sequence temp = rhs;
        swap(temp);
    }
    return *this;
}
//empty constuctor
bool Sequence :: empty() const {
    //check if empty
    if (m_size == 0) {
        return true;
    }
    return false;
}
int Sequence :: size() const {
    //return size
    return m_size;
}
int Sequence :: insert(int pos, const ItemType& value) {
    if (pos < 0 || pos > m_size) {
        return -1;
    } else {
        //create a newNode to go through
        Node* newNode = new Node;
        newNode -> m_value = value;
        //when in the beginning
        if (pos == 0) {
            //when empty
            if (empty() == true) {
                newNode -> prev = newNode;
                newNode -> next = newNode;
                head = newNode;
                tail = newNode;
            } else {
                //first, but if other elements in list
                //assigning nodes
                newNode -> prev = tail;
                newNode -> next = head;
                
                tail -> next = newNode;
                head -> prev = newNode;
                head = newNode;
                
            }
        } else if (pos == m_size) {
            //if at the end of the list
            //assigning nodes
            newNode -> prev = tail;
            newNode -> next = head;
            tail -> next = newNode;
            head -> prev = newNode;
            tail = newNode;
        } else {
            //if at the middle of the list
        
            Node* temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp -> next;
                
            }
            //assigning the nodes
            newNode -> prev = temp;
            newNode -> next = temp -> next;
            temp -> next = newNode;
            newNode -> next -> prev = newNode;
            
        }
           
    }
    //increase size and return position
    m_size++;
    return pos;
    
    
}
int Sequence :: insert(const ItemType& value) {
    
    if (empty() == true) {
        //if empty insert at position 0 or first position
        insert(0, value);
        return 0;
    }
    Node* i;
    int pos = 0;
    //increasing position until value
    for (i = head; i != tail && i -> m_value < value; i = i -> next) {
        pos++;
    }
    //inserting if at the end
    if (i == tail && i -> m_value < value) {
        insert(pos + 1, value);
        
        return pos + 1;
    } else {
        //inserting the position found from above
        insert(pos, value);
        return pos;
    }
    
    
}
bool Sequence :: erase(int pos) {
    
    if (pos < 0 || pos >= m_size) {
        return false;
    }
    
   
    Node* killNode;
    //if at the front
    if (pos == 0) {
        killNode = head;
        if(m_size == 1) {
            //if only one element, set head and tail null
            head = nullptr;
            tail = nullptr;
        } else {
            //if erasing from front and has more than one element
            tail -> next = head -> next;
            head -> next -> prev = head -> prev;
            head = tail -> next;
          }
        
        } else if (pos == m_size - 1) {
            //if deleting from the end
            killNode = tail;
            tail = tail -> prev;
            
        } else {
            //if deleting from the middle
            killNode = head;
            for (int i = 0; i < pos; i++) {
                killNode = killNode -> next;

            }

            killNode -> next -> prev = killNode -> prev;
            killNode -> prev -> next = killNode -> next;
          
    }
    //delete the temp node
    delete killNode;
    //decrease size
    m_size--;
    return true;
}
int Sequence :: remove(const ItemType& value) {
    int counter = 0;
    Node* i = head;
    if (m_size != 0) {
        int pos = 0;
        //while the temp head not pointing to tail
        while(i != tail) {
            //if values match
            if (i -> m_value == value) {
                i = i -> next;
                counter++;
                //use erase function to delete at the position
                erase(pos);
            } else {
                //incrase the potion and move to next
                pos++;
                i = i -> next;
            }
            
        }
        //doesn't check for tail so cheking again.
        if (tail -> m_value == value) {
            erase(m_size - 1);
            counter++;
        }
        
    }
    //return counter.
    return counter;
}
bool Sequence :: get(int pos, ItemType& value) const {
    if (pos < 0 || pos >= m_size) {
        return false;
    } else {
        Node* temp = head;
        //loop through list
        for (int i = 0; i < pos; i++) {
            temp = temp -> next;
        }
        //set value to the temp value
        value = temp -> m_value;
        return true;
    }
    
}

bool Sequence :: set(int pos, const ItemType& value) {
    
    if (pos < 0 || pos >= m_size) {
        return false;
    } else {
        Node* temp = head;
        //loop through list
        for (int i = 0; i < pos; i++) {
            temp = temp -> next;
        }
        //set the temp value to the value put in
        temp -> m_value = value;
        return true;
    }
}

int Sequence :: find(const ItemType& value) const {
    
    Node* temp = head; // set temp to head
    int pos = 0; // set pos to 0

    // loop over list to find first occurrence of value
    while(temp != tail) {
        if(temp -> m_value == value) // value found, return pos
            return pos;
        pos++;
        temp = temp -> next;
    }
    if (tail -> m_value == value) {
        return m_size - 1;
    } else {
        return -1;
    }


}
void Sequence :: swap(Sequence& other) {
    
    
    //create temp for head tail and size
    Node* tempHead;
    Node* tempTail;
    int tempSize = m_size;
    //set the temps
    tempHead = head;
    tempTail = tail;
    
    //set the heads and tails
    head = other.head;
    tail = other.tail;
    //swap them
    other.head = tempHead;
    other.tail = tempTail;
    
    //swapping sizes
    m_size = other.m_size;
    other.m_size = tempSize;
    
    
    
}


int subsequence(const Sequence& seq1, const Sequence& seq2) {
    
    
    int count = 0;
    //loop through the first sequence
    for (int i = 0; i < seq1.size(); i++) {
        //loop through the second
        for (int j = 0; j < seq2.size(); j++) {
            
            ItemType value1;
            //get sequence 1
            seq1.get(i + j, value1);
            
            ItemType value2;
            //get sequence 2
            seq2.get(j, value2);

            //if they are not equal
            if (value1 != value2) {
                count = 0;
            } else {
                //increase counter
                count++;
            }

        }
        //if the amount matched
        if (count == seq2.size()) {
            //return where starts
            return i;
        }

        if (i >= seq1.size() - seq2.size()) {
            return -1;
        }


    }

    return -1;
    

}
void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result) {
     
    Sequence temp;
    //loop through sequence 1 backwards
    for (int i = seq1.size()-1; i >= 0 ; i--) {
        
        ItemType value;
        //get values in sequence 1
        seq1.get(i, value);
        //insert reverse order
        temp.insert((seq1.size() - 1)-i, value);
    }
    
    
    for (int i = seq2.size() - 1; i >= 0; i--) {
        ItemType value;
        seq2.get(i, value);
        //insert after the first sequence
        temp.insert(seq1.size() + seq1.size() - 1 - i, value);
    }

    result = temp;
 


}


void Sequence::dump() {
    Node* curr = head;
    std:: cerr << "\n--------------\n" << std:: endl;
    std :: cerr<< " \n start dump: " << std::endl;
    for (curr = head; curr != tail; curr = curr->next)
    {
        
        std :: cerr << curr->m_value << std::endl;
    }
    std :: cerr << curr -> m_value;
}
