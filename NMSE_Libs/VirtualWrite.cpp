#include "VirtualWrite.h"

void VirtualSet(uintptr_t addr, int val, size_t length){
	unsigned long oldProtect;
	VirtualProtect((void*)addr, length, PAGE_EXECUTE_READWRITE, &oldProtect);
	memset((void*)addr, val, length);
	VirtualProtect((void*)addr, length, oldProtect, &oldProtect);
}

void VirtualWrite(uintptr_t addr, void* data, size_t buffer) {
	unsigned long oldProtect;
	VirtualProtect((void*)addr, buffer, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy((void*)addr, data, buffer);
	VirtualProtect((void*)addr, buffer, oldProtect, &oldProtect);
}

void VirtualWrite8(uintptr_t addr, uint8_t data) {
	VirtualWrite(addr, &data, sizeof(data));
}

void VirtualWrite16(uintptr_t addr, uint16_t data) {
	VirtualWrite(addr, &data, sizeof(data));
}

void VirtualWrite32(uintptr_t addr, uint32_t data) {
	VirtualWrite(addr, &data, sizeof(data));
}

void VirtualWrite64(uintptr_t addr, uint64_t data) {
	VirtualWrite(addr, &data, sizeof(data));
}