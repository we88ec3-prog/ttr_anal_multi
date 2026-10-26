
void FUN_007a7cc0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint3 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_009324e4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x1c) != 0) {
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_8 = 0;
    FUN_007c7dd0(*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x10),&local_24,
                 DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    uVar4 = DAT_00fb79e8 & 1;
    *(int *)(param_1 + 0x128) = param_2;
    if (uVar4 == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8._0_1_ = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      uVar3 = local_8._1_3_;
      local_8 = (uint)local_8._1_3_ << 8;
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8._0_1_ = 2;
        local_8._1_3_ = uVar3;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = (uint)local_8._1_3_ << 8;
      }
    }
    (**(code **)(*DAT_00fb76a8 + 0xa0))(&local_14,"2s_alphatest");
    uVar4 = 0;
    if (local_20 - local_24 >> 2 != 0) {
      do {
        piVar1 = *(int **)(local_24 + uVar4 * 4);
        if (piVar1[0x59] == local_14) {
          iVar2 = *piVar1;
          if (param_2 == 0) {
            if (*(float *)(param_1 + 0x138) == 1.0) {
              (**(code **)(iVar2 + 0x48))(0x1b);
              (**(code **)(*piVar1 + 0x48))(0x13);
              (**(code **)(*piVar1 + 0x48))(0x14);
              goto LAB_007a7e37;
            }
            (**(code **)(iVar2 + 0x44))(0x1b,1,0);
            (**(code **)(*piVar1 + 0x44))(0x13,5,2);
            uVar5 = 6;
          }
          else {
            (**(code **)(iVar2 + 0x44))(0x1b,1,0);
            (**(code **)(*piVar1 + 0x44))(0x13,5,2);
            uVar5 = 2;
          }
          (**(code **)(*piVar1 + 0x44))(0x14,uVar5,1);
        }
LAB_007a7e37:
        uVar4 = uVar4 + 1;
      } while (uVar4 < (uint)(local_20 - local_24 >> 2));
    }
    if (local_24 != 0) {
      FUN_0089120c(local_24);
    }
  }
  ExceptionList = local_10;
  return;
}

