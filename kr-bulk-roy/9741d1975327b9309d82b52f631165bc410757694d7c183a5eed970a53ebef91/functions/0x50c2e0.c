
void FUN_0050c2e0(int param_1,undefined4 *param_2,code *param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  int in_EAX;
  uint uVar4;
  int iVar5;
  
  while (param_1 < in_EAX) {
    iVar5 = (in_EAX + -1) / 2;
    uVar4 = param_5 + iVar5;
    if (*(uint *)(param_4 + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)(param_4 + 8);
    }
    cVar3 = (*param_3)(*(undefined4 *)(*(int *)(param_4 + 4) + uVar4 * 4),param_2);
    if (cVar3 == '\0') break;
    uVar4 = param_5 + iVar5;
    if (*(uint *)(param_4 + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)(param_4 + 8);
    }
    puVar1 = *(undefined4 **)(*(int *)(param_4 + 4) + uVar4 * 4);
    uVar4 = param_5 + in_EAX;
    if (*(uint *)(param_4 + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)(param_4 + 8);
    }
    puVar2 = *(undefined4 **)(*(int *)(param_4 + 4) + uVar4 * 4);
    *puVar2 = *puVar1;
    puVar2[1] = puVar1[1];
    puVar2[2] = puVar1[2];
    puVar2[3] = puVar1[3];
    *(undefined2 *)(puVar2 + 4) = *(undefined2 *)(puVar1 + 4);
    *(undefined1 *)((int)puVar2 + 0x12) = *(undefined1 *)((int)puVar1 + 0x12);
    in_EAX = iVar5;
  }
  uVar4 = in_EAX + param_5;
  if (*(uint *)(param_4 + 8) <= uVar4) {
    uVar4 = uVar4 - *(uint *)(param_4 + 8);
  }
  puVar1 = *(undefined4 **)(*(int *)(param_4 + 4) + uVar4 * 4);
  *puVar1 = *param_2;
  puVar1[1] = param_2[1];
  puVar1[2] = param_2[2];
  puVar1[3] = param_2[3];
  *(undefined2 *)(puVar1 + 4) = *(undefined2 *)(param_2 + 4);
  *(undefined1 *)((int)puVar1 + 0x12) = *(undefined1 *)((int)param_2 + 0x12);
  return;
}

