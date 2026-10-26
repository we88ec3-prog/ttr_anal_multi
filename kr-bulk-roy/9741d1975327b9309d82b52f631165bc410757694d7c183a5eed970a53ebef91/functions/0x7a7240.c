
undefined4 FUN_007a7240(int param_1,ushort param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00918dea;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  local_38 = (uint)param_2;
  local_34 = 0;
  while( true ) {
    local_38._0_3_ = CONCAT12((undefined1)param_3,(undefined2)local_38);
    local_34 = CONCAT22(local_34._2_2_,*(undefined2 *)(param_1 + 0x18));
    if ((DAT_00fe1bc0 & 1) == 0) {
      DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
      local_c = 0;
      FUN_007bef00(uVar3);
      _atexit((_func_4879 *)&LAB_00bcec50);
      local_c = 0xffffffff;
    }
    uVar5 = local_34;
    uVar7 = local_38;
    local_28 = local_38;
    local_24 = local_34;
    FUN_004dd400(&DAT_00fe1b60,&local_40,&local_28);
    if ((local_40 == DAT_00fe1b64) || (iVar6 = *(int *)(local_40 + 0x18), iVar6 == 0)) {
      local_30._0_3_ = CONCAT12((undefined1)param_3,param_2);
      local_30 = (uint)(uint3)local_30;
      local_2c = 0;
      if ((DAT_00fe1bc0 & 1) == 0) {
        DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
        local_c = 1;
        FUN_007bef00(uVar3);
        _atexit((_func_4879 *)&LAB_00bcec50);
        local_c = 0xffffffff;
      }
      uVar5 = local_2c;
      uVar7 = local_30;
      local_20 = local_30;
      local_1c = local_2c;
      FUN_004dd400(&DAT_00fe1b60,&local_3c,&local_20);
      if (local_3c == DAT_00fe1b64) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(local_3c + 0x18);
      }
    }
    if (iVar6 != 0) break;
    if (param_3 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    param_3 = param_3 + -1;
  }
  FUN_007a7510(param_1,uVar7,uVar5);
  iVar1 = *(int *)(iVar6 + 0x20);
  iVar2 = *(int *)(param_1 + 0x60);
  iVar6 = iVar1 + 0x10;
  local_3c = iVar6;
  piVar4 = (int *)FUN_007a0c00(&local_3c);
  if (iVar2 != *piVar4) {
    FUN_007a7620(param_1,iVar6);
  }
  if ((param_4 != 0) && (iVar1 == 1)) {
    while( true ) {
      local_30._0_3_ = (uint3)param_4 & 0xffff;
      local_30 = CONCAT13(1,(uint3)local_30);
      local_2c = 0;
      iVar6 = param_3;
      while( true ) {
        local_30._0_3_ = CONCAT12((char)iVar6,(undefined2)local_30);
        uVar3 = local_30;
        local_2c = CONCAT22(local_2c._2_2_,*(undefined2 *)(param_1 + 0x18));
        uVar5 = local_2c;
        local_38 = local_30;
        local_34 = local_2c;
        if ((DAT_00fe1bc0 & 1) == 0) {
          DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
          local_c = 2;
          FUN_007bef00();
          _atexit((_func_4879 *)&LAB_00bcec50);
          local_c = 0xffffffff;
        }
        local_20 = uVar3;
        local_1c = uVar5;
        FUN_004dd400(&DAT_00fe1b60,&local_3c,&local_20);
        if ((local_3c != DAT_00fe1b64) && (*(int *)(local_3c + 0x18) != 0)) goto LAB_007a74bd;
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
      }
      if (param_4 == 0) break;
      param_4 = param_4 + -1;
    }
LAB_007a74bd:
    FUN_007a7510(param_1,local_38,local_34);
  }
  ExceptionList = local_14;
  return 1;
}

