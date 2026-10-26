
void FUN_008cf3c0(void)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  int in_EAX;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int local_2c;
  int local_20;
  int local_1c;
  uint local_8;
  
  iVar9 = in_EAX * 0xcc + 4 + *(int *)(in_ECX + 0x18);
  iVar1 = *(int *)(iVar9 + 0xc4);
  local_1c = *(int *)(iVar9 + 200);
  puVar6 = *(uint **)(in_ECX + 0xc);
  iVar9 = *(int *)(in_ECX + 4);
  do {
    if (iVar9 == 0) {
      return;
    }
    uVar13 = *puVar6;
    uVar11 = uVar13 + puVar6[1] * 0x28;
    uVar10 = 0;
    uVar7 = 0;
    local_8 = 0;
    uVar4 = uVar13;
    if (uVar13 < uVar11) {
      do {
        if ((*(byte *)(uVar4 + 0x10) & 0x20) != 0) {
          if (uVar10 == 0) {
            uVar10 = uVar4;
            local_8 = uVar4;
          }
          uVar7 = uVar7 + 1;
        }
        uVar4 = uVar4 + 0x28;
      } while (uVar4 < uVar11);
      uVar4 = uVar10;
      uVar3 = local_8;
      if (uVar7 < 2) {
        if (uVar7 == 1) {
          lVar2 = (longlong)*(int *)(uVar10 + 0x1c) * (longlong)iVar1;
          lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
          local_1c = *(int *)(uVar10 + 0x24) -
                     (((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000);
        }
        for (; uVar13 < uVar11; uVar13 = uVar13 + 0x28) {
          if (uVar13 != uVar10) {
            lVar2 = (longlong)*(int *)(uVar13 + 0x1c) * (longlong)iVar1;
            lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
            *(uint *)(uVar13 + 0x24) =
                 ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000 + local_1c;
          }
        }
      }
      else {
        do {
          do {
            local_8 = uVar3;
            uVar11 = uVar4;
            uVar4 = *(uint *)(uVar11 + 4);
            if (uVar4 == uVar10) goto LAB_008cf607;
            uVar3 = uVar4;
          } while ((*(byte *)(uVar4 + 0x10) & 0x20) != 0);
          do {
            uVar4 = *(uint *)(uVar4 + 4);
          } while ((*(byte *)(uVar4 + 0x10) & 0x20) == 0);
          iVar5 = *(int *)(uVar11 + 0x1c);
          local_20 = *(int *)(uVar4 + 0x1c);
          if (local_20 < iVar5) {
            iVar14 = *(int *)(uVar4 + 0x24);
            iVar12 = *(int *)(uVar11 + 0x24);
            iVar8 = iVar5 - local_20;
          }
          else {
            iVar14 = *(int *)(uVar11 + 0x24);
            iVar12 = *(int *)(uVar4 + 0x24);
            iVar8 = local_20 - iVar5;
            local_20 = iVar5;
          }
          local_2c = 0x10000;
          if (0 < iVar8) {
            local_2c = FUN_008b7f40(iVar12 - iVar14,iVar8);
          }
          local_8 = *(uint *)(local_8 + 4);
          do {
            iVar5 = *(int *)(local_8 + 0x1c) - local_20;
            if (iVar5 < 1) {
              lVar2 = (longlong)iVar5 * (longlong)iVar1 +
                      (ulonglong)((int)((longlong)iVar5 * (longlong)iVar1 >> 0x3f) + 0x8000);
              iVar5 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
            }
            else if (iVar5 < iVar8) {
              lVar2 = (longlong)iVar5 * (longlong)local_2c +
                      (ulonglong)((int)((longlong)iVar5 * (longlong)local_2c >> 0x3f) + 0x8000);
              iVar5 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
            }
            else {
              lVar2 = (longlong)(iVar5 - iVar8) * (longlong)iVar1;
              lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
              iVar5 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000 +
                      (iVar12 - iVar14);
            }
            *(int *)(local_8 + 0x24) = iVar5 + iVar14;
            local_8 = *(uint *)(local_8 + 4);
          } while (local_8 != uVar4);
          uVar3 = uVar4;
        } while (uVar4 != uVar10);
      }
    }
LAB_008cf607:
    iVar9 = iVar9 + -1;
    puVar6 = puVar6 + 2;
  } while( true );
}

