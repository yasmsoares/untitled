#include <iostream>
#include <utility>
#include <cassert>
#include <fstream>
#include "Map.h"
using namespace std;

bool testInt()
{
    Map<int, int> map1;
    // Insert a new (key,value) and check if its correct
    int k1 = 1, v1= 3;
    auto pair1 = map1.insert(k1, v1);
    assert(pair1.second);
    assert(*pair1.first == v1);
    assert(map1[k1] == v1);

    // Check that an attempt to insert an existing key
    // doesn't change the value
    int k2 = 1, v2 = 5;
    auto pair2 = map1.insert(k2, v2);
    assert(!pair2.second);
    assert(*pair2.first == v1);
    assert(map1[k1] == v1);

    // Check hash collision
    int k3 = k1 + SIZE, v3 = 115;
    auto pair3 = map1.insert(k3,v3);
    assert(pair3.second);
    assert(*pair3.first == v3);
    assert(map1[k1] == v1);
    assert(map1[k3] == v3);

    // test operator[]
    int v4 = 1984;
    map1[k1] = v4;
    assert(map1[k1] == v4);

    int k5 = 23432,v5 = 525829;
    map1[k5] = v5;
    assert(map1[k5] == v5);

    cout << "testInt() passed\n";
}

bool testString()
{
    Map<string, string> map1;
    // Insert a new (key,value) and check if its correct
    string k1 = "Paula", v1= "gorgeous";
    auto pair1 = map1.insert(k1, v1);
    assert(pair1.second);
    assert(*pair1.first == v1);
    assert(map1[k1] == v1);

    // Check that an attempt to insert an existing key
    // doesn't change the value
    string k2 = "Paula", v2 = "ugly";
    auto pair2 = map1.insert(k2, v2);
    assert(!pair2.second);
    assert(*pair2.first == v1);
    assert(map1[k1] == v1);

    // Check hash collision
    string k3 = "aluaP", v3 = "suoegrog";
    auto pair3 = map1.insert(k3,v3);
    assert(pair3.second);
    assert(*pair3.first == v3);
    assert(map1[k1] == v1);
    assert(map1[k3] == v3);

    // test operator[]
    string v4 = "Smart";
    map1[k1] = v4;
    assert(map1[k1] == v4);

    string k5 = "Yasmin", v5 = "Soares";
    map1[k5] = v5;
    assert(map1[k5] == v5);

    cout << "testString() passed\n";
}

int main()
{
    testInt();
    testString();

}
