
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c5370(void)

{
  uint uVar1;
  int *piVar2;
  int in_ECX;
  undefined4 uStack_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009169ee;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uStack_14 = in_ECX;
  if ((_DAT_00fb734c & 1) == 0) {
    _DAT_00fb734c = _DAT_00fb734c | 1;
    DAT_00fb7350 = '\x01';
    _atexit((_func_4879 *)&DAT_00bcd0b0);
  }
  if (DAT_00fb7350 != '\0') {
    if (*(int *)(in_ECX + 0x5ebc) == 0) {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      uStack_14 = CONCAT22(0x19,(undefined2)uStack_14);
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&uStack_14 + 2,2,uVar1);
      }
    }
    else {
      piVar2 = (int *)FUN_00891268(0x14);
      if (piVar2 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        *piVar2 = (int)FoxUI::FXUIEvent::vftable;
        piVar2[1] = -1;
        piVar2[2] = -1;
        piVar2[3] = 0;
        piVar2[4] = 0xf439f;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_8 = 0;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_8 = 0xffffffff;
      }
      if (DAT_00f95bd4 != (int *)0x0) {
        (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar2);
      }
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x10))(1);
      }
    }
    if ((_DAT_00fb734c & 1) == 0) {
      _DAT_00fb734c = _DAT_00fb734c | 1;
      DAT_00fb7350 = 1;
      _atexit((_func_4879 *)&DAT_00bcd0b0);
    }
    DAT_00fb7350 = '\0';
  }
  ExceptionList = local_10;
  return;
}

