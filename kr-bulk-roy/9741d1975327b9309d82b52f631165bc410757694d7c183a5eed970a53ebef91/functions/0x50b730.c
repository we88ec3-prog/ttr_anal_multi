
void FUN_0050b730(undefined4 param_1,undefined4 param_2,uint param_3,int *param_4,undefined4 param_5
                 ,uint param_6,int *param_7,undefined4 param_8,uint param_9)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  uint uVar3;
  int iVar4;
  
  while (param_3 != param_6) {
    param_6 = param_6 - 1;
    iVar4 = 0;
    if (param_4 != (int *)0x0) {
      iVar4 = *param_4;
    }
    uVar3 = param_6;
    if (*(uint *)(iVar4 + 8) <= param_6) {
      uVar3 = param_6 - *(uint *)(iVar4 + 8);
    }
    puVar1 = *(undefined4 **)(*(int *)(iVar4 + 4) + uVar3 * 4);
    param_9 = param_9 - 1;
    iVar4 = 0;
    if (param_7 != (int *)0x0) {
      iVar4 = *param_7;
    }
    uVar3 = param_9;
    if (*(uint *)(iVar4 + 8) <= param_9) {
      uVar3 = param_9 - *(uint *)(iVar4 + 8);
    }
    puVar2 = *(undefined4 **)(*(int *)(iVar4 + 4) + uVar3 * 4);
    *puVar2 = *puVar1;
    puVar2[1] = puVar1[1];
    puVar2[2] = puVar1[2];
    puVar2[3] = puVar1[3];
    *(undefined2 *)(puVar2 + 4) = *(undefined2 *)(puVar1 + 4);
    *(undefined1 *)((int)puVar2 + 0x12) = *(undefined1 *)((int)puVar1 + 0x12);
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

