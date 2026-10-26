
void FUN_006a6ab0(int param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c4c2;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar3 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  if (iVar3 != 0) {
    iVar3 = *(int *)(iVar3 + 0xdc);
    iVar4 = -1;
    if (iVar3 != 0) {
      iVar4 = *(int *)(iVar3 + 0x20);
    }
    if (iVar4 != -1) {
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 0;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
      }
      if (iVar4 != DAT_00f93930) {
        if ((DAT_00faadd4 & 1) == 0) {
          DAT_00faadd4 = DAT_00faadd4 | 1;
          local_c = 1;
          FUN_00587480();
          _atexit((_func_4879 *)&LAB_00bcccc0);
        }
        local_c = 0xffffffff;
        puVar2 = (undefined4 *)FUN_00891268();
        if (puVar2 != (undefined4 *)0x0) {
          puVar2[1] = 0xffffffff;
          puVar2[2] = 0xffffffff;
          puVar2[3] = 0;
          puVar2[4] = 0xf43e8;
          *puVar2 = FoxUI::FXUIEventI1::vftable;
          puVar2[5] = iVar4;
        }
        FUN_00402160();
        local_c = 2;
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_c._0_1_ = 3;
          local_c._1_3_ = 0;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          local_c = CONCAT31(local_c._1_3_,2);
        }
        iVar3 = FUN_005854b0();
        FUN_005740f0();
        if (local_20 == *(int *)(iVar3 + 4)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        FUN_004f6a30();
        FUN_004ed610();
        local_c = 0xffffffff;
        FUN_0058b270(0xcf);
      }
    }
  }
  ExceptionList = local_14;
  return;
}

