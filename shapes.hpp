// shape declarations

#ifndef SHAPES_H
#define SHAPES_H

#include "object.hpp"

class Circle : public GeometricObject {
    private:
        double radius;
    public:
        std::string getName() const override;
        std::string getDescription() const override;
        std::string getUsage() const override;
        bool parseAndCalculate(const std::vector<std::string>& args) override;
};

class Square : public GeometricObject {
    private:
        double length;
    public:
        std::string getName() const override;
        std::string getDescription() const override;
        std::string getUsage() const override;
        bool parseAndCalculate(const std::vector<std::string>& args) override;
};

class Rectangle : public GeometricObject {
    private:
        double length1, length2;
    public:
    std::string getName() const override;
    std::string getDescription() const override;
    std::string getUsage() const override;
    bool parseAndCalculate(const std::vector<std::string>& args) override;
};

#endif