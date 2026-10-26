
int FUN_008ccbd0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint *in_EAX;
  int iVar2;
  uint uVar3;
  
  uVar3 = *in_EAX + 1;
  if (in_EAX[1] < uVar3) {
    iVar2 = FUN_008ccb80(param_1);
    if (iVar2 != 0) {
      *param_2 = 0;
      return iVar2;
    }
  }
  puVar1 = (undefined4 *)((in_EAX[2] - 0x10) + uVar3 * 0x10);
  *puVar1 = 0;
  puVar1[3] = 0;
  *in_EAX = uVar3;
  *param_2 = puVar1;
  return 0;
}

