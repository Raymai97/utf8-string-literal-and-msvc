#include <stdio.h>
#include <Windows.h>

extern char const * szUtf8;

int main() {
	HWND hwnd = GetForegroundWindow();
	int cchWide = MultiByteToWideChar(CP_UTF8, 0, szUtf8, -1, NULL, 0);
	LPWSTR szWide = new wchar_t[cchWide];
	int cchOk = MultiByteToWideChar(CP_UTF8, 0, szUtf8, -1, szWide, cchWide);
	if (cchWide != cchOk) {
		printf("cch mismatch error\n");
		printf("GetLastError() returns %i \n", GetLastError());
	}
	else {
		MessageBoxW(hwnd, szWide, L"utf8literal test", MB_ICONASTERISK);
	}
	return 0;
}
