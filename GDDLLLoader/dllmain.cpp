#include "modlist.hpp"
#include <Windows.h>
#include <string>
#include <filesystem>

HMODULE module;

DWORD WINAPI main_hook(LPVOID lpParam) {
	if (!MenuLayer::mem_init())
		return 1;

	if (!std::filesystem::is_directory("mods") || !std::filesystem::exists("mods")) 
		std::filesystem::create_directory("mods");

	for (std::filesystem::directory_entry file : std::filesystem::directory_iterator("mods\\")) {
		std::string p = file.path().string();
		if (methods::ewith(p, ".dll"))
			MenuLayer::load_mod(p);
	}

	while (true) {};

	MH_DisableHook(MH_ALL_HOOKS);
	FreeLibraryAndExitThread(module, 0);
	exit(0);

	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	module = hModule;

	switch (ul_reason_for_call) {
		case DLL_PROCESS_ATTACH:
			CreateThread(0, 0x1000, &main_hook, 0, 0, NULL);
		case DLL_PROCESS_DETACH:
			break;
	}
	return 1;
}
