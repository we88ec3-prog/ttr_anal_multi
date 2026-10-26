
int FUN_008d8230(int param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  int local_8;
  
  local_8 = 0;
  if ((byte *)(param_1 + 5U) <= param_2) {
    uVar9 = (uint)*(byte *)(param_1 + 4);
    bVar1 = *(byte *)(param_1 + 3);
    uVar10 = param_3[0x17] + uVar9;
    pbVar6 = (byte *)(param_1 + 5);
    if ((uint)param_3[0x18] < uVar10) {
      uVar10 = uVar10 + 3 & 0xfffffffc;
      uVar2 = FUN_008bc7d0(*param_3,0x24,param_3[0x17],uVar10,param_3[0x19],&local_8);
      param_3[0x19] = uVar2;
      if (local_8 != 0) {
        return local_8;
      }
      param_3[0x18] = uVar10;
    }
    iVar5 = 8;
    if ((bVar1 & 1) != 0) {
      iVar5 = 9;
    }
    if ((bVar1 & 2) != 0) {
      iVar5 = iVar5 + 1;
    }
    if ((bVar1 & 4) != 0) {
      iVar5 = iVar5 + 1;
    }
    if ((bVar1 & 8) != 0) {
      iVar5 = iVar5 + 1;
    }
    if ((bVar1 & 0x10) != 0) {
      iVar5 = iVar5 + 1;
    }
    puVar4 = (uint *)(param_3[0x19] + param_3[0x17] * 0x24);
    uVar10 = uVar9;
    if (pbVar6 + iVar5 * uVar9 <= param_2) {
      for (; uVar10 != 0; uVar10 = uVar10 - 1) {
        if ((bVar1 & 1) == 0) {
          uVar3 = (uint)*pbVar6;
          pbVar7 = pbVar6 + 1;
        }
        else {
          pbVar7 = pbVar6 + 2;
          uVar3 = (uint)CONCAT11(*pbVar6,pbVar6[1]);
        }
        *puVar4 = uVar3;
        if ((bVar1 & 2) == 0) {
          uVar3 = (uint)*pbVar7;
          pbVar6 = pbVar7 + 1;
        }
        else {
          pbVar6 = pbVar7 + 2;
          uVar3 = (uint)CONCAT11(*pbVar7,pbVar7[1]);
        }
        puVar4[1] = uVar3;
        puVar4[2] = (uint)*pbVar6;
        if ((bVar1 & 4) == 0) {
          pbVar7 = pbVar6 + 3;
          uVar3 = (uint)pbVar6[1];
        }
        else {
          pbVar7 = pbVar6 + 4;
          uVar3 = (uint)CONCAT11(pbVar6[1],pbVar6[2]);
        }
        puVar4[5] = uVar3 << 8 | (uint)pbVar7[-1];
        if ((bVar1 & 8) == 0) {
          pbVar8 = pbVar7 + 2;
          uVar3 = (uint)*pbVar7;
        }
        else {
          pbVar8 = pbVar7 + 3;
          uVar3 = (uint)CONCAT11(*pbVar7,pbVar7[1]);
        }
        puVar4[6] = uVar3 << 8 | (uint)pbVar8[-1];
        if ((bVar1 & 0x10) == 0) {
          uVar3 = (uint)*pbVar8;
          pbVar6 = pbVar8 + 1;
        }
        else {
          pbVar6 = pbVar8 + 2;
          uVar3 = (uint)CONCAT11(*pbVar8,pbVar8[1]);
        }
        puVar4[7] = uVar3;
        puVar4 = puVar4 + 9;
      }
      param_3[0x17] = param_3[0x17] + uVar9;
      return local_8;
    }
  }
  return 8;
}

