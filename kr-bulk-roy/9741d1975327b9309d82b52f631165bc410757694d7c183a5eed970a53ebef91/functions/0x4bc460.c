
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004bc460(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  undefined4 uStack_20;
  undefined2 local_1c;
  undefined2 auStack_1a [3];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093605e;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  *(undefined4 *)(in_ECX + 0x5eb4) = 0;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(uVar3);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  iVar4 = *(int *)(DAT_00fab130 + 0x5edc) - *(int *)(DAT_00fab130 + 0x5ed8);
  iVar2 = iVar4 >> 0x1f;
  cVar1 = *(char *)(param_1 + 2);
  if (iVar4 / 5 + iVar2 == iVar2) {
    if (cVar1 == '\0') {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      uStack_20 = (void *)CONCAT22(0x9f,(undefined2)uStack_20);
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&uStack_20 + 2,2);
      }
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      auStack_1a[0] = 0x19;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,auStack_1a,2);
      }
    }
    else if (cVar1 == '\x02') {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_1c = 0x19;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1c,2);
        ExceptionList = uStack_20;
        return 0;
      }
    }
  }
  else {
    if (cVar1 == '\0') {
      FUN_004054c0();
      FUN_0058aad0(0xf426c);
      ExceptionList = local_14;
      return 0;
    }
    if (cVar1 == '\x02') {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      uStack_20 = (void *)CONCAT22(0x19,(undefined2)uStack_20);
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&uStack_20 + 2,2);
        ExceptionList = uStack_20;
        return 0;
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}

