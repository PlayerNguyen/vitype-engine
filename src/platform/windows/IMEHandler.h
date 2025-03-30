#ifndef IME_HANDLER_H
#define IME_HANDLER_H

#include "CWrapper.h"
#include <windows.h>

class IMEHandler {
public:
  IMEHandler();
  ~IMEHandler();
  void processKeyPress(WPARAM wParam, LPARAM lParam);
  std::wstring getConvertedText();

private:
  ConverterHandle converter;
  std::wstring buffer;
};

#endif
