
void FUN_006b2b80(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009169ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x98) + 0x20)) {
      piVar1 = (int *)FUN_00891268(0x14,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      if (piVar1 == (int *)0x0) {
        piVar1 = (int *)0x0;
      }
      else {
        *piVar1 = (int)FoxUI::FXUIEvent::vftable;
        piVar1[1] = -1;
        piVar1[2] = -1;
        piVar1[3] = 0;
        piVar1[4] = 0xf439e;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_8 = 0;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_8 = 0xffffffff;
      }
      if (DAT_00f95bd4 != (int *)0x0) {
        (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar1);
      }
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x10))(1);
        ExceptionList = local_10;
        return;
      }
    }
    else if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x94) + 0x20)) {
      puVar2 = (undefined4 *)FUN_00891268(0x14,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf42f0;
      }
      FUN_00404aa0();
      FUN_00750020();
    }
  }
  ExceptionList = local_10;
  return;
}

