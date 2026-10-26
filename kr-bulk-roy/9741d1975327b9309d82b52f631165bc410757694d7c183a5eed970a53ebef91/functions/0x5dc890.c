
void FUN_005dc890(short param_1)

{
  int iVar1;
  uint uVar2;
  int *unaff_ESI;
  void *pvStack_24;
  uint local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  *(short *)(unaff_ESI + 0xa6) = param_1;
  if (param_1 != 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(uVar2);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    iVar1 = DAT_00f94308;
    local_c = 0xffffffff;
    local_20 = (uint)*(ushort *)(unaff_ESI + 0xa6);
    FUN_004dae30(&local_20);
    if (local_1c == *(int *)(iVar1 + 4)) {
      local_1c = iVar1 + 0x30;
    }
    else {
      local_1c = local_1c + 0x10;
    }
    if (local_1c != 0) {
      (**(code **)(*unaff_ESI + 0x19c))(*(undefined4 *)(local_1c + 0x3c),0);
      ExceptionList = pvStack_24;
      return;
    }
  }
  (**(code **)(*unaff_ESI + 0x19c))(0xffffffff,0xffffffff,0,0);
  ExceptionList = pvStack_24;
  return;
}

