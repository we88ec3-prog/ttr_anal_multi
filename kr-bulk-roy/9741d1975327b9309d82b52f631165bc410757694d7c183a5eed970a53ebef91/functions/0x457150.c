
void FUN_00457150(int param_1,undefined4 *param_2)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  int *piVar5;
  undefined1 auStack_a8 [12];
  undefined4 uStack_9c;
  uint *puStack_98;
  undefined4 uStack_94;
  int local_78;
  uint local_70;
  undefined4 *local_6c [6];
  uint local_54;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009318ec;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6c[0] = param_2;
  if (((*(char *)(*(int *)(param_1 + 0x248) + 0xa4) != '\0') &&
      (piVar5 = *(int **)(*(int *)(param_1 + 0x248) + 0x94), piVar5 != (int *)0x0)) &&
     (iVar3 = (**(code **)(*piVar5 + 4))(), iVar3 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0x248) + 200))();
  FUN_00453d70(auStack_a8,*(undefined4 *)(in_ECX + 0x3e));
  local_8 = 0;
  puVar4 = (undefined4 *)FUN_00412df0();
  if (7 < (uint)puVar4[5]) {
    puVar4 = (undefined4 *)*puVar4;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_8._0_1_ = 1;
  local_6c[0] = (undefined4 *)0x19;
  FUN_005740f0(local_6c);
  if (local_70 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  local_8._0_1_ = 3;
  FUN_004796c0(puVar4);
  local_8 = CONCAT31(local_8._1_3_,4);
  uStack_94 = 0x457297;
  FUN_00757800();
  if (7 < local_1c) {
    uStack_94 = 0x4572aa;
    FUN_0089120c();
  }
  local_8 = 0xffffffff;
  local_1c = 7;
  local_20 = 0;
  local_30 = local_30 & 0xffff0000;
  if (7 < local_54) {
    uStack_94 = 0x4572d6;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(param_1 + 0x24c) + 200))();
  FUN_00757710();
  (**(code **)(**(int **)(param_1 + 0x250) + 200))();
  uStack_94 = *(undefined4 *)(in_ECX + 0x32);
  puStack_98 = local_4c;
  uStack_9c = 0x457321;
  FUN_00433f80();
  local_8 = 5;
  FUN_00757710();
  local_8 = 0xffffffff;
  if (7 < local_38) {
    uStack_94 = 0x45735c;
    FUN_0089120c();
  }
  local_4c[0] = local_4c[0] & 0xffff0000;
  local_38 = 7;
  local_3c = 0;
  (**(code **)(**(int **)(param_1 + 0x254) + 200))();
  local_78 = 0;
  local_70 = 1;
  local_6c[0] = &DAT_00f943f0;
  piVar5 = (int *)(param_1 + 600);
  do {
    puVar4 = local_6c[0];
    if (2 < local_78) break;
    if ((local_70 & (int)*(short *)(in_ECX + 0x30)) != 0) {
      if ((DAT_00f94394 & 1) == 0) {
        DAT_00f94394 = DAT_00f94394 | 1;
        local_8 = 6;
        FUN_005c3de0();
        uStack_94 = 0x4573d2;
        _atexit((_func_4879 *)&LAB_00bccc30);
        local_8 = 0xffffffff;
      }
      if (((*(char *)(*piVar5 + 0xa4) != '\0') &&
          (piVar1 = *(int **)(*piVar5 + 0x94), piVar1 != (int *)0x0)) &&
         (iVar3 = (**(code **)(*piVar1 + 4))(), iVar3 == 0xbf6b)) {
        FUN_0077b200();
        puVar4 = local_6c[0];
      }
      (**(code **)(*(int *)*piVar5 + 200))();
      local_78 = local_78 + 1;
      piVar5 = piVar5 + 1;
    }
    local_6c[0] = puVar4 + 1;
    local_70 = local_70 << 1 | (uint)((int)local_70 < 0);
  } while ((int)local_6c[0] < 0xf94415);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

