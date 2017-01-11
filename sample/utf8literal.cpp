#include <stdio.h>
#include <Windows.h>

LPCSTR const szUtf8 =
	"ひび割れた夜に 幾星霜の空 \n"
	"映る僕たちは まぼろし \n"
	"もうし叶うのなら 昨日とは違う \n"
	"本当の僕を この地に \n"
	"僕ら生きてきたこと 彼方へ消えてく \n"
	"錆びついたレール 君はただ 立ちつくす \n"
	"今この腕に流れる 青い火があるなら \n"
	"振り返る 君の手を引いて \n"
	"もう二度と離さないと 灰の星へ誓うよ \n"
	"書き換える この歌を";

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
