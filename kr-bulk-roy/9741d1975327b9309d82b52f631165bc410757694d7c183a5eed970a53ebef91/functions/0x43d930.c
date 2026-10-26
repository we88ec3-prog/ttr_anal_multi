
void FUN_0043d930(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  int *local_58;
  uint local_54;
  int local_50;
  undefined4 local_4c [5];
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar5 = DAT_00fb7618;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009342d6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar10 = DAT_00fb7618 + 8;
  if (*(uint *)(DAT_00fb7618 + 0x36) < 4) {
    local_54 = CONCAT31(local_54._1_3_,1);
    if (*(uint *)(DAT_00fb7618 + 0x36) != 0) goto LAB_0043d981;
  }
  local_54 = local_54 & 0xffffff00;
LAB_0043d981:
  local_50 = iVar10;
  (**(code **)(**(int **)(param_1 + 0x104) + 0x94))(local_54,local_14);
  (**(code **)(**(int **)(param_1 + 0xf0) + 0x94))((char)local_54 == '\0');
  if ((char)local_54 == '\0') {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_58 = (int *)0x1b;
    FUN_005740f0(&local_58);
    if (local_50 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    FUN_00420070();
    local_8 = 1;
    if (0.0 < *(float *)(iVar5 + 0x52)) {
      local_58 = (int *)0x1c;
      iVar6 = FUN_00585620();
      FUN_005740f0(&local_58);
      if (local_50 == *(int *)(iVar6 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      uVar7 = FUN_00438510(*(undefined4 *)(iVar5 + 0x52));
      local_8._0_1_ = 2;
      FUN_004041f0(uVar7,0,0xffffffff);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
    }
    FUN_00757800(local_4c);
    (**(code **)(**(int **)(param_1 + 0xf0) + 200))();
    local_8 = 0xffffffff;
    if (7 < local_38) {
      FUN_0089120c(local_4c[0]);
    }
  }
  else {
    local_58 = *(int **)(param_1 + 0x134 + *(int *)(iVar5 + 0x36) * 4);
    if (((*(char *)(*(int *)(param_1 + 0x104) + 0xa4) != '\0') &&
        (piVar11 = *(int **)(*(int *)(param_1 + 0x104) + 0x94), piVar11 != (int *)0x0)) &&
       (iVar5 = (**(code **)(*piVar11 + 4))(), iVar5 == 0xbf6b)) {
      FUN_0077b200();
      iVar10 = local_50;
    }
    (**(code **)(**(int **)(param_1 + 0x104) + 200))();
  }
  FUN_00439990(param_1,iVar10 + 0x42);
  uVar7 = FUN_00433f80(local_30,*(undefined4 *)(iVar10 + 0x32),*(undefined4 *)(iVar10 + 0x36));
  local_8 = 3;
  FUN_00757800(uVar7);
  local_8 = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_30[0] = local_30[0] & 0xffff0000;
  local_1c = 7;
  local_20 = 0;
  (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
  piVar11 = (int *)(DAT_00fb7618 + 0x5c);
  iVar5 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  uVar4 = (*(int *)(DAT_00fb7618 + 0x60) - *(int *)(DAT_00fb7618 + 0x5c)) / 0x52;
  local_58 = piVar11;
  if (iVar5 != 0) {
    FUN_00408920(iVar5,uVar4);
  }
  local_54 = 0;
  if (uVar4 != 0) {
    local_50 = 0;
    do {
      iVar5 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
      if (iVar5 != 0) {
        for (piVar8 = *(int **)(iVar5 + 0xa8); piVar8 != *(int **)(iVar5 + 0xac);
            piVar8 = piVar8 + 1) {
          piVar9 = (int *)*piVar8;
          if (piVar9[8] == local_54) goto LAB_0043dc50;
        }
      }
      piVar9 = (int *)0x0;
LAB_0043dc50:
      if ((uint)((local_58[1] - *piVar11) / 0x52) <= local_54) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript");
      }
      FUN_0043ae40(piVar9);
      (**(code **)(*piVar9 + 200))();
      local_50 = local_50 + 0x52;
      local_54 = local_54 + 1;
      piVar11 = local_58;
    } while (local_54 < uVar4);
  }
  piVar11 = *(int **)(param_1 + 0xec);
  puVar1 = (undefined4 *)piVar11[0x19];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    iVar5 = puVar2[2];
    if ((*(int *)(iVar5 + 0x60) != 0) && ((*(int **)(iVar5 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar5 + 0x1c) + 0x30))(iVar5);
    }
  }
  (**(code **)(*piVar11 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xec) + 200))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

