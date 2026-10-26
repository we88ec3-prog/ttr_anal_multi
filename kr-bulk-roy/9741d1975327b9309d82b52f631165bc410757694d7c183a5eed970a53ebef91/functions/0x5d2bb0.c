
void FUN_005d2bb0(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009169ee;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(int *)(param_1 + 0x10) == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == *(int *)(*(int *)(in_ECX + 0x8c) + 0x20)) {
      ExceptionList = &local_10;
      piVar3 = (int *)FUN_00891268(0x14,uVar2);
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        *piVar3 = (int)FoxUI::FXUIEvent::vftable;
        piVar3[1] = -1;
        piVar3[2] = -1;
        piVar3[3] = 0;
        piVar3[4] = 0xf42dc;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_8 = 0;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_8 = 0xffffffff;
      }
      if (DAT_00f95bd4 != (int *)0x0) {
        (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar3);
      }
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x10))(1);
        ExceptionList = local_10;
        return;
      }
    }
    else {
      if (iVar1 == *(int *)(*(int *)(in_ECX + 0x94) + 0x20)) {
        ExceptionList = &local_10;
        puVar4 = (undefined4 *)FUN_00891268(0x14,uVar2);
        if (puVar4 != (undefined4 *)0x0) {
          *puVar4 = FoxUI::FXUIEvent::vftable;
          puVar4[1] = 0xffffffff;
          puVar4[2] = 0xffffffff;
          puVar4[3] = 0;
          puVar4[4] = 0xf42dd;
        }
      }
      else {
        if (iVar1 != *(int *)(*(int *)(in_ECX + 0xa4) + 0x20)) {
          return;
        }
        ExceptionList = &local_10;
        puVar4 = (undefined4 *)FUN_00891268(0x18,uVar2);
        if (puVar4 != (undefined4 *)0x0) {
          puVar4[1] = 0xffffffff;
          puVar4[2] = 0xffffffff;
          puVar4[3] = 0;
          puVar4[4] = 0xf42df;
          *puVar4 = FoxUI::FXUIEventI1::vftable;
          puVar4[5] = 0;
        }
      }
      FUN_00404aa0();
      FUN_00750020();
    }
  }
  ExceptionList = local_10;
  return;
}

