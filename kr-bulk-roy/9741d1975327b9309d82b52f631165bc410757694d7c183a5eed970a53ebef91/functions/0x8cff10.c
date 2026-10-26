
uint FUN_008cff10(int param_1,uint *param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_8;
  
  uVar7 = 0;
  uVar6 = *param_2 + 1;
  local_8 = 0;
  if (*(uint *)(param_1 + 0x10) != 0) {
    iVar2 = *(int *)(param_1 + 0x14);
    uVar5 = *(uint *)(param_1 + 0x10);
    do {
      uVar3 = (uVar5 - uVar7 >> 1) + uVar7;
      uVar4 = *(uint *)(iVar2 + uVar3 * 8);
      if (uVar4 == uVar6) {
        uVar7 = *(uint *)(iVar2 + 4 + uVar3 * 8);
        *param_2 = uVar6;
        return uVar7;
      }
      uVar4 = uVar4 & 0x7fffffff;
      if (uVar4 == uVar6) {
        local_8 = *(uint *)(iVar2 + 4 + uVar3 * 8);
      }
      if (uVar4 < uVar6) {
        uVar7 = uVar3 + 1;
        uVar3 = uVar5;
      }
      uVar5 = uVar3;
    } while (uVar7 < uVar3);
    if (local_8 != 0) {
      *param_2 = uVar6;
      return local_8;
    }
  }
  if (*(uint *)(param_1 + 0x10) <= uVar7) {
    *param_2 = 0;
    return local_8;
  }
  puVar1 = (uint *)(*(int *)(param_1 + 0x14) + uVar7 * 8);
  uVar7 = puVar1[1];
  *param_2 = *puVar1 & 0x7fffffff;
  return uVar7;
}

