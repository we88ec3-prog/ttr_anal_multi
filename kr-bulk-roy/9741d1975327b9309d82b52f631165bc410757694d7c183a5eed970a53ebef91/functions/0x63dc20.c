
void FUN_0063dc20(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b84e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf0) + 0x20)) {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 0;
        FUN_00587480();
        _atexit((_func_4879 *)&LAB_00bcccc0);
      }
      local_8 = 0xffffffff;
      FUN_0058aad0();
    }
    else if ((*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) &&
            (iVar3 = *(int *)(*(int *)(in_ECX + 0xec) + 0xcc), iVar3 != 0)) {
      iVar3 = *(int *)(iVar3 + 0xdc);
      if (iVar3 == 0) {
        iVar3 = -1;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x20);
      }
      if (iVar3 != -1) {
        FUN_0048a3d0();
        FUN_004f2940();
        FUN_004054c0();
        puVar2 = (undefined4 *)FUN_00891268();
        if (puVar2 != (undefined4 *)0x0) {
          puVar2[1] = 0xffffffff;
          puVar2[2] = 0xffffffff;
          puVar2[3] = 0;
          puVar2[4] = 0xf43c4;
          *puVar2 = FoxUI::FXUIEventI1::vftable;
          puVar2[5] = iVar3;
        }
        FUN_00402250();
        local_8 = 1;
        FUN_005854b0();
        FUN_00585330();
        puVar2 = (undefined4 *)FUN_004ed610();
        local_8._0_1_ = 2;
        if (7 < (uint)puVar2[5]) {
          puVar2 = (undefined4 *)*puVar2;
        }
        FUN_00402250(puVar2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0058b270(0xcf);
        FUN_004fa440();
      }
    }
  }
  else if (*(int *)(param_1 + 0x10) == 0xf43c4) {
    FUN_0063ddd0();
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

