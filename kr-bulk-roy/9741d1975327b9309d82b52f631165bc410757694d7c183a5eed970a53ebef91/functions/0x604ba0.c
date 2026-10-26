
void FUN_00604ba0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009433bc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0 < unaff_EDI) {
    if ((DAT_00fc1cbc & 1) == 0) {
      DAT_00fc1cbc = DAT_00fc1cbc | 1;
      local_8 = 0;
      FUN_004fdac0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit(FUN_00bce150);
    }
    local_8 = 0xffffffff;
    if (*(int *)(&DAT_00fc7b70 + unaff_EDI * 0x40) == 0) {
      puVar4 = (undefined4 *)FUN_00891268(0x1c);
      if (puVar4 != (undefined4 *)0x0) {
        uVar1 = *(undefined4 *)(param_1 + 0x15c + unaff_EDI * 4);
        uVar2 = *(undefined4 *)(param_1 + 0x13c + unaff_EDI * 4);
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[3] = 0;
        puVar4[4] = 0xf4369;
        *puVar4 = FoxUI::FXUIEventI2::vftable;
        puVar4[5] = uVar2;
        puVar4[6] = uVar1;
      }
      FUN_004072a0();
      puVar4 = (undefined4 *)FUN_00891268(0x1c);
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[3] = 0;
        puVar4[4] = 0xf4368;
        *puVar4 = FoxUI::FXUIEventI2::vftable;
        puVar4[5] = param_2;
        puVar4[6] = param_3;
      }
      FUN_004072a0();
      uVar3 = DAT_00fc1cbc & 1;
      *(undefined4 *)(param_1 + 0x13c + unaff_EDI * 4) = param_2;
      *(undefined4 *)(param_1 + 0x15c + unaff_EDI * 4) = param_3;
      if (uVar3 == 0) {
        DAT_00fc1cbc = DAT_00fc1cbc | 1;
        local_8 = 1;
        FUN_004fdac0();
        _atexit(FUN_00bce150);
        local_8 = 0xffffffff;
      }
      FUN_004ff210(unaff_EDI,param_2,param_3,param_4);
    }
  }
  ExceptionList = local_10;
  return;
}

