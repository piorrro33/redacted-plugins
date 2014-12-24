#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <timeapi.h>

#pragma comment(lib, "Winmm.lib")

#include "Utility\Patterns.h"
#include "Utility\Hooking.h"
#include "Utility\VariadicString.h"

#include "Struct\T6.h"

#include "Functions\Functions.h"

#include "Global\Global.h"
#include "Export\Export.h"
