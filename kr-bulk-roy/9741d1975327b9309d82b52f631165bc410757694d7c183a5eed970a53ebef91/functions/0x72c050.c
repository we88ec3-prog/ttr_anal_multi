
void FUN_0072c050(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int in_EAX;
  int *in_ECX;
  uint uVar8;
  int iVar9;
  short *psVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  ushort *puVar15;
  int local_18;
  int local_14;
  int *local_10;
  int local_c;
  
  iVar2 = in_ECX[1];
  iVar3 = *in_ECX;
  piVar4 = (int *)in_ECX[2];
  iVar9 = *piVar4;
  iVar5 = piVar4[1];
  iVar6 = piVar4[2];
  uVar11 = piVar4[4];
  *(undefined4 *)(in_EAX + 0xb3c) = 0;
  *(undefined4 *)(in_EAX + 0xb40) = 0;
  *(undefined4 *)(in_EAX + 0xb44) = 0;
  *(undefined4 *)(in_EAX + 0xb48) = 0;
  *(undefined4 *)(in_EAX + 0xb4c) = 0;
  *(undefined4 *)(in_EAX + 0xb50) = 0;
  *(undefined4 *)(in_EAX + 0xb54) = 0;
  *(undefined4 *)(in_EAX + 0xb58) = 0;
  *(undefined2 *)(iVar3 + 2 + *(int *)(in_EAX + 0xb5c + *(int *)(in_EAX + 0x1454) * 4) * 4) = 0;
  iVar12 = 0;
  local_14 = *(int *)(in_EAX + 0x1454) + 1;
  local_c = 0;
  if (local_14 < 0x23d) {
    local_10 = (int *)(in_EAX + 0xb5c + local_14 * 4);
    local_18 = 0x23d - local_14;
    local_14 = local_14 + local_18;
    do {
      iVar7 = *local_10;
      uVar8 = *(ushort *)(iVar3 + 2 + (uint)*(ushort *)(iVar3 + 2 + iVar7 * 4) * 4) + 1;
      if ((int)uVar11 < (int)uVar8) {
        iVar12 = iVar12 + 1;
        uVar8 = uVar11;
        local_c = iVar12;
      }
      *(short *)(iVar3 + 2 + iVar7 * 4) = (short)uVar8;
      if (iVar7 <= iVar2) {
        psVar10 = (short *)(in_EAX + 0xb3c + uVar8 * 2);
        *psVar10 = *psVar10 + 1;
        iVar13 = 0;
        if (iVar6 <= iVar7) {
          iVar13 = *(int *)(iVar5 + (iVar7 - iVar6) * 4);
        }
        uVar14 = (uint)*(ushort *)(iVar3 + iVar7 * 4);
        *(int *)(in_EAX + 0x16a8) = *(int *)(in_EAX + 0x16a8) + (uVar8 + iVar13) * uVar14;
        iVar12 = local_c;
        if (iVar9 != 0) {
          *(int *)(in_EAX + 0x16ac) =
               *(int *)(in_EAX + 0x16ac) +
               ((uint)*(ushort *)(iVar9 + 2 + iVar7 * 4) + iVar13) * uVar14;
        }
      }
      local_10 = local_10 + 1;
      local_18 = local_18 + -1;
    } while (local_18 != 0);
    if (iVar12 != 0) {
      puVar15 = (ushort *)(in_EAX + 0xb3c + uVar11 * 2);
      do {
        iVar9 = uVar11 - 1;
        psVar10 = (short *)(in_EAX + 0xb3c + iVar9 * 2);
        sVar1 = *(short *)(in_EAX + 0xb3c + iVar9 * 2);
        while (sVar1 == 0) {
          psVar10 = psVar10 + -1;
          iVar9 = iVar9 + -1;
          sVar1 = *psVar10;
        }
        psVar10 = (short *)(in_EAX + 0xb3e + iVar9 * 2);
        *psVar10 = *psVar10 + 2;
        psVar10 = (short *)(in_EAX + 0xb3c + iVar9 * 2);
        *psVar10 = *psVar10 + -1;
        *puVar15 = *puVar15 - 1;
        iVar12 = iVar12 + -2;
      } while (0 < iVar12);
      for (; uVar11 != 0; uVar11 = uVar11 - 1) {
        uVar8 = (uint)*puVar15;
        if (uVar8 != 0) {
          iVar9 = in_EAX + 0xb5c + local_14 * 4;
          local_10 = (int *)uVar8;
          do {
            iVar5 = *(int *)(iVar9 + -4);
            local_14 = local_14 + -1;
            iVar9 = iVar9 + -4;
            if (iVar5 <= iVar2) {
              uVar8 = (uint)*(ushort *)(iVar3 + 2 + iVar5 * 4);
              if (uVar8 != uVar11) {
                *(int *)(in_EAX + 0x16a8) =
                     *(int *)(in_EAX + 0x16a8) +
                     (uVar11 - uVar8) * (uint)*(ushort *)(iVar3 + iVar5 * 4);
                *(short *)(iVar3 + 2 + iVar5 * 4) = (short)uVar11;
              }
              uVar8 = (int)local_10 - 1;
              local_10 = (int *)uVar8;
            }
          } while (uVar8 != 0);
        }
        puVar15 = puVar15 + -1;
      }
    }
  }
  return;
}

