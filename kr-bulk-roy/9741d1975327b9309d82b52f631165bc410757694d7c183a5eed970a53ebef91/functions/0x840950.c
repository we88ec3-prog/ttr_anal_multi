
undefined4 *
FUN_00840950(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  void **ppvVar2;
  uint uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0090e41f;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_8 = 1;
  ppvVar2 = &local_10;
  local_10 = ExceptionList;
  for (; ExceptionList = ppvVar2, in_ECX != param_2; in_ECX = in_ECX + 0x78) {
    FUN_00839870(in_ECX);
    ppvVar2 = ExceptionList;
  }
  *param_1 = param_3;
  param_1[1] = param_4;
  param_1[2] = param_5;
  local_8 = local_8 & 0xffffff00;
  if (DAT_00fbacc0 != DAT_00fbacc4) {
    if (param_5 != 0) {
      if (DAT_00fe34d8 == (undefined *)0x0) {
        if ((DAT_00fe3480 & 1) == 0) {
          DAT_00fe3480 = DAT_00fe3480 | 1;
          local_8 = 2;
          FUN_00862d10(uVar3);
          _atexit((_func_4879 *)&LAB_00bd0e20);
          local_8 = local_8 & 0xffffff00;
        }
        DAT_00fe34d8 = &DAT_00fe3488;
      }
      FUN_00863050(DAT_00fe34d8,param_4);
    }
    iVar1 = DAT_00fbacc0;
    if (DAT_00fbacc0 != DAT_00fbacc4) {
      FUN_00840d00(DAT_00fbacc4,param_2);
      DAT_00fbacc4 = iVar1;
    }
  }
  ExceptionList = local_10;
  return param_1;
}

