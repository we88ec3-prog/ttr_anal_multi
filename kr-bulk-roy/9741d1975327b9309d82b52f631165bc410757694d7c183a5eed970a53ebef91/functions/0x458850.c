
void FUN_00458850(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *unaff_EBX;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *local_44;
  uint uStack_40;
  ushort *local_3c;
  int local_38;
  int local_34;
  undefined2 local_30 [9];
  ushort local_1e;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009417be;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_44;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffb0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar6 = DAT_00f942c4;
  local_c = 0xffffffff;
  *(int *)(param_1 + 0xdc) = DAT_00f942c4;
  if (iVar6 == 0) {
    puVar5 = (undefined4 *)(param_1 + 0x80);
    iVar6 = 9;
    do {
      (**(code **)(*(int *)*puVar5 + 0x94))(0);
      puVar5 = puVar5 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    puVar5 = (undefined4 *)(param_1 + 0xd0);
    iVar6 = 3;
    do {
      (**(code **)(*(int *)*puVar5 + 0x94))(0);
      (**(code **)(*(int *)*puVar5 + 200))();
      puVar5 = puVar5 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    (**(code **)(**(int **)(param_1 + 0xa4) + 0x94))(1);
    iVar6 = *(int *)(param_1 + 0xa4);
    iVar7 = *(int *)(param_1 + 0xa8);
    if ((*(char *)(iVar6 + 0xa4) != '\0') && (*(int *)(iVar6 + 0x94) != 0)) {
      iVar2 = (**(code **)(**(int **)(iVar6 + 0x94) + 4))();
      if ((iVar2 == 0xbf6b) && (iVar6 = *(int *)(iVar6 + 0x94), *(int *)(iVar6 + 0x10) != iVar7)) {
        if (((iVar7 != 0) && (piVar4 = *(int **)(iVar7 + 8), piVar4 != (int *)0x0)) &&
           (piVar4[0x27] = piVar4[0x27] + 1, piVar4[0x27] == 1)) {
          (**(code **)(*piVar4 + 0x24))();
        }
        if ((*(int *)(iVar6 + 0x10) != 0) &&
           (piVar4 = *(int **)(*(int *)(iVar6 + 0x10) + 8), piVar4 != (int *)0x0)) {
          piVar1 = piVar4 + 0x27;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar4 + 0x28))();
          }
        }
        *(int *)(iVar6 + 0x10) = iVar7;
      }
    }
    (**(code **)(**(int **)(param_1 + 0xa4) + 200))();
    iVar6 = *(int *)(param_1 + 0xe4) + -0xf;
  }
  else if (iVar6 < 0) {
    (**(code **)(**(int **)(param_1 + 0xa4) + 0x94))(1);
    iVar6 = *(int *)(param_1 + 0xa4);
    if ((*(char *)(iVar6 + 0xa4) != '\0') && (*(int *)(iVar6 + 0x94) != 0)) {
      iVar6 = (**(code **)(**(int **)(iVar6 + 0x94) + 4))();
      if (iVar6 == 0xbf6b) {
        FUN_0077b200();
      }
    }
    (**(code **)(**(int **)(param_1 + 0xa4) + 200))();
    iVar6 = *(int *)(param_1 + 0xe4);
  }
  else {
    iVar7 = 0;
    do {
      iVar3 = iVar6 / 10;
      iVar2 = iVar7 + 1;
      local_30[iVar7] = (short)(iVar6 % 10);
      iVar6 = iVar3;
      iVar7 = iVar2;
    } while (iVar3 != 0);
    *(undefined4 *)(param_1 + 0xdc) = 0;
    local_3c = &local_1e;
    piVar4 = (int *)(param_1 + 0x80);
    local_34 = 10;
    local_38 = iVar2;
    do {
      local_44 = piVar4;
      if (iVar2 < local_34) {
        (**(code **)(*(int *)*piVar4 + 0x94))(0);
        (**(code **)(*(int *)*piVar4 + 200))();
      }
      else {
        uStack_40 = (uint)*local_3c;
        if (-1 < (short)*local_3c) {
          (**(code **)(*(int *)*piVar4 + 0x94))(1);
          iVar6 = *piVar4;
          local_44 = *(int **)(param_1 + 0xa8 + (short)local_44 * 4);
          if ((*(char *)(iVar6 + 0xa4) != '\0') && (*(int *)(iVar6 + 0x94) != 0)) {
            iVar6 = (**(code **)(**(int **)(iVar6 + 0x94) + 4))();
            if (iVar6 == 0xbf6b) {
              FUN_0077b200();
              piVar4 = unaff_EBX;
            }
          }
          (**(code **)(*(int *)*piVar4 + 200))();
          iVar2 = local_38;
        }
      }
      local_3c = local_3c + -1;
      local_34 = local_34 + -1;
      piVar4 = piVar4 + 1;
    } while (0 < local_34);
    piVar1 = (int *)((iVar2 + -1) / 3);
    local_44 = piVar4;
    if (0 < (int)piVar1) {
      puVar5 = (undefined4 *)(param_1 + 0xd0);
      local_44 = piVar1;
      do {
        (**(code **)(*(int *)*puVar5 + 0x94))(1);
        (**(code **)(*(int *)*puVar5 + 200))();
        puVar5 = puVar5 + 1;
        local_44 = (int *)((int)local_44 + -1);
      } while (local_44 != (int *)0x0);
    }
    iVar6 = ((int)piVar1 * 0xd + -0x1e + local_38 * 0x1e) / 2 + *(int *)(param_1 + 0xe4);
  }
  FUN_00749a00(iVar6,0);
  (**(code **)(**(int **)(param_1 + 0xe0) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_44);
  return;
}

