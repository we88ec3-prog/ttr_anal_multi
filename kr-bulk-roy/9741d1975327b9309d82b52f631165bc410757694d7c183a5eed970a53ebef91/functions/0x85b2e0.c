
undefined4 FUN_0085b2e0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_128 [44];
  undefined4 local_fc [4];
  undefined1 local_ec [4];
  undefined4 local_e8;
  undefined4 local_d4;
  undefined4 local_c0;
  undefined **local_b0 [4];
  undefined **local_a0 [4];
  undefined **local_90 [4];
  undefined **local_80 [4];
  undefined **local_70 [4];
  undefined **local_60 [4];
  undefined **local_50 [4];
  undefined **local_40 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined **local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar1 = param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00908e71;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  (**(code **)(**(int **)(param_1 + 4) + 0x10))
            (*(int **)(param_1 + 4),*param_2,local_128,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar2 = FUN_00858b10();
  if (iVar2 == 0) {
    ExceptionList = local_10;
    return 0;
  }
  local_20 = gbParam::vftable;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_8 = 0;
  switch(iVar2) {
  case 1:
    param_2 = (undefined4 *)0x0;
    (**(code **)(**(int **)(param_1 + 4) + 0x5c))(*(int **)(param_1 + 4),*puVar1,&param_2);
    FUN_007bb350();
    FUN_00867960(local_60,&param_2);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_0085dcd0();
    local_60[0] = gbParam::vftable;
    break;
  case 2:
    param_2 = (undefined4 *)0x0;
    (**(code **)(**(int **)(param_1 + 4) + 0x6c))(*(int **)(param_1 + 4),*puVar1,&param_2);
    FUN_007bb350();
    FUN_00867960(local_90,&param_2);
    local_8 = CONCAT31(local_8._1_3_,8);
    FUN_0085dcd0();
    local_90[0] = gbParam::vftable;
    break;
  case 3:
    param_2 = (undefined4 *)0x0;
    (**(code **)(**(int **)(param_1 + 4) + 0x7c))(*(int **)(param_1 + 4),*puVar1,&param_2);
    FUN_007bb350();
    FUN_008679b0(local_80,&param_2);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0085dcd0();
    local_80[0] = gbParam::vftable;
    break;
  default:
    local_20 = gbParam::vftable;
    FUN_00867f40();
    ExceptionList = local_10;
    return 0;
  case 5:
    local_28 = 0;
    local_24 = 0;
    (**(code **)(**(int **)(param_1 + 4) + 0x54))(*(int **)(param_1 + 4),*puVar1,&local_28,8);
    FUN_007bb350();
    FUN_00867b20(local_a0,&local_28);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0085dcd0();
    local_a0[0] = gbParam::vftable;
    break;
  case 6:
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    (**(code **)(**(int **)(param_1 + 4) + 0x54))(*(int **)(param_1 + 4),*puVar1,&local_2c,0xc);
    FUN_007bb350();
    FUN_00867ab0(local_40,&local_2c);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_0085dcd0();
    local_40[0] = gbParam::vftable;
    break;
  case 7:
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0x3f800000;
    (**(code **)(**(int **)(param_1 + 4) + 0x54))(*(int **)(param_1 + 4),*puVar1,&local_30,0x10);
    FUN_007bb350();
    FUN_00867b90(local_b0,&local_30);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_0085dcd0();
    local_b0[0] = gbParam::vftable;
    break;
  case 8:
    FUN_00780450();
    (**(code **)(**(int **)(param_1 + 4) + 0x54))(*(int **)(param_1 + 4),*param_2,local_ec,0x34);
    FUN_007bb350();
    FUN_00867c10(local_50,local_ec);
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_0085dcd0();
    local_50[0] = gbParam::vftable;
    break;
  case 9:
    _memset(local_fc,0,0x44);
    local_c0 = 0x3f800000;
    local_d4 = 0x3f800000;
    local_e8 = 0x3f800000;
    local_fc[0] = 0x3f800000;
    (**(code **)(**(int **)(param_1 + 4) + 0x54))(*(int **)(param_1 + 4),*puVar1,local_fc,0x44);
    FUN_007bb350();
    FUN_00867c90(local_70,local_fc);
    local_8 = CONCAT31(local_8._1_3_,7);
    FUN_0085dcd0();
    local_70[0] = gbParam::vftable;
  }
  FUN_00867f40();
  local_20 = gbParam::vftable;
  FUN_00867f40();
  ExceptionList = local_10;
  return 1;
}

