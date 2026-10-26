
void FUN_007a9a70(int param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 ***pppuVar4;
  char cVar5;
  undefined4 *puVar6;
  undefined4 **local_58;
  undefined4 *local_54;
  uint uStack_50;
  undefined1 local_40 [32];
  undefined4 *local_20;
  int *local_1c;
  undefined1 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00939094;
  local_10 = ExceptionList;
  uStack_50 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(char *)(*(int *)(param_2 + 8) + 4) == '\0') {
    local_54 = (undefined4 *)0x38;
    local_58 = (undefined4 **)0x7a9ab7;
    local_54 = (undefined4 *)FUN_00891268();
    local_8._0_1_ = 1;
    if (local_54 == (undefined4 *)0x0) {
      local_54 = (undefined4 *)0x0;
    }
    else {
      local_58 = (undefined4 **)0x7a9acb;
      local_54 = (undefined4 *)FUN_007a5680();
    }
    local_58 = &local_20;
    local_8._0_1_ = 0;
    local_20 = (undefined4 *)0x0;
    local_1c = (int *)0x0;
    FUN_007aa780();
    puVar6 = local_20;
    local_8 = CONCAT31(local_8._1_3_,2);
    local_54 = (undefined4 *)(param_1 + 0x2c);
    *local_20 = *(undefined4 *)(param_1 + 0x18);
    local_58 = (undefined4 **)0x7a9afb;
    FUN_007a5730();
    puVar6[1] = *(undefined4 *)(param_1 + 0x1c);
    if (puVar6 + 10 != (undefined4 *)(param_1 + 0x6c)) {
      local_54 = (undefined4 *)puVar6[0xb];
      local_58 = (undefined4 **)*local_54;
      FUN_006d7120();
      local_54 = (undefined4 *)(param_1 + 0x6c);
      local_58 = (undefined4 **)0x7a9b27;
      FUN_007aa150();
      puVar6 = local_20;
    }
    piVar3 = local_1c;
    local_18 = (undefined1 *)&local_58;
    local_58 = (undefined4 **)0x0;
    local_54 = (undefined4 *)0x0;
    pppuVar4 = &local_58;
    if ((local_1c != (int *)0x0) &&
       (cVar5 = FUN_0047c250(), pppuVar4 = (undefined4 ***)local_18, cVar5 != '\0')) {
      FUN_007a31c0(puVar6,piVar3);
      pppuVar4 = (undefined4 ***)local_18;
    }
    local_18 = (undefined1 *)pppuVar4;
    uVar2 = local_8 >> 8;
    if ((DAT_00fc0f60 & 1) == 0) {
      DAT_00fc0f60 = DAT_00fc0f60 | 1;
      local_8._0_1_ = 4;
      FUN_0079cf40();
      _atexit((_func_4879 *)&LAB_00bcdb80);
      uVar2 = (uint)local_8._1_3_;
    }
    local_8._1_3_ = (uint3)uVar2;
    local_8._0_1_ = 2;
    FUN_0079de00();
    local_8 = (uint)local_8._1_3_ << 8;
    if (piVar3 != (int *)0x0) {
      LOCK();
      iVar1 = piVar3[1] + -1;
      piVar3[1] = iVar1;
      UNLOCK();
      if (iVar1 == 0) {
        local_54 = (undefined4 *)0x7a9bb6;
        (**(code **)*piVar3)();
        LOCK();
        iVar1 = piVar3[2] + -1;
        piVar3[2] = iVar1;
        UNLOCK();
        if (iVar1 == 0) {
          local_54 = (undefined4 *)0x7a9bcb;
          (**(code **)(*piVar3 + 4))();
        }
      }
    }
  }
  local_54 = (undefined4 *)0x38;
  local_58 = (undefined4 **)0x7a9bd4;
  local_54 = (undefined4 *)FUN_00891268();
  local_8._0_1_ = 5;
  if (local_54 == (undefined4 *)0x0) {
    local_54 = (undefined4 *)0x0;
  }
  else {
    local_58 = (undefined4 **)0x7a9be8;
    local_54 = (undefined4 *)FUN_007a5680();
  }
  local_58 = &local_20;
  local_8._0_1_ = 0;
  local_20 = (undefined4 *)0x0;
  local_1c = (int *)0x0;
  FUN_007aa780();
  puVar6 = local_20;
  local_8 = CONCAT31(local_8._1_3_,6);
  *local_20 = *(undefined4 *)(param_1 + 0x18);
  local_54 = (undefined4 *)(*(int *)(param_2 + 8) + 0x28);
  local_58 = (undefined4 **)0x7a9c1e;
  FUN_007a5730();
  puVar6[1] = *(undefined4 *)(param_2 + 0x10);
  if (puVar6 + 10 != (undefined4 *)(param_2 + 0x18)) {
    local_54 = (undefined4 *)puVar6[0xb];
    local_58 = (undefined4 **)*local_54;
    FUN_006d7120();
    local_58 = (undefined4 **)0x7a9c53;
    local_54 = (undefined4 *)(param_2 + 0x18);
    FUN_007aa150();
    puVar6 = local_20;
  }
  piVar3 = local_1c;
  local_18 = (undefined1 *)&local_58;
  local_58 = (undefined4 **)0x0;
  local_54 = (undefined4 *)0x0;
  pppuVar4 = &local_58;
  if ((local_1c != (int *)0x0) &&
     (cVar5 = FUN_0047c250(), pppuVar4 = (undefined4 ***)local_18, cVar5 != '\0')) {
    FUN_007a31c0(puVar6,piVar3);
    pppuVar4 = (undefined4 ***)local_18;
  }
  local_18 = (undefined1 *)pppuVar4;
  uVar2 = local_8 >> 8;
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_8._0_1_ = 8;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
    uVar2 = (uint)local_8._1_3_;
  }
  local_8._1_3_ = (uint3)uVar2;
  local_8._0_1_ = 6;
  FUN_0079de00();
  local_8._0_1_ = 0;
  if (piVar3 != (int *)0x0) {
    LOCK();
    iVar1 = piVar3[1] + -1;
    piVar3[1] = iVar1;
    UNLOCK();
    if (iVar1 == 0) {
      local_54 = (undefined4 *)0x7a9ce2;
      (**(code **)*piVar3)();
      LOCK();
      iVar1 = piVar3[2] + -1;
      piVar3[2] = iVar1;
      UNLOCK();
      if (iVar1 == 0) {
        local_54 = (undefined4 *)0x7a9cf7;
        (**(code **)(*piVar3 + 4))();
      }
    }
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  local_54 = (undefined4 *)0x7a9d06;
  FUN_00597b70();
  local_54 = (undefined4 *)local_40;
  local_58 = (undefined4 **)0x7a9d0f;
  local_54 = (undefined4 *)FUN_007a5020();
  local_8._0_1_ = 9;
  local_58 = (undefined4 **)0x7a9d1c;
  FUN_007a5730();
  local_54 = (undefined4 *)local_40;
  local_8 = (uint)local_8._1_3_ << 8;
  local_58 = (undefined4 **)0x7a9d29;
  FUN_007a5120();
  local_8 = 0xffffffff;
  *(undefined1 *)(param_1 + 0x28) = 1;
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (param_3 != (int *)0x0) {
    LOCK();
    iVar1 = param_3[1] + -1;
    param_3[1] = iVar1;
    UNLOCK();
    if (iVar1 == 0) {
      local_54 = (undefined4 *)0x7a9d58;
      (**(code **)*param_3)();
      LOCK();
      iVar1 = param_3[2] + -1;
      param_3[2] = iVar1;
      UNLOCK();
      if (iVar1 == 0) {
        local_54 = (undefined4 *)0x7a9d6d;
        (**(code **)(*param_3 + 4))();
      }
    }
  }
  ExceptionList = local_10;
  return;
}

