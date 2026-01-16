#include "object.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

  if (argc < 2) { // in case the user executes the program without any arguments
    std::cerr << "Usage: " << argv[0] << " <object_type> [parameters..]\n";
    std::cerr << "\nRegistered objects: \n";
    for (const auto &name :
         ObjectRegistry::getRegisteredObjects()) { // shows registered objects
      std::cerr << " - " << name << "\n";
    }
    return 1;
  }

  std::string objectType = argv[1];

  auto obj =
      ObjectRegistry::create(objectType); // creates an object of objectType and
                                          // returns a unique pointer to it

  if (!obj) {
    std::cerr << "Error: Unknown object type '" << objectType << "'\n";
    std::cerr << "\nRegistered objects:\n";
    for (const auto &name : ObjectRegistry::getRegisteredObjects()) {
      std::cerr << " - " << name << "\n";
    }
    return 1;
  }

  // parse arguments and perform calculations
  std::vector<std::string> args;
  for (int i = 2; i < argc; ++i) {
    args.push_back(argv[i]); // args is passed on to the object to use extra
                             // parameters to calculate area, perimeter, etc
  }

  if (!obj->parseAndCalculate(args)) {
    return 1;
  }
  return 0;
}