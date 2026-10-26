
void FUN_0050bdf0(undefined4 param_1,int param_2,uint param_3,int param_4,int param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined2 local_18;
  undefined1 local_16;
  int local_14;
  uint local_8;
  
  for (; 1 < (int)(param_5 - param_3); param_5 = param_5 + -1) {
    uVar1 = param_5 - 1;
    uVar4 = uVar1;
    if (*(uint *)(param_4 + 8) <= uVar1) {
      uVar4 = uVar1 - *(uint *)(param_4 + 8);
    }
    puVar2 = *(undefined4 **)(*(int *)(param_4 + 4) + uVar4 * 4);
    local_28 = *puVar2;
    local_24 = puVar2[1];
    local_20 = puVar2[2];
    local_1c = puVar2[3];
    local_18 = *(undefined2 *)(puVar2 + 4);
    local_16 = *(undefined1 *)((int)puVar2 + 0x12);
    local_14 = param_2;
    local_8 = param_3;
    if (*(uint *)(param_2 + 8) <= param_3) {
      local_8 = param_3 - *(uint *)(param_2 + 8);
    }
    uVar4 = uVar1;
    if (*(uint *)(param_4 + 8) <= uVar1) {
      uVar4 = uVar1 - *(uint *)(param_4 + 8);
    }
    puVar2 = *(undefined4 **)(*(int *)(param_2 + 4) + local_8 * 4);
    puVar3 = *(undefined4 **)(*(int *)(param_4 + 4) + uVar4 * 4);
    *puVar3 = *puVar2;
    puVar3[1] = puVar2[1];
    puVar3[2] = puVar2[2];
    puVar3[3] = puVar2[3];
    *(undefined2 *)(puVar3 + 4) = *(undefined2 *)(puVar2 + 4);
    *(undefined1 *)((int)puVar3 + 0x12) = *(undefined1 *)((int)puVar2 + 0x12);
    FUN_0050c190(0,uVar1 - param_3,&local_28,param_1,param_2,param_3);
  }
  return;
}

