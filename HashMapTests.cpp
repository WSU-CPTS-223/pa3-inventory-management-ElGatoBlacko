#include "HashMap.hpp"
#include "Product.hpp"
#include <string>
#include <cassert>
#include <iostream>


void testInsertandFind(){
    HashMap<std::string,Product> test;

    //adds a product item
    Product p1;
    p1.uniqId = "A1";
    p1.productName = "normal test case";
    test.insert(p1.uniqId,p1);
    std::list<std::pair<std::string,Product>> result1 = test.find("A1");
    //tests if product name matches
    assert(result1.front().second.productName=="normal test case");

    //adds product with duplicate key
    Product p2;
    p2.uniqId = "A1";
    p2.productName = "duplicate test case";
    test.insert(p2.uniqId,p2);
    std::list<std::pair<std::string,Product>> result2 = test.find("A1");
    //tests if both product names are stored at key location
    assert(result2.front().second.productName=="normal test case");
    result2.pop_front();
    assert(result2.front().second.productName=="duplicate test case");

    //adds product with differnt key
    Product p3;
    p3.uniqId = "B1";
    p3.productName = "non duplicate test case";
    test.insert(p3.uniqId,p3);
    std::list<std::pair<std::string,Product>> result3 = test.find("B1");
    //tests if product name matches at new keys location
    assert(result3.front().second.productName=="non duplicate test case");
    std::cout<< "insert and find tests passed"<<std::endl;
}


void testResize(){
    //add enough items to make load factor >0.5 
    HashMap<int,std::string> test;
    for(int i = 0; i < 513; i++){
        test.insert(i,"testvalue" + std::to_string(i));
    }

    //loops through all items and makes sure each item has the correct key and value
    for(int i = 0; i < 513; i++){
        std::list<std::pair<int,std::string>> result = test.find(i);
        bool found = false;
        if(result.front().first == i && result.front().second == ("testvalue" +std::to_string(i))){
            found = true;
        }
        assert(found);
    }
    std::cout<< "resize test passed"<<std::endl;
}

int main(){
    testInsertandFind();
    testResize();
    return 0;
}