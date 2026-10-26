
/* WARNING: Removing unreachable block (ram,0x005a6704) */

void FUN_005a65a0(void)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094a180;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00596010(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_005a6a50();
  FUN_005a9f40((undefined4 *)(in_ECX + 0x140));
  FUN_0059f850();
  FUN_005a9f40(in_ECX + 0x13c);
  FUN_005a6b30();
  FUN_005a9f40(in_ECX + 0x138);
  FUN_005a6c10();
  FUN_005a9f40(in_ECX + 0x134);
  FUN_0040b670(in_ECX);
  (**(code **)(**(int **)(in_ECX + 0x134) + 0xd0))();
  if (*(int *)(in_ECX + 0x144) == 0) {
    (**(code **)(**(int **)(in_ECX + 0x140) + 0xd0))();
    iVar1 = *(int *)(in_ECX + 0x134);
    (**(code **)(**(int **)(iVar1 + 0xb0) + 0x94))(0);
    (**(code **)(**(int **)(iVar1 + 0xb4) + 0x94))(0);
    (**(code **)(**(int **)(iVar1 + 0xb8) + 0x94))(0);
    FUN_005a64b0();
  }
  else {
    iVar1 = *(int *)(in_ECX + 0x134);
    (**(code **)(**(int **)(iVar1 + 0xb0) + 0x94))(1);
    (**(code **)(**(int **)(iVar1 + 0xb4) + 0x94))(1);
    (**(code **)(**(int **)(iVar1 + 0xb8) + 0x94))(1);
  }
  ExceptionList = local_10;
  return;
}

