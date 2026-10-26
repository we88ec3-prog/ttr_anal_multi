
int FUN_008d6300(int param_1,int *param_2,uint param_3)

{
  byte *pbVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  uint uVar10;
  undefined1 *puVar11;
  bool bVar12;
  
  iVar3 = *param_2;
  param_2 = (int *)0x0;
  if (iVar3 == 0) {
    return 6;
  }
  iVar4 = *(int *)(iVar3 + 0x84);
  if ((iVar4 != 0) && (param_3 < *(uint *)(iVar3 + 0x10))) {
    if (param_3 == 0) {
      uVar10 = (uint)*(byte *)(iVar4 + 0x6a);
    }
    else {
      uVar10 = param_3 - 1;
    }
    bVar12 = *(short *)(iVar4 + 4) == 0x300;
    uVar10 = (-(uint)bVar12 & 0x1e) + 0x76 + ((uint)bVar12 * 2 + 4) * uVar10;
    if (uVar10 < (*(int *)(iVar4 + 8) - ((uint)bVar12 * 2 + 2)) - 2) {
      pbVar1 = (byte *)(*(int *)(iVar4 + 0xa0) + 2 + uVar10);
      *(uint *)(param_1 + 0x50) =
           (int)(short)((ushort)pbVar1[-1] << 8) | (uint)*(byte *)(*(int *)(iVar4 + 0xa0) + uVar10);
      if (bVar12) {
        uVar10 = (uint)*(uint3 *)(pbVar1 + 1);
      }
      else {
        uVar10 = (uint)pbVar1[1];
      }
      uVar10 = uVar10 << 8 | (uint)*pbVar1;
      if (uVar10 < *(uint *)(iVar4 + 8)) {
        uVar5 = *(undefined4 *)(*(int *)(param_1 + 4) + 100);
        iVar3 = *(int *)(iVar4 + 0xa0);
        iVar9 = *(int *)(param_1 + 0x50) + 7 >> 3;
        *(int *)(param_1 + 0x54) = iVar9;
        uVar2 = *(ushort *)(iVar4 + 0x60);
        *(uint *)(param_1 + 0x4c) = (uint)uVar2;
        puVar11 = (undefined1 *)(iVar3 + uVar10);
        *(undefined1 *)(param_1 + 0x5e) = 1;
        if ((uint)uVar2 * iVar9 + uVar10 <= *(uint *)(iVar4 + 8)) {
          puVar6 = (undefined1 *)
                   FUN_008bc7d0(uVar5,*(undefined4 *)(param_1 + 0x4c),0,iVar9,0,&param_2);
          *(undefined1 **)(param_1 + 0x58) = puVar6;
          if (param_2 != (int *)0x0) {
            return (int)param_2;
          }
          for (; 0 < iVar9; iVar9 = iVar9 + -1) {
            puVar8 = puVar11 + *(int *)(param_1 + 0x4c);
            puVar7 = puVar6;
            for (; puVar11 < puVar8; puVar11 = puVar11 + 1) {
              *puVar7 = *puVar11;
              puVar7 = puVar7 + *(int *)(param_1 + 0x54);
            }
            puVar6 = puVar6 + 1;
          }
          *(undefined4 *)(*(int *)(param_1 + 0x9c) + 4) = 1;
          *(undefined4 *)(param_1 + 100) = 0;
          *(uint *)(param_1 + 0x68) = (uint)*(ushort *)(iVar4 + 0x50);
          *(undefined4 *)(param_1 + 0x48) = 0x62697473;
          *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x50) << 6;
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x4c) << 6;
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x50) << 6;
          *(undefined4 *)(param_1 + 0x20) = 0;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x68) << 6;
          FUN_008b86a0(param_1 + 0x18,*(int *)(param_1 + 0x4c) << 6);
          return (int)param_2;
        }
      }
    }
    return 3;
  }
  return 6;
}

