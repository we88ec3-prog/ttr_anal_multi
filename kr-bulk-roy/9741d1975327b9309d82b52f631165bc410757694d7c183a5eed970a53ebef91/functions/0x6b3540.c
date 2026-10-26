
void FUN_006b3540(int param_1)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092c298;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar4;
  if ((DAT_00fb93b8 & 1) == 0) {
    DAT_00fb93b8 = DAT_00fb93b8 | 1;
    local_8 = 0;
    FUN_00823720(uVar4);
    _atexit(FUN_00bcd5a0);
  }
  local_8 = 0xffffffff;
  local_58 = param_1;
  FUN_008438c0(&local_58);
  if ((local_50 == DAT_00fb93c0) || (local_54 = *(int *)(local_50 + 0x10) + 8, local_54 == 0)) {
    iVar5 = *(int *)(in_ECX + 0x8c);
    if ((*(char *)(iVar5 + 0xa4) != '\0') &&
       ((*(int **)(iVar5 + 0x94) != (int *)0x0 &&
        (iVar6 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))(), iVar6 == 0xbf6b)))) {
      iVar5 = *(int *)(iVar5 + 0x94);
      iVar6 = *(int *)(iVar5 + 0x10);
      if (iVar6 != 0) {
        piVar2 = *(int **)(iVar6 + 8);
        if (piVar2 != (int *)0x0) {
          piVar1 = piVar2 + 0x27;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar2 + 0x28))();
          }
        }
        *(undefined4 *)(iVar5 + 0x10) = 0;
      }
    }
    FUN_00757710();
    FUN_00757710();
  }
  else {
    if ((DAT_00fb93b8 & 1) == 0) {
      DAT_00fb93b8 = DAT_00fb93b8 | 1;
      local_8 = 1;
      FUN_00823720(uVar4);
      _atexit(FUN_00bcd5a0);
      local_8 = 0xffffffff;
    }
    FUN_00823620(param_1);
    local_8._1_3_ = 0;
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 3;
      local_8._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8._0_1_ = 2;
    local_50 = 0x154;
    FUN_005740f0(&local_50);
    if (local_58 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    FUN_00426ec0();
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8._0_1_ = 5;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    local_54 = param_1;
    FUN_0082ef00(&local_54);
    if (((*(char *)(*(int *)(in_ECX + 0x8c) + 0xa4) != '\0') &&
        (piVar2 = *(int **)(*(int *)(in_ECX + 0x8c) + 0x94), piVar2 != (int *)0x0)) &&
       (iVar5 = (**(code **)(*piVar2 + 4))(), iVar5 == 0xbf6b)) {
      FUN_0077b200();
    }
    FUN_00757710();
    FUN_00757710();
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    local_8 = 0xffffffff;
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
    local_38 = 7;
    local_3c = 0;
    local_4c = local_4c & 0xffff0000;
  }
  FUN_00757710();
  (**(code **)(**(int **)(in_ECX + 0x8c) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x90) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x84) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x88) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

