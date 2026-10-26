
int FUN_008e8170(void)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  byte *pbVar5;
  int iVar6;
  char *pcVar7;
  int unaff_EBX;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  undefined1 local_194 [96];
  undefined4 local_134;
  int local_120;
  int local_118;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_e0;
  undefined4 local_c4;
  int local_b8;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_5c;
  undefined4 local_58;
  int local_4c;
  undefined4 local_40;
  undefined4 local_3c;
  byte *local_1c;
  undefined4 *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  uVar4 = *(undefined4 *)(unaff_EBX + 0x1e8);
  FUN_008e80a0();
  *(undefined4 *)(unaff_EBX + 0x214) = 0xffffffff;
  *(undefined4 *)(unaff_EBX + 0x218) = 0xffffffff;
  *(undefined4 *)(unaff_EBX + 0x21c) = 0;
  *(undefined4 *)(unaff_EBX + 0x118) = 7;
  *(undefined4 *)(unaff_EBX + 0x11c) = 1;
  *(undefined4 *)(unaff_EBX + 0xac) = 4;
  *(undefined4 *)(unaff_EBX + 0x15c) = 0xf5c;
  *(undefined4 *)(unaff_EBX + 0x114) = 0x27a000;
  local_c = FUN_008e5980(local_194,*(undefined4 *)(unaff_EBX + 100));
  if ((((local_c == 0) && (local_c = FUN_008e7ce0(), local_c == 0)) &&
      (local_c = FUN_008e5b40(uVar4), local_c == 0)) && (local_c = FUN_008e7ce0(), local_c == 0)) {
    *(byte *)(unaff_EBX + 0xb0) = *(byte *)(unaff_EBX + 0xb0) & 0xfe;
    iVar8 = *(int *)(unaff_EBX + 0x210);
    if (((iVar8 != 0) && (*(int *)(iVar8 + 0x1a0) != 0)) &&
       (*(int *)(iVar8 + 0x1a0) != *(int *)(iVar8 + 4))) {
      *(undefined4 *)(iVar8 + 0x1a0) = 0;
    }
    piVar2 = *(int **)(unaff_EBX + 0x210);
    if ((piVar2 != (int *)0x0) && ((*piVar2 == 0 || (piVar2[1] == 0)))) {
      FUN_008e6750();
    }
    iVar8 = *(int *)(unaff_EBX + 0x210);
    if ((iVar8 != 0) && (uVar3 = 0, *(int *)(iVar8 + 4) != 0)) {
      pcVar7 = (char *)(iVar8 + 0x58);
      do {
        if (*pcVar7 == '\0') {
          FUN_008e6750();
          break;
        }
        uVar3 = uVar3 + 1;
        pcVar7 = pcVar7 + 0xc;
      } while (uVar3 < *(uint *)(*(int *)(unaff_EBX + 0x210) + 4));
    }
    if (*(int *)(unaff_EBX + 0x210) == 0) {
      *(undefined4 *)(unaff_EBX + 0x21c) = 0;
    }
    else if (*(int *)(unaff_EBX + 0x21c) != 0) {
      uVar4 = FUN_008bc7d0(*(undefined4 *)(unaff_EBX + 100),4,0,*(int *)(unaff_EBX + 0x21c),0,
                           &local_c);
      *(undefined4 *)(unaff_EBX + 0x220) = uVar4;
      if (local_c != 0) {
        *(undefined4 *)(unaff_EBX + 0x21c) = 0;
        FUN_008e80f0();
        return local_c;
      }
    }
    *(undefined4 *)(unaff_EBX + 0x1a0) = local_fc;
    if (local_4c != 0) {
      *(undefined4 *)(unaff_EBX + 0x194) = local_5c;
      local_4c = 0;
      *(undefined4 *)(unaff_EBX + 0x188) = local_58;
      *(undefined4 *)(unaff_EBX + 0x198) = local_40;
      *(undefined4 *)(unaff_EBX + 0x19c) = local_3c;
    }
    if ((*(int *)(*(int *)(unaff_EBX + 0x80) + 0x30) == 0) && (local_b8 == 0)) {
      local_c = 3;
    }
    *(undefined4 *)(unaff_EBX + 0x18c) = local_c4;
    *(undefined4 *)(unaff_EBX + 0x1a8) = local_ac;
    local_b8 = 0;
    *(undefined4 *)(unaff_EBX + 0x1ac) = local_a8;
    *(undefined4 *)(unaff_EBX + 400) = local_f8;
    *(undefined4 *)(unaff_EBX + 0x1a4) = local_e0;
    local_f8 = 0;
    local_e0 = 0;
    if (*(int *)(unaff_EBX + 0x170) == 1) {
      local_10 = 0;
      local_14 = 0;
      local_8 = 0;
      if (0 < local_120) {
LAB_008e83f0:
        iVar8 = 0;
        *(undefined2 *)(*(int *)(unaff_EBX + 0x180) + local_8 * 2) = 0;
        *(char **)(*(int *)(unaff_EBX + 0x184) + local_8 * 4) = ".notdef";
        local_1c = *(byte **)(local_118 + local_8 * 4);
        if ((local_1c != (byte *)0x0) && (0 < *(int *)(unaff_EBX + 0x1a0))) {
          local_18 = *(undefined4 **)(unaff_EBX + 0x1a4);
          do {
            pbVar10 = (byte *)*local_18;
            pbVar5 = local_1c;
            pbVar9 = pbVar10;
            do {
              bVar1 = *pbVar5;
              bVar11 = bVar1 < *pbVar9;
              if (bVar1 != *pbVar9) {
LAB_008e8460:
                iVar6 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
                goto LAB_008e8465;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar5[1];
              bVar11 = bVar1 < pbVar9[1];
              if (bVar1 != pbVar9[1]) goto LAB_008e8460;
              pbVar5 = pbVar5 + 2;
              pbVar9 = pbVar9 + 2;
            } while (bVar1 != 0);
            iVar6 = 0;
LAB_008e8465:
            if (iVar6 == 0) {
              *(short *)(*(int *)(unaff_EBX + 0x180) + local_8 * 2) = (short)iVar8;
              *(byte **)(*(int *)(unaff_EBX + 0x184) + local_8 * 4) = pbVar10;
              pcVar7 = ".notdef";
              goto LAB_008e8495;
            }
            local_18 = local_18 + 1;
            iVar8 = iVar8 + 1;
          } while (iVar8 < *(int *)(unaff_EBX + 0x1a0));
        }
        goto LAB_008e84da;
      }
LAB_008e84ea:
      *(int *)(unaff_EBX + 0x178) = local_10;
      *(int *)(unaff_EBX + 0x17c) = local_14;
      *(undefined4 *)(unaff_EBX + 0x174) = local_134;
    }
  }
  FUN_008e80f0();
  return local_c;
  while( true ) {
    bVar1 = pcVar7[1];
    bVar11 = bVar1 < pbVar10[1];
    if (bVar1 != pbVar10[1]) goto LAB_008e84b5;
    pcVar7 = pcVar7 + 2;
    pbVar10 = pbVar10 + 2;
    if (bVar1 == 0) break;
LAB_008e8495:
    bVar1 = *pcVar7;
    bVar11 = bVar1 < *pbVar10;
    if (bVar1 != *pbVar10) {
LAB_008e84b5:
      iVar8 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      goto LAB_008e84ba;
    }
    if (bVar1 == 0) break;
  }
  iVar8 = 0;
LAB_008e84ba:
  if (iVar8 != 0) {
    if (local_8 < local_10) {
      local_10 = local_8;
    }
    if (local_14 <= local_8) {
      local_14 = local_8 + 1;
    }
  }
LAB_008e84da:
  local_8 = local_8 + 1;
  if (local_120 <= local_8) goto LAB_008e84ea;
  goto LAB_008e83f0;
}

