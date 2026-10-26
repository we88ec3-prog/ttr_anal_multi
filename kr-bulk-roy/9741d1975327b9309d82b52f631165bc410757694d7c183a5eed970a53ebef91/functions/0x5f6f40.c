
/* WARNING: Removing unreachable block (ram,0x005f7017) */

void FUN_005f6f40(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009211e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = 0;
  iVar1 = (**(code **)(*in_ECX + 0x1ac))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (0 < iVar1) {
    do {
      FUN_0040aa10(in_ECX[0x3e]);
      *(undefined4 *)(in_ECX[0x41] + iVar2 * 4) = 0;
      iVar2 = iVar2 + 1;
      iVar1 = (**(code **)(*in_ECX + 0x1ac))();
    } while (iVar2 < iVar1);
  }
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0x5f);
  FUN_004095e0(0x60);
  FUN_004095e0(0x61);
  FUN_004095e0(0x62);
  FUN_004095e0(99);
  FUN_004095e0(100);
  ExceptionList = local_10;
  return;
}

