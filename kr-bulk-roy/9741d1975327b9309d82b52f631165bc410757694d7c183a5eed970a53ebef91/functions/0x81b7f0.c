
void FUN_0081b7f0(uint *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar1;
  int *unaff_ESI;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x11);
  EnterCriticalSection(lpCriticalSection);
  uVar1 = (**(code **)(*unaff_ESI + 4))();
  if (((uint)unaff_ESI & ~-(uint)((uVar1 & 0x11000000) != 0x11000000)) != 0) {
    FUN_007bb350();
    *param_1 = *param_1 | 1;
    LeaveCriticalSection(lpCriticalSection);
    return;
  }
  uVar1 = (**(code **)(*unaff_ESI + 4))();
  if (((uint)unaff_ESI & ~-(uint)((uVar1 & 0x12000000) != 0x12000000)) == 0) {
    uVar1 = (**(code **)(*unaff_ESI + 4))();
    if (((uint)unaff_ESI & ~-(uint)((uVar1 & 0x14000000) != 0x14000000)) != 0) {
      *param_1 = *param_1 | 8;
      FUN_007bb350();
    }
  }
  else {
    uVar1 = (**(code **)(*unaff_ESI + 4))();
    if (((uint)unaff_ESI & ~-(uint)((uVar1 & 0x12100000) != 0x12100000)) != 0) {
      *param_1 = *param_1 | 2;
      FUN_007bb350();
      LeaveCriticalSection(lpCriticalSection);
      return;
    }
    uVar1 = (**(code **)(*unaff_ESI + 4))();
    if (((uint)unaff_ESI & ~-(uint)((uVar1 & 0x12200000) != 0x12200000)) != 0) {
      *param_1 = *param_1 | 4;
      FUN_007bb350();
      LeaveCriticalSection(lpCriticalSection);
      return;
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return;
}

