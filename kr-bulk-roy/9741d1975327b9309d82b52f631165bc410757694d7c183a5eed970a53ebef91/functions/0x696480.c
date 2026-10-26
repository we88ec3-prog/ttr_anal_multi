
/* WARNING: Removing unreachable block (ram,0x006967c4) */

void FUN_00696480(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int in_ECX;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093842a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  piVar1 = (int *)(in_ECX + 0x84);
  FUN_006968a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(piVar1);
  FUN_00696980();
  FUN_005a9f40(in_ECX + 0x88);
  *(undefined4 *)(*piVar1 + 0xf4) = 0x16;
  (**(code **)(*(int *)*piVar1 + 0xb4))(0xd6);
  *(undefined4 *)(*(int *)(in_ECX + 0x88) + 0xf4) = 0x24;
  (**(code **)(**(int **)(in_ECX + 0x88) + 0xb4))(0xda);
  FUN_0040b670(in_ECX);
  *(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(*(int *)(in_ECX + 0x84) + 0xf0);
  *(undefined4 *)(in_ECX + 0x90) = *(undefined4 *)(*(int *)(in_ECX + 0x88) + 0xf0);
  iVar2 = *(int *)(*(int *)(in_ECX + 0x94) + 0xd8);
  if (iVar2 != 0) {
    FUN_0040acb0(iVar2,0,*(int *)(in_ECX + 0x84));
  }
  iVar2 = *(int *)(*(int *)(in_ECX + 0x94) + 0xd8);
  if (iVar2 != 0) {
    FUN_0040acb0(iVar2,1,*(undefined4 *)(in_ECX + 0x88));
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  local_14 = 0x237;
  FUN_005740f0(&local_14);
  if (local_18 != DAT_00fe5ac8) {
    if (*(int *)(*(int *)(in_ECX + 0x94) + 0xd8) != 0) {
      local_18 = 0;
      FUN_0082ef00(&local_18);
    }
    FUN_00757710();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 3;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    local_18 = 0x23c;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5ac8) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    if (*(int *)(*(int *)(in_ECX + 0x94) + 0xd8) != 0) {
      local_18 = 1;
      FUN_0082ef00(&local_18);
    }
    FUN_00757710();
    (**(code **)(**(int **)(in_ECX + 0x94) + 0xd8))(*(undefined4 *)(in_ECX + 0x80));
    FUN_00749920(*(undefined4 *)(in_ECX + 0x94));
    (**(code **)(**(int **)(in_ECX + 0x94) + 200))();
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xb4))(0xda);
    iVar2 = *(int *)(in_ECX + 0x8c);
    iVar3 = *(int *)(iVar2 + 8);
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -iVar3;
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -iVar3;
    iVar3 = *(int *)(iVar2 + 0xc);
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + -iVar3;
    *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + -iVar3;
    FUN_00746f70();
    if ((DAT_00fc7f1c & 1) == 0) {
      DAT_00fc7f1c = DAT_00fc7f1c | 1;
      local_8._0_1_ = 4;
      FUN_0053c300();
      _atexit(FUN_00bce1d0);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    FUN_0040b5b0(DAT_00fcdddc != 0);
    ExceptionList = local_10;
    return;
  }
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}

