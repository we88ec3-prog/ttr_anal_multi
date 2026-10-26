
/* WARNING: Removing unreachable block (ram,0x006dc140) */

void FUN_006dbf20(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  float local_24;
  undefined4 local_1c;
  int *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939adf;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = param_1 + 4;
  if ((param_1[4] != 0) && (0 < *param_1)) {
    (**(code **)(*(int *)(param_1[4] + 8) + 8))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    FUN_004c9f40();
  }
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_8 = 0;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
    local_8 = 0xffffffff;
  }
  local_14 = param_2;
  FUN_00515790(&local_14);
  if ((local_18 != (int *)DAT_00fc0e94) && (*(int *)(*(int *)((int)local_18 + 0x10) + 0x54) != 0)) {
    local_18 = (int *)FUN_00891268(0x170);
    local_8 = 1;
    if (local_18 == (int *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_007a4c50(local_18,param_2);
    }
    local_8 = 0xffffffff;
    local_1c = 0;
    local_18 = (int *)0x0;
    FUN_004ca460(&local_1c,uVar5);
    local_8 = 2;
    FUN_004e0f60();
    piVar4 = local_18;
    local_8 = 0xffffffff;
    if (local_18 != (int *)0x0) {
      LOCK();
      iVar3 = local_18[1] + -1;
      local_18[1] = iVar3;
      UNLOCK();
      if (iVar3 == 0) {
        (**(code **)*local_18)();
        piVar2 = piVar4 + 2;
        LOCK();
        iVar3 = *piVar2 + -1;
        *piVar2 = iVar3;
        UNLOCK();
        if (iVar3 == 0) {
          (**(code **)(*piVar4 + 4))();
        }
      }
    }
    FUN_007a6ea0(*piVar1,1,0);
  }
  if ((0 < *param_1) && (*piVar1 != 0)) {
    local_1c = 0;
    local_18 = (int *)0x3f800000;
    FUN_007a8630(0);
    iVar3 = *piVar1;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_8 = 3;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_8 = 0xffffffff;
    }
    iVar6 = FUN_004f7a70();
    (**(code **)(*(int *)(iVar3 + 4) + 0x14))((120.0 / local_24) * *(float *)(iVar6 + 0x5c));
    FUN_007a6970(param_1[0x1e],0x3f800000);
  }
  if (param_1[0x2d] != param_1[0x2e]) {
    param_1[0x2e] = param_1[0x2d];
  }
  ExceptionList = local_10;
  return;
}

