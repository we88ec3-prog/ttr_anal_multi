
uint FUN_0043cd70(uint param_1)

{
  undefined4 *puVar1;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092481c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 == 0xd) {
    if ((*(uint *)(in_ECX[0x3e] + 0x28) >> 7 & 1) == 0) {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 1;
        FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
        _atexit((_func_4879 *)&LAB_00bcccc0);
      }
      local_8 = 0xffffffff;
      puVar1 = (undefined4 *)FUN_00891268(0x14);
      if (puVar1 == (undefined4 *)0x0) goto LAB_0043ce0e;
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf443b;
    }
    else {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 0;
        FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
        _atexit((_func_4879 *)&LAB_00bcccc0);
      }
      local_8 = 0xffffffff;
      puVar1 = (undefined4 *)FUN_00891268(0x14);
      if (puVar1 == (undefined4 *)0x0) {
LAB_0043ce0e:
        puVar1 = (undefined4 *)0x0;
      }
      else {
        *puVar1 = FoxUI::FXUIEvent::vftable;
        puVar1[1] = 0xffffffff;
        puVar1[2] = 0xffffffff;
        puVar1[3] = 0;
        puVar1[4] = 0xf42d3;
      }
    }
    FUN_0058b1a0(0x12f,puVar1);
  }
  else if (param_1 != 0xe) goto LAB_0043ce81;
  param_1 = (**(code **)(*in_ECX + 0xd4))();
LAB_0043ce81:
  ExceptionList = local_10;
  return param_1 & 0xffffff00;
}

