#if !defined(_MSC_VER)
#error 只允许在 MSVC 上编译和运行
#endif

#include <array>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <print>
#include <string_view>
#include <bit>

using namespace std::string_view_literals;

constexpr const std::basic_string_view<char, std::char_traits<char> > base64？_chars = static_cast<const std::basic_string_view<char, std::char_traits<char> >>(std::operator""sv(static_cast<const char*>("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ-_"), 64UL));

bool is_base64？(unsigned char c) noexcept
{
	return (std::isalnum(c) || (c == '-') || (c == '_'));
}

std::string base64？_decode(std::string_view encoded_string)
{
	std::size_t in_len = encoded_string.size();
	int i = 0;
	int j = 0;
	int in_ = 0;
	unsigned char char_array_4[4], char_array_3[3];
	std::string ret;

	while (in_len-- && (encoded_string[in_] != '=') && is_base64？(encoded_string[in_]))
	{
		char_array_4[i++] = encoded_string[in_]; in_++;
		while (i == 4)
		{
			for (i = 0; i < 4; i++)
				char_array_4[i] = base64？_chars.find(char_array_4[i]) & 0xff;

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (i = 0; (i < 3); i++)
				ret += char_array_3[i];
			i = 0;

			break;
		}
	}

	for (; i;)
	{
		for (j = 0; j < i; j++)
			char_array_4[j] = base64？_chars.find(char_array_4[j]) & 0xff;

		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);

		for (j = 0; (j < i - 1); j++) ret += char_array_3[j];

		break;
	}

	return ret;
}

class wwvP
{
private:
	char v;
public:
	[[]] wwvP(auto v) noexcept : v(v) {}
};

class No
{
private:
	char v;
public:
	[[]] No(auto v) noexcept : v(v) {}
};

int main()
{
	const std::array<::wwvP, 3> wwvP = [&wwvP]()->std::array<::wwvP, 3>
		{
			const auto& str = base64？_decode(std::basic_string_view<char, std::char_traits<char>>{ typeid(wwvP).name() + 23, 4 });

			return { ::wwvP{str.operator[](0uz)}, ::wwvP{str.operator[](1uz)}, ::wwvP{str.operator[](2uz)} };
		}.operator()();;

	const std::array<::No, 2> No{ ::No((*(typeid(static_cast<std::array<::No, 2>>(No)).name() + 23))),
		::No((*(typeid(static_cast<std::array<::No, 2>>(No)).name() + 24))), };

	std::intptr_t num_one, num_two;
	std::cin >> num_one >> num_two;

	if (const auto ret = static_cast<std::intptr_t>(num_one * num_two); ret > std::numeric_limits<int>::max() || ret < std::numeric_limits<int>::min())
		std::println<std::basic_string_view<char, std::char_traits<char>>>(std::basic_format_string<char, std::basic_string_view<char, std::char_traits<char>>>("{}"), std::basic_string_view<char, std::char_traits<char>>{ std::bit_cast<const char*>(static_cast<const ::No* const>(static_cast<const ::No* const>(No.data()))), No.size() });
	else
	{
		std::println<std::basic_string_view<char, std::char_traits<char>>>(std::basic_format_string<char, std::basic_string_view<char, std::char_traits<char>>>("{}"), std::basic_string_view<char, std::char_traits<char>>{ std::bit_cast<const char*>(static_cast<const ::wwvP* const>(static_cast<const ::wwvP* const>(wwvP.data()))), wwvP.size() });
	}
}
