
undefined4 FUN_004b2310(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093c77e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_2 < 2) {
    uVar4 = 0;
  }
  else {
    uVar4 = param_2 - 2 >> 2;
  }
  if (uVar4 != 0) {
    puVar3 = (undefined2 *)(param_1 + 2);
    do {
      iVar2 = FUN_0040f060(uVar1);
      FUN_0053db30(*(undefined4 *)(iVar2 + 4),*puVar3);
      puVar3 = puVar3 + 2;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4266);
  ExceptionList = local_10;
  return 0;
}

