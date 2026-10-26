
uint FUN_00572370(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_00572350();
  iVar2 = thunk_FUN_005723e0();
  if (iVar2 - (uVar1 >> 1) < uVar1) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 + (uVar1 >> 1);
  }
  if (param_1 <= uVar1) {
    param_1 = uVar1;
  }
  return param_1;
}

