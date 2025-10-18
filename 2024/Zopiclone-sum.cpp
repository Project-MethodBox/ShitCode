#include <iostream>
#include <print>

#include <ranges>

int main()
{
	std::int64_t Input = 0x114514;
	std::cin >> Input;

	std::uint64_t Value = 0;

	for (auto i : std::ranges::views::iota(1, Input + 1))
		Value += i;

	std::println("{}", Value);
	return 114514 + 1919810;
}