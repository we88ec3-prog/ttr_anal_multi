
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063e770(int param_1)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *in_ECX;
  int local_44;
  uint local_40;
  int *local_3c;
  undefined4 local_38;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093db68;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_44;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  local_3c = in_ECX;
  FUN_00757710(uVar4);
  if (*in_ECX == 0) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c = 0xffffffff;
    }
    local_44 = 0;
    FUN_005740f0(&local_44);
    if (local_40 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    FUN_00757710(uVar4);
  }
  else {
    FUN_00426ec0();
    local_c = 0;
    FUN_00757710(uVar4);
    local_c = 0xffffffff;
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  FUN_00507a30(DAT_00f94208,(short)in_ECX[4]);
  FUN_00757710();
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  FUN_004f3060(*(undefined1 *)((int)in_ECX + 0x12),(short)in_ECX[5],
               *(undefined1 *)((int)in_ECX + 0x16));
  local_c = 3;
  FUN_00757710();
  local_c = 0xffffffff;
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  piVar2 = local_3c;
  if (*(char *)((int)local_3c + 0x12) == '\n') {
    *(undefined4 *)(param_1 + 0x154) = 0xff787878;
    *(undefined4 *)(*(int *)(param_1 + 0x248) + 0x154) = 0xff787878;
    *(undefined4 *)(*(int *)(param_1 + 0x24c) + 0x154) = 0xff787878;
    *(undefined4 *)(*(int *)(param_1 + 0x250) + 0x154) = 0xff787878;
  }
  else {
    *(undefined4 *)(param_1 + 0x154) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x248) + 0x154) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x24c) + 0x154) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x250) + 0x154) = 0xffffffff;
  }
  if (*(short *)((int)local_3c + 0xe) == 0) {
    iVar5 = *(int *)(param_1 + 0x254);
    if (((*(char *)(iVar5 + 0xa4) != '\0') && (*(int **)(iVar5 + 0x94) != (int *)0x0)) &&
       (iVar6 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))(), iVar6 == 0xbf6b)) {
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
    iVar5 = *(int *)(param_1 + 600);
    if (((*(char *)(iVar5 + 0xa4) != '\0') && (*(int **)(iVar5 + 0x94) != (int *)0x0)) &&
       (iVar6 = (**(code **)(**(int **)(iVar5 + 0x94) + 4))(), iVar6 == 0xbf6b)) {
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
  }
  else {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c = 4;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c = 0xffffffff;
    }
    if (*(ushort *)((int)piVar2 + 0xe) != 0) {
      local_40 = (*(ushort *)((int)piVar2 + 0xe) - 1) / 6;
      FUN_0082ef00(&local_40);
    }
    if (((*(char *)(*(int *)(param_1 + 0x254) + 0xa4) != '\0') &&
        (piVar2 = *(int **)(*(int *)(param_1 + 0x254) + 0x94), piVar2 != (int *)0x0)) &&
       (iVar5 = (**(code **)(*piVar2 + 4))(), iVar5 == 0xbf6b)) {
      FUN_0077b200();
    }
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c = 5;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c = 0xffffffff;
    }
    uVar4 = (uint)*(ushort *)((int)local_3c + 0xe);
    if ((uVar4 != 0x25) && (uVar4 != 0)) {
      local_40 = 0xc - (uVar4 - 1) % 6;
      FUN_0082ef00(&local_40);
    }
    if (((*(char *)(*(int *)(param_1 + 600) + 0xa4) != '\0') &&
        (piVar2 = *(int **)(*(int *)(param_1 + 600) + 0x94), piVar2 != (int *)0x0)) &&
       (iVar5 = (**(code **)(*piVar2 + 4))(), iVar5 == 0xbf6b)) {
      FUN_0077b200();
    }
  }
  (**(code **)(**(int **)(param_1 + 0x254) + 200))();
  (**(code **)(**(int **)(param_1 + 600) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_44);
  return;
}

