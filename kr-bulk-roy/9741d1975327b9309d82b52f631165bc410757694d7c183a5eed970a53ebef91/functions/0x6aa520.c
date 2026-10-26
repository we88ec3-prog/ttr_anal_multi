
void FUN_006aa520(int param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 ***pppuVar3;
  int local_38;
  undefined4 local_34;
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = -1;
  puStack_c = &LAB_0092c424;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = param_2;
  *(undefined4 *)(param_1 + 0x24c) = *param_3;
  local_14 = uVar1;
  FUN_004026e0(param_3 + 1,0,0xffffffff);
  FUN_00757800(param_1 + 0x250);
  if (*(int *)(param_1 + 0x24c) == 2) {
    local_1c = 7;
    local_20 = 0;
    local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffff0000);
    FUN_004026e0(local_34,0,0xffffffff);
    local_8 = 0;
    FUN_00404300(&DAT_00c1ae08,1);
    FUN_004041f0(param_1 + 0x250,0,0xffffffff);
    pppuVar3 = (undefined4 ***)local_30[0];
    if (local_1c < 8) {
      pppuVar3 = local_30;
    }
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8._0_1_ = 1;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    FUN_005ca810(pppuVar3);
    FUN_00745060();
    (**(code **)(**(int **)(param_1 + 0x248) + 200))();
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  else {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 2;
      FUN_005c3de0(uVar1);
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = -1;
    }
    iVar2 = DAT_00f943ac;
    local_34 = 0xf;
    FUN_0082ef00(&local_34);
    if ((local_38 != *(int *)(iVar2 + 8)) && (*(int *)(local_38 + 0x10) != 0)) {
      FUN_00763360(L"Ico_G_Folder");
      iVar2 = *(int *)(param_1 + 0x248);
      if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
        iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
        if (iVar2 == 0xbf6b) {
          FUN_0077b200();
        }
      }
      (**(code **)(**(int **)(param_1 + 0x248) + 200))();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

