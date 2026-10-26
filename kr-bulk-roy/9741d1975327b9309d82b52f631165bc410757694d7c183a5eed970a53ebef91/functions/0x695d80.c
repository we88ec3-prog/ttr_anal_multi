
/* WARNING: Removing unreachable block (ram,0x00695e0e) */

void FUN_00695d80(void)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912470;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  (**(code **)(**(int **)(in_ECX + 0xec) + 0x74))
            (*(undefined4 *)(in_ECX + 0xf0),DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  iVar1 = *(int *)(in_ECX + 0xf4);
  if ((iVar1 == 0x16) || (iVar1 == 0x24)) {
    FUN_004095e0(iVar1);
  }
  ExceptionList = local_10;
  return;
}

