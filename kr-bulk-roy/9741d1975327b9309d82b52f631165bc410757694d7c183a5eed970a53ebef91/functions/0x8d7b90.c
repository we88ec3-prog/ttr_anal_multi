
int FUN_008d7b90(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  int iVar7;
  char *pcVar8;
  byte *pbVar9;
  byte *pbVar10;
  int iVar11;
  bool bVar12;
  undefined4 local_f0;
  int local_dc;
  int local_d4;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_9c;
  undefined4 local_80;
  int local_74;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar4 = param_1;
  uVar2 = *(undefined4 *)(param_1 + 100);
  FUN_008d7a30();
  uVar5 = FUN_008baee0(uVar2,0xc,&local_8);
  *(undefined4 *)(param_1 + 0x1ec) = uVar5;
  if (((local_8 == 0) && (local_8 = FUN_008d69d0(uVar2), local_8 == 0)) &&
     (local_8 = FUN_008d7830(param_1), local_8 == 0)) {
    if (*(char *)(param_1 + 0x1b1) != '*') {
      local_8 = 2;
      FUN_008d7a60();
      return local_8;
    }
    *(undefined4 *)(param_1 + 0x1a0) = local_b8;
    if (local_74 == 0) {
      local_8 = 3;
    }
    *(undefined4 *)(param_1 + 0x18c) = local_80;
    *(undefined4 *)(param_1 + 0x1a8) = local_68;
    *(undefined4 *)(param_1 + 0x1ac) = local_64;
    *(undefined4 *)(param_1 + 400) = local_b4;
    *(undefined4 *)(param_1 + 0x1a4) = local_9c;
    if (*(int *)(param_1 + 0x170) == 1) {
      local_c = 0;
      local_10 = 0;
      param_1 = 0;
      if (0 < local_dc) {
LAB_008d7cb8:
        iVar11 = 0;
        *(undefined2 *)(*(int *)(iVar4 + 0x180) + param_1 * 2) = 0;
        *(char **)(*(int *)(iVar4 + 0x184) + param_1 * 4) = ".notdef";
        pbVar3 = *(byte **)(local_d4 + param_1 * 4);
        if ((pbVar3 != (byte *)0x0) && (0 < *(int *)(iVar4 + 0x1a0))) {
          local_14 = *(undefined4 **)(iVar4 + 0x1a4);
          do {
            pbVar10 = (byte *)*local_14;
            pbVar6 = pbVar3;
            pbVar9 = pbVar10;
            do {
              bVar1 = *pbVar6;
              bVar12 = bVar1 < *pbVar9;
              if (bVar1 != *pbVar9) {
LAB_008d7d30:
                iVar7 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                goto LAB_008d7d35;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar6[1];
              bVar12 = bVar1 < pbVar9[1];
              if (bVar1 != pbVar9[1]) goto LAB_008d7d30;
              pbVar6 = pbVar6 + 2;
              pbVar9 = pbVar9 + 2;
            } while (bVar1 != 0);
            iVar7 = 0;
LAB_008d7d35:
            if (iVar7 == 0) {
              *(short *)(*(int *)(iVar4 + 0x180) + param_1 * 2) = (short)iVar11;
              *(byte **)(*(int *)(iVar4 + 0x184) + param_1 * 4) = pbVar10;
              pcVar8 = ".notdef";
              goto LAB_008d7d65;
            }
            local_14 = local_14 + 1;
            iVar11 = iVar11 + 1;
          } while (iVar11 < *(int *)(iVar4 + 0x1a0));
        }
        goto LAB_008d7da8;
      }
LAB_008d7db8:
      *(int *)(iVar4 + 0x178) = local_c;
      *(int *)(iVar4 + 0x17c) = local_10;
      *(undefined4 *)(iVar4 + 0x174) = local_f0;
    }
  }
  FUN_008d7a60();
  return local_8;
  while( true ) {
    bVar1 = pcVar8[1];
    bVar12 = bVar1 < pbVar10[1];
    if (bVar1 != pbVar10[1]) goto LAB_008d7d85;
    pcVar8 = pcVar8 + 2;
    pbVar10 = pbVar10 + 2;
    if (bVar1 == 0) break;
LAB_008d7d65:
    bVar1 = *pcVar8;
    bVar12 = bVar1 < *pbVar10;
    if (bVar1 != *pbVar10) {
LAB_008d7d85:
      iVar11 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      goto LAB_008d7d8a;
    }
    if (bVar1 == 0) break;
  }
  iVar11 = 0;
LAB_008d7d8a:
  if (iVar11 != 0) {
    if (param_1 < local_c) {
      local_c = param_1;
    }
    if (local_10 <= param_1) {
      local_10 = param_1 + 1;
    }
  }
LAB_008d7da8:
  param_1 = param_1 + 1;
  if (local_dc <= param_1) goto LAB_008d7db8;
  goto LAB_008d7cb8;
}

