
undefined4 FUN_0060c740(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int unaff_EDI;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090f73e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = *(undefined4 *)(unaff_EDI + 4);
  if ((DAT_00fb11a8 & 1) == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_8 = 0;
    FUN_00813890(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_8 = 0xffffffff;
  local_14 = param_1;
  FUN_0082ef00(&local_14);
  if (local_18 == DAT_00fb11b0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(local_18 + 0x10);
  }
  if ((byte)param_2 == 0) {
    piVar3 = *(int **)(unaff_EDI + 4);
    if (piVar3 == (int *)0x0) {
      ExceptionList = local_10;
      return uVar1;
    }
    param_2 = 1;
  }
  else {
    if (iVar2 != 0) {
      if ((*(int *)(iVar2 + 0x14) != *(int *)(iVar2 + 0x18)) &&
         ((byte)param_2 < (byte)((char)(*(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x14) >> 2) - 1U))
         ) {
        if (param_4 == 0) {
          if (*(int *)(unaff_EDI + 4) == 0) {
            ExceptionList = local_10;
            return uVar1;
          }
          FUN_00612b50(param_1);
          ExceptionList = local_10;
          return uVar1;
        }
        if (*(int *)(unaff_EDI + 8) == 0) {
          ExceptionList = local_10;
          return uVar1;
        }
        FUN_00612b50(param_1);
        ExceptionList = local_10;
        return *(undefined4 *)(unaff_EDI + 8);
      }
    }
    piVar3 = *(int **)(unaff_EDI + 4);
    if (piVar3 == (int *)0x0) {
      ExceptionList = local_10;
      return uVar1;
    }
  }
  (**(code **)(*piVar3 + 0x184))(param_1,param_2,param_3);
  (**(code **)(*piVar3 + 0x188))();
  ExceptionList = local_10;
  return uVar1;
}

