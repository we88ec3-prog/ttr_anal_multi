
void FUN_005a7890(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  bool bVar4;
  undefined4 ***local_4c [5];
  uint local_38;
  undefined4 ***local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00943b5d;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x10) == 0xf42a3) {
    FUN_00597a30();
  }
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf4241:
    (**(code **)(**(int **)(in_ECX + 0x138) + 0xd4))();
    (**(code **)(**(int **)(in_ECX + 0x150) + 0xd4))();
    FUN_005a7570();
    break;
  case 0xf4242:
    piVar1 = (int *)FUN_0044d680();
    if (((*piVar1 != 0) && (*(int *)(*piVar1 + 0x28) == 2)) &&
       (puVar2 = (undefined4 *)FUN_00891268(), puVar2 != (undefined4 *)0x0)) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf4400;
    }
    switch(*(undefined4 *)(param_1 + 0x14)) {
    case 1:
      bVar4 = *(int *)(param_1 + 0x28) != 0;
      if (bVar4) {
        FUN_00402110();
      }
      else {
        FUN_005854b0();
        FUN_00585330();
        FUN_00402250();
      }
      local_8 = (uint)bVar4;
      FUN_00402880();
      local_8 = 2;
      if (bVar4) {
        FUN_004fa440();
      }
      local_8._0_1_ = 4;
      if (!bVar4) {
        FUN_004fa440();
      }
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8._0_1_ = 5;
      if (local_1c < 8) {
        local_30[0] = local_30;
      }
      FUN_00402250(local_30[0]);
      local_8 = CONCAT31(local_8._1_3_,4);
      goto LAB_005a7a86;
    case 2:
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8 = 6;
      break;
    case 3:
      bVar4 = *(int *)(param_1 + 0x28) != 0;
      if (bVar4) {
        FUN_00402110();
        local_8 = 8;
      }
      else {
        FUN_005854b0();
        FUN_00585330();
        FUN_00402250();
        local_8 = 7;
      }
      FUN_00402880();
      local_8 = 9;
      if (bVar4) {
        FUN_004fa440();
      }
      local_8._0_1_ = 0xb;
      if (!bVar4) {
        FUN_004fa440();
      }
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8._0_1_ = 0xc;
      if (local_1c < 8) {
        local_30[0] = local_30;
      }
      FUN_00402250(local_30[0]);
      local_8 = CONCAT31(local_8._1_3_,0xb);
LAB_005a7a86:
      FUN_0058b270(0xca);
      local_8 = 0xffffffff;
      FUN_004fa440();
      goto LAB_005a7f1d;
    case 4:
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8 = 0xd;
      break;
    case 5:
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8 = 0xe;
      break;
    case 6:
      bVar4 = *(int *)(param_1 + 0x28) != 0;
      if (bVar4) {
        FUN_00402110();
        local_8 = 0x10;
      }
      else {
        FUN_005854b0();
        FUN_00585330();
        FUN_00402250();
        local_8 = 0xf;
      }
      FUN_00402880();
      local_8 = 0x11;
      if (bVar4) {
        FUN_004fa440();
      }
      local_8._0_1_ = 0x13;
      if (!bVar4) {
        FUN_004fa440();
      }
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8._0_1_ = 0x14;
      if (local_38 < 8) {
        local_4c[0] = local_4c;
      }
      FUN_00402250(local_4c[0]);
      local_8 = CONCAT31(local_8._1_3_,0x13);
      FUN_0058b270(0xca);
      local_8 = 0xffffffff;
      FUN_004fa440();
      goto LAB_005a7f1d;
    case 7:
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8 = 0x15;
      break;
    case 8:
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8 = 0x18;
      break;
    case 9:
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8 = 0x19;
      break;
    case 10:
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8 = 0x16;
      break;
    case 0xb:
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8 = 0x17;
      break;
    case 0xc:
      puVar2 = (undefined4 *)FUN_00891268();
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4400;
      }
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8 = 0x1a;
      FUN_005854b0();
      uVar3 = FUN_00585330();
      FUN_00402250(uVar3);
      goto LAB_005a7f10;
    default:
      FUN_005854b0();
      FUN_00585330();
      FUN_00402250();
      local_8 = 0x1b;
    }
    FUN_005854b0();
    uVar3 = FUN_00585330();
    FUN_00402250(uVar3);
LAB_005a7f10:
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
LAB_005a7f1d:
    FUN_0066e400();
    break;
  case 0xf4243:
    FUN_0066b910();
    break;
  case 0xf42c2:
    FUN_00484ca0();
    break;
  case 0xf42c3:
    FUN_0044db10();
    break;
  case 0xf42c4:
    FUN_00484b40();
    break;
  case 0xf42c5:
    FUN_0047f070();
    break;
  case 0xf42c6:
    FUN_0047f1c0();
    break;
  case 0xf42c7:
    (**(code **)(**(int **)(in_ECX + 0x164) + 0xd0))();
    break;
  case 0xf42c8:
    FUN_0047f8f0();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

