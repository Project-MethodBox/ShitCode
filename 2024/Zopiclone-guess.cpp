#include <print>
#include <iostream>
#include <random>

#include <Windows.h>
#include <tbs.h>
#pragma comment(lib, "tbs.lib")

int main()
{
	std::uint8_t RandomValue = 0;

	TBS_CONTEXT_PARAMS2 ContextParams
	{
		.version = TBS_CONTEXT_VERSION_TWO,
	};
	ContextParams.includeTpm20 = true;

	TBS_HCONTEXT Context;
	auto Return = Tbsi_Context_Create(reinterpret_cast<PCTBS_CONTEXT_PARAMS>(&ContextParams), &Context);
	if (Return == TBS_E_TPM_NOT_FOUND)
	{
		std::println("[DEBUG] TPM2.0 设备未找到,正在尝试使用TPM1.2生成随机数");
		ContextParams.version = TBS_CONTEXT_VERSION_ONE;
		ContextParams.includeTpm12 = true;
		Return = Tbsi_Context_Create(reinterpret_cast<PCTBS_CONTEXT_PARAMS>(&ContextParams), &Context);
		if (Return != TBS_SUCCESS)
			std::println("[DEBUG] TPM1.2 设备未找到,使用标准库作为随机数生成");
	}
	if (Return == TBS_SUCCESS)
	{
		std::vector<std::uint8_t> Command{ 0x80,0x01,0x00,0x00,0x00,12,0x00,0x00,0x01,0x7B,0x00,1 };

		std::uint32_t ReturnSize = 13;
		std::vector<std::uint8_t> ReturnCode;
		ReturnCode.resize(ReturnSize);

		while (true)
		{
			Return = Tbsip_Submit_Command(Context, TBS_COMMAND_LOCALITY_ZERO, TBS_COMMAND_PRIORITY_NORMAL, Command.data(), static_cast<UINT32>(Command.size()), ReturnCode.data(), &ReturnSize);
			if (Return == TBS_SUCCESS)
			{
				RandomValue = ReturnCode.back();
				if (RandomValue < 10)
					break;
			}
			else
			{
				break;
			}
		}
		Tbsip_Context_Close(Context);
	}
	else
	{
		std::random_device RandomDevice{};
		std::mt19937_64 Mt{ RandomDevice() };
		std::uniform_int_distribution<int> Distribute{ 0, 10 };
		RandomValue = Distribute(Mt);
	}

	std::uint8_t Count = 0;
	std::int32_t Value;
	std::println("请猜0-9以内的数");
	while (true)
	{
		if (Count >= 3)
		{
			std::println("Game Over,You Lose");
			break;
		}
		std::cin >> Value;
		Count += 1;
		if (Value < RandomValue)
		{
			std::println("猜小了");
		}
		else if (Value > RandomValue)
		{
			std::println("猜大了");
		}
		else
		{
			std::println("You Win!");
			break;
		}
	}

	return 114514 + 1919810;
}