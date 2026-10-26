
void FUN_006a4360(void)

{
  int iVar1;
  uint uVar2;
  int unaff_EDI;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00928b7a;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = *(int *)(*(int *)(unaff_EDI + 0xd0) + 0xcc);
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 0xdc);
    if (iVar1 == 0) {
      local_14 = -1;
    }
    else {
      local_14 = *(int *)(iVar1 + 0x20);
    }
    if (local_14 != -1) {
      local_14 = local_14 + 1;
      if ((DAT_00fe1e44 & 1) == 0) {
        DAT_00fe1e44 = DAT_00fe1e44 | 1;
        local_8 = 0;
        FUN_00531b40(uVar2);
        _atexit(thunk_FUN_00531c60);
      }
      local_8 = 0xffffffff;
      FUN_006a4510(&local_14);
      if ((DAT_00fe1e44 & 1) == 0) {
        DAT_00fe1e44 = DAT_00fe1e44 | 1;
        local_8 = 1;
        FUN_00531b40(uVar2);
        _atexit(thunk_FUN_00531c60);
        local_8 = 0xffffffff;
      }
      iVar1 = local_18;
      if (local_18 != *(int *)(&DAT_00fe1eac + *(int *)(unaff_EDI + 0xcc) * 0x10)) {
        if ((DAT_00f94394 & 1) == 0) {
          DAT_00f94394 = DAT_00f94394 | 1;
          local_8 = 2;
          FUN_005c3de0();
          _atexit((_func_4879 *)&LAB_00bccc30);
          local_8 = 0xffffffff;
        }
        if (*(uint *)(unaff_EDI + 0xcc) < 4) {
          local_18 = *(int *)(iVar1 + 0xc);
          FUN_0082ef00(&local_18);
        }
        FUN_00745060();
        (**(code **)(**(int **)(unaff_EDI + 0xd4) + 200))();
      }
    }
  }
  ExceptionList = local_10;
  return;
}

