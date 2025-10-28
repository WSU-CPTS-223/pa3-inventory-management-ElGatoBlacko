#include <iostream>
#include <string>
#include "HashMap.hpp"
#include <fstream>
#include "Product.hpp"
#include <sstream>

using namespace std;



std::vector<std::string> parseLine(const std::string& line) {
    std::vector<std::string> fields;
    std::string curField;
    bool inQuotes = false;

    for(int i = 0; i <line.size(); i++){
        char c = line[i];

        if(c == '"'){
            inQuotes = !inQuotes;
        }else if(c == ',' && !inQuotes){
            if(curField == ""){
                fields.push_back("NA");
            }else{
                fields.push_back(curField);    
            }
            curField = "";
        }else{
            curField+=c;
        }
    }
    if(curField == ""){
        fields.push_back("NA");
        }else{
            fields.push_back(curField);    
    }
    return fields;
}

std::vector<std::string> splitCategories(std::string catString){
    std::vector<std::string> result;
    std::string tok;
    std::stringstream ss(catString);

    while(std::getline(ss,tok,'|')){
        tok.erase(0, tok.find_first_not_of(" \""));
        tok.erase(tok.find_last_not_of(" \"") + 1);
        result.push_back(tok);
    }
    return result;
}

void loadTables(HashMap<string,Product>& idMap, HashMap<string,Product>& categoryMap,std::ifstream& in){
    std::string line;
    
    // skip header
    std::getline(in, line);
    while(std::getline(in, line)){
        std::vector<std::string> fields = parseLine(line);
        Product tempProd;
        tempProd.uniqId = fields[0];
        tempProd.productName = fields[1];
        tempProd.brandName = fields[2];
        tempProd.asin = fields[3];
        tempProd.categories = splitCategories(fields[4]);
        tempProd.upcEanCode = fields[5];
        tempProd.listPrice = fields[6];
        tempProd.sellingPrice = fields[7];
        tempProd.quantity = fields[8];
        tempProd.modelNumber = fields[9];
        tempProd.aboutProduct = fields[10];
        tempProd.productSpecification = fields[11];
        tempProd.technicalDetails = fields[12];
        tempProd.shippingWeight = fields[13];
        tempProd.productDimensions = fields[14];
        tempProd.imageUrls = fields[15];
        tempProd.variantUrls = fields[16];
        tempProd.sku = fields[17];
        tempProd.productUrl = fields[18];
        tempProd.stock = fields[19];
        tempProd.productDetails = fields[20];
        tempProd.dimensions = fields[21];
        tempProd.color = fields[22];
        tempProd.ingredients = fields[23];
        tempProd.directionToUse = fields[24];
        tempProd.isAmazonSeller = fields[25];
        tempProd.sizeQuantityVariant = fields[26];
        tempProd.productDescription = fields[27];

        idMap.insert(tempProd.uniqId,tempProd);
        for(int i = 0; i < tempProd.categories.size();i++){
            categoryMap.insert(tempProd.categories[i],tempProd);
        }
    }
}


void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(HashMap<string,Product>& idMap, HashMap<string,Product>& categoryMap,string line)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        string id = line.substr(5);
        std::list<std::pair<string,Product>> temp = idMap.find(id);
        if(temp.empty()){
            cout << "Inventory/Product not found" << endl;
        }else{
            Product item = temp.back().second;
            item.print();
        }
        //cout << "YET TO IMPLEMENT!" << endl;
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        string category = line.substr(14);
        std::list<std::pair<string,Product>> temp = categoryMap.find(category);
        if(temp.empty()){
            cout << "Invalid Category" << endl;
        }else{
            while(!temp.empty()){
                Product item = temp.back().second;
                std::cout << "uniqId               : " << item.uniqId << "\n";
                std::cout << "productName          : " << item.productName << "\n";
                temp.pop_back();
            }
        }

        //cout << "YET TO IMPLEMENT!" << endl;
    }
}

void bootStrap(HashMap<string,Product>& idMap, HashMap<string,Product>& categoryMap)
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
    std::ifstream file("marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data-1.csv");
    loadTables(idMap,categoryMap,file);
    file.close();

    //idMap.print();
    //categoryMap.print();
}

int main(int argc, char const *argv[])
{
    // HashMap<string, string> test;
    // test.insert("key one", "abe");
    // test.insert("key two", "beat");
    // test.insert("key tree", "cece");
    // test.insert("key four", "dede");
    // test.insert("key one", "abe2");
    // test.insert("key two", "beat2");
    // test.insert("key tree", "cece2");
    // test.insert("key four", "dede2");
    // test.print();
    // std::list<std::pair<string,string>> temp = test.find("key tre");
    HashMap<string,Product> idTable;
    HashMap<string,Product> categoryTable;
    string line;
    bootStrap(idTable,categoryTable);
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(idTable,categoryTable,line);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
