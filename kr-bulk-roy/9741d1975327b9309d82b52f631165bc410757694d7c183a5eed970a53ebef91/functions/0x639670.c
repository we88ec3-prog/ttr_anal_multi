
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00639670(void)

{
  undefined4 *puVar1;
  undefined2 local_10;
  undefined1 local_e;
  undefined2 local_d;
  undefined1 local_b;
  undefined2 local_a;
  undefined1 local_8;
  undefined2 local_7;
  undefined1 local_5;
  
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_7 = 0xbd9;
  local_5 = 1;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(2,&local_7,3);
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_a = 0xbd9;
  local_8 = 2;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(2,&local_a,3);
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_d = 0xbd9;
  local_b = 3;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(2,&local_d,3);
  }
  if ((_DAT_00fb1314 & 1) == 0) {
    _DAT_00fb1314 = _DAT_00fb1314 | 1;
    _atexit((_func_4879 *)&DAT_00bccf10);
  }
  local_10 = 0xbd9;
  local_e = 4;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(2,&local_10,3);
  }
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = FoxUI::FXUIEvent::vftable;
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0xf4303;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

