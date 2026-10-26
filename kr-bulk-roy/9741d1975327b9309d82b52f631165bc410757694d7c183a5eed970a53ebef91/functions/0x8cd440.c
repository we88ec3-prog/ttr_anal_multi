
void FUN_008cd440(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1[1] == 0) {
    uVar1 = *param_1;
    iVar2 = FUN_008cd100(uVar1);
    if (iVar2 == 0) {
      FUN_008cd100(uVar1);
    }
  }
  return;
}

