#include "object.hpp"
#include <iostream>
#include <string>

int main (int argc, char* argv[]) {

    if(argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <object_type> [parameters..]\n";
        std::cerr << "\nRegistered objects: \n";
        for(const auto& name: ObjectRegistry::getRegisteredObjects()) {
            std::cerr << " - " << name << "\n";
        }
        return 1;
    }

    std::string objectType = argv[1];

    auto obj = ObjectRegistry::create(objectType);

    if (!obj) {
        std::cerr << "Error: Unknown object type '" << objectType << "'\n";
        std::cerr << "\nRegistered objects:\n";
        for (const auto& name: ObjectRegistry::getRegisteredObjects()) {
            std::cerr << " - " << name << "\n";
        } 
        return 1;
    }

    // parse arguments and perform calculations
    std::vector<std::string> args;
    for (int i=2; i<argc; ++i) {
        args.push_back(argv[i]);
    }

    if(!obj->parseAndCalculate(args)) {
        return 1;
    }
    return 0;
}