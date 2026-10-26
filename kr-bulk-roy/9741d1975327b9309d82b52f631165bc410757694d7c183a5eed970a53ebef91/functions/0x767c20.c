
/* WARNING: Removing unreachable block (ram,0x00767dd8) */
/* WARNING: Removing unreachable block (ram,0x00767de0) */
/* WARNING: Removing unreachable block (ram,0x00767df6) */
/* WARNING: Removing unreachable block (ram,0x00767e01) */
/* WARNING: Removing unreachable block (ram,0x00767e14) */
/* WARNING: Removing unreachable block (ram,0x00767e21) */
/* WARNING: Removing unreachable block (ram,0x00767e9a) */

uint FUN_00767c20(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  uint uVar6;
  uint uVar7;
  uint local_48;
  int local_44;
  int local_34;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0091ecd8;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffa8;
  uVar7 = *(uint *)(unaff_ESI + 0x14c);
  local_48 = *(uint *)(unaff_ESI + 0x150);
  if ((uVar7 == local_48) && (*(int *)(unaff_ESI + 0x154) == *(int *)(unaff_ESI + 0x158))) {
    return uVar7 & 0xffffff00;
  }
  if ((int)local_48 < (int)uVar7) {
    iVar4 = *(int *)(unaff_ESI + 0x158);
    iVar2 = *(int *)(unaff_ESI + 0x154);
    uVar6 = local_48;
    local_48 = uVar7;
  }
  else {
    iVar4 = *(int *)(unaff_ESI + 0x154);
    iVar2 = *(int *)(unaff_ESI + 0x158);
    uVar6 = uVar7;
  }
  if ((local_48 - uVar6 != 0) || (iVar3 = iVar2, iVar4 < iVar2)) {
    iVar3 = iVar4;
  }
  ExceptionList = &local_14;
  *(int *)(unaff_ESI + 0x140) = iVar3;
  *(uint *)(unaff_ESI + 0x13c) = uVar6;
  iVar3 = (local_48 - uVar6) + 1;
  local_c = 0;
  local_34 = 0;
  uVar7 = uVar6;
  if (0 < iVar3) {
    do {
      if ((uint)(*(int *)(unaff_ESI + 0x114) - *(int *)(unaff_ESI + 0x110) >> 2) <= uVar7) break;
      iVar5 = 0;
      local_44 = 0;
      if (uVar7 == uVar6) {
        local_44 = iVar4;
        if (uVar7 == local_48) {
          iVar5 = iVar2;
          if ((iVar2 <= iVar4) && (local_44 = iVar2, iVar2 < iVar4)) {
            iVar5 = iVar4;
          }
        }
        else {
          iVar5 = *(int *)(*(int *)(*(int *)(unaff_ESI + 0x110) + uVar7 * 4) + 0x10);
        }
      }
      else if (uVar7 == local_48) {
        local_44 = 0;
        iVar5 = iVar2;
      }
      else {
        FUN_004a8680(uVar1);
      }
      if ((uVar7 == uVar6) || (uVar7 == local_48)) {
        FUN_00757e40(iVar5 - local_44,local_44);
      }
      local_34 = local_34 + 1;
      uVar7 = uVar7 + 1;
    } while (local_34 < iVar3);
  }
  FUN_00766390(uVar6,0,0);
  iVar4 = *(int *)(unaff_ESI + 0x13c);
  if (iVar4 < *(int *)(unaff_ESI + 0x134)) {
    *(int *)(unaff_ESI + 0x134) = iVar4;
  }
  *(int *)(unaff_ESI + 0x14c) = iVar4;
  *(int *)(unaff_ESI + 0x150) = iVar4;
  *(undefined4 *)(unaff_ESI + 0x154) = *(undefined4 *)(unaff_ESI + 0x140);
  *(undefined4 *)(unaff_ESI + 0x158) = *(undefined4 *)(unaff_ESI + 0x140);
  ExceptionList = local_14;
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}

