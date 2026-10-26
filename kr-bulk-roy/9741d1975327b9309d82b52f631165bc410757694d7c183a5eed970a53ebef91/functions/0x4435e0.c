
void FUN_004435e0(int param_1,char param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined1 auStack_94 [20];
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 auStack_78 [12];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  int iStack_5c;
  undefined1 auStack_44 [4];
  undefined1 *local_40;
  undefined1 *local_3c;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009453a4;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_44;
  ExceptionList = &local_14;
  switch(param_2) {
  case '\0':
    FUN_004054c0();
    iStack_5c = 0;
    uStack_60 = 0x196;
    uStack_64 = 0x443646;
    FUN_005854b0();
    uStack_64 = 0x44364d;
    uStack_7c = FUN_00585330();
    local_3c = auStack_78;
    uStack_80 = 0x44365c;
    FUN_00402250();
    local_c = 0;
    uStack_7c = 0x1e1;
    break;
  case '\x01':
    FUN_004054c0();
    iStack_5c = 0;
    uStack_60 = 0x196;
    uStack_64 = 0x443681;
    FUN_005854b0();
    uStack_64 = 0x443688;
    uStack_7c = FUN_00585330();
    local_3c = auStack_78;
    uStack_80 = 0x443697;
    FUN_00402250();
    local_c = 1;
    uStack_7c = 0x1e2;
    break;
  case '\x02':
    FUN_004054c0();
    iStack_5c = 0;
    uStack_60 = 0x196;
    uStack_64 = 0x4436bc;
    FUN_005854b0();
    uStack_64 = 0x4436c3;
    uStack_7c = FUN_00585330();
    local_3c = auStack_78;
    uStack_80 = 0x4436d2;
    FUN_00402250();
    local_c = 2;
    uStack_7c = 0x10;
    break;
  case '\x03':
    FUN_004054c0();
    iStack_5c = 0;
    uStack_60 = 0x196;
    uStack_64 = 0x4436f0;
    FUN_005854b0();
    uStack_64 = 0x4436f7;
    uStack_7c = FUN_00585330();
    local_3c = auStack_78;
    uStack_80 = 0x443706;
    FUN_00402250();
    local_c = 3;
    uStack_7c = 0xb;
    break;
  case '\x04':
    FUN_004054c0();
    iStack_5c = 0;
    uStack_60 = 0x196;
    uStack_64 = 0x443725;
    FUN_005854b0();
    uStack_64 = 0x44372c;
    uStack_7c = FUN_00585330();
    local_3c = auStack_78;
    uStack_80 = 0x44373b;
    FUN_00402250();
    local_c = 4;
    uStack_7c = 0x1e3;
    break;
  case '\x05':
    FUN_004054c0();
    iStack_5c = 0;
    uStack_60 = 0x196;
    uStack_64 = 0x44375d;
    FUN_005854b0();
    uStack_64 = 0x443764;
    uStack_7c = FUN_00585330();
    local_3c = auStack_78;
    uStack_80 = 0x443773;
    FUN_00402250();
    local_c = 5;
    uStack_7c = 0xd;
    break;
  default:
    goto switchD_0044362c_default;
  }
  uStack_80 = 0x443782;
  FUN_005854b0();
  uStack_80 = 0x443789;
  uVar1 = FUN_00585330();
  local_40 = auStack_94;
  FUN_00402250(uVar1);
  local_c = 0xffffffff;
  FUN_0058b270(0xca);
switchD_0044362c_default:
  if (param_2 == '\x04') {
    iVar3 = *(int *)(param_1 + 0xfc);
    *(undefined4 *)(iVar3 + 0x94) = 2;
    *(undefined4 *)(iVar3 + 0x98) = *(undefined4 *)(iVar3 + 0xa0);
    *(undefined4 *)(iVar3 + 0xa8) = 0;
    *(undefined4 *)(iVar3 + 0xb0) = 0;
    *(undefined4 *)(iVar3 + 0x90) = 0;
    FUN_0068a590();
    local_24 = 0xf;
    local_28 = 0;
    local_38 = local_38 & 0xffffff00;
    iStack_5c = 0x443814;
    FUN_0040b310();
    local_c = 6;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c._0_1_ = 7;
      local_c._1_3_ = 0;
      FUN_0080a3a0();
      iStack_5c = 0x443840;
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_c = CONCAT31(local_c._1_3_,6);
    }
    iStack_5c = 0x443856;
    piVar2 = (int *)FUN_0080ab00();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))();
    }
    local_c = 0xffffffff;
    if (0xf < local_24) {
      iStack_5c = 0x44387c;
      FUN_0089120c();
    }
  }
  else {
    FUN_0068a350();
  }
  iStack_5c = param_1;
  local_40 = (undefined1 *)0x0;
  uStack_60 = 0x44389d;
  FUN_00442710();
  iStack_5c = param_1;
  local_40 = (undefined1 *)0x1;
  uStack_60 = 0x4438b0;
  FUN_00442710();
  FUN_00442590();
  if (param_3 != 0) {
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_c = 8;
      FUN_0051c120();
      iStack_5c = 0x4438e9;
      _atexit((_func_4879 *)&LAB_00bccc90);
      local_c = 0xffffffff;
    }
    local_40 = (undefined1 *)param_3;
    iStack_5c = 0x44390b;
    FUN_008438c0();
    if (local_3c == DAT_00f8d91c) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(local_3c + 0x10);
    }
    uStack_60 = *(undefined4 *)(iVar3 + 0x1c);
    uStack_64 = *(undefined4 *)(iVar3 + 0x20);
    iStack_5c = 0;
    uStack_68 = 0x443938;
    (**(code **)(**(int **)(param_1 + 0x14c) + 0x19c))();
    uStack_68 = 1;
    uStack_6c = 0x44394a;
    (**(code **)(**(int **)(param_1 + 0x14c) + 0x94))();
    uStack_6c = 0x44395c;
    (**(code **)(**(int **)(param_1 + 0x14c) + 200))();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_44);
  return;
}

