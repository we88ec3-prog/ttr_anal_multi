
/* WARNING: Removing unreachable block (ram,0x008bfbd9) */

short FUN_008bfb80(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  
  iVar1 = *(int *)(param_1 + 0x14);
  uVar2 = *(uint *)(param_1 + 0x10);
  uVar7 = 0;
  uVar5 = *param_2 + 1;
  sVar6 = 0;
  uVar8 = uVar2;
  if (uVar2 != 0) {
    do {
      uVar4 = uVar8 + uVar7 >> 1;
      uVar3 = *(uint *)(iVar1 + uVar4 * 8);
      if (uVar5 == uVar3) {
        sVar6 = *(short *)(iVar1 + 4 + uVar4 * 8);
        goto LAB_008bfbcc;
      }
      if (uVar3 <= uVar5) {
        uVar7 = uVar4 + 1;
        uVar4 = uVar8;
      }
      uVar8 = uVar4;
    } while (uVar7 < uVar4);
  }
  uVar5 = 0;
  if (uVar7 < uVar2) {
    uVar5 = *(uint *)(iVar1 + uVar7 * 8);
    sVar6 = *(short *)(iVar1 + 4 + uVar7 * 8);
LAB_008bfbcc:
    sVar6 = sVar6 + 1;
  }
  *param_2 = uVar5;
  return sVar6;
}

