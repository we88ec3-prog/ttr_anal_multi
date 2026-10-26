
undefined4 FUN_007b8680(undefined4 param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int unaff_ESI;
  
  uVar2 = *(uint *)(unaff_ESI + 0x20);
  uVar3 = FUN_005525e0();
  uVar3 = uVar3 & uVar2;
  if (*(uint *)(unaff_ESI + 0x24) <= uVar3) {
    uVar3 = uVar3 + (-1 - (uVar2 >> 1));
  }
  piVar1 = (int *)(*(int *)(unaff_ESI + 0x10) + uVar3 * 8);
  if ((int *)piVar1[1] == param_2) {
    if ((int *)*piVar1 == param_2) {
      *piVar1 = *(int *)(unaff_ESI + 4);
      *(undefined4 *)(*(int *)(unaff_ESI + 0x10) + 4 + uVar3 * 8) = *(undefined4 *)(unaff_ESI + 4);
    }
    else {
      piVar1[1] = param_2[1];
    }
  }
  else if ((int *)*piVar1 == param_2) {
    *piVar1 = *param_2;
  }
  FUN_00719b20(param_1,param_2);
  return param_1;
}

