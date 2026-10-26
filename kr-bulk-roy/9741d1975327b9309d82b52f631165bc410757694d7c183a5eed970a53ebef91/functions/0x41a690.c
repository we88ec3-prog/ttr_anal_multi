
/* WARNING: Removing unreachable block (ram,0x0041a76d) */

void FUN_0041a690(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00927dc0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  piVar1 = (int *)(in_ECX + 0xf8);
  FUN_0041bb90(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(piVar1);
  FUN_0040b670(*(undefined4 *)(in_ECX + 0x80));
  *(int *)(*piVar1 + 0xac) = in_ECX;
  (**(code **)(*(int *)*piVar1 + 0xb4))(0x6a);
  iVar2 = *piVar1;
  *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) | 0x40;
  if ((*(uint *)(iVar2 + 0x28) & 0x10) != 0) {
    *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) ^ 0x10;
  }
  if ((*(uint *)(iVar2 + 0x28) & 0x20) != 0) {
    *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) ^ 0x20;
  }
  if (*(int *)(*piVar1 + 0x60) != 0) {
    FUN_00749f40(*piVar1);
  }
  (**(code **)(*(int *)*piVar1 + 0xd0))();
  ExceptionList = local_10;
  return;
}

