
void FUN_0050c190(int param_1,int param_2,undefined4 param_3,code *param_4,int param_5,int param_6)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar3 = param_1;
  while( true ) {
    iVar7 = iVar3 * 2 + 2;
    if (param_2 <= iVar7) break;
    uVar5 = param_6 + iVar7;
    uVar6 = uVar5 - 1;
    if (*(uint *)(param_5 + 8) <= uVar6) {
      uVar6 = uVar6 - *(uint *)(param_5 + 8);
    }
    if (*(uint *)(param_5 + 8) <= uVar5) {
      uVar5 = uVar5 - *(uint *)(param_5 + 8);
    }
    cVar4 = (*param_4)(*(undefined4 *)(*(int *)(param_5 + 4) + uVar5 * 4),
                       *(undefined4 *)(*(int *)(param_5 + 4) + uVar6 * 4));
    if (cVar4 != '\0') {
      iVar7 = iVar3 * 2 + 1;
    }
    uVar6 = param_6 + iVar7;
    if (*(uint *)(param_5 + 8) <= uVar6) {
      uVar6 = uVar6 - *(uint *)(param_5 + 8);
    }
    puVar1 = *(undefined4 **)(*(int *)(param_5 + 4) + uVar6 * 4);
    uVar6 = param_6 + iVar3;
    if (*(uint *)(param_5 + 8) <= uVar6) {
      uVar6 = uVar6 - *(uint *)(param_5 + 8);
    }
    puVar2 = *(undefined4 **)(*(int *)(param_5 + 4) + uVar6 * 4);
    *puVar2 = *puVar1;
    puVar2[1] = puVar1[1];
    puVar2[2] = puVar1[2];
    puVar2[3] = puVar1[3];
    *(undefined2 *)(puVar2 + 4) = *(undefined2 *)(puVar1 + 4);
    *(undefined1 *)((int)puVar2 + 0x12) = *(undefined1 *)((int)puVar1 + 0x12);
    iVar3 = iVar7;
  }
  if (iVar7 == param_2) {
    uVar6 = param_6 + -1 + param_2;
    if (*(uint *)(param_5 + 8) <= uVar6) {
      uVar6 = uVar6 - *(uint *)(param_5 + 8);
    }
    puVar1 = *(undefined4 **)(*(int *)(param_5 + 4) + uVar6 * 4);
    uVar6 = iVar3 + param_6;
    if (*(uint *)(param_5 + 8) <= uVar6) {
      uVar6 = uVar6 - *(uint *)(param_5 + 8);
    }
    puVar2 = *(undefined4 **)(*(int *)(param_5 + 4) + uVar6 * 4);
    *puVar2 = *puVar1;
    puVar2[1] = puVar1[1];
    puVar2[2] = puVar1[2];
    puVar2[3] = puVar1[3];
    *(undefined2 *)(puVar2 + 4) = *(undefined2 *)(puVar1 + 4);
    *(undefined1 *)((int)puVar2 + 0x12) = *(undefined1 *)((int)puVar1 + 0x12);
  }
  FUN_0050c2e0(param_1,param_3,param_4,param_5,param_6);
  return;
}

