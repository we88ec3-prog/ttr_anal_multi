
/* WARNING: Removing unreachable block (ram,0x00692789) */

void FUN_006926b0(void)

{
  int in_ECX;
  int *piVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009211e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  piVar1 = (int *)(in_ECX + 0x8c);
  FUN_00692a30(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(piVar1);
  FUN_00692b10();
  FUN_005a9f40(in_ECX + 0x90);
  FUN_00692bf0();
  FUN_005a9f40(in_ECX + 0x94);
  FUN_0040b670(in_ECX);
  iVar2 = 3;
  do {
    (**(code **)(*(int *)piVar1[-3] + 0x70))(*piVar1);
    *(undefined4 *)(*piVar1 + 0xb0) = 0;
    (**(code **)(*(int *)*piVar1 + 0xd0))();
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  ExceptionList = local_10;
  return;
}

