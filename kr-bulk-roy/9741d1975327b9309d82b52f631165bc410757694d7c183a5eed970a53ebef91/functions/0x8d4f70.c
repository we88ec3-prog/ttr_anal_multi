
/* WARNING: Removing unreachable block (ram,0x008d4fc7) */

int FUN_008d4f70(int param_1,uint *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar2 = *(int *)(param_1 + 0x14);
  uVar3 = *(uint *)(param_1 + 0x10);
  uVar7 = *param_2 + 1;
  iVar5 = 0;
  uVar8 = 0;
  uVar9 = uVar3;
  if (uVar3 != 0) {
    do {
      uVar6 = uVar9 + uVar8 >> 1;
      uVar4 = *(uint *)(iVar2 + uVar6 * 8);
      if (uVar7 == uVar4) {
        uVar1 = *(ushort *)(iVar2 + 4 + uVar6 * 8);
        goto LAB_008d4fc1;
      }
      if (uVar4 <= uVar7) {
        uVar8 = uVar6 + 1;
        uVar6 = uVar9;
      }
      uVar9 = uVar6;
    } while (uVar8 < uVar6);
  }
  uVar7 = 0;
  if (uVar8 < uVar3) {
    uVar7 = *(uint *)(iVar2 + uVar8 * 8);
    uVar1 = *(ushort *)(iVar2 + 4 + uVar8 * 8);
LAB_008d4fc1:
    iVar5 = uVar1 + 1;
  }
  *param_2 = uVar7;
  return iVar5;
}

