
uint FUN_008604e0(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int *piVar5;
  int in_ECX;
  int iVar6;
  int *in_EDX;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  bool bVar12;
  
  piVar5 = *(int **)(in_ECX + 0x98);
  uVar7 = in_EDX[1] - *in_EDX >> 2;
  uVar10 = *(int *)(in_ECX + 0x9c) - (int)piVar5 >> 2;
  if (uVar7 != uVar10) {
    return (uint)piVar5 & 0xffffff00;
  }
  uVar9 = 0;
  if (uVar10 != 0) {
    iVar6 = *in_EDX - (int)piVar5;
    piVar11 = piVar5;
    do {
      if (uVar7 <= uVar9) {
LAB_0086058a:
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript");
      }
      iVar2 = *(int *)(iVar6 + (int)piVar11);
      pbVar3 = (byte *)(iVar2 + 8);
      if (0xf < *(uint *)(iVar2 + 0x1c)) {
        pbVar3 = *(byte **)pbVar3;
      }
      if (uVar10 <= uVar9) goto LAB_0086058a;
      pbVar8 = (byte *)(*piVar11 + 8);
      if (0xf < *(uint *)(*piVar11 + 0x1c)) {
        pbVar8 = *(byte **)pbVar8;
      }
      do {
        bVar1 = *pbVar8;
        bVar12 = bVar1 < *pbVar3;
        if (bVar1 != *pbVar3) {
LAB_00860570:
          uVar4 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          goto LAB_00860575;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar8[1];
        bVar12 = bVar1 < pbVar3[1];
        if (bVar1 != pbVar3[1]) goto LAB_00860570;
        pbVar8 = pbVar8 + 2;
        pbVar3 = pbVar3 + 2;
      } while (bVar1 != 0);
      uVar4 = 0;
LAB_00860575:
      if (uVar4 != 0) {
        return uVar4 & 0xffffff00;
      }
      uVar9 = uVar9 + 1;
      piVar11 = piVar11 + 1;
      piVar5 = (int *)0x0;
    } while (uVar9 < uVar10);
  }
  return CONCAT31((int3)((uint)piVar5 >> 8),1);
}

