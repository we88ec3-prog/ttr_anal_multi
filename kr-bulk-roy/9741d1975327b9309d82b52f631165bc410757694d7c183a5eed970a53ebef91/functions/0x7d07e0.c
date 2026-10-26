
void FUN_007d07e0(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int local_24;
  int local_20;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0092bb64;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 0;
  uStack_7 = 0;
  FUN_007c7b30(param_2,&local_24,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar1 = local_20;
  if (param_3 == 1) {
    uVar3 = 0;
    uVar4 = local_20 - local_24 >> 2;
    if (uVar4 != 0) {
      do {
        iVar1 = *(int *)(*(int *)(local_24 + uVar3 * 4) + 0x78);
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x3c) = 1;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar4);
    }
  }
  else {
    iVar2 = local_24;
    if (param_3 == 2) {
      for (; iVar2 != iVar1; iVar2 = iVar2 + 4) {
        FUN_0079c520(1);
      }
    }
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb7704);
  (**(code **)(*param_2 + 0x58))(param_1);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 2;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb7704);
  if (local_24 != 0) {
    FUN_0089120c(local_24);
  }
  ExceptionList = local_10;
  return;
}

