#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>

class Converter {
public:
  Converter();
  ~Converter();
  std::string convert(const std::string &input);
};

#endif
