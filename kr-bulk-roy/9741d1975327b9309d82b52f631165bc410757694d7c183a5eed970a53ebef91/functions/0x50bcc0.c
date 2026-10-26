
void FUN_0050bcc0(int param_1,uint param_2,int param_3,uint param_4)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  if (*(uint *)(param_3 + 8) <= param_4) {
    param_4 = param_4 - *(uint *)(param_3 + 8);
  }
  if (*(uint *)(param_1 + 8) <= param_2) {
    param_2 = param_2 - *(uint *)(param_1 + 8);
  }
  puVar3 = *(undefined4 **)(*(int *)(param_1 + 4) + param_2 * 4);
  uVar4 = puVar3[3];
  puVar5 = *(undefined4 **)(*(int *)(param_3 + 4) + param_4 * 4);
  uVar6 = *puVar3;
  uVar7 = puVar3[1];
  uVar8 = puVar3[2];
  uVar2 = *(undefined2 *)(puVar3 + 4);
  uVar1 = *(undefined1 *)((int)puVar3 + 0x12);
  *puVar3 = *puVar5;
  puVar3[1] = puVar5[1];
  puVar3[2] = puVar5[2];
  puVar3[3] = puVar5[3];
  *(undefined2 *)(puVar3 + 4) = *(undefined2 *)(puVar5 + 4);
  *(undefined1 *)((int)puVar3 + 0x12) = *(undefined1 *)((int)puVar5 + 0x12);
  *puVar5 = uVar6;
  puVar5[1] = uVar7;
  puVar5[2] = uVar8;
  puVar5[3] = uVar4;
  *(undefined2 *)(puVar5 + 4) = uVar2;
  *(undefined1 *)((int)puVar5 + 0x12) = uVar1;
  return;
}

