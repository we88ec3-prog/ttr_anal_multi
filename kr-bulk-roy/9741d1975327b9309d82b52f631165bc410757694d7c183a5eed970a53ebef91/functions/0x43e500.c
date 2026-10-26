
undefined4 FUN_0043e500(int param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined1 *puVar6;
  uint local_30;
  int local_2c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091bcbe;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  if (param_3 < 2) {
    local_30 = 0;
  }
  else {
    local_30 = (param_3 - 2) / 6;
  }
  if (local_30 != 0) {
    puVar6 = (undefined1 *)(param_2 + 7);
    do {
      puVar1 = (undefined4 *)(puVar6 + -5);
      FUN_0082ef00(puVar1);
      if (local_2c == *(int *)(param_1 + 4)) {
        puVar3 = (undefined4 *)FUN_00891268(8,uVar2);
        *puVar3 = *puVar1;
        *(undefined1 *)(puVar3 + 1) = puVar6[-1];
        *(undefined1 *)((int)puVar3 + 5) = *puVar6;
        uVar4 = FUN_0057ef20();
        FUN_0082f200(param_1,uVar4);
      }
      else {
        **(undefined4 **)(local_2c + 0x10) = *puVar1;
        *(undefined1 *)(*(int *)(local_2c + 0x10) + 4) = puVar6[-1];
        *(undefined1 *)(*(int *)(local_2c + 0x10) + 5) = *puVar6;
      }
      puVar6 = puVar6 + 6;
      local_30 = local_30 - 1;
    } while (local_30 != 0);
  }
  piVar5 = (int *)FUN_00891268(0x14,uVar2);
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    *piVar5 = (int)FoxUI::FXUIEvent::vftable;
    piVar5[1] = -1;
    piVar5[2] = -1;
    piVar5[3] = 0;
    piVar5[4] = 0xf443d;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 0;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  if (DAT_00f95bd4 != (int *)0x0) {
    (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar5);
  }
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 0x10))(1);
  }
  ExceptionList = local_14;
  return 0;
}

