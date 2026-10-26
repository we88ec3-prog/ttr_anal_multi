
void FUN_008d0930(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined **ppuVar2;
  undefined4 *puVar3;
  
  param_1[1] = param_2;
  *param_1 = param_2;
  param_1[4] = param_4;
  param_1[3] = 0;
  param_1[2] = param_3;
  ppuVar2 = &PTR_FUN_00be7b68;
  puVar3 = param_1 + 5;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *ppuVar2;
    ppuVar2 = ppuVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}

