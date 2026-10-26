
void FUN_005102e0(undefined4 param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_3 != param_5) {
    do {
      param_5 = param_5 - 1;
      if (param_3 == param_5) {
        return;
      }
      uVar5 = param_5 >> 2;
      if (*(uint *)(param_4 + 8) <= uVar5) {
        uVar5 = uVar5 - *(uint *)(param_4 + 8);
      }
      uVar4 = param_3 >> 2;
      if (*(uint *)(param_2 + 8) <= uVar4) {
        uVar4 = uVar4 - *(uint *)(param_2 + 8);
      }
      puVar1 = (undefined4 *)(*(int *)(*(int *)(param_4 + 4) + uVar5 * 4) + (param_5 & 3) * 4);
      puVar2 = (undefined4 *)(*(int *)(*(int *)(param_2 + 4) + uVar4 * 4) + (param_3 & 3) * 4);
      uVar3 = *puVar2;
      *puVar2 = *puVar1;
      *puVar1 = uVar3;
      param_3 = param_3 + 1;
    } while (param_3 != param_5);
  }
  return;
}

