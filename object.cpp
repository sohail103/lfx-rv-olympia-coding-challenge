#include "object.hpp"

ObjectRegistry& ObjectRegistry::instance() {
    static ObjectRegistry inst;
    return inst;
}

void ObjectRegistry::registerObject(const std::string& name, CreatorFunc creator) {
    instance().registry[name] = creator;
}

std::unique_ptr<GeometricObject> ObjectRegistry::create(const std::string& name) {
    auto& reg = instance().registry;
    auto it = reg.find(name);
    if (it != reg.end()) {
        return it->second();
    }
    return nullptr;
}

std::vector<std::string> ObjectRegistry::getRegisteredObjects() {
    std::vector<std::string> names;
    for (const auto& pair : instance().registry) {
        names.push_back(pair.first);
    }
    return names;
}