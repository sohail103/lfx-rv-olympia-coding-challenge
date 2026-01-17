#ifndef OBJECT_H
#define OBJECT_H

#include <map>
#include <memory>
#include <string>
#include <vector>

// abstract class that other objects derive from
// objects that inherit from this have to define the overridden functions
class Object {
public:
  virtual ~Object() = default;

  // pure virtual functions that derived objects must implement
  virtual std::string getDescription() const = 0;
  virtual bool parseAndCalculate(const std::vector<std::string> &args) = 0;
  virtual std::string getName() const = 0;
};

// object registry - maintains a map of string -> function pointer to create
// object
class ObjectRegistry {
private:
  using CreatorFunc = std::unique_ptr<Object> (*)();
  std::map<std::string, CreatorFunc> registry;

  static ObjectRegistry &instance();

public:
  static void registerObject(const std::string &name, CreatorFunc creator);
  static std::unique_ptr<Object> create(const std::string &name);
  static std::vector<std::string> getRegisteredObjects();
};

// helper class for automatic registration
template <typename T> class ObjectRegistrar {
public:
  ObjectRegistrar(const std::string &name) {
    ObjectRegistry::registerObject(
        name, []() -> std::unique_ptr<Object> {
          return std::make_unique<T>(); // lambda returns unique_ptr to newly
                                        // created object
        });
  }
};

// macro to simplify registration
#define REGISTER_OBJECT(ClassName, name)                                       \
  static ObjectRegistrar<ClassName> ClassName##_registrar(name);
#endif