
undefined4 FUN_008bc1e0(undefined4 *param_1)

{
  byte bVar1;
  int *piVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  bool bVar8;
  byte *local_18 [4];
  uint local_8;
  
  puVar3 = param_1;
  if (param_1 == (undefined4 *)0x0) {
    return 0x21;
  }
  param_1[0x2f] = param_1[0x2f] + -1;
  if ((int)param_1[0x2f] < 1) {
    local_18[3] = (byte *)*param_1;
    local_18[0] = &DAT_00bd6ef4;
    local_18[1] = (byte *)0x0;
    local_8 = 0;
    do {
      param_1 = (undefined4 *)0x0;
      if (puVar3[4] != 0) {
        local_18[2] = local_18[local_8];
        puVar7 = puVar3 + 5;
        do {
          piVar2 = (int *)*puVar7;
          if (local_18[2] == (byte *)0x0) {
LAB_008bc279:
            if ((*(byte *)*piVar2 & 1) != 0) {
              iVar5 = piVar2[4];
              while (iVar5 != 0) {
                FUN_008bbe50(*(undefined4 *)(iVar5 + 8));
                iVar5 = piVar2[4];
              }
            }
          }
          else {
            pbVar4 = *(byte **)(*piVar2 + 8);
            pbVar6 = local_18[2];
            do {
              bVar1 = *pbVar4;
              bVar8 = bVar1 < *pbVar6;
              if (bVar1 != *pbVar6) {
LAB_008bc270:
                iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
                goto LAB_008bc275;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar4[1];
              bVar8 = bVar1 < pbVar6[1];
              if (bVar1 != pbVar6[1]) goto LAB_008bc270;
              pbVar4 = pbVar4 + 2;
              pbVar6 = pbVar6 + 2;
            } while (bVar1 != 0);
            iVar5 = 0;
LAB_008bc275:
            if (iVar5 == 0) goto LAB_008bc279;
          }
          param_1 = (undefined4 *)((int)param_1 + 1);
          puVar7 = puVar7 + 1;
        } while (param_1 < (uint)puVar3[4]);
      }
      local_8 = local_8 + 1;
    } while (local_8 < 2);
    iVar5 = puVar3[4];
    while (iVar5 != 0) {
      FUN_008bc0d0(puVar3,puVar3[puVar3[4] + 4]);
      iVar5 = puVar3[4];
    }
    FUN_008b9f80(local_18[3],puVar3[0x29]);
    puVar3[0x29] = 0;
    puVar3[0x2a] = 0;
    FUN_008b9f80(local_18[3],puVar3);
  }
  return 0;
}

