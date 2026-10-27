
/* WARNING: Removing unreachable block (ram,0x004b3eb1) */

void FUN_004b3da0(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00947c14;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = FUN_00404ba0(uVar2);
  if (((*(byte *)(param_1 + 2) < 10) &&
      (iVar3 = *(int *)(iVar3 + 0x6924) + (uint)*(byte *)(param_1 + 2) * 0x210,
      *(int *)(iVar3 + 0x5c) != 0)) && (iVar3 != 0)) {
    FUN_004d41a0();
  }
  iVar3 = FUN_0040f060();
  uVar1 = *(undefined4 *)(iVar3 + 0x8c);
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 0;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_8 = 0xffffffff;
  }
  FUN_00500240(&DAT_00fab2a0,uVar1);
  FUN_0040b310("LEVELUP_TALK");
  local_8 = 1;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  piVar4 = (int *)FUN_0080ab00(&DAT_00fab028);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x14))();
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

