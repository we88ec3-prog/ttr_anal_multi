
void FUN_0050c3e0(undefined4 param_1,uint param_2,int param_3,uint param_4,int param_5,uint param_6)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *in_EAX;
  uint uVar3;
  
  while (param_2 != param_4) {
    param_4 = param_4 - 1;
    uVar3 = param_4;
    if (*(uint *)(param_3 + 8) <= param_4) {
      uVar3 = param_4 - *(uint *)(param_3 + 8);
    }
    puVar1 = *(undefined4 **)(*(int *)(param_3 + 4) + uVar3 * 4);
    param_6 = param_6 - 1;
    uVar3 = param_6;
    if (*(uint *)(param_5 + 8) <= param_6) {
      uVar3 = param_6 - *(uint *)(param_5 + 8);
    }
    puVar2 = *(undefined4 **)(*(int *)(param_5 + 4) + uVar3 * 4);
    *puVar2 = *puVar1;
    puVar2[1] = puVar1[1];
    puVar2[2] = puVar1[2];
    puVar2[3] = puVar1[3];
    *(undefined2 *)(puVar2 + 4) = *(undefined2 *)(puVar1 + 4);
    *(undefined1 *)((int)puVar2 + 0x12) = *(undefined1 *)((int)puVar1 + 0x12);
  }
  *in_EAX = param_5;
  in_EAX[1] = param_6;
  return;
}

