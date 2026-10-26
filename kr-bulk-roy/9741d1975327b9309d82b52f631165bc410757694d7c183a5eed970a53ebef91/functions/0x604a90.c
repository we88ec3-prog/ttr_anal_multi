
void FUN_00604a90(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00946cfe;
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
    if (((unaff_EDI / 7 + (unaff_EDI >> 0x1f) == unaff_EDI >> 0x1f) &&
        (unaff_EDI * 0x40 != -0xfc7b70)) && ((&DAT_00fc7b88)[unaff_EDI * 0x10] != 0)) {
      puVar3 = (undefined4 *)FUN_00891268(0x1c);
      if (puVar3 != (undefined4 *)0x0) {
        uVar1 = *(undefined4 *)(param_1 + 0x15c + unaff_EDI * 4);
        uVar2 = *(undefined4 *)(param_1 + 0x13c + unaff_EDI * 4);
        puVar3[1] = 0xffffffff;
        puVar3[2] = 0xffffffff;
        puVar3[3] = 0;
        puVar3[4] = 0xf4369;
        *puVar3 = FoxUI::FXUIEventI2::vftable;
        puVar3[5] = uVar2;
        puVar3[6] = uVar1;
      }
      FUN_004072a0();
      FUN_0048a360();
      FUN_004ff4e0(unaff_EDI);
      *(undefined4 *)(param_1 + 0x13c + unaff_EDI * 4) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x15c + unaff_EDI * 4) = 0xffffffff;
    }
  }
  ExceptionList = local_10;
  return;
}

