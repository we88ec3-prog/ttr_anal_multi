
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00671bd0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_20;
  undefined2 local_1c;
  undefined1 local_1a;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00941c7c;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (DAT_00f9392c == 7) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_20 = (void *)CONCAT13(local_20._3_1_,0x41);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_20,3);
      ExceptionList = local_20;
      return;
    }
  }
  else {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590(uVar1);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if (DAT_00f9392c == 0x15) {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_1c = 0x41;
      local_1a = 1;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1c,3);
        ExceptionList = local_20;
        return;
      }
    }
    else {
      iVar2 = FUN_00404ba0();
      if (*(int *)(iVar2 + 0x5f4c) == 0x17) {
        FUN_00414680();
        uVar3 = 2;
      }
      else {
        iVar2 = FUN_00404ba0();
        if (*(int *)(iVar2 + 0x5f4c) != 0x18) {
          ExceptionList = local_14;
          return;
        }
        FUN_00414680();
        uVar3 = 3;
      }
      FUN_004a3b40(uVar3);
    }
  }
  ExceptionList = local_14;
  return;
}

