
void FUN_0057d5d0(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int in_ECX;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x70) != 0) goto LAB_0057d80c;
  FUN_0057a1e0();
  FUN_00579ec0(param_1);
  *(undefined4 *)(in_ECX + 0xe4) = 0x442f0000;
  *(undefined4 *)(in_ECX + 0xe8) = 0x441b0000;
  *(undefined4 *)(in_ECX + 0xec) = 0x40800000;
  *(undefined4 *)(in_ECX + 0xf0) = 0x3f99999a;
  *(undefined4 *)(in_ECX + 0xf4) = 0;
  *(undefined4 *)(in_ECX + 0x110) = 0;
  piVar2 = *(int **)(in_ECX + 0x104);
  piVar3 = (int *)*piVar2;
  piVar1 = (int *)(in_ECX + 0x104);
  *piVar2 = (int)piVar2;
  *(int *)(*piVar1 + 4) = *piVar1;
  *(undefined4 *)(in_ECX + 0x108) = 0;
  if (piVar3 != (int *)*piVar1) {
    do {
      piVar2 = (int *)*piVar3;
      FUN_0089120c(piVar3);
      piVar3 = piVar2;
    } while (piVar2 != (int *)*piVar1);
  }
  local_14 = FUN_0089289d();
  local_14 = local_14 % 3;
  local_10 = FUN_0089289d();
  local_10 = local_10 % 3;
  local_c = FUN_0089289d();
  local_c = local_c % 3;
  *(float *)(in_ECX + 0x18) = (float)local_14 * 64.0 + 49.0;
  *(float *)(in_ECX + 0x34) = (float)local_10 * 64.0 + 49.0;
  *(undefined4 *)(in_ECX + 0x1c) = 0x41a00000;
  *(undefined4 *)(in_ECX + 0x38) = 0x41a00000;
  *(undefined4 *)(in_ECX + 0x54) = 0x41a00000;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(float *)(in_ECX + 0x50) = (float)local_c * 64.0 + 49.0;
  *(undefined4 *)(in_ECX + 0xf4) = 0;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  iVar4 = FUN_0089289d();
  iVar4 = iVar4 % 3;
  if (iVar4 == 2) {
    local_18 = 1;
  }
  else {
    local_18 = iVar4 + 1;
  }
  iVar5 = FUN_0089289d();
  *(int *)(in_ECX + 0x14) = iVar4;
  *(int *)(in_ECX + 0x30) = local_18;
  *(int *)(in_ECX + 0x4c) = iVar5 % 3;
  piVar2 = (int *)*piVar1;
  piVar3 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(int *)(*piVar1 + 4) = *piVar1;
  *(undefined4 *)(in_ECX + 0x108) = 0;
  if (piVar3 != (int *)*piVar1) {
    do {
      piVar2 = (int *)*piVar3;
      FUN_0089120c(piVar3);
      piVar3 = piVar2;
    } while (piVar2 != (int *)*piVar1);
  }
  uVar6 = FUN_0089289d();
  uVar6 = uVar6 & 0x80000001;
  if ((int)uVar6 < 0) {
    uVar6 = (uVar6 - 1 | 0xfffffffe) + 1;
  }
  if (uVar6 == 0) {
    local_18 = 5;
    FUN_0074a200();
    local_18 = 6;
LAB_0057d7b8:
    FUN_0074a200();
    local_18 = 7;
    FUN_0074a200();
  }
  else if (uVar6 == 1) {
    local_18 = 6;
    FUN_0074a200();
    local_18 = 5;
    goto LAB_0057d7b8;
  }
  iVar4 = *piVar1;
  local_18 = 8;
  iVar5 = FUN_0074d700(iVar4,*(undefined4 *)(iVar4 + 4),&local_18);
  if (*(int *)(in_ECX + 0x108) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(in_ECX + 0x108) = *(int *)(in_ECX + 0x108) + 1;
  *(int *)(iVar4 + 4) = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
LAB_0057d80c:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

