#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <vector>
#include <iostream>

class Product{
    //fields for each column from csv
    public:
    std::string uniqId;
    std::string productName;
    std::string brandName;
    std::string asin;
    std::vector<std::string> categories;
    std::string upcEanCode;
    std::string listPrice;
    std::string sellingPrice;
    std::string quantity;
    std::string modelNumber;
    std::string aboutProduct;
    std::string productSpecification;
    std::string technicalDetails;
    std::string shippingWeight;
    std::string productDimensions;
    std::string imageUrls;
    std::string variantUrls;
    std::string sku;
    std::string productUrl;
    std::string stock;
    std::string productDetails;
    std::string dimensions;
    std::string color;
    std::string ingredients;
    std::string directionToUse;
    std::string isAmazonSeller;
    std::string sizeQuantityVariant;
    std::string productDescription;

    //print all elements of product in neat form
    void print() {
        std::cout << "uniqId               : " << uniqId << "\n";
        std::cout << "productName          : " << productName << "\n";
        std::cout << "brandName            : " << brandName << "\n";
        std::cout << "asin                 : " << asin << "\n";
        std::cout << "categories           : ";
        for (size_t i = 0; i < categories.size(); i++) {
            std::cout << categories[i];
            if (i < categories.size() - 1){
                std::cout << " | ";
            } 
        }
        std::cout << "\n";
        std::cout << "upcEanCode           : " << upcEanCode << "\n";
        std::cout << "listPrice            : " << listPrice << "\n";
        std::cout << "sellingPrice         : " << sellingPrice << "\n";
        std::cout << "quantity             : " << quantity << "\n";
        std::cout << "modelNumber          : " << modelNumber << "\n";
        std::cout << "aboutProduct         : " << aboutProduct << "\n";
        std::cout << "productSpecification : " << productSpecification << "\n";
        std::cout << "technicalDetails     : " << technicalDetails << "\n";
        std::cout << "shippingWeight       : " << shippingWeight << "\n";
        std::cout << "productDimensions    : " << productDimensions << "\n";
        std::cout << "imageUrls            : " << imageUrls << "\n";
        std::cout << "variantUrls          : " << variantUrls << "\n";
        std::cout << "sku                  : " << sku << "\n";
        std::cout << "productUrl           : " << productUrl << "\n";
        std::cout << "stock                : " << stock << "\n";
        std::cout << "productDetails       : " << productDetails << "\n";
        std::cout << "dimensions           : " << dimensions << "\n";
        std::cout << "color                : " << color << "\n";
        std::cout << "ingredients          : " << ingredients << "\n";
        std::cout << "directionToUse       : " << directionToUse << "\n";
        std::cout << "isAmazonSeller       : " << isAmazonSeller << "\n";
        std::cout << "sizeQuantityVariant  : " << sizeQuantityVariant << "\n";
        std::cout << "productDescription   : " << productDescription << "\n";
    }

};

#endif