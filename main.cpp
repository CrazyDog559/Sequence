//
//  main.cpp
//  Homework2
//
//  Created by Drew Wan on 4/22/23.
//

#include <iostream>
#include <cassert>
#include "Sequence.h"


using namespace std;

/// Description
int main() {
    Sequence a;

    a.insert(0,"a"); //Checking inserts
    assert(a.insert(1, "2") == 1);
    assert(a.insert(2, "3") == 2); //checking with some asserts
    a.insert(3, "4"); //using dump to check
    assert(a.insert(4, "5") == 4);

    assert(a.set(2, "6") == true); //Checking set

    //a.dump();

    string x;
    assert(a.get(0, x)  &&  x == "a"); //Testing Get

    assert(a.find("2") == 1); //testing find

    Sequence s1;
    s1.insert(0, "paratha");
    s1.insert(0, "focaccia");
    Sequence s2;
    s2.insert(0, "roti");
    s2.insert(0, "bruh");
    s2.remove("bruh");
    s1.swap(s2);

    //testing insert swap and remove
    assert(s1.size() == 1); //size should be 1 since swapped
    assert(s1.find("roti") == 0); //roti found at pos 1
    assert(s1.find("bruh") == -1); //bruh not in list
    assert(s2.size() == 2); // size should switch
    assert(s2.find("focaccia") == 0); //both of these should be found in swap
    assert(s2.find("paratha") == 1);
    //s1.dump();



    Sequence s3 = Sequence(a); //testing copy constructor
    s2 = s1; //testing operator

    a.erase(5); //testing erase from end
    a.erase(0); // from front
    a.erase(3); //from middle

    //a.dump(); //used dump to verify

    Sequence b;
    b.insert(0,"a");
    b.insert(1, "b");
    b.insert(2, "c");
    b.insert(3, "d");
    b.insert(4, "e");


    b.erase(0); //retesting erase
    assert(b.find("a") == -1); //testing find and verfying a is gone
    b.insert(0,"a"); //testing insert and putting a back
    assert(b.find("a") == 0); // verfying being put back
    b.erase(1); //testing erase in the middle
    assert(b.find("b") == -1);
    b.insert(1,"b");
    assert(b.find("b") == 1); // find at pos 1
    b.erase(4); //testing erase in the end
    assert(b.find("e") == -1);
    //b.dump();

    Sequence c1;
    c1.insert("sup"); //testing insert
    //c1.dump();
    assert(c1.erase(0) == true); //testing erase again

    //testing normal insert
    c1.insert("1");
    c1.insert("3");
    c1.insert("5");
    c1.insert("4");
    c1.insert("2");
    c1.insert("0");

    //cerr << "test c1" << endl;
    //c1.dump(); //testing via dump.  should be 012345



    assert(b.find("d") == 3); //testing find d should be at 3
    b.remove("d"); //testing remove
    //b.dump();
    assert(b.find("d")== -1); //return -1 cuz not there
    b.remove("e"); //remove 3
    assert(b.find("e") == -1); //return -1 cuz not there



    Sequence a1;
    a1.insert("1");
    a1.insert("2");
    a1.insert("3");

    Sequence a2;
    a2.insert("4");
    a2.insert("5");
    a2.insert("6");

    Sequence a3;
    //testing concatReverse via dump with an empty 3rd sequence
    concatReverse(a1,a2,a3);

    //a3.dump();


    Sequence b1;
    b1.insert(0,"hi");
    b1.insert(1, "bruh");
    b1.insert(2, "hola");
    b1.insert(3, "suppo");

    Sequence b2;
    b2.insert(0, "bruh");
    b2.insert(1, "hola");
    b2.insert(2, "suppo");
    //testing subsequnce
    assert(subsequence(b1, b2) == 1);
    //b2.dump();

    Sequence d1;
    d1.insert(0,"1");
    d1.insert(1,"3"); //testing if the 3 comes first but the subsequence is after
    d1.insert(2,"2");
    d1.insert(3,"3");
    d1.insert(4,"4");
    d1.insert(5,"5");

    Sequence d2;
    d2.insert("3");
    d2.insert("4");
    d2.insert("5");
    //testing subsequnce
    //cerr << subsequence(d1,d2) << endl;
    assert(subsequence(d1,d2) == 3); //should start at position 3
    Sequence e;
    assert(e.empty() == true); // testing if empty


    
    
    

//Testing unsigned Long
//------------------------------------
//   Sequence a;
//   a.insert(0,1);
//   a.insert(1, 2);
//   a.insert(2, 3);
//   a.insert(3, 4);
//   a.insert(4, 5);
//
//   a.set(2, 6);
//
//
//   unsigned long x;
//   assert(a.get(0, x)  &&  x == 1);
//
//   assert(a.find(2) == 1);
//
//   Sequence s1;
//   s1.insert(0, 1234);
//   s1.insert(0, 34);
//   Sequence s2;
//   s2.insert(0, 56);
//   s1.swap(s2);
//
//
//   assert(s1.size() == 1);
//   assert(s1.find(56) == 0);
//   assert(s1.find(235) == -1);
//   assert(s2.size() == 2);
//   assert(s2.find(34) == 0);
//   assert(s2.find(1234) == 1);
//
//   Sequence s3 = Sequence(a);
//   s2 = s1;
//
//   a.erase(5);
//   a.erase(0);
//   a.erase(3);
//
//   Sequence b;
//   b.insert(0,1);
//   b.insert(1, 2);
//   b.insert(2, 3);
//   b.insert(3, 4);
//   b.insert(4, 5);
//
//
//   b.erase(0);
//
//   assert(b.find(1) == -1);
//   b.insert(0,1);
//   b.erase(1);
//   assert(b.find(2) == -1);
//   b.insert(1,2);
//   b.erase(4);
//   assert(b.find(5) == -1);
//   b.dump();
//
//   Sequence c1;
//   c1.insert(1);
//   c1.dump();
//   assert(c1.erase(0) == true);
//
//
//
//   assert(b.find(4) == 3);
//   b.remove(4);
//   b.dump();
//   assert(b.find(4)== -1);
//   b.remove(5);
//   assert(b.find(5) == -1);
//
//
//
//   Sequence a1;
//   a1.insert(1);
//   a1.insert(2);
//   a1.insert(3);
//
//   Sequence a2;
//   a2.insert(4);
//   a2.insert(5);
//   a2.insert(6);
//
//   Sequence a3;
//
//   concatReverse(a1,a2,a3);
//
//   a3.dump();
//
//   Sequence b1;
//   b1.insert(0,0);
//   b1.insert(1, 1);
//   b1.insert(2, 2);
//   b1.insert(3, 3);
//
//   Sequence b2;
//   b2.insert(0, 1);
//   b2.insert(1, 2);
//   b2.insert(2, 3);
//   assert(subsequence(b1, b2) == 1);
//
//
//   b2.dump();

    
    
   
   
    
    cerr << " yay " << endl;
    
}
