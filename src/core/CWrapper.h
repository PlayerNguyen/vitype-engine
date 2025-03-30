#ifndef CWRAPPER_H
#define CWRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void *ConverterHandle;

ConverterHandle createConverter();
void destroyConverter(ConverterHandle handle);
const char *convertText(ConverterHandle handle, const char *text);

#ifdef __cplusplus
}
#endif

#endif
