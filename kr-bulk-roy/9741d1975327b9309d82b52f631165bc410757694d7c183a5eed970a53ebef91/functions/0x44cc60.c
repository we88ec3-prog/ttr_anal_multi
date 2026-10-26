
void FUN_0044cc60(undefined4 param_1)

{
  uint uVar1;
  SIZE_T SVar2;
  uint uVar3;
  _SYSTEM_INFO local_48;
  _MEMORY_BASIC_INFORMATION local_24;
  PVOID local_8;
  
  FUN_0044c9e0("\r\n\tModule list: names, addresses, sizes, time stamps and file times:\r\n");
  GetSystemInfo(&local_48);
  local_8 = (PVOID)0x0;
  uVar1 = (int)(0x40000000 / (ulonglong)local_48.dwPageSize) * 4;
  if (uVar1 != 0) {
    uVar3 = 0;
    do {
      SVar2 = VirtualQuery((LPCVOID)(uVar3 * local_48.dwPageSize),&local_24,0x1c);
      if ((SVar2 == 0) || (local_24.RegionSize == 0)) {
        uVar3 = uVar3 + (int)(0x10000 / (ulonglong)local_48.dwPageSize);
      }
      else {
        uVar3 = uVar3 + local_24.RegionSize / local_48.dwPageSize;
        if ((local_24.State == 0x1000) && (local_8 < local_24.AllocationBase)) {
          local_8 = local_24.AllocationBase;
          FUN_0044cac0(param_1,local_24.AllocationBase);
        }
      }
    } while (uVar3 < uVar1);
  }
  return;
}

