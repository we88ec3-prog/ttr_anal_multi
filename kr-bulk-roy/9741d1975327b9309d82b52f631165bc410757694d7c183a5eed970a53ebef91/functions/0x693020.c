
/* WARNING: Removing unreachable block (ram,0x0069310e) */

void FUN_00693020(void)

{
  int in_ECX;
  int iVar1;
  int *piVar2;
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
  piVar2 = (int *)(in_ECX + 0x90);
  FUN_006933a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(piVar2);
  FUN_00693480();
  FUN_005a9f40(in_ECX + 0x94);
  FUN_00693560();
  FUN_005a9f40(in_ECX + 0x98);
  FUN_00693640();
  FUN_005a9f40(in_ECX + 0x9c);
  FUN_0040b670(in_ECX);
  iVar1 = 4;
  do {
    (**(code **)(*(int *)piVar2[-4] + 0x70))(*piVar2);
    *(undefined4 *)(*piVar2 + 0xb0) = 1;
    FUN_00694000();
    (**(code **)(*(int *)*piVar2 + 0xd0))();
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  ExceptionList = local_10;
  return;
}

