
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00495280(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094950a;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if ((_DAT_00fb79ec & 1) == 0) {
    _DAT_00fb79ec = _DAT_00fb79ec | 1;
    DAT_00fb79f0 = CCheckPointMgr::vftable;
    DAT_00fb79f4 = 0;
    DAT_00fb79f8 = 0;
    DAT_00fb79fc = 0;
    DAT_00fb7a04 = 1;
    _atexit((_func_4879 *)&LAB_00bcd270);
  }
  FUN_005449a0(&DAT_00fb79f0);
  iVar3 = FUN_00891268(0x5eac,uVar2);
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)FUN_004add50();
    *puVar4 = Scene::CFirstScene::vftable;
    DAT_00d6a674 = 0x46495253;
  }
  if ((_DAT_00fd2cf4 & 1) == 0) {
    _DAT_00fd2cf4 = _DAT_00fd2cf4 | 1;
    DAT_00fd2cf8 = CSceneManager::vftable;
    DAT_00fd8ba4 = 0;
    FUN_004b7dc0();
    _atexit((_func_4879 *)&LAB_00bcdcf0);
  }
  FUN_004b7d50();
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  if (DAT_00faadec == 0) {
    FUN_0058a9a0();
  }
  else {
    _DAT_00faadf0 = 0;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  uVar1 = DAT_00f93930;
  Sleep(3000);
  if ((DAT_00fbacd0 & 1) == 0) {
    DAT_00fbacd0 = DAT_00fbacd0 | 1;
    local_c = 2;
    DAT_00fbacd4 = 0;
    DAT_00fbacd4 = FUN_006d6300();
    _atexit((_func_4879 *)&LAB_00bcd670);
    local_c = 0xffffffff;
  }
  iVar3 = FUN_006d64c0(&DAT_00fbacd4,uVar1);
  if (iVar3 == 0) {
    FUN_006ded00(&DAT_00c059c8);
  }
  ExceptionList = local_14;
  return 0;
}

