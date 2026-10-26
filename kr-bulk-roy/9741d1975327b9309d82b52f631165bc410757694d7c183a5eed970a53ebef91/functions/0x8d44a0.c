
void FUN_008d44a0(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  int iVar7;
  int unaff_ESI;
  uint uVar8;
  uint local_34;
  int local_1c [5];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar1 = *(undefined4 *)(in_ECX + 100);
  local_1c[0] = FUN_008d3f00();
  if ((local_1c[0] != 0) || (local_1c[0] = FUN_008babe0(), local_1c[0] != 0)) {
LAB_008d4650:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  uVar2 = FUN_008b9a00();
  uVar3 = uVar2 >> 2 & 1;
  if (uVar3 == 0) {
    uVar4 = FUN_008b9a00();
  }
  else {
    uVar4 = FUN_008b99c0();
  }
  FUN_008baca0();
  if (((((uVar2 & 0xffffff00) != 0) || ((int)*(uint *)(in_ECX + 0x120) < 0)) ||
      (uVar4 != *(uint *)(in_ECX + 0x120))) ||
     (iVar5 = FUN_008bc7d0(uVar1,4,0,uVar4,0,local_1c), local_1c[0] != 0)) goto LAB_008d4650;
  uVar8 = 0;
  if (uVar4 != 0) {
    do {
      if (uVar3 == 1) {
        uVar6 = FUN_008b9c00();
        *(undefined4 *)(iVar5 + uVar8 * 4) = uVar6;
      }
      else {
        uVar6 = FUN_008b9c70();
        *(undefined4 *)(iVar5 + uVar8 * 4) = uVar6;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar4);
    if (local_1c[0] != 0) goto LAB_008d4628;
  }
  uVar8 = 0;
  do {
    if (uVar3 == 1) {
      FUN_008b9c00();
    }
    else {
      FUN_008b9c70();
    }
    if (local_1c[0] != 0) goto LAB_008d4628;
    uVar8 = uVar8 + 1;
  } while (uVar8 < 4);
  uVar3 = 0;
  if (uVar4 != 0) {
    iVar7 = 0;
    do {
      uVar8 = *(uint *)(iVar5 + uVar3 * 4);
      if ((-1 < (int)uVar8) && (uVar8 <= local_34)) {
        *(uint *)(*(int *)(in_ECX + 0x124) + 0xc + iVar7) = *(int *)(unaff_ESI + 8) + uVar8;
      }
      uVar3 = uVar3 + 1;
      iVar7 = iVar7 + 0x10;
    } while (uVar3 < uVar4);
  }
  *(uint *)(in_ECX + 0x134) = uVar2;
LAB_008d4628:
  FUN_008b9f80(uVar1,iVar5);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

