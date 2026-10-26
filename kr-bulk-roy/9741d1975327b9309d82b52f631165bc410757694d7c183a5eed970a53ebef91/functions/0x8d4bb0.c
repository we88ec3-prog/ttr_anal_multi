
undefined4 FUN_008d4bb0(void)

{
  short sVar1;
  short sVar2;
  longlong lVar3;
  int iVar4;
  undefined4 uVar5;
  short *psVar6;
  int iVar7;
  undefined4 uVar8;
  short sVar9;
  undefined4 *unaff_EDI;
  int local_c;
  char local_5;
  
  uVar8 = unaff_EDI[0x19];
  local_c = FUN_008d3c80();
  if ((((local_c == 0) && (local_c = FUN_008d4030(), local_c == 0)) &&
      ((local_5 = FUN_008d3f80(), local_5 != '\0' || (local_c = FUN_008d4880(), local_c == 0)))) &&
     ((((local_c = FUN_008d4300(), local_c == 0 && (local_c = FUN_008d44a0(), local_c == 0)) &&
       (local_c = FUN_008d4660(), local_c == 0)) &&
      ((iVar4 = 0, local_5 == '\0' || (iVar4 = FUN_008d4880(), iVar4 == 0)))))) {
    local_c = iVar4;
    unaff_EDI[2] = unaff_EDI[2] | 0x92;
    *unaff_EDI = 1;
    unaff_EDI[1] = 0;
    if (*(char *)((int)unaff_EDI + 199) != '\0') {
      unaff_EDI[2] = unaff_EDI[2] | 4;
    }
    local_c = FUN_008d49c0();
    if (local_c == 0) {
      iVar4 = FUN_008d3fa0("FAMILY_NAME");
      if ((iVar4 == 0) || (*(char *)(iVar4 + 4) == '\0')) {
        unaff_EDI[5] = 0;
      }
      else {
        uVar5 = FUN_008ba000(uVar8,*(undefined4 *)(iVar4 + 8),&local_c);
        unaff_EDI[5] = uVar5;
        if (local_c != 0) {
          return 3;
        }
      }
      unaff_EDI[4] = unaff_EDI[0x48] + 1;
      unaff_EDI[7] = 1;
      psVar6 = (short *)FUN_008bc7d0(uVar8,0x10,0,1,0,&local_c);
      unaff_EDI[8] = psVar6;
      if (local_c == 0) {
        psVar6[0] = 0;
        psVar6[1] = 0;
        psVar6[2] = 0;
        psVar6[3] = 0;
        psVar6[4] = 0;
        psVar6[5] = 0;
        psVar6[6] = 0;
        psVar6[7] = 0;
        sVar9 = *(short *)(unaff_EDI + 0x34);
        sVar1 = *(short *)(unaff_EDI + 0x33);
        sVar2 = 0;
        *psVar6 = sVar9 + sVar1;
        iVar4 = FUN_008d3fa0("AVERAGE_WIDTH");
        if (iVar4 == 0) {
          lVar3 = (longlong)((short)(sVar9 + sVar1) * 2) * 0x55555556;
          psVar6[1] = (short)((ulonglong)lVar3 >> 0x20) - (short)(lVar3 >> 0x3f);
        }
        else {
          iVar4 = *(int *)(iVar4 + 8) + 5;
          psVar6[1] = ((short)(iVar4 / 10) + (short)(iVar4 >> 0x1f)) -
                      (short)((longlong)iVar4 * 0x66666667 >> 0x3f);
        }
        iVar4 = FUN_008d3fa0("POINT_SIZE");
        if (iVar4 != 0) {
          *(int *)(psVar6 + 2) = (*(int *)(iVar4 + 8) * 0x70800 + 0x8d27) / 0x11a4e;
        }
        iVar4 = FUN_008d3fa0("PIXEL_SIZE");
        if (iVar4 != 0) {
          *(int *)(psVar6 + 6) = (int)*(short *)(iVar4 + 8) << 6;
        }
        iVar4 = FUN_008d3fa0("RESOLUTION_X");
        if (iVar4 != 0) {
          sVar2 = *(short *)(iVar4 + 8);
        }
        iVar4 = FUN_008d3fa0("RESOLUTION_Y");
        if (iVar4 == 0) {
          sVar9 = 0;
        }
        else {
          sVar9 = *(short *)(iVar4 + 8);
        }
        if (*(int *)(psVar6 + 6) == 0) {
          *(int *)(psVar6 + 6) = *(int *)(psVar6 + 2);
          if (sVar9 != 0) {
            *(int *)(psVar6 + 6) = ((int)sVar9 * *(int *)(psVar6 + 2)) / 0x48;
          }
        }
        if ((sVar2 == 0) || (sVar9 == 0)) {
          *(undefined4 *)(psVar6 + 4) = *(undefined4 *)(psVar6 + 6);
        }
        else {
          *(int *)(psVar6 + 4) = ((int)sVar2 * *(int *)(psVar6 + 6)) / (int)sVar9;
        }
        iVar4 = FUN_008d3fa0("CHARSET_REGISTRY");
        iVar7 = FUN_008d3fa0("CHARSET_ENCODING");
        if ((((iVar4 != 0) && (*(char *)(iVar4 + 4) != '\0')) && (iVar7 != 0)) &&
           (*(char *)(iVar7 + 4) != '\0')) {
          uVar5 = FUN_008ba000(uVar8,*(undefined4 *)(iVar7 + 8),&local_c);
          unaff_EDI[0x2c] = uVar5;
          if (local_c != 0) {
            return 3;
          }
          uVar8 = FUN_008ba000(uVar8,*(undefined4 *)(iVar4 + 8),&local_c);
          unaff_EDI[0x2d] = uVar8;
        }
        if (local_c == 0) {
          return 0;
        }
      }
    }
  }
  return 3;
}

