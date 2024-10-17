#pragma once

#include <iostream>

namespace InetFW
{
	bool setRule(const wchar_t* rule, const wchar_t* filename);
	bool removeRule(const wchar_t* rule);
}