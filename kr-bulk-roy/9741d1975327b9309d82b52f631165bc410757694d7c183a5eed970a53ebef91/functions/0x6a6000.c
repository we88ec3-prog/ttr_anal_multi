
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006a6000(int param_1)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int *in_ECX;
  int local_44;
  uint local_40;
  int *local_3c;
  undefined4 local_38 [5];
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094298c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_44;
  ExceptionList = &local_14;
  local_3c = in_ECX;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 0;
    FUN_004f3d80(DAT_00d61f20 ^ (uint)&stack0xffffffb0);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_c = 0xffffffff;
  FUN_004f6a30(in_ECX[1]);
  FUN_00757710();
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_c = 1;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_c = 0xffffffff;
  }
  iVar3 = DAT_00f943ac;
  local_44 = 0xf;
  FUN_0082ef00(&local_44);
  if ((local_40 != *(uint *)(iVar3 + 8)) && (*(int *)(local_40 + 0x10) != 0)) {
    if (*(char *)((int)in_ECX + 0x12) == '\0') {
      if ((short)in_ECX[5] == 0) {
        (**(code **)(**(int **)(param_1 + 0x248) + 0x94))(0);
      }
      else {
        FUN_00763360(L"Ico_G_Admin");
        FUN_00745100();
        (**(code **)(**(int **)(param_1 + 0x248) + 0x94))(1);
        (**(code **)(**(int **)(param_1 + 0x248) + 200))();
      }
    }
    else {
      FUN_00763360(L"Ico_G_Master");
      if (((*(char *)(*(int *)(param_1 + 0x248) + 0xa4) != '\0') &&
          (piVar1 = *(int **)(*(int *)(param_1 + 0x248) + 0x94), piVar1 != (int *)0x0)) &&
         (iVar3 = (**(code **)(*piVar1 + 4))(), iVar3 == 0xbf6b)) {
        FUN_0077b200();
      }
      (**(code **)(**(int **)(param_1 + 0x248) + 0x94))(1);
      (**(code **)(**(int **)(param_1 + 0x248) + 200))();
      in_ECX = local_3c;
    }
  }
  if (*in_ECX == 0) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 3;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c = 0xffffffff;
    }
    local_40 = 0;
    FUN_005740f0(&local_40);
    if (local_44 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_00757710();
  }
  else {
    FUN_00426ec0();
    local_c = 2;
    FUN_00757710();
    local_c = 0xffffffff;
    in_ECX = local_3c;
    if (7 < uStack_24) {
      FUN_0089120c(local_38[0]);
      in_ECX = local_3c;
    }
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 4;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  FUN_00507a30(DAT_00f94208,(short)in_ECX[3]);
  FUN_00757710();
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  FUN_004f3460(*(undefined1 *)((int)in_ECX + 0xe),(short)in_ECX[4]);
  local_c = 5;
  FUN_00757710();
  local_c = 0xffffffff;
  if (7 < uStack_24) {
    FUN_0089120c(local_38[0]);
  }
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  uVar4 = FUN_004f3880(local_38,*(undefined1 *)((int)local_3c + 0xe),
                       *(undefined1 *)((int)local_3c + 0x16),local_3c[6]);
  local_c = 6;
  FUN_00757800(uVar4);
  local_c = 0xffffffff;
  if (7 < uStack_24) {
    FUN_0089120c(local_38[0]);
  }
  piVar1 = local_3c;
  if (*(char *)((int)local_3c + 0xe) == '\n') {
    *(undefined4 *)(param_1 + 0x154) = 0xff787878;
    *(undefined4 *)(*(int *)(param_1 + 0x254) + 0x154) = 0xff787878;
    *(undefined4 *)(*(int *)(param_1 + 600) + 0x154) = 0xff787878;
    *(undefined4 *)(*(int *)(param_1 + 0x25c) + 0x154) = 0xff787878;
    *(undefined4 *)(*(int *)(param_1 + 0x260) + 0x154) = 0xff787878;
  }
  else {
    *(undefined4 *)(param_1 + 0x154) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x254) + 0x154) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 600) + 0x154) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x25c) + 0x154) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x260) + 0x154) = 0xffffffff;
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_c = 7;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_c = 0xffffffff;
  }
  if (*(ushort *)((int)piVar1 + 10) != 0) {
    local_40 = (*(ushort *)((int)piVar1 + 10) - 1) / 6;
    FUN_0082ef00(&local_40);
    if (local_44 != DAT_00f945e4) {
      local_44 = *(int *)(local_44 + 0x10);
      goto LAB_006a64db;
    }
  }
  local_44 = 0;
LAB_006a64db:
  if (((*(char *)(*(int *)(param_1 + 0x24c) + 0xa4) != '\0') &&
      (piVar1 = *(int **)(*(int *)(param_1 + 0x24c) + 0x94), piVar1 != (int *)0x0)) &&
     (iVar3 = (**(code **)(*piVar1 + 4))(), iVar3 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0x24c) + 200))();
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_c = 8;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_c = 0xffffffff;
  }
  uVar5 = (uint)*(ushort *)((int)local_3c + 10);
  if ((uVar5 != 0x25) && (uVar5 != 0)) {
    local_40 = 0xc - (uVar5 - 1) % 6;
    FUN_0082ef00(&local_40);
  }
  if (((*(char *)(*(int *)(param_1 + 0x250) + 0xa4) != '\0') &&
      (piVar1 = *(int **)(*(int *)(param_1 + 0x250) + 0x94), piVar1 != (int *)0x0)) &&
     (iVar3 = (**(code **)(*piVar1 + 4))(), iVar3 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0x250) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_44);
  return;
}

