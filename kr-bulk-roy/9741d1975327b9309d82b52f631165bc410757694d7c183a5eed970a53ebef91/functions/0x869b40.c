
undefined8 FUN_00869b40(void)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  LARGE_INTEGER local_30;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  int local_1c;
  LARGE_INTEGER local_18;
  LARGE_INTEGER local_10;
  
  QueryPerformanceCounter(&local_10);
  QueryPerformanceFrequency(&local_30);
  local_30.s.LowPart = local_30.s.LowPart >> 5 | local_30.s.HighPart << 0x1b;
  local_30.s.HighPart = local_30.s.HighPart >> 5;
  local_28 = 0;
  local_24 = 0;
  uVar1 = rdtsc();
  local_1c = (int)((ulonglong)uVar1 >> 0x20);
  local_20 = (uint)uVar1;
  do {
    do {
      QueryPerformanceCounter(&local_18);
      iVar2 = (local_18.s.HighPart - local_10._4_4_) -
              (uint)(local_18.s.LowPart < local_10.s.LowPart);
    } while (iVar2 < local_30.s.HighPart);
  } while ((iVar2 <= local_30.s.HighPart) &&
          (local_18.s.LowPart - local_10._0_4_ < local_30.s.LowPart));
  uVar1 = rdtsc();
  uVar3 = (uint)uVar1 - local_20;
  return CONCAT44((((int)((ulonglong)uVar1 >> 0x20) - local_1c) - (uint)((uint)uVar1 < local_20)) *
                  0x20 | uVar3 >> 0x1b,uVar3 * 0x20);
}

