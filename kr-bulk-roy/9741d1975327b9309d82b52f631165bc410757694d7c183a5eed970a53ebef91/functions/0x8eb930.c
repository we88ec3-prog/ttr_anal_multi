
void FUN_008eb930(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  ushort uVar5;
  int *piVar6;
  int in_ECX;
  int iVar7;
  int *piVar8;
  int iVar9;
  int local_54;
  int local_4c [17];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _memset(local_4c,0,0x44);
  bVar1 = false;
  bVar2 = false;
  bVar3 = false;
  uVar5 = 0;
  bVar4 = false;
  if (*(short *)(in_ECX + 0x98) != 0) {
    do {
      bVar1 = bVar4;
      iVar7 = *(int *)((uint)uVar5 * 0x10 + *(int *)(in_ECX + 0x9c));
      iVar9 = 0;
      local_54 = 0;
      if (iVar7 == 0x63767420) {
        iVar7 = 0;
        bVar1 = true;
LAB_008eb9bc:
        piVar6 = (int *)(&UNK_00beaba8 + iVar7 * 8);
        do {
          if (*(int *)(*(int *)(in_ECX + 0x9c) + 0xc + (uint)uVar5 * 0x10) == piVar6[1]) {
            if (local_54 == 0) {
              local_54 = FUN_008eb8e0();
            }
            if (*piVar6 == local_54) {
              local_4c[iVar9] = local_4c[iVar9] + 1;
            }
            if (local_4c[iVar9] == 3) goto LAB_008eba6d;
          }
          iVar9 = iVar9 + 1;
          piVar6 = piVar6 + 6;
        } while (iVar9 < 0x11);
      }
      else {
        if (iVar7 == 0x6670676d) {
          iVar7 = 1;
          bVar2 = true;
          goto LAB_008eb9bc;
        }
        if (iVar7 == 0x70726570) {
          iVar7 = 2;
          bVar3 = true;
          goto LAB_008eb9bc;
        }
      }
      uVar5 = uVar5 + 1;
      bVar4 = bVar1;
    } while (uVar5 < *(ushort *)(in_ECX + 0x98));
  }
  piVar6 = local_4c;
  piVar8 = &DAT_00beabb4;
  while( true ) {
    if ((!bVar1) && (piVar8[-2] == 0)) {
      *piVar6 = *piVar6 + 1;
    }
    if ((!bVar2) && (*piVar8 == 0)) {
      *piVar6 = *piVar6 + 1;
    }
    if ((!bVar3) && (piVar8[2] == 0)) {
      *piVar6 = *piVar6 + 1;
    }
    if (*piVar6 == 3) break;
    piVar8 = piVar8 + 6;
    piVar6 = piVar6 + 1;
    if (0xbead4b < (int)piVar8) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
LAB_008eba6d:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

