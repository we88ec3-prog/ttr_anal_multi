
void FUN_004d8a90(undefined4 param_1,undefined4 param_2,uint param_3,int *param_4,undefined4 param_5
                 ,uint param_6,int *param_7,undefined4 param_8,uint param_9)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  uint uVar2;
  int iVar3;
  
  while (param_3 != param_6) {
    param_6 = param_6 - 1;
    if (param_4 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *param_4;
    }
    uVar2 = param_6 >> 1;
    if (*(uint *)(iVar3 + 8) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(iVar3 + 8);
    }
    puVar1 = (undefined4 *)(*(int *)(*(int *)(iVar3 + 4) + uVar2 * 4) + (param_6 & 1) * 8);
    param_9 = param_9 - 1;
    if (param_7 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *param_7;
    }
    uVar2 = param_9 >> 1;
    if (*(uint *)(iVar3 + 8) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(iVar3 + 8);
    }
    iVar3 = *(int *)(*(int *)(iVar3 + 4) + uVar2 * 4);
    *(undefined4 *)(iVar3 + (param_9 & 1) * 8) = *puVar1;
    *(undefined4 *)(iVar3 + 4 + (param_9 & 1) * 8) = puVar1[1];
  }
  *in_EAX = 0;
  in_EAX[1] = 0;
  if (param_7 != (int *)0x0) {
    if ((undefined4 *)*param_7 == (undefined4 *)0x0) {
      in_EAX[2] = param_9;
      return;
    }
    *in_EAX = *(undefined4 *)*param_7;
  }
  in_EAX[2] = param_9;
  return;
}

