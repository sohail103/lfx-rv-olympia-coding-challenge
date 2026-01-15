#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <vector>
#include <memory>
#include <map>

// base class defining interface for all objects
class GeometricObject {
    public:
        virtual ~GeometricObject() = default;

        // pure virtual functions that derived objects must implement
        virtual std::string getDescription() const = 0;
        virtual std::string getUsage() const = 0;
        virtual bool parseAndCalculate(const std::vector<std::string>& args) = 0;
        virtual std::string getName() const = 0;
};

// object registry
class ObjectRegistry {
    private:
        using CreatorFunc = std::unique_ptr<GeometricObject>(*)();
        std::map<std::string, CreatorFunc> registry;

        static ObjectRegistry& instance();
    
    public:
        static void registerObject(const std::string& name, CreatorFunc creator);
        static std::unique_ptr<GeometricObject> create(const std::string& name);
        static std::vector<std::string> getRegisteredObjects();
};

// helper class for automatic registration
template<typename T>
class ObjectRegistrar {
    public:
        ObjectRegistrar(const std::string& name) {
            ObjectRegistry::registerObject(name, []() -> std::unique_ptr<GeometricObject> {
                return std::make_unique<T>();
            });
        }
};

// macro to simplify registration
#define REGISTER_OBJECT(ClassName, name) \
    static ObjectRegistrar<ClassName> ClassName##_registrar(name);

#endif