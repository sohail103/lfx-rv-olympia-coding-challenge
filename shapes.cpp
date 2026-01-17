// shape implementations

#include "shapes.hpp"
#include <cmath>
#include <iostream>

// circle implementation
std::string Circle::getName() const { return "circle"; }

std::string Circle::getDescription() const {
  return "A circle has a radius. If the user provides the radius:\n"
         "\"./describe_object circle <radius>\""
         "\nThe program can calculate circumference, area.";
}

bool Circle::parseAndCalculate(const std::vector<std::string> &args) {
  if (args.size() == 0) {
    std::cout << getDescription() << std::endl;
  } else if (args.size() != 1) {
    std::cerr << "Usage: ./describe_object circle <radius>" << std::endl;
    return false;
  } else {
    try {
      radius = std::stod(args[0]);
      if (radius <= 0) {
        std::cerr << "Error: Radius must be positive\n";
        return false;
      }
    } catch (...) {
      std::cerr << "Error: Invalid radius value\n";
      return false;
    }

    const double pi = std::acos(-1); // calculating value of pi from inverse cos
    double circumference = 2 * pi * radius;
    double area = pi * radius * radius;

    std::cout << "Circle with radius " << radius << ":\n";
    std::cout << " - Circumference: " << circumference << "\n";
    std::cout << " - Area: " << area << "\n";
  }

  return true;
}

// square implementation
std::string Square::getName() const { return "square"; }

std::string Square::getDescription() const {
  return std::string("A square has four sides that are of equal length.\n"
                     "If the user provides the length:\n"
                     "\"./describe_object square <length>\""
                     "\nThe program can calculate: perimeter, area.");
}

bool Square::parseAndCalculate(const std::vector<std::string> &args) {
  if (args.size() == 0) {
    std::cout << getDescription() << std::endl;
  } else if (args.size() != 1) {
    std::cerr << "Usage: ./describe_object square <length>";
    return false;
  } else {
    try {
      length = std::stod(args[0]);
      if (length <= 0) {
        std::cerr << "Error: Length must be positive\n";
        return false;
      }
    } catch (...) {
      std::cerr << "Error: Invalid length value\n";
      return false;
    }

    double perimeter = 4 * length;
    double area = length * length;

    std::cout << "Square with length " << length << ":\n";
    std::cout << " - Perimeter: " << perimeter << "\n";
    std::cout << " - Area: " << area << "\n";
  }

  return true;
}

// rectangle implementation
std::string Rectangle::getName() const { return "rect"; }

std::string Rectangle::getDescription() const {
  return "A rectangle has 4 sides broken into 2 side pairs"
         " of equal length and are parallel.\n"
         "If the user provides the length of each pair: \n"
         "\"./describe_object rect <length side 1> <length side 2>\"\n"
         "The program can calculate: perimeter, area.";
}

bool Rectangle::parseAndCalculate(const std::vector<std::string> &args) {
  if (args.size() == 0) {
    std::cout << getDescription() << std::endl;
  } else if (args.size() != 2) {
    std::cerr
        << "Usage: ./describe_object rect <length side 1> <length side 2>";
    return false;
  } else {
    try {
      length1 = std::stod(args[0]);
      length2 = std::stod(args[1]);
      if (length1 <= 0 || length2 <= 0) {
        std::cerr << "Error: Lengths must be positive\n";
        return false;
      }
    } catch (...) {
      std::cerr << "Error: Invalid length values\n";
      return false;
    }

    double perimeter = 2 * (length1 + length2);
    double area = length1 * length2;

    std::cout << "Rectangle with lengths " << length1 << " and " << length2
              << ":\n";
    std::cout << " - Perimeter: " << perimeter << "\n";
    std::cout << " - Area: " << area << "\n";
  }

  return true;
}

// object registrations
REGISTER_OBJECT(Circle, "circle")
REGISTER_OBJECT(Square, "square")
REGISTER_OBJECT(Rectangle, "rect")