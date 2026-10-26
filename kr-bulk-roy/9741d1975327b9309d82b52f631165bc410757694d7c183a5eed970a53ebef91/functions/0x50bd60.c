
void FUN_0050bd60(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined2 local_14;
  undefined1 local_12;
  int local_c;
  int local_8;
  
  local_8 = param_5 - param_3;
  iVar3 = local_8 / 2;
  while (0 < iVar3) {
    iVar3 = iVar3 + -1;
    uVar2 = param_3 + iVar3;
    local_c = param_3;
    if (*(uint *)(param_2 + 8) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(param_2 + 8);
    }
    puVar1 = *(undefined4 **)(*(int *)(param_2 + 4) + uVar2 * 4);
    local_24 = *puVar1;
    local_20 = puVar1[1];
    local_1c = puVar1[2];
    local_18 = puVar1[3];
    local_14 = *(undefined2 *)(puVar1 + 4);
    local_12 = *(undefined1 *)((int)puVar1 + 0x12);
    FUN_0050c190(iVar3,local_8,&local_24,param_1,param_2,param_3);
  }
  return;
}

