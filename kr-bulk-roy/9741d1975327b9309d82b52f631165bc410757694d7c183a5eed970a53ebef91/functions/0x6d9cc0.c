
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d9cc0(void)

{
  uint uVar1;
  int unaff_ESI;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915f38;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0xb4));
  local_8 = 0;
  if ((_DAT_00fc1698 & 1) == 0) {
    _DAT_00fc1698 = _DAT_00fc1698 | 1;
    FUN_0080c8a0(uVar1);
    _atexit((_func_4879 *)&LAB_00bce320);
  }
  piVar2 = &DAT_00fc16a0;
  do {
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0x2c))();
    }
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0xfc16e0);
  FUN_006dab40(unaff_ESI + 0x28);
  FUN_00402a70(&DAT_00bf2375,0);
  *(undefined4 *)(unaff_ESI + 0x34) = 0;
  *(undefined4 *)(unaff_ESI + 0x68) = 0;
  FUN_00402a70(&DAT_00bf2375,0);
  *(undefined4 *)(unaff_ESI + 0x6c) = 0;
  *(undefined4 *)(unaff_ESI + 0xa0) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0xb4));
  ExceptionList = local_10;
  return;
}

