
uint FUN_008ba190(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 - 1 & param_1;
  while (uVar1 = uVar2, uVar1 != 0) {
    param_1 = uVar1;
    uVar2 = uVar1 & uVar1 - 1;
  }
  return param_1;
}

