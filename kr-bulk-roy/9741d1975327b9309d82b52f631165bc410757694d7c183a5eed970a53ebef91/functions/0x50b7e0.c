
void FUN_0050b7e0(int *param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5
                 ,uint param_6,int *param_7,undefined4 param_8,uint param_9)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  for (; param_3 != param_6; param_3 = param_3 + 1) {
    if (param_1 == (int *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *param_1;
    }
    uVar3 = param_3;
    if (*(uint *)(iVar5 + 8) <= param_3) {
      uVar3 = param_3 - *(uint *)(iVar5 + 8);
    }
    iVar6 = 0;
    if (param_7 != (int *)0x0) {
      iVar6 = *param_7;
    }
    uVar4 = param_9;
    if (*(uint *)(iVar6 + 8) <= param_9) {
      uVar4 = param_9 - *(uint *)(iVar6 + 8);
    }
    puVar1 = *(undefined4 **)(*(int *)(iVar6 + 4) + uVar4 * 4);
    puVar2 = *(undefined4 **)(*(int *)(iVar5 + 4) + uVar3 * 4);
    *puVar1 = *puVar2;
    puVar1[1] = puVar2[1];
    puVar1[2] = puVar2[2];
    puVar1[3] = puVar2[3];
    *(undefined2 *)(puVar1 + 4) = *(undefined2 *)(puVar2 + 4);
    *(undefined1 *)((int)puVar1 + 0x12) = *(undefined1 *)((int)puVar2 + 0x12);
    param_9 = param_9 + 1;
  }
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = param_9;
  if ((param_7 != (int *)0x0) && ((undefined4 *)*param_7 != (undefined4 *)0x0)) {
    *in_EAX = *(undefined4 *)*param_7;
  }
  return;
}

