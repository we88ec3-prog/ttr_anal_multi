
void FUN_0070f2b0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  int local_28;
  
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = *(int *)(in_ECX + 4);
  piVar2 = *(int **)(in_ECX + 0x30);
  iVar3 = *(int *)(in_ECX + 0x10);
  if (iVar3 == 0x28) {
    if (iVar1 != *(int *)(in_ECX + 8)) {
                    /* WARNING: Subroutine does not return */
      FUN_006ff130();
    }
    FUN_00700740();
    if (*(int *)(in_ECX + 0x10) == 0x29) {
      local_28 = 0;
    }
    else {
      FUN_0070f1c0();
      FUN_007121b0(0xffffffff);
    }
    FUN_0070d8b0();
  }
  else if (iVar3 == 0x7b) {
    FUN_0070e950();
  }
  else {
    if (iVar3 != 0x11e) {
                    /* WARNING: Subroutine does not return */
      FUN_006ff130();
    }
    FUN_0070d9d0();
    FUN_00700740();
  }
  iVar3 = param_1[2];
  if ((local_28 == 0xd) || (local_28 == 0xe)) {
    iVar5 = -1;
  }
  else {
    if (local_28 != 0) {
      FUN_00712630();
    }
    iVar5 = (piVar2[9] - iVar3) + -1;
  }
  uVar6 = FUN_00713370((iVar5 + 1) * 0x800000 | iVar3 << 6 | 0x801c,*(undefined4 *)(piVar2[3] + 8));
  *param_1 = 0xd;
  param_1[2] = uVar6;
  param_1[4] = 0xffffffff;
  param_1[5] = 0xffffffff;
  *(int *)(*(int *)(*piVar2 + 0x14) + -4 + piVar2[6] * 4) = iVar1;
  piVar2[9] = iVar3 + 1;
  __security_check_cookie(uVar4 ^ (uint)&stack0xfffffffc);
  return;
}

