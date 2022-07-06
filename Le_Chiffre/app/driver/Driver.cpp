//#include "../Include.h"
/*
Driver::Driver(const char* processName)
{
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	const auto snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	while (Process32Next(snapShot, &entry))
	{
		if (!strcmp(processName, entry.szExeFile))
		{
			this->id = entry.th32ProcessID;
			this->process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->id);
			break;
		}
	}

	if (snapShot)
		CloseHandle(snapShot);
}

Driver::~Driver()
{
	if (this->process)
		CloseHandle(this->process);
}

DWORD Driver::GetProcessId()
{
	return this->id;
}
HANDLE Driver::GetProcessHandle()
{
	return this->process;
}

uintptr_t Driver::GetModuleAddress(const char* moduleName)
{
	MODULEENTRY32 entry2;
	entry2.dwSize = sizeof(MODULEENTRY32);

	const auto snapShot2 = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, this->id);

	uintptr_t result = 0;

	while (Module32Next(snapShot2, &entry2))
	{
		if (!strcmp(moduleName, entry2.szModule))
		{
			result = reinterpret_cast<uintptr_t>(entry2.modBaseAddr);
			break;
		}
	}

	if (snapShot2)
		CloseHandle(snapShot2);

	return result;
}*/