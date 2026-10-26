
/* WARNING: Removing unreachable block (ram,0x0050c98b) */

void FUN_0050c8d0(void)

{
  uint uVar1;
  uint *puVar2;
  int *piVar3;
  int in_ECX;
  int in_EDX;
  undefined4 extraout_EDX;
  uint uVar4;
  uint in_stack_ffffffd0;
  uint uVar5;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924104;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = (uint *)((uint)*(byte *)(in_ECX + 10) * 0x10 + in_EDX);
  *puVar2 = (uint)*(ushort *)(in_ECX + 6);
  puVar2[1] = (uint)*(ushort *)(in_ECX + 8);
  puVar2[2] = *(uint *)(in_ECX + 2);
  *(undefined1 *)(puVar2 + 3) = 1;
  uVar5 = in_stack_ffffffd0 & 0xffffff00;
  uVar4 = uVar1;
  FUN_0040b310("SET_ON_QUICKSLOT");
  local_8 = 0;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_0080a3a0(uVar4);
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  piVar3 = (int *)FUN_0080ab00(&DAT_00fab028);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x14))();
  }
  uVar5 = uVar5 & 0xffffff00;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 2;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  FUN_0058aad0(0xf4277);
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc,extraout_EDX,uVar5);
  return;
}

