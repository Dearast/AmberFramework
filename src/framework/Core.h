#pragma once

#include "Profiling.h"

#if defined(__linux__)
#if defined(_SHARED_LIBRARY_)
#define AMBER_API __attribute__((visibility("default")))
#else
#define AMBER_API
#endif
#endif
