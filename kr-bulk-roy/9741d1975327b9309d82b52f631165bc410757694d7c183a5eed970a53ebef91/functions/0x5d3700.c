
void FUN_005d3700(int param_1)

{
  ushort uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int *piVar6;
  undefined1 auStack_70 [20];
  undefined4 uStack_5c;
  undefined1 *puStack_44;
  int iStack_40;
  int iStack_3c;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00943752;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_44;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    uStack_5c = 0x5d3761;
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if (DAT_00fba7a4 != (int *)0x0) {
    iVar4 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    iStack_3c = iVar4;
    if (iVar4 != 0) {
      if ((*(int *)(iVar4 + 0x158) == 0) || (*(int *)(*(int *)(iVar4 + 0x158) + 0x34) != 0)) {
        pcVar5 = *(code **)(**(int **)(param_1 + 0x80) + 0x128);
        (*(int **)(param_1 + 0x80))[0x34] = 0;
        (*pcVar5)();
        puStack_44 = auStack_70;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(*(undefined4 *)(param_1 + 0x80));
        (**(code **)(**(int **)(param_1 + 0x80) + 200))();
        pcVar5 = *(code **)(**(int **)(param_1 + 0x84) + 0x128);
        (*(int **)(param_1 + 0x84))[0x34] = 0;
        (*pcVar5)();
        puStack_44 = auStack_70;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(*(undefined4 *)(param_1 + 0x84));
        (**(code **)(**(int **)(param_1 + 0x84) + 200))();
        pcVar5 = *(code **)(**(int **)(param_1 + 0x88) + 0x128);
        (*(int **)(param_1 + 0x88))[0x34] = 0;
        (*pcVar5)();
        puStack_44 = auStack_70;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(*(undefined4 *)(param_1 + 0x88));
        pcVar5 = *(code **)(**(int **)(param_1 + 0x88) + 200);
      }
      else {
        puStack_44 = auStack_70;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(*(undefined4 *)(param_1 + 0x80));
        (**(code **)(**(int **)(param_1 + 0x80) + 200))();
        puVar2 = *(undefined1 **)(iVar4 + 0x3bc);
        if ((int)puVar2 < 1) {
          piVar6 = *(int **)(param_1 + 0x80);
          piVar6[0x34] = 0;
        }
        else {
          iStack_40 = *(int *)(iVar4 + 0x3c8);
          piVar6 = *(int **)(param_1 + 0x80);
          piVar6[0x34] = (int)((float)iStack_40 / (float)(int)puVar2);
          puStack_44 = puVar2;
        }
        (**(code **)(*piVar6 + 0x128))();
        puStack_44 = auStack_70;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(*(undefined4 *)(param_1 + 0x84));
        (**(code **)(**(int **)(param_1 + 0x84) + 200))();
        iVar3 = *(int *)(iVar4 + 0x3c0);
        if (iVar3 < 1) {
          piVar6 = *(int **)(param_1 + 0x84);
          piVar6[0x34] = 0;
        }
        else {
          puStack_44 = *(undefined1 **)(iVar4 + 0x3cc);
          piVar6 = *(int **)(param_1 + 0x84);
          piVar6[0x34] = (int)((float)(int)puStack_44 / (float)iVar3);
          iStack_40 = iVar3;
        }
        (**(code **)(*piVar6 + 0x128))();
        puStack_44 = auStack_70;
        FUN_0040e460(&DAT_00bf2bf8);
        FUN_0040eff0(*(undefined4 *)(param_1 + 0x88));
        (**(code **)(**(int **)(param_1 + 0x88) + 200))();
        iVar3 = *(int *)(iVar4 + 0x3c4);
        if (iVar3 < 1) {
          piVar6 = *(int **)(param_1 + 0x88);
          piVar6[0x34] = 0;
        }
        else {
          puStack_44 = *(undefined1 **)(iVar4 + 0x3d0);
          piVar6 = *(int **)(param_1 + 0x88);
          piVar6[0x34] = (int)((float)(int)puStack_44 / (float)iVar3);
          iStack_40 = iVar3;
        }
        pcVar5 = *(code **)(*piVar6 + 0x128);
      }
      (*pcVar5)();
      uVar1 = *(ushort *)(iVar4 + 0x88);
      if ((DAT_00f94394 & 1) == 0) {
        DAT_00f94394 = DAT_00f94394 | 1;
        local_c = 1;
        FUN_005c3de0();
        uStack_5c = 0x5d3a68;
        _atexit((_func_4879 *)&LAB_00bccc30);
        local_c = 0xffffffff;
      }
      puStack_44 = (undefined1 *)(&DAT_00f943f0)[uVar1];
      iVar4 = *(int *)(param_1 + 0x90);
      if ((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) {
        iVar4 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))();
        if (iVar4 == 0xbf6b) {
          FUN_0077b200();
        }
      }
      (**(code **)(**(int **)(param_1 + 0x90) + 200))();
      FUN_0040ef80();
      local_c = 2;
      uStack_5c = 0x5d3af7;
      FUN_00757800();
      local_c = 0xffffffff;
      if (7 < uStack_24) {
        uStack_5c = 0x5d3b10;
        FUN_0089120c();
      }
      uStack_38 = uStack_38 & 0xffff0000;
      uStack_24 = 7;
      uStack_28 = 0;
      (**(code **)(**(int **)(param_1 + 0x8c) + 200))();
      iStack_40 = 2;
      do {
        FUN_005d2610();
        iStack_40 = iStack_40 + -1;
      } while (iStack_40 != 0);
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 3;
        FUN_004e1590();
        uStack_5c = 0x5d3b7b;
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      iVar4 = *(int *)(param_1 + 0x98);
      *(undefined4 *)(iVar4 + 0xe0) = DAT_00f93930;
      *(undefined4 *)(iVar4 + 0xdc) = 2;
      uStack_5c = 0x5d3bae;
      FUN_0068b260();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&puStack_44);
  return;
}

