#include "object.hpp"

ObjectRegistry &ObjectRegistry::instance() {
  static ObjectRegistry inst;
  return inst; // returns a reference to a static ObjectRegistry object
}

// NOTE: use the macro REGISTER_OBJECT, this is not intended to be used directly
void ObjectRegistry::registerObject(const std::string &name,
                                    CreatorFunc creator) {
  instance().registry[name] = creator; // to register a new object
}
std::unique_ptr<Object>
ObjectRegistry::create(const std::string &name) {
  auto &reg = instance().registry;
  auto it = reg.find(name);
  if (it != reg.end()) {
    return it
        ->second(); // calls the creator function and returns the created object
  }
  return nullptr;
}

std::vector<std::string>
ObjectRegistry::getRegisteredObjects() { // to display list of registered
                                         // objects
  std::vector<std::string> names;
  for (const auto &pair : instance().registry) {
    names.push_back(pair.first);
  }
  return names;
}