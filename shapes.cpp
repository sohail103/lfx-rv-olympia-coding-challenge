// shape implementations

#include "shapes.hpp"
#include <cmath>
#include <iostream>

// circle implementation
std::string Circle::getName() const { return "circle"; }

std::string Circle::getDescription() const { return "A circle has a radius."; }

std::string Circle::getUsage() const {
  return "describe_object circle <radius>";
}

bool Circle::parseAndCalculate(const std::vector<std::string> &args) {
  if (args.size() == 0) {
    std::cout << "A circle has a radius. If the user provides the radius:\n"
              << "\"describe_object circle <radius>\"\n"
              << "The program can calculate: circumference, area.";
  } else if (args.size() != 1) {
    std::cerr << "Error: Circle requires exactly 1 argument (radius)\n";
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

    double circumference = 2 * M_PI * radius;
    double area = M_PI * radius * radius;

    std::cout << "Circle with radius " << radius << ":\n";
    std::cout << " Circumference: " << circumference << "\n";
    std::cout << " Area: " << area << "\n";
  }

  return true;
}

// square implementation
std::string Square::getName() const { return "square"; }

std::string Square::getDescription() const {
  return "A square has four sides that are of equal length.";
}

std::string Square::getUsage() const {
  return "describe_object square <length>";
}

bool Square::parseAndCalculate(const std::vector<std::string> &args) {
  if (args.size() == 0) {
    std::cout << "A square has four sides that are of equal length. If the "
                 "user provides the length:\n"
              << "\"describe_object square <length>\"\n"
              << "The program can calculate: perimeter, area.";
  } else if (args.size() != 1) {
    std::cerr << "Error: Square requires exactly 1 argument (length)\n";
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
    std::cout << " Perimeter: " << perimeter << "\n";
    std::cout << " Area: " << area << "\n";
  }

  return true;
}

// rectangle implementation
std::string Rectangle::getName() const { return "rect"; }

std::string Rectangle::getDescription() const {
  return "A rectangle has 4 sides broken into 2 side pairs of equal length and "
         "are parallel.";
}

std::string Rectangle::getUsage() const {
  return "describe_object rect <length side 1> <length side 2>";
}

bool Rectangle::parseAndCalculate(const std::vector<std::string> &args) {
  if (args.size() == 0) {
    std::cout << "A rectangle has 4 sides broken into 2 side pairs of equal "
                 "length and are parallel.\n"
              << "If the user provides the length of each pair:\n"
              << "\"describe_object rect <length side 1> <length side 2>\"\n"
              << "The program can calculate: perimeter, area.";
  } else if (args.size() != 2) {
    std::cerr
        << "Error: Rectangle requires exactly 2 arguments (length1, length2)\n";
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
    std::cout << " Perimeter: " << perimeter << "\n";
    std::cout << " Area: " << area << "\n";
  }

  return true;
}

REGISTER_OBJECT(Circle, "circle")
REGISTER_OBJECT(Square, "square")
REGISTER_OBJECT(Rectangle, "rect")