
/* WARNING: Removing unreachable block (ram,0x005fb3c3) */

void FUN_005fb310(void)

{
  int in_ECX;
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009211e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = 0;
  if (*(int *)(in_ECX + 0x108) - *(int *)(in_ECX + 0x104) >> 2 != 0) {
    do {
      FUN_0040aa10(*(undefined4 *)(in_ECX + 0xf8));
      *(undefined4 *)(*(int *)(in_ECX + 0x104) + uVar1 * 4) = 0;
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(*(int *)(in_ECX + 0x108) - *(int *)(in_ECX + 0x104) >> 2));
  }
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0x66);
  FUN_004095e0(0x67);
  ExceptionList = local_10;
  return;
}

