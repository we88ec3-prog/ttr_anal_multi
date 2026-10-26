
/* WARNING: Removing unreachable block (ram,0x005fb2dc) */

void FUN_005fb0e0(void)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int *in_ECX;
  int local_4c;
  int *local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e016;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar1 = in_ECX + 0x41;
  local_34 = in_ECX;
  iVar5 = (**(code **)(*in_ECX + 0x1ac))(local_14);
  FUN_005f7e40(iVar5 + 1);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  iVar5 = *piVar1;
  FUN_005fe740();
  FUN_005a9f40(iVar5);
  iVar5 = *piVar1;
  FUN_005fe820();
  FUN_005a9f40(iVar5 + 4);
  piVar4 = local_34;
  FUN_0040b670(local_34);
  FUN_005f5ca0(1);
  piVar2 = *(int **)*piVar1;
  local_34 = (int *)(**(code **)(*piVar2 + 0x1a4))();
  (**(code **)(*piVar2 + 0x1a0))();
  uVar6 = FUN_0040e460(&DAT_00bf2bf8);
  local_8._0_1_ = 2;
  FUN_00757800(uVar6);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  *(int **)(*(int *)*piVar1 + 0x110) = piVar4 + 0x4a;
  if (*(int *)(piVar4[0x3e] + 0xd8) != 0) {
    FUN_0040acb0(*(int *)(piVar4[0x3e] + 0xd8),0,*(undefined4 *)*piVar1);
  }
  FUN_005f5ca0(2);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 3;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  local_34 = (int *)0x3;
  FUN_005740f0(&local_34);
  if (local_4c == DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  FUN_00757710();
  if (*(int *)(piVar4[0x3e] + 0xd8) != 0) {
    FUN_0040acb0(*(int *)(piVar4[0x3e] + 0xd8),1,*(undefined4 *)(*piVar1 + 4));
  }
  FUN_00749920(piVar4[0x3e]);
  FUN_0040b5b0(0);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

