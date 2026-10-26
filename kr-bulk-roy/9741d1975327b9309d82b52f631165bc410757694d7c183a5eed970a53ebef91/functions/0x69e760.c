
void FUN_0069e760(int param_1)

{
  uint uVar1;
  uint uVar2;
  int unaff_EBX;
  uint uVar3;
  undefined4 *puVar4;
  uint local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00935a7e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fe1bd8 & 1) == 0) {
    DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
    local_c = 0;
    FUN_00533f80(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bced30);
  }
  local_c = 0xffffffff;
  uVar1 = (DAT_00fe1c40 - DAT_00fe1c3c) / 0x1f;
  uVar3 = 0;
  local_24 = 0;
  puVar4 = (undefined4 *)(param_1 + 0xf0);
  do {
    (**(code **)(*(int *)*puVar4 + 0x90))(uVar3 < uVar1);
    uVar2 = uVar1;
    if (uVar3 < uVar1) {
      uVar2 = unaff_EBX + DAT_00fe1c3c;
    }
    FUN_0069e210(uVar2);
    (**(code **)(*(int *)*puVar4 + 200))();
    local_24 = local_24 + 0x1f;
    uVar3 = uVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (local_24 < 0x136);
  ExceptionList = local_14;
  return;
}

