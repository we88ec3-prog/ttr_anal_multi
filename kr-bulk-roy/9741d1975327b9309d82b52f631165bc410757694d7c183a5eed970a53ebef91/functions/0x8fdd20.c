
/* WARNING: Removing unreachable block (ram,0x008fddc0) */

void FUN_008fdd20(void)

{
  uint uVar1;
  int *piVar2;
  int in_ECX;
  undefined4 extraout_EDX;
  uint uVar3;
  uint in_stack_ffffffd0;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00921b1e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar4 = in_stack_ffffffd0 & 0xffffff00;
  uVar3 = uVar1;
  FUN_0040b310("RANDOMCAPSULE_ONGETITEM");
  local_8 = 0;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_0080a3a0(uVar3);
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  piVar2 = (int *)FUN_0080ab00(&DAT_00fab028);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x14))();
  }
  local_8 = 0xffffffff;
  uVar4 = uVar4 & 0xffffff00;
  FUN_008fdc30();
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc,extraout_EDX,uVar4);
  return;
}

