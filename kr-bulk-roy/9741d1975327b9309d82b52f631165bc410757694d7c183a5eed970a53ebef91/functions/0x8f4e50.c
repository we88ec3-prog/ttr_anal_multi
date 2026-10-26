
void FUN_008f4e50(int param_1,int param_2)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint local_18;
  int local_c;
  int local_8;
  
  if (param_2 == 0) {
    local_8 = *(int *)(param_1 + 4);
    local_c = *(int *)(param_1 + 0xc);
  }
  else {
    local_c = *(int *)(param_1 + 0x10);
    local_8 = *(int *)(param_1 + 8);
  }
  piVar1 = (int *)(param_2 * 0x42c + 0x2c + in_ECX);
  if ((piVar1[0x109] != local_8) || (piVar1[0x10a] != local_c)) {
    piVar1[0x109] = local_8;
    piVar1[0x10a] = local_c;
    uVar3 = 0;
    if (*(uint *)(in_ECX + 0x530) != 0) {
      pbVar7 = (byte *)(in_ECX + 0x54c);
      do {
        if ((*pbVar7 & 4) != 0) {
          iVar5 = in_ECX + 0x534 + uVar3 * 0x1c;
          if (iVar5 != 0) {
            lVar2 = (longlong)*(int *)(iVar5 + 0xc) * (longlong)*(int *)(param_1 + 8);
            lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
            uVar4 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
            uVar3 = *(uint *)(*(int *)(in_ECX + 0x24) + 0xc);
            uVar8 = (uint)*(ushort *)(*(int *)(*(int *)(in_ECX + 4) + 0x58) + 0xc);
            iVar5 = 0x28;
            if (((uVar3 != 0) && (uVar8 <= uVar3)) && (5 < uVar8)) {
              iVar5 = 0x34;
            }
            uVar3 = uVar4 + iVar5 & 0xffffffc0;
            if ((uVar4 != uVar3) && (param_2 == 1)) {
              local_8 = FUN_008b7dc0(local_8,uVar3,uVar4);
            }
          }
          break;
        }
        uVar3 = uVar3 + 1;
        pbVar7 = pbVar7 + 0x1c;
      } while (uVar3 < *(uint *)(in_ECX + 0x530));
    }
    *piVar1 = local_8;
    piVar1[1] = local_c;
    if (param_2 == 0) {
      *(int *)(in_ECX + 8) = local_8;
      *(int *)(in_ECX + 0x10) = local_c;
    }
    else {
      *(int *)(in_ECX + 0xc) = local_8;
      *(int *)(in_ECX + 0x14) = local_c;
    }
    if (piVar1[2] != 0) {
      piVar10 = piVar1 + 5;
      uVar3 = 0;
      do {
        lVar2 = (longlong)piVar10[-2] * (longlong)local_8 +
                (ulonglong)((int)((longlong)piVar10[-2] * (longlong)local_8 >> 0x3f) + 0x8000);
        iVar5 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
        piVar10[-1] = iVar5;
        *piVar10 = iVar5;
        uVar3 = uVar3 + 1;
        piVar10 = piVar10 + 3;
      } while (uVar3 < (uint)piVar1[2]);
    }
    lVar2 = (longlong)piVar1[0x34] * (longlong)local_8 +
            (ulonglong)((int)((longlong)piVar1[0x34] * (longlong)local_8 >> 0x3f) + 0x8000);
    *(bool *)(piVar1 + 0x35) =
         (int)(((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000) < 0x28;
    if ((param_2 == 1) && (local_18 = 0, piVar1[0x36] != 0)) {
      piVar10 = piVar1 + 0x3a;
      do {
        lVar2 = (longlong)piVar10[-3] * (longlong)local_8 +
                (ulonglong)((int)((longlong)piVar10[-3] * (longlong)local_8 >> 0x3f) + 0x8000);
        iVar5 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000 + local_c;
        piVar10[-2] = iVar5;
        piVar10[-1] = iVar5;
        lVar2 = (longlong)*piVar10 * (longlong)local_8 +
                (ulonglong)((int)((longlong)*piVar10 * (longlong)local_8 >> 0x3f) + 0x8000);
        piVar10[3] = piVar10[3] & 0xfffffffe;
        iVar5 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000 + local_c;
        piVar10[1] = iVar5;
        piVar10[2] = iVar5;
        lVar2 = (longlong)(piVar10[-3] - *piVar10) * (longlong)local_8;
        lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
        iVar5 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
        if (iVar5 + 0x30U < 0x61) {
          iVar6 = iVar5;
          if (iVar5 < 0) {
            iVar6 = -iVar5;
          }
          iVar9 = 0;
          if (0x1f < iVar6) {
            iVar9 = ((0x2f < iVar6) - 1 & 0xffffffe0) + 0x40;
          }
          if (iVar5 < 0) {
            iVar9 = -iVar9;
          }
          uVar3 = piVar10[-2] + 0x20U & 0xffffffc0;
          piVar10[-1] = uVar3;
          piVar10[3] = piVar10[3] | 1;
          piVar10[2] = uVar3 - iVar9;
        }
        local_18 = local_18 + 1;
        piVar10 = piVar10 + 7;
      } while (local_18 < (uint)piVar1[0x36]);
    }
  }
  return;
}

