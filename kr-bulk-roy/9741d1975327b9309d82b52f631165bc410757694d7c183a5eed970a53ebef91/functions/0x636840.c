
void FUN_00636840(void)

{
  undefined4 *puVar1;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093aa4c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_00745930(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  puVar1 = (undefined4 *)FUN_00891268(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0xf4350;
    *puVar1 = FoxUI::FXUIEventP1::vftable;
    puVar1[5] = in_ECX;
  }
  FUN_004072a0();
  if ((DAT_00fb761c & 1) == 0) {
    DAT_00fb761c = DAT_00fb761c | 1;
    local_c = 0;
    FUN_0054e750();
    _atexit((_func_4879 *)&LAB_00bcd260);
    local_c = 0xffffffff;
  }
  if (DAT_00fb7620 != (int *)0x0) {
    (**(code **)(*DAT_00fb7620 + 0xc))();
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_c = 0xffffffff;
  }
  FUN_007986e0(DAT_00fb76e8,"Talkbox");
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x84) = 0;
  *(undefined4 *)(in_ECX + 0xb8) = 0;
  *(undefined4 *)(in_ECX + 0x94) = 0;
  *(undefined4 *)(in_ECX + 0x98) = 0;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  ExceptionList = local_14;
  return;
}

