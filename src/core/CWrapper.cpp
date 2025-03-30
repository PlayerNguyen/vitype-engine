#include "CWrapper.h"
#include "Converter.h"

extern "C" {

ConverterHandle createConverter() { return new Converter(); }

void destroyConverter(ConverterHandle handle) {
  delete static_cast<Converter *>(handle);
}

const char *convertText(ConverterHandle handle, const char *text) {
  static std::string output; // Để giữ kết quả
  output = static_cast<Converter *>(handle)->convert(text);
  return output.c_str();
}
}
