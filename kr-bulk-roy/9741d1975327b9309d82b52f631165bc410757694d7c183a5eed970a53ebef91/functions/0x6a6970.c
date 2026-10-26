
void FUN_006a6970(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar2 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar2 + 0xdc);
    if (iVar2 == 0) {
      iVar2 = -1;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x20);
    }
    if (iVar2 != -1) {
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 0;
        FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
        _atexit((_func_4879 *)&LAB_00bccc80);
      }
      local_c = 0xffffffff;
      if (iVar2 != DAT_00f93930) {
        puVar1 = (undefined4 *)FUN_00891268(0x18);
        if (puVar1 != (undefined4 *)0x0) {
          puVar1[1] = 0xffffffff;
          puVar1[2] = 0xffffffff;
          puVar1[3] = 0;
          puVar1[4] = 0xf42ff;
          *puVar1 = FoxUI::FXUIEventI1::vftable;
          puVar1[5] = iVar2;
        }
        FUN_004072a0();
      }
    }
  }
  ExceptionList = local_14;
  return;
}

