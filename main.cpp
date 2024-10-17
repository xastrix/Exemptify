#include "inetfw.h"

int wmain(int argc, const wchar_t** argv)
{
	if (argc == 3 && wcscmp(argv[2], L"--net-on") == 0) {
		if (InetFW::removeRule(argv[1])) {
			wprintf(L"The internet for \"%ls\" is allowed\n", argv[1]);
		}
		return 0;
	}
	else if (argc == 4 && wcscmp(argv[3], L"--net-off") == 0) {
		if (InetFW::setRule(argv[1], argv[2])) {
			wprintf(L"The internet for \"%ls\" is blocked\n", argv[1]);
		}
		return 0;
	}

	printf("Exemptify\n");
	printf("  A utility that allows you to add application exceptions to the windows firewall, thereby blocking outgoing traffic\n\n");
	printf("Usage\n");
	printf("  Exemptify <RuleID> <PathToTheDubiousApplication> --net-off\n");
	printf("    - Adds an exception rule for the specified application, disabling network access.\n");
	printf("    - <RuleID> is a unique identifier for the rule you are creating.\n");
	printf("    - <PathToTheDubiousApplication> is the file path to the application you want to exempt.\n\n");
	printf("  Exemptify <RuleID> --net-on\n");
	printf("    - Enables network access for the specified exception rule.\n");
	printf("    - <RuleID> must correspond to an existing rule created previously.\n\n");
	printf("Examples\n");
	printf("  Exemptify test1 /path/to/app.exe --net-off\n");
	printf("  Exemptify test1 --net-on\n\n");
	printf("Note\n");
	printf("  If you like the project and find the utility useful, give the repository a star!\n");

	return 0;
}