
undefined4 FUN_0054a450(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  int unaff_ESI;
  int iVar7;
  int local_34;
  int local_30;
  float local_28;
  int local_24;
  float local_20;
  float local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00938a0e;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  bVar2 = false;
  local_34 = 0;
  do {
    iVar1 = *(int *)(unaff_ESI + 0x6c);
    local_30 = 0;
    if (iVar1 == 0) {
      if (local_34 == 0) {
LAB_0054a4aa:
        iVar7 = *(int *)(unaff_ESI + 0x54);
      }
      else {
        if (local_34 == 1) goto LAB_0054a4f3;
        if (local_34 != 2) goto LAB_0054a50e;
LAB_0054a4ee:
        iVar7 = *(int *)(unaff_ESI + 0x58);
      }
LAB_0054a4ad:
      if (iVar7 != 0) {
        iVar4 = 0;
        puVar6 = (uint *)(unaff_ESI + 0xa8);
        do {
          if (*puVar6 == (uint)*(ushort *)(iVar7 + 4)) {
            if (iVar4 != -1) {
              local_30 = unaff_ESI + 0xa8 + iVar4 * 0x10;
            }
            break;
          }
          iVar4 = iVar4 + 1;
          puVar6 = puVar6 + 4;
        } while (iVar4 < 3);
      }
    }
    else if (iVar1 == 1) {
      if (local_34 == 0) {
LAB_0054a4f3:
        iVar7 = *(int *)(unaff_ESI + 0x50);
        goto LAB_0054a4ad;
      }
      if (local_34 == 1) goto LAB_0054a4aa;
      if (local_34 == 2) {
        iVar7 = *(int *)(unaff_ESI + 0x58);
        goto LAB_0054a4ad;
      }
    }
    else if (iVar1 == 2) {
      if (local_34 == 0) goto LAB_0054a4f3;
      if (local_34 == 1) goto LAB_0054a4ee;
      if (local_34 == 2) goto LAB_0054a4aa;
    }
LAB_0054a50e:
    iVar7 = 0;
    if (iVar1 == 0) {
      if (local_34 == 0) {
LAB_0054a538:
        iVar7 = *(int *)(unaff_ESI + 0x54);
      }
      else {
        if (local_34 == 1) goto LAB_0054a666;
        if (local_34 == 2) {
LAB_0054a65e:
          iVar7 = *(int *)(unaff_ESI + 0x58);
        }
      }
    }
    else if (iVar1 == 1) {
      if (local_34 == 0) {
LAB_0054a666:
        iVar7 = *(int *)(unaff_ESI + 0x50);
      }
      else {
        if (local_34 == 1) goto LAB_0054a538;
        if (local_34 == 2) {
          iVar7 = *(int *)(unaff_ESI + 0x58);
        }
      }
    }
    else if (iVar1 == 2) {
      if (local_34 == 0) goto LAB_0054a666;
      if (local_34 == 1) goto LAB_0054a65e;
      if (local_34 == 2) goto LAB_0054a538;
    }
    if ((local_30 != 0) && (iVar7 != 0)) {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 0;
        FUN_004dec90(uVar3);
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_28 = *(float *)(local_30 + 8);
      FUN_0082ef00(&local_28);
      if ((((local_24 == DAT_00fab13c) || (iVar1 = *(int *)(local_24 + 0x10), iVar1 == 0)) ||
          (*(int *)(iVar1 + 0x158) == 0)) || (*(int *)(*(int *)(iVar1 + 0x158) + 0x34) != 0)) {
        *(undefined4 *)(local_30 + 8) = 0;
      }
      else {
        local_20 = *(float *)(iVar7 + 0xa0) - *(float *)(iVar1 + 0xa0);
        local_1c = *(float *)(iVar7 + 0xa4) - *(float *)(iVar1 + 0xa4);
        local_28 = local_20 * local_20 + local_1c * local_1c;
        if (local_28 <= *(float *)(unaff_ESI + 0x7c + local_34 * 0x10)) {
          bVar2 = true;
        }
        else {
          *(undefined4 *)(local_30 + 8) = 0;
        }
      }
    }
    local_34 = local_34 + 1;
    if (2 < local_34) {
      iVar1 = *(int *)(unaff_ESI + 0x108);
      if (*(int *)(unaff_ESI + (iVar1 + 0xb) * 0x10) == 0) {
        if (*(int *)(unaff_ESI + 0x10c) != 2) {
          uVar5 = FUN_00549320(unaff_ESI);
          *(undefined4 *)(unaff_ESI + iVar1 * 0x10 + 0xb0) = uVar5;
        }
        if (*(int *)(unaff_ESI + 0x10c) == 0) {
          if (*(int *)(unaff_ESI + 0xb0) == 0) {
            *(undefined4 *)(unaff_ESI + 0xb0) =
                 *(undefined4 *)(unaff_ESI + (*(int *)(unaff_ESI + 0x108) + 0xb) * 0x10);
          }
          if (*(int *)(unaff_ESI + 0xc0) == 0) {
            *(undefined4 *)(unaff_ESI + 0xc0) =
                 *(undefined4 *)(unaff_ESI + (*(int *)(unaff_ESI + 0x108) + 0xb) * 0x10);
          }
          if (*(int *)(unaff_ESI + 0xd0) == 0) {
            *(undefined4 *)(unaff_ESI + 0xd0) =
                 *(undefined4 *)(unaff_ESI + (*(int *)(unaff_ESI + 0x108) + 0xb) * 0x10);
          }
        }
      }
      iVar1 = *(int *)(unaff_ESI + 0x108);
      if ((*(int *)(unaff_ESI + (iVar1 + 0xb) * 0x10) != 0) || (bVar2)) {
        *(undefined4 *)(unaff_ESI + 0xac + iVar1 * 0x10) = 4;
      }
      else {
        iVar7 = *(int *)(unaff_ESI + 0xac + iVar1 * 0x10);
        if ((iVar7 != 5) && (iVar7 != 6)) {
          *(undefined4 *)(unaff_ESI + 0xac + iVar1 * 0x10) = 1;
          ExceptionList = local_14;
          return 0;
        }
      }
      ExceptionList = local_14;
      return 0;
    }
  } while( true );
}

