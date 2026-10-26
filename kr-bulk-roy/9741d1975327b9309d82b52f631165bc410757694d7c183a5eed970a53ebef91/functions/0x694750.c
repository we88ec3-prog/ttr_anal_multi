
void FUN_00694750(int param_1)

{
  uint uVar1;
  int iVar2;
  uint in_ECX;
  undefined4 uVar3;
  uint local_44;
  int local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00935ba0;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_44;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(uVar1);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  if (in_ECX < (uint)(*(int *)(DAT_00fab130 + 0x5eec) - *(int *)(DAT_00fab130 + 0x5ee8) >> 2)) {
    uVar3 = *(undefined4 *)(*(int *)(DAT_00fab130 + 0x5ee8) + in_ECX * 4);
  }
  else {
    uVar3 = 0;
  }
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 1;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_c = 0xffffffff;
  FUN_004f6a30(uVar3);
  FUN_00757710();
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 2;
    FUN_004dec90(uVar1);
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  local_40 = FUN_004dfb60();
  if (local_40 == 0) {
    iVar2 = -1;
    if ((*(int *)(param_1 + 0xd4) == -1) || (*(int *)(param_1 + 0xd8) == -1)) goto LAB_00694a13;
    FUN_00745100();
    (**(code **)(**(int **)(param_1 + 0x84) + 200))();
    FUN_00757710();
    (**(code **)(**(int **)(param_1 + 0x94) + 200))();
    *(undefined4 *)(param_1 + 0xd4) = 0xffffffff;
  }
  else {
    uVar1 = (uint)*(ushort *)(local_40 + 0x88);
    local_44 = uVar1;
    if (*(uint *)(param_1 + 0xd4) != uVar1) {
      if ((DAT_00f94394 & 1) == 0) {
        DAT_00f94394 = DAT_00f94394 | 1;
        local_c = 3;
        FUN_005c3de0();
        _atexit((_func_4879 *)&LAB_00bccc30);
        local_c = 0xffffffff;
      }
      iVar2 = *(int *)(param_1 + 0x84);
      local_3c = (&DAT_00f943f0)[uVar1];
      if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
         (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
        FUN_0077b200();
        uVar1 = local_44;
      }
      (**(code **)(**(int **)(param_1 + 0x84) + 200))();
      *(uint *)(param_1 + 0xd4) = uVar1;
    }
    iVar2 = *(int *)(local_40 + 0x3d4);
    if (iVar2 == *(int *)(param_1 + 0xd8)) goto LAB_00694a13;
    FUN_0040ef80();
    local_c = 4;
    FUN_00757710();
    local_c = 0xffffffff;
    if (7 < uStack_24) {
      FUN_0089120c(local_38);
    }
    local_38 = local_38 & 0xffff0000;
    uStack_24 = 7;
    uStack_28 = 0;
    (**(code **)(**(int **)(param_1 + 0x94) + 200))();
  }
  *(int *)(param_1 + 0xd8) = iVar2;
LAB_00694a13:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_44);
  return;
}

