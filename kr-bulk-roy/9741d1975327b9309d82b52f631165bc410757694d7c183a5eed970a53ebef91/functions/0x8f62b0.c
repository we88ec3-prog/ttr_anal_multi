
void FUN_008f62b0(int param_1)

{
  int *piVar1;
  longlong lVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  int *piVar8;
  uint local_1c;
  int local_14;
  
  if (in_EAX == 0) {
    iVar3 = *(int *)(in_ECX + 4);
    iVar7 = *(int *)(in_ECX + 0xc);
  }
  else {
    iVar3 = *(int *)(in_ECX + 8);
    iVar7 = *(int *)(in_ECX + 0x10);
  }
  piVar1 = (int *)(in_EAX * 0x42c + 0x2c + param_1);
  if ((piVar1[0x109] != iVar3) || (piVar1[0x10a] != iVar7)) {
    piVar1[0x109] = iVar3;
    piVar1[0x10a] = iVar7;
    *piVar1 = iVar3;
    piVar1[1] = iVar7;
    local_1c = 0;
    if (piVar1[0x36] != 0) {
      piVar8 = piVar1 + 0x3a;
      do {
        lVar2 = (longlong)piVar8[-3] * (longlong)iVar3 +
                (ulonglong)((int)((longlong)piVar8[-3] * (longlong)iVar3 >> 0x3f) + 0x8000);
        iVar4 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000 + iVar7;
        piVar8[-2] = iVar4;
        piVar8[-1] = iVar4;
        lVar2 = (longlong)*piVar8 * (longlong)iVar3 +
                (ulonglong)((int)((longlong)*piVar8 * (longlong)iVar3 >> 0x3f) + 0x8000);
        piVar8[3] = piVar8[3] & 0xfffffffe;
        iVar4 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000 + iVar7;
        piVar8[1] = iVar4;
        piVar8[2] = iVar4;
        lVar2 = (longlong)(piVar8[-3] - *piVar8) * (longlong)iVar3;
        lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
        if (((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000 + 0x30 < 0x61) {
          uVar5 = piVar8[-2] + 0x20U & 0xffffffc0;
          piVar8[-1] = uVar5;
          iVar4 = FUN_008b7f40(uVar5,iVar3);
          iVar4 = iVar4 - *piVar8;
          local_14 = iVar4;
          if (iVar4 < 0) {
            local_14 = -iVar4;
          }
          lVar2 = (longlong)local_14 * (longlong)iVar3 +
                  (ulonglong)((int)((longlong)local_14 * (longlong)iVar3 >> 0x3f) + 0x8000);
          iVar6 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
          if (iVar6 < 0x20) {
            uVar5 = 0;
          }
          else {
            uVar5 = iVar6 + 0x20U & 0xffffffc0;
          }
          if (iVar4 < 0) {
            uVar5 = -uVar5;
          }
          piVar8[3] = piVar8[3] | 1;
          piVar8[2] = piVar8[-1] - uVar5;
        }
        local_1c = local_1c + 1;
        piVar8 = piVar8 + 7;
      } while (local_1c < (uint)piVar1[0x36]);
    }
  }
  return;
}

