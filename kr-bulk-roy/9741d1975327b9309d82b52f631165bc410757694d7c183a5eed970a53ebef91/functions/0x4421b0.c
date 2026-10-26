
void FUN_004421b0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int local_40 [7];
  undefined1 local_24;
  int local_1c;
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar2 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e5de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  (**(code **)(*(int *)param_1[0x5d] + 0x90))(0,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  (**(code **)(*(int *)piVar2[0x5d] + 200))();
  param_1 = (int *)0x0;
  local_1c = 0;
  FUN_00442930(&param_1);
  local_1c = 0;
  param_1 = (int *)0x0;
  FUN_00443570(&param_1);
  (**(code **)(*(int *)piVar2[0x53] + 0x19c))(0xffffffff,0xffffffff,0,0);
  (**(code **)(*(int *)piVar2[0x53] + 0x94))(0);
  (**(code **)(*(int *)piVar2[0x53] + 200))();
  piVar5 = piVar2 + 0x55;
  param_1 = (int *)0x3;
  do {
    (**(code **)(*(int *)*piVar5 + 0x94))(0);
    (**(code **)(*(int *)*piVar5 + 200))();
    piVar5 = piVar5 + 1;
    param_1 = (int *)((int)param_1 + -1);
  } while (param_1 != (int *)0x0);
  (**(code **)(*(int *)piVar2[0x58] + 0x94))(0);
  (**(code **)(*(int *)piVar2[0x58] + 200))();
  piVar5 = piVar2 + 0x50;
  local_1c = 2;
  param_1 = piVar2 + 0x40;
  do {
    local_18 = piVar5;
    (**(code **)(*(int *)*piVar5 + 0x19c))(0xffffffff,0xffffffff,0,0);
    (**(code **)(*(int *)*piVar5 + 200))();
    piVar3 = (int *)FUN_00891268(0x1c);
    piVar5 = (int *)0x0;
    if (piVar3 != (int *)0x0) {
      iVar4 = param_1[1];
      iVar1 = *param_1;
      piVar3[3] = 0;
      piVar3[1] = -1;
      piVar3[2] = -1;
      piVar3[4] = 0xf4369;
      *piVar3 = (int)FoxUI::FXUIEventI2::vftable;
      piVar3[5] = iVar1;
      piVar3[6] = iVar4;
      piVar5 = piVar3;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 0;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    if (DAT_00f95bd4 != (int *)0x0) {
      (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar5);
    }
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x10))(1);
    }
    piVar5 = local_18 + 1;
    local_18 = piVar5;
    local_40[0] = -1;
    local_40[1] = 0xffffffff;
    local_40[2] = 0xffffffff;
    local_40[3] = 0xffffffff;
    local_40[6] = 0xffffffff;
    piVar3 = param_1 + 8;
    local_1c = local_1c + -1;
    local_40[4] = 0;
    local_40[5] = 0;
    local_24 = 0;
    piVar6 = local_40;
    for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
      *param_1 = *piVar6;
      piVar6 = piVar6 + 1;
      param_1 = param_1 + 1;
    }
    param_1 = piVar3;
  } while (local_1c != 0);
  (**(code **)(*piVar2 + 200))();
  ExceptionList = local_10;
  return;
}

