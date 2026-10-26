
void FUN_008e2340(int param_1)

{
  longlong lVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *unaff_EDI;
  int local_2c;
  int *local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  local_c = 0;
  _memset(unaff_EDI,0,0x134);
  *unaff_EDI = *(int *)(param_1 + 0x30);
  FUN_008e0be0(unaff_EDI + 3,unaff_EDI + 4,unaff_EDI + 5);
  FUN_008e0c30(&local_8,&local_28);
  FUN_008e0c60(&local_1c,&local_14);
  FUN_008e0c90(&local_18,&local_24);
  FUN_008e0cc0(&local_20,&local_2c);
  iVar2 = FUN_008e0cf0();
  if ((iVar2 == 1) &&
     ((local_8 == (int *)0x0 ||
      ((((local_8 == (int *)0x4 && (*local_28 * 0x10000 < -0x780000)) &&
        (local_28[1] * 0x10000 < -0x780000)) &&
       ((0x3700000 < local_28[2] * 0x10000 && (0x3700000 < local_28[3] * 0x10000)))))))) {
    unaff_EDI[0xe] = -0x780001;
    lVar1 = (longlong)*unaff_EDI * -0x780001 +
            (ulonglong)((int)((longlong)*unaff_EDI * -0x780001 >> 0x3f) + 0x8000);
    unaff_EDI[0xf] =
         (((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000 + 0x8000 & 0xffff0000) -
         0x8000;
    unaff_EDI[0x10] = *unaff_EDI;
    unaff_EDI[0xc] = 0x31;
    iVar2 = *(int *)(param_1 + 0xbc) * 2 + 0x3700001;
    unaff_EDI[9] = iVar2;
    lVar1 = (longlong)iVar2 * (longlong)*unaff_EDI;
    lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
    unaff_EDI[10] =
         (((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000 + 0x8000 & 0xffff0000) +
         0x8000;
    unaff_EDI[0xb] = *unaff_EDI;
    unaff_EDI[7] = 0x32;
    *(undefined1 *)((int)unaff_EDI + 9) = 1;
    return;
  }
  piVar7 = (int *)0x0;
  if (local_8 != (int *)0x0) {
    do {
      unaff_EDI[unaff_EDI[1] * 5 + 0x11] = local_28[(int)piVar7] << 0x10;
      unaff_EDI[unaff_EDI[1] * 5 + 0x12] = local_28[(int)piVar7 + 1] << 0x10;
      iVar2 = unaff_EDI[1];
      iVar5 = unaff_EDI[iVar2 * 5 + 0x12] - unaff_EDI[iVar2 * 5 + 0x11];
      if (-1 < iVar5) {
        if (local_c < iVar5) {
          local_c = iVar5;
        }
        if (piVar7 == (int *)0x0) {
          *(undefined1 *)(unaff_EDI + iVar2 * 5 + 0x15) = 1;
          iVar2 = unaff_EDI[unaff_EDI[1] * 5 + 0x12];
          piVar3 = unaff_EDI + unaff_EDI[1] * 5;
        }
        else {
          unaff_EDI[iVar2 * 5 + 0x12] = unaff_EDI[iVar2 * 5 + 0x12] + *(int *)(param_1 + 0xbc) * 2;
          unaff_EDI[unaff_EDI[1] * 5 + 0x11] =
               unaff_EDI[unaff_EDI[1] * 5 + 0x11] + *(int *)(param_1 + 0xbc) * 2;
          *(undefined1 *)(unaff_EDI + unaff_EDI[1] * 5 + 0x15) = 0;
          piVar3 = unaff_EDI + unaff_EDI[1] * 5;
          iVar2 = piVar3[0x11];
        }
        piVar3[0x13] = iVar2;
        unaff_EDI[1] = unaff_EDI[1] + 1;
      }
      piVar7 = (int *)((int)piVar7 + 2);
    } while (piVar7 < local_8);
  }
  uVar8 = 0;
  if (local_1c != 0) {
    do {
      unaff_EDI[unaff_EDI[1] * 5 + 0x11] = *(int *)(local_14 + uVar8 * 4) << 0x10;
      unaff_EDI[unaff_EDI[1] * 5 + 0x12] = *(int *)(local_14 + 4 + uVar8 * 4) << 0x10;
      iVar2 = unaff_EDI[1];
      iVar5 = unaff_EDI[iVar2 * 5 + 0x12] - unaff_EDI[iVar2 * 5 + 0x11];
      if (-1 < iVar5) {
        if (local_c < iVar5) {
          local_c = iVar5;
        }
        *(undefined1 *)(unaff_EDI + iVar2 * 5 + 0x15) = 1;
        unaff_EDI[unaff_EDI[1] * 5 + 0x13] = unaff_EDI[unaff_EDI[1] * 5 + 0x12];
        unaff_EDI[1] = unaff_EDI[1] + 1;
      }
      uVar8 = uVar8 + 2;
    } while (uVar8 < local_1c);
  }
  local_14 = FUN_008b7f40(0x10000,*unaff_EDI);
  iVar2 = local_c;
  local_28 = (int *)0x0;
  if (unaff_EDI[1] != 0) {
    local_8 = unaff_EDI + 0x13;
    do {
      local_10 = *local_8;
      if ((char)local_8[2] == '\0') {
        uVar8 = 2;
        iVar5 = 0x7fffffff;
        if (2 < local_18) {
          do {
            iVar6 = *(int *)(local_24 + uVar8 * 4) * 0x8000 + *(int *)(param_1 + 0xbc);
            uVar9 = local_10 + iVar6 * -2;
            uVar10 = (int)uVar9 >> 0x1f;
            iVar4 = (uVar9 ^ uVar10) - uVar10;
            if (((iVar4 < iVar5) && (iVar4 < local_14)) &&
               (*local_8 = iVar6 * 2, iVar5 = iVar4, iVar4 == 0)) break;
            uVar8 = uVar8 + 2;
          } while (uVar8 < local_18);
        }
      }
      else {
        iVar5 = 0x7fffffff;
        local_1c = 0;
        if (local_20 != 0) {
          piVar7 = (int *)(local_2c + 4);
          iVar4 = iVar5;
          do {
            uVar8 = local_10 + *piVar7 * -0x10000;
            uVar9 = (int)uVar8 >> 0x1f;
            iVar5 = (uVar8 ^ uVar9) - uVar9;
            if (((iVar5 < iVar4) && (iVar5 < local_14)) &&
               (*local_8 = *piVar7 * 0x10000, iVar4 = iVar5, iVar5 == 0)) break;
            iVar5 = iVar4;
            local_1c = local_1c + 2;
            piVar7 = piVar7 + 2;
            iVar4 = iVar5;
          } while (local_1c < local_20);
        }
        if (1 < local_18) {
          uVar8 = local_10 + *(int *)(local_24 + 4) * -0x10000;
          uVar9 = (int)uVar8 >> 0x1f;
          iVar4 = (uVar8 ^ uVar9) - uVar9;
          if ((iVar4 < iVar5) && (iVar4 < local_14)) {
            *local_8 = *(int *)(local_24 + 4) * 0x10000;
          }
        }
      }
      local_28 = (int *)((int)local_28 + 1);
      local_8 = local_8 + 5;
    } while (local_28 < (int *)unaff_EDI[1]);
  }
  uVar8 = 0;
  if ((0 < local_c) && (iVar5 = FUN_008b7f40(0x10000,local_c), iVar5 < unaff_EDI[3])) {
    iVar2 = FUN_008b7f40(0x10000,iVar2);
    unaff_EDI[3] = iVar2;
  }
  if (*unaff_EDI < unaff_EDI[3]) {
    *(undefined1 *)(unaff_EDI + 2) = 1;
    iVar2 = FUN_008b7dc0(0x999a,*unaff_EDI,unaff_EDI[3]);
    unaff_EDI[6] = 0x999a - iVar2;
    if (0x7fff < 0x999a - iVar2) {
      unaff_EDI[6] = 0x7fff;
    }
  }
  if (*(char *)(param_1 + 0x8e) != '\0') {
    unaff_EDI[6] = 0;
  }
  if (unaff_EDI[1] != 0) {
    piVar7 = unaff_EDI + 0x13;
    do {
      if ((char)piVar7[2] == '\0') {
        lVar1 = (longlong)*piVar7 * (longlong)*unaff_EDI;
        lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
        piVar7[1] = unaff_EDI[6] + 0x8000 +
                    ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000 & 0xffff0000;
      }
      else {
        lVar1 = (longlong)*piVar7 * (longlong)*unaff_EDI;
        lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
        piVar7[1] = ((((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000) -
                    unaff_EDI[6]) + 0x8000 & 0xffff0000;
      }
      uVar8 = uVar8 + 1;
      piVar7 = piVar7 + 5;
    } while (uVar8 < (uint)unaff_EDI[1]);
  }
  return;
}

