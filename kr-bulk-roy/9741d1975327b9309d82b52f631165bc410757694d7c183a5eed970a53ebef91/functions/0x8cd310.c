
void FUN_008cd310(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1[1] == 0) {
    uVar1 = *param_1;
    if (param_1[3] == 1) {
      iVar2 = FUN_008ccf30(uVar1);
      if (iVar2 == 0) {
        iVar2 = FUN_008ccf30(uVar1);
        if (iVar2 == 0) {
          return;
        }
        param_1[1] = iVar2;
        return;
      }
    }
    else {
      iVar2 = 6;
    }
    param_1[1] = iVar2;
  }
  return;
}

