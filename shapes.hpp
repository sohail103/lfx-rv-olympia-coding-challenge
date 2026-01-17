// shape declarations

#ifndef SHAPES_H
#define SHAPES_H

#include "object.hpp"

class Circle : public Object {
private:
  double radius;

public:
  std::string getName() const override;
  std::string getDescription() const override;
  bool parseAndCalculate(const std::vector<std::string> &args)
      override; // parses args and calculates area, circumference
};

class Square : public Object {
private:
  double length;

public:
  std::string getName() const override;
  std::string getDescription() const override;
  bool parseAndCalculate(const std::vector<std::string> &args)
      override; // parses args and calculates area, perimeter
};

class Rectangle : public Object {
private:
  double length1, length2;

public:
  std::string getName() const override;
  std::string getDescription() const override;
  bool parseAndCalculate(const std::vector<std::string> &args)
      override; // parses args and calculates area, perimeter
};

#endif