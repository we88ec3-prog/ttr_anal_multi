
int FUN_008d5e70(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (*param_2 + 1 <= uVar1) {
    *param_2 = uVar1;
    return 1;
  }
  uVar2 = (*param_2 + 1) - uVar1;
  if (uVar2 < *(uint *)(param_1 + 0x14)) {
    *param_2 = uVar1 + uVar2;
    return uVar2 + 1;
  }
  *param_2 = 0;
  return 0;
}

