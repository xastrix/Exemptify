#include "utils.h"

#include <sys/stat.h>

bool utils::IsAdminRights()
{
	bool   elevated = false;
	HANDLE h        = 0;

	if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &h))
	{
		DWORD size = 0;
		GetTokenInformation(h, TokenElevation, NULL, 0, &size);

		TOKEN_ELEVATION* elevation = (TOKEN_ELEVATION*)malloc(size);
		if (GetTokenInformation(h, TokenElevation, elevation, size, &size))
		{
			elevated = elevation->TokenIsElevated;
		}
		free(elevation);
	}

	CloseHandle(h);

	return elevated;
}

bool utils::IsObjectExists(const wchar_t* Path)
{
	bool res = false;

	struct _stat64i32 s;
	if (_wstat(Path, &s) == 0) {
		res = s.st_mode & S_IFREG ? true : false;
	}

	return res;
}