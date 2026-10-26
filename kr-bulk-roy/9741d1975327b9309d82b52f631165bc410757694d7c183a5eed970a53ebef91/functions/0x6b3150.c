
void FUN_006b3150(int param_1)

{
  int *piVar1;
  short sVar2;
  int *piVar3;
  code *pcVar4;
  undefined4 *puVar5;
  short *psVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  int in_ECX;
  int local_70;
  int local_6c;
  uint local_68;
  undefined4 local_58;
  uint local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092c302;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fe17b8 & 1) == 0) {
    DAT_00fe17b8 = DAT_00fe17b8 | 1;
    local_8 = 0;
    FUN_0050caf0(local_14);
    _atexit((_func_4879 *)&LAB_00bce7e0);
  }
  local_8 = 0xffffffff;
  local_70 = param_1;
  FUN_005366c0(&local_70);
  if ((local_6c == DAT_00fe17e4) || (local_6c == -0x10)) {
    iVar8 = *(int *)(in_ECX + 0x8c);
    if ((*(char *)(iVar8 + 0xa4) != '\0') &&
       ((*(int **)(iVar8 + 0x94) != (int *)0x0 &&
        (iVar9 = (**(code **)(**(int **)(iVar8 + 0x94) + 4))(), iVar9 == 0xbf6b)))) {
      iVar8 = *(int *)(iVar8 + 0x94);
      iVar9 = *(int *)(iVar8 + 0x10);
      if (iVar9 != 0) {
        piVar3 = *(int **)(iVar9 + 8);
        if (piVar3 != (int *)0x0) {
          piVar1 = piVar3 + 0x27;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar3 + 0x28))();
          }
        }
        *(undefined4 *)(iVar8 + 0x10) = 0;
      }
    }
    FUN_00757710();
    FUN_00757710();
    FUN_00757710();
  }
  else {
    iVar8 = *(int *)(local_6c + 0x28);
    if (*(uint *)(iVar8 + 0x18) < 8) {
      psVar6 = (short *)(iVar8 + 4);
    }
    else {
      psVar6 = *(short **)(iVar8 + 4);
    }
    local_4c = local_4c & 0xffff0000;
    local_38 = 7;
    local_3c = 0;
    psVar7 = psVar6;
    do {
      sVar2 = *psVar7;
      psVar7 = psVar7 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar6,(int)psVar7 - (int)(psVar6 + 1) >> 1);
    local_8._1_3_ = 0;
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 2;
      local_8._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8._0_1_ = 1;
    local_6c = 0x153;
    FUN_005740f0(&local_6c);
    if (local_70 == DAT_00fe5ac8) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    puVar5 = (undefined4 *)(local_70 + 0x10);
    if (7 < *(uint *)(local_70 + 0x24)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    psVar6 = (short *)FUN_0040e460(puVar5);
    local_8._0_1_ = 3;
    if (7 < *(uint *)(psVar6 + 10)) {
      psVar6 = *(short **)psVar6;
    }
    local_30 = (uint)local_30._2_2_ << 0x10;
    local_1c = 7;
    local_20 = 0;
    psVar7 = psVar6;
    do {
      sVar2 = *psVar7;
      psVar7 = psVar7 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar6,(int)psVar7 - (int)(psVar6 + 1) >> 1);
    local_8._0_1_ = 5;
    if (7 < local_54) {
      FUN_0089120c(local_68);
    }
    local_54 = 7;
    local_58 = 0;
    local_68 = local_68 & 0xffff0000;
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8._0_1_ = 6;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8._0_1_ = 5;
    }
    local_6c = param_1;
    FUN_0082ef00(&local_6c);
    if (((*(char *)(*(int *)(in_ECX + 0x8c) + 0xa4) != '\0') &&
        (piVar3 = *(int **)(*(int *)(in_ECX + 0x8c) + 0x94), piVar3 != (int *)0x0)) &&
       (iVar8 = (**(code **)(*piVar3 + 4))(), iVar8 == 0xbf6b)) {
      FUN_0077b200();
    }
    FUN_00757710();
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
  (**(code **)(**(int **)(in_ECX + 0x8c) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x90) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x84) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x88) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

