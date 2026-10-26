
undefined4 FUN_007ba8a0(float param_1,float param_2,float *param_3,undefined4 param_4)

{
  int iVar1;
  int in_ECX;
  undefined4 *extraout_ECX;
  uint uVar2;
  float unaff_EDI;
  uint uVar3;
  float fStack_2c;
  void *local_28;
  void *local_24;
  float local_20;
  void *local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00909f55;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_008380b0(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
  uVar3 = 0;
  local_c = 0;
  iVar1 = *(int *)(in_ECX + 0x40);
  if ((iVar1 != 0) && (0.0 <= param_1)) {
    local_24 = *(void **)(iVar1 + 0x158);
    local_20 = *(float *)(iVar1 + 0x15c);
    if ((param_1 <= (float)local_24) &&
       ((0.0 <= param_2 && (local_24 = *(void **)(iVar1 + 0x158), param_2 <= local_20)))) {
      local_28 = (void *)0xc77fff00;
      uVar2 = *(int *)(in_ECX + 0xcc) - *(int *)(in_ECX + 200) >> 2;
      if (uVar2 != 0) {
        do {
          iVar1 = FUN_007e97b0(param_1,param_2);
          if (iVar1 != 0) {
            local_24 = local_28;
            (**(code **)*extraout_ECX)(param_1,param_2,&local_24,param_4);
            if ((float)local_28 < (float)local_24) {
              local_28 = local_24;
            }
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < uVar2);
      }
      local_1c[0] = local_28;
      (**(code **)**(undefined4 **)(in_ECX + 0x40))(param_1,param_2,local_1c,param_4);
      if (unaff_EDI < fStack_2c) {
        unaff_EDI = fStack_2c;
      }
      *param_3 = unaff_EDI;
      FUN_00837fd0();
      PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
      ExceptionList = local_24;
      return 1;
    }
  }
  FUN_00837fd0();
  PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
  ExceptionList = local_14;
  return 0;
}

