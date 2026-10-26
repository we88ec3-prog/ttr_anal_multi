
undefined4 FUN_0087a8c0(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,int param_5)

{
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090dfd8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_5 + 0x40) == 0) {
    OutputDebugStringA("G-Blender Effect Warning : Null Technique\n");
  }
  else {
    (**(code **)(**(int **)(param_1 + 4) + 0xe8))
              (*(int **)(param_1 + 4),*(int *)(param_5 + 0x40),DAT_00d61f20 ^ (uint)&stack0xfffffffc
              );
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0xffffffff;
    local_18 = 0;
    local_14 = 0;
    local_8 = 0;
    local_34 = *param_4;
    local_30 = 0;
    local_2c = FUN_0087af70(param_1 + 0x60);
    local_28 = param_4[3];
    local_18 = param_4[7];
    FUN_00863260(param_3 + 0x28,&local_34);
    FUN_008630f0(param_3,param_1,param_2);
  }
  ExceptionList = local_10;
  return 1;
}

