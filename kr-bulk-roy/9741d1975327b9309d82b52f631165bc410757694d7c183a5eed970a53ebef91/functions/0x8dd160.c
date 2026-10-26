
int FUN_008dd160(byte *param_1,int param_2,int *param_3)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  byte *in_EAX;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar8 = 0;
  bVar4 = false;
  bVar2 = false;
  bVar3 = false;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  local_8 = 0;
  iVar7 = 0;
  local_10 = 0;
  local_14 = 0;
  local_c = 0;
  iVar6 = 4;
  while( true ) {
    while( true ) {
      if ((iVar6 != 0) && (in_EAX = in_EAX + 1, param_1 <= in_EAX)) goto LAB_008dd3b5;
      bVar1 = *in_EAX >> ((byte)iVar6 & 0x1f);
      iVar6 = 4 - iVar6;
      uVar5 = bVar1 & 0xf;
      if (uVar5 != 0xe) break;
      bVar4 = true;
    }
    if (9 < uVar5) break;
    if (iVar8 < 0xccccccc) {
      if (((bVar1 & 0xf) != 0) || (iVar8 != 0)) {
        local_14 = local_14 + 1;
        iVar8 = uVar5 + iVar8 * 10;
      }
    }
    else {
      local_10 = local_10 + 1;
    }
  }
  if (uVar5 == 10) {
    while( true ) {
      if ((iVar6 != 0) && (in_EAX = in_EAX + 1, param_1 <= in_EAX)) goto LAB_008dd3b5;
      bVar1 = *in_EAX >> ((byte)iVar6 & 0x1f);
      iVar6 = 4 - iVar6;
      uVar5 = bVar1 & 0xf;
      if (9 < uVar5) break;
      if (((bVar1 & 0xf) == 0) && (iVar8 == 0)) {
        local_10 = local_10 + -1;
      }
      else if ((iVar8 < 0xccccccc) && (local_c < 9)) {
        local_c = local_c + 1;
        iVar8 = uVar5 + iVar8 * 10;
      }
    }
  }
  if (uVar5 == 0xc) {
    bVar2 = true;
LAB_008dd250:
    while( true ) {
      if ((iVar6 != 0) && (in_EAX = in_EAX + 1, param_1 <= in_EAX)) goto LAB_008dd3b5;
      bVar1 = (byte)iVar6;
      iVar6 = 4 - iVar6;
      uVar5 = *in_EAX >> (bVar1 & 0x1f) & 0xf;
      if (9 < uVar5) break;
      if (iVar7 < 0x3e9) {
        iVar7 = uVar5 + iVar7 * 10;
      }
      else {
        bVar3 = true;
      }
    }
    if (bVar2) {
      iVar7 = -iVar7;
    }
  }
  else if (uVar5 == 0xb) goto LAB_008dd250;
  if (iVar8 == 0) goto LAB_008dd44a;
  if (bVar3) {
    if (!bVar2) {
      local_8 = 0x7fffffff;
      goto LAB_008dd44a;
    }
  }
  else {
    iVar7 = iVar7 + local_10 + param_2;
    if (param_3 != (int *)0x0) {
      local_c = local_c + local_14;
      iVar7 = iVar7 + local_14;
      if (5 < local_c) {
        if (iVar8 / (int)(&PTR_FUN_00be9344)[local_c] < 0x8000) {
          local_8 = FUN_008b7f40(iVar8,(&PTR_FUN_00be9344)[local_c]);
          *param_3 = iVar7 + -5;
        }
        else {
          local_8 = FUN_008b7f40(iVar8,*(undefined4 *)(&DAT_00be9348 + local_c * 4));
          *param_3 = iVar7 + -4;
        }
        goto LAB_008dd44a;
      }
      if (0x7fff < iVar8) {
        local_8 = FUN_008b7f40(iVar8,10);
        *param_3 = (iVar7 - local_c) + 1;
        goto LAB_008dd44a;
      }
      if (iVar7 < 1) {
LAB_008dd346:
        iVar7 = iVar7 - local_c;
      }
      else {
        iVar6 = iVar7;
        if (4 < iVar7) {
          iVar6 = 5;
        }
        if (iVar6 - local_c < 1) goto LAB_008dd346;
        iVar8 = iVar8 * *(int *)(&DAT_00be9358 + (iVar6 - local_c) * 4);
        iVar7 = iVar7 - iVar6;
        if (0x7fff < iVar8) {
          local_8 = (iVar8 / 10) * 0x10000;
          *param_3 = iVar7 + 1;
          goto LAB_008dd44a;
        }
      }
      local_8 = iVar8 << 0x10;
      *param_3 = iVar7;
      goto LAB_008dd44a;
    }
    local_14 = local_14 + iVar7;
    local_c = local_c - iVar7;
    if (5 < local_14) {
LAB_008dd43b:
      local_8 = 0x7fffffff;
      goto LAB_008dd44a;
    }
    if (-6 < local_14) {
      if (local_14 < 0) {
        iVar8 = iVar8 / *(int *)(&DAT_00be9358 + local_14 * -4);
        local_c = local_c + local_14;
      }
      if (local_c == 10) {
        iVar8 = iVar8 / 10;
        local_c = 9;
      }
      else if (local_c < 1) {
        if (*(int *)(&DAT_00be9358 + local_c * -4) * iVar8 < 0x8000) {
          local_8 = *(int *)(&DAT_00be9358 + local_c * -4) * iVar8 * 0x10000;
          goto LAB_008dd44a;
        }
        goto LAB_008dd43b;
      }
      if (iVar8 / *(int *)(&DAT_00be9358 + local_c * 4) < 0x8000) {
        local_8 = FUN_008b7f40(iVar8,*(int *)(&DAT_00be9358 + local_c * 4));
      }
      goto LAB_008dd44a;
    }
  }
LAB_008dd3b5:
  local_8 = 0;
LAB_008dd44a:
  if (bVar4) {
    local_8 = -local_8;
  }
  return local_8;
}

