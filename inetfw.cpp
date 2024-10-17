#include "inetfw.h"
#include "utils.h"

#include <comdef.h>
#include <netfw.h>

bool InetFW::setRule(const wchar_t* rule, const wchar_t* filename)
{
	bool res = false;

	if (!utils::IsAdminRights()) {
		printf("You need administrator rights for setRule\n");
		return res;
	}

	if (!utils::IsObjectExists(filename)) {
		wprintf(L"Application \"%ls\" Not found\n", filename);
		return res;
	}

	CoInitialize(NULL);

	INetFwPolicy2* pNetFwPolicy2 = NULL;
	HRESULT hr = CoCreateInstance(__uuidof(NetFwPolicy2),
		0,
		CLSCTX_INPROC_SERVER,
		__uuidof(INetFwPolicy2),
		(void**)&pNetFwPolicy2);

	if (FAILED(hr)) {
		return res;
	}

	INetFwRule* pNetFwRule = NULL;
	hr = CoCreateInstance(__uuidof(NetFwRule),
		0,
		CLSCTX_INPROC_SERVER,
		__uuidof(INetFwRule),
		(void**)&pNetFwRule);

	if (SUCCEEDED(hr)) {
		pNetFwRule->put_Name(_bstr_t(rule));
		pNetFwRule->put_Action(NET_FW_ACTION_BLOCK);
		pNetFwRule->put_Enabled(VARIANT_TRUE);
		pNetFwRule->put_Direction(NET_FW_RULE_DIR_OUT);
		pNetFwRule->put_ApplicationName(_bstr_t(filename));

		INetFwRules* pFwRules = NULL;
		hr = pNetFwPolicy2->get_Rules(&pFwRules);
		res = SUCCEEDED(hr);

		if (res) {
			pFwRules->Add(pNetFwRule);
			pFwRules->Release();
		}

		pNetFwRule->Release();
	}

	pNetFwPolicy2->Release();
	CoUninitialize();

	return res;
}

bool InetFW::removeRule(const wchar_t* rule)
{
	bool res = false;

	if (!utils::IsAdminRights()) {
		printf("You need administrator rights for removeRule\n");
		return res;
	}

	CoInitialize(NULL);

	INetFwPolicy2* pNetFwPolicy2 = NULL;
	HRESULT hr = CoCreateInstance(__uuidof(NetFwPolicy2),
		0,
		CLSCTX_INPROC_SERVER,
		__uuidof(INetFwPolicy2),
		(void**)&pNetFwPolicy2);

	if (FAILED(hr)) {
		return res;
	}

	INetFwRules* pFwRules = NULL;
	hr = pNetFwPolicy2->get_Rules(&pFwRules);
	res = SUCCEEDED(hr);

	if (res) {
		hr = pFwRules->Remove(_bstr_t(rule));
		pFwRules->Release();
	}

	pNetFwPolicy2->Release();
	CoUninitialize();

	return res;
}