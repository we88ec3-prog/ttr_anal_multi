
/* WARNING: Removing unreachable block (ram,0x00862b3d) */
/* WARNING: Removing unreachable block (ram,0x00862b18) */

undefined4 FUN_00862aa0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00906a08;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  local_c = 0;
  FUN_004e7330(10);
  iVar2 = FUN_00862820(uVar1);
  if ((iVar2 != 0) && (iVar2 = (**(code **)(*param_1 + 0x158))(param_1,0,param_3), -1 < iVar2)) {
    ExceptionList = local_14;
    return 1;
  }
  ExceptionList = local_14;
  return 0;
}

