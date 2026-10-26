
void FUN_007c7f90(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int local_48 [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_28 [16];
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00907730;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = (**(code **)(*param_1 + 4))(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == -0x5eed0000) {
    uVar5 = 0;
    iVar2 = param_1[0x37] - param_1[0x36] >> 2;
    if (0 < iVar2) {
      do {
        if (uVar5 < (uint)(param_1[0x37] - param_1[0x36] >> 2)) {
          uVar4 = *(undefined4 *)(param_1[0x36] + uVar5 * 4);
        }
        else {
          uVar4 = 0;
        }
        FUN_007c7f90(uVar4,param_2);
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < iVar2);
    }
    uVar5 = (**(code **)(*param_1 + 0x34))();
    uVar6 = 0;
    if (uVar5 != 0) {
      do {
        uVar4 = (**(code **)(*param_1 + 0x30))(uVar6,param_2);
        FUN_007c7f90(uVar4);
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar5);
    }
  }
  else if (iVar2 == -0x5edf0000) {
    uVar6 = 0;
    uVar5 = param_1[0x1f] - param_1[0x1e] >> 2;
    if (uVar5 != 0) {
      do {
        FUN_007c7f90(*(undefined4 *)(param_1[0x1e] + uVar6 * 4),param_2);
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar5);
      ExceptionList = local_10;
      return;
    }
  }
  else if (iVar2 == -0x5edc0000) {
    if ((int *)param_1[0x1d] == (int *)0x0) {
      local_14 = 0;
    }
    else {
      local_14 = (**(code **)(*(int *)param_1[0x1d] + 0x38))();
      if (local_14 == 0) {
        local_14 = 1;
      }
    }
    param_1 = (int *)0x0;
    if (local_14 != 0) {
      do {
        if ((int *)piVar1[0x1d] == (int *)0x0) {
LAB_007c8059:
          local_18 = (int *)0x0;
        }
        else {
          iVar2 = (**(code **)(*(int *)piVar1[0x1d] + 0x24))();
          if (iVar2 == 0) {
            if (param_1 != (int *)0x0) goto LAB_007c8059;
            local_18 = (int *)piVar1[0x1d];
          }
          else {
            iVar2 = (**(code **)(*(int *)piVar1[0x1d] + 0x38))();
            if (iVar2 <= (int)param_1) goto LAB_007c8059;
            local_18 = (int *)(**(code **)(*(int *)piVar1[0x1d] + 0x28))(param_1);
          }
        }
        piVar3 = (int *)FUN_00848020(&local_18);
        if (*piVar3 == *(int *)(param_2 + 4)) {
          local_38 = 0;
          local_34 = 0;
          local_30 = 0;
          local_8 = 0;
          FUN_007e8a90(local_48,&local_38);
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_004fcae0();
          FUN_007cd000(param_2,local_28);
          if (local_48[0] != 0) {
            FUN_0089120c(local_48[0]);
          }
          local_8 = 0xffffffff;
          local_48[0] = 0;
          local_48[1] = 0;
          local_48[2] = 0;
          local_38 = 0;
          local_34 = 0;
          local_30 = 0;
        }
        FUN_00848020(&local_18);
        local_18 = piVar1;
        FUN_007bb350();
        param_1 = (int *)((int)param_1 + 1);
        if (local_14 <= param_1) {
          ExceptionList = local_10;
          return;
        }
      } while( true );
    }
  }
  ExceptionList = local_10;
  return;
}

