#if 1
#include <iostream>
#include <string>
#include <codecvt>
#include <locale>
using namespace std;
int main() {
    // Unicode code points as string (e.g., "uc774uc218ube48")
    string unicodeCodePoints;

    // Get input Unicode code points
    cout << "Enter Unicode code points: ";
    cin >> unicodeCodePoints;

    // Convert Unicode code points to UTF-8
    wstring_convert<codecvt_utf8<char32_t>, char32_t> converter;
    u32string utf32String;

    try {
        // Convert hex Unicode code points to actual code points
        for (size_t i = 0; i < unicodeCodePoints.length(); i += 6) {
            string hexCodePoint = unicodeCodePoints.substr(i, 6);
            char32_t codePoint = stoi(hexCodePoint, nullptr, 16);
            utf32String += codePoint;
        }

        // Convert UTF-32 to UTF-8
        string utf8String = converter.to_bytes(utf32String);

        // Display the UTF-8 string
        cout << "UTF-8 String: " << utf8String << endl;
    }
    catch (const exception& e) {
        cerr << "Error: Invalid Unicode code points." << endl;
    }

    return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <codecvt>
using namespace std;

int main() {
    // Unicode string
    wstring unicodeString;

    // Get input Unicode string
    wcout << "Enter Unicode string: ";
    getline(wcin, unicodeString);

    // Convert Unicode to UTF-8
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    string utf8String = converter.to_bytes(unicodeString);

    // Display the UTF-8 string
    cout << "UTF-8 String: " << utf8String << endl;

    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

using namespace std;

int main() {
    // Set the locale to UTF-8

    wstring unicodeString;
    locale::global(locale("ko_KR.UTF-8"));

    // Unicode string
    
    wcout << "Enter Unicode string: ";
    getline(wcin, unicodeString);
    // Convert Unicode to UTF-8
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    string utf8String = converter.to_bytes(unicodeString);

    // Display the UTF-8 string
    cout << "UTF-8 String: " << utf8String << std::endl;

    return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
#include <codecvt>

int main() {
    // Unicode string
    std::wstring unicodeString = L"이수빈";

    // Convert Unicode to UTF-8
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::string utf8String = converter.to_bytes(unicodeString);

    // Display the UTF-8 string
    std::cout << "UTF-8 String: " << utf8String << std::endl;

    return 0;
}
#endif
#if 0
#include <iostream>
#include <atlstr.h> // 요기에 정의..  이거하면 MFC사용안하고도 CString를 사용할수 있다
#include <cstring>
#include <string>

using namespace std;

void main()
{
	
	wchar_t strUni[256] = L"이수빈";
	char strUtf8[256] = { 0, };
	int nLen = WideCharToMultiByte(CP_UTF8, 0, strUni, lstrlenW(strUni), NULL, 0, NULL, NULL);
	cout << WideCharToMultiByte(CP_UTF8, 0, strUni, lstrlenW(strUni), strUtf8, nLen, NULL, NULL);
}
#endif