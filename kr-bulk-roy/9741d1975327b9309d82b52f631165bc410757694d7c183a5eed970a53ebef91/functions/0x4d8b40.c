
void FUN_004d8b40(undefined4 *param_1,int *param_2,undefined4 param_3,uint param_4,
                 undefined4 param_5,undefined4 param_6,uint param_7,int *param_8,undefined4 param_9,
                 uint param_10)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  for (; param_4 != param_7; param_4 = param_4 + 1) {
    iVar1 = 0;
    if (param_2 != (int *)0x0) {
      iVar1 = *param_2;
    }
    uVar4 = param_4 >> 1;
    if (*(uint *)(iVar1 + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)(iVar1 + 8);
    }
    if (param_8 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *param_8;
    }
    uVar2 = param_10 >> 1;
    if (*(uint *)(iVar3 + 8) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(iVar3 + 8);
    }
    iVar1 = *(int *)(*(int *)(iVar1 + 4) + uVar4 * 4);
    iVar3 = *(int *)(*(int *)(iVar3 + 4) + uVar2 * 4);
    *(undefined4 *)(iVar3 + (param_10 & 1) * 8) = *(undefined4 *)(iVar1 + (param_4 & 1) * 8);
    *(undefined4 *)(iVar3 + 4 + (param_10 & 1) * 8) = *(undefined4 *)(iVar1 + 4 + (param_4 & 1) * 8)
    ;
    param_10 = param_10 + 1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = param_10;
  if ((param_8 != (int *)0x0) && ((undefined4 *)*param_8 != (undefined4 *)0x0)) {
    *param_1 = *(undefined4 *)*param_8;
  }
  return;
}

