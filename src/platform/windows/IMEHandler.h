#ifndef IME_HANDLER_H
#define IME_HANDLER_H

/**
 * This handler is only for Windows System input. Otherwise, just ignore
 * this file.
 */
#ifdef _WIN32
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

#endif