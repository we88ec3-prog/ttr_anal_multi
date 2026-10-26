
int FUN_00727220(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  
  iVar1 = FUN_00729760(0xffffffff,0xf,0);
  if (iVar1 == 0) {
    iVar2 = FUN_00729a20(4);
    if (iVar2 == 1) {
      *param_2 = local_28;
      iVar1 = FUN_0072a1e0();
    }
    else {
      FUN_0072a1e0();
      iVar1 = -5;
      if (iVar2 != 0) {
        return iVar2;
      }
    }
  }
  return iVar1;
}

