
void FUN_008cdfe0(uint *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint in_EAX;
  int iVar4;
  uint uVar5;
  
  iVar1 = param_1[2] + in_EAX * 0x1c;
  if ((in_EAX < *param_1) && ((*(uint *)(iVar1 + 0x10) & 4) == 0)) {
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 4;
    puVar2 = (undefined4 *)param_1[4];
    uVar5 = param_1[1];
    *(undefined4 *)(iVar1 + 0x14) = 0;
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      uVar3 = *puVar2;
      iVar4 = FUN_008cdf60();
      if (iVar4 != 0) {
        *(undefined4 *)(iVar1 + 0x14) = uVar3;
        break;
      }
      puVar2 = puVar2 + 1;
    }
    if (param_1[1] < *param_1) {
      *(int *)(param_1[4] + param_1[1] * 4) = iVar1;
      param_1[1] = param_1[1] + 1;
    }
  }
  return;
}

