// [特殊挑战] 挑战D

#if !defined(_MSC_VER)
#error 只允许在 MSVC 上编译和运行
#endif

#if !defined(_DEBUG)
#error 必须以 DEBUG 模式编译
#endif

// 请尽量使编译器(cl.exe)的编译选项为"/JMC /permissive- /ifcOutput "Path" /GS /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"Path\vc145.pdb" /Zc:inline /fp:precise /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTC1 /std:clatest /Gd /MDd /std:c++latest /FC /Fa"Path" /EHsc /nologo /Fo"Path" /Fp"Path\ShitCode.pch" /diagnostics:column"\

#include <iostream>
#include <print>

constexpr auto _ = static_cast<void(*)(std::basic_format_string<char, std::uintptr_t>, std::uintptr_t&&)>(&std::println<std::uintptr_t>);

int main()
{
	(void)_;

	std::uintptr_t num;
	std::cin >> num;

	if (num > '\n')
		reinterpret_cast<void(*)(std::basic_format_string<char, std::uintptr_t>, std::uintptr_t&&)>(reinterpret_cast<std::uintptr_t>(main) - L'፛')("{}", (num * num) * (true + true));
	else
		reinterpret_cast<void(*)(std::basic_format_string<char, std::uintptr_t>, std::uintptr_t&&)>(reinterpret_cast<std::uintptr_t>(main) - L'፛')("{}", std::move(num));
}