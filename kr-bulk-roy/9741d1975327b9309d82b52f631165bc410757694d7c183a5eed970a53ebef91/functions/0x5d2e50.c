
void FUN_005d2e50(int param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  undefined1 uVar7;
  uint uStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009437b2;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_44;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffb0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  iVar1 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  iStack_40 = iVar1;
  if (iVar1 == 0) goto LAB_005d30cf;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 1;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    local_c = 0xffffffff;
  }
  if (DAT_00fb7258 == 0) {
    piVar5 = *(int **)(param_1 + 0x98);
LAB_005d2f70:
    (**(code **)(*piVar5 + 0x94))(0);
    (**(code **)(**(int **)(param_1 + 0xa0) + 0x94))(0);
    pcVar3 = *(code **)(**(int **)(param_1 + 0x9c) + 0x94);
    uVar7 = 0;
  }
  else {
    iVar2 = FUN_00404ba0();
    iVar2 = FUN_00539aa0(*(undefined4 *)(iVar2 + 0x5f50));
    piVar5 = *(int **)(param_1 + 0x98);
    if (iVar2 == 0) goto LAB_005d2f70;
    (**(code **)(*piVar5 + 0x94))(*(undefined1 *)(iVar2 + 6));
    (**(code **)(**(int **)(param_1 + 0xa0) + 0x94))(*(undefined1 *)(iVar2 + 7));
    uVar7 = *(undefined1 *)(iVar2 + 8);
    pcVar3 = *(code **)(**(int **)(param_1 + 0x9c) + 0x94);
  }
  (*pcVar3)(uVar7);
  uVar6 = (uint)*(ushort *)(iVar1 + 0x88);
  uStack_44 = uVar6;
  if (*(uint *)(param_1 + 0x80) != uVar6) {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c = 2;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c = 0xffffffff;
    }
    iVar1 = *(int *)(param_1 + 0x88);
    uStack_3c = (&DAT_00f943f0)[uVar6];
    if ((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) {
      iVar1 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))();
      if (iVar1 == 0xbf6b) {
        FUN_0077b200();
        uVar6 = uStack_44;
      }
    }
    (**(code **)(**(int **)(param_1 + 0x88) + 200))();
    *(uint *)(param_1 + 0x80) = uVar6;
  }
  iVar1 = *(int *)(iStack_40 + 0x3d4);
  if (*(int *)(param_1 + 0x84) != iVar1) {
    uVar4 = FUN_0040ef80();
    local_c = 3;
    FUN_00757800(uVar4);
    local_c = 0xffffffff;
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
    uStack_38 = uStack_38 & 0xffff0000;
    uStack_24 = 7;
    uStack_28 = 0;
    (**(code **)(**(int **)(param_1 + 0x90) + 200))();
    *(int *)(param_1 + 0x84) = iVar1;
  }
  FUN_005d2d30(param_1);
LAB_005d30cf:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&uStack_44);
  return;
}

