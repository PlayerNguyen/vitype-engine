#include "IMEHandler.h"

IMEHandler::IMEHandler() {
    converter = createConverter();
}

IMEHandler::~IMEHandler() {
    destroyConverter(converter);
}

void IMEHandler::processKeyPress(WPARAM wParam, LPARAM lParam) {
    wchar_t ch = static_cast<wchar_t>(wParam);
    char mbStr[2] = { static_cast<char>(ch), '\0' };  // Chuyển ký tự sang UTF-8

    const char* result = convertText(converter, mbStr);
    buffer = std::wstring(result, result + strlen(result));  // Convert sang wide string
}

std::wstring IMEHandler::getConvertedText() {
    return buffer;
}
