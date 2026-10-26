
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006cb640(int param_1)

{
  int iVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = DAT_00fe1b58;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093276e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_006caaf0(*(undefined4 *)(param_1 + 0x118));
  if (*(char *)(iVar1 + 0xc) == '\x01') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_0058aad0(0xf439f);
  }
  else {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    param_1 = CONCAT22(0x19,(undefined2)param_1);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&param_1 + 2,2,uVar2);
    }
  }
  if ((_DAT_00fb734c & 1) == 0) {
    _DAT_00fb734c = _DAT_00fb734c | 1;
    DAT_00fb7350 = 1;
    _atexit((_func_4879 *)&DAT_00bcd0b0);
  }
  DAT_00fb7350 = 0;
  ExceptionList = local_10;
  return;
}

