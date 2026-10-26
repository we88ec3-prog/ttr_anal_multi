
undefined2 * FUN_004a7f20(undefined2 *param_1,int param_2)

{
  undefined4 *puVar1;
  int *in_EAX;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)*in_EAX;
  uVar3 = 0;
  uVar2 = in_EAX[1] - (int)puVar1 >> 2;
  puVar4 = puVar1;
  if (uVar2 != 0) {
    do {
      if (*(int *)*puVar4 == param_2) {
        FUN_004a78b0(puVar1[uVar3]);
        return param_1;
      }
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar3 < uVar2);
  }
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_00402160(&DAT_00bed1fc,0);
  return param_1;
}

