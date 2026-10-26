
undefined4 *
FUN_00543700(undefined4 *param_1,short param_2,undefined2 param_3,float param_4,char param_5,
            undefined4 param_6,undefined1 param_7)

{
  float *pfVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float *in_ECX;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00929828;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004ca730(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x3c] = 0;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  *(undefined2 *)((int)param_1 + 0xf6) = param_3;
  *(undefined1 *)(param_1 + 0x3e) = param_7;
  param_1[0x40] = param_6;
  *param_1 = CCheckPoint::vftable;
  *(short *)(param_1 + 0x3d) = param_2;
  param_1[0x3f] = param_4;
  *(undefined1 *)(param_1 + 0x41) = 0;
  *(char *)((int)param_1 + 0x105) = param_5;
  pfVar1 = (float *)(param_1 + 0x28);
  if ((*in_ECX != (float)param_1[0x28]) || (in_ECX[1] != (float)param_1[0x29])) {
    *pfVar1 = *in_ECX;
    param_1[0x29] = in_ECX[1];
    param_1[0x2b] = 1;
    FUN_004cab30();
  }
  if (param_2 == 2) {
    iVar2 = FUN_004fb910();
    if ((iVar2 == 0) || (3 < *(int *)(iVar2 + 8) - 1U)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 8) + -1;
    }
    if ((DAT_00fdf6dc & 1) == 0) {
      DAT_00fdf6dc = DAT_00fdf6dc | 1;
      local_8._0_1_ = 1;
      FUN_00550820();
      _atexit((_func_4879 *)&LAB_00bce6b0);
      local_8._0_1_ = 0;
    }
    FUN_00551b80(0,iVar2);
    uVar3 = FUN_00551dd0(&DAT_00fdf680,0,pfVar1,0,0x40000000,0);
  }
  else {
    if (param_2 == 0) {
      param_1[0x2d] = param_4 * 0.2334;
      param_1[0x3f] = param_4 * 0.8;
      if (*(char *)(param_1 + 0x3e) == '\0') {
        puVar4 = (undefined4 *)FUN_00891268(0x48);
        local_8._0_1_ = 2;
        if (puVar4 == (undefined4 *)0x0) {
          local_8._0_1_ = 0;
          puVar4 = (undefined4 *)FUN_00489fb0();
          uVar3 = *puVar4;
          puVar4 = (undefined4 *)0x0;
        }
        else {
          if (param_5 == '\x01') {
            iVar2 = 4;
          }
          else {
            iVar2 = *(short *)((int)param_1 + 0xf6) + 1;
          }
          puVar4[1] = (int)*(short *)((int)param_1 + 0xf6);
          puVar4[2] = iVar2;
          *puVar4 = 8;
          *(undefined1 *)(puVar4 + 3) = 1;
          puVar4[4] = *pfVar1;
          puVar4[5] = param_1[0x29];
          puVar4[7] = 0;
          puVar4[6] = 0;
          puVar4[8] = 0;
          puVar4[0xe] = 7;
          puVar4[0xd] = 0;
          *(undefined2 *)(puVar4 + 9) = 0;
          FUN_00402160(&DAT_00bed1fc,0);
          puVar4[0x10] = 0;
          puVar4[0x11] = 0;
          local_8._0_1_ = 0;
          puVar5 = (undefined4 *)FUN_00489fb0();
          uVar3 = *puVar5;
        }
      }
      else {
        puVar4 = (undefined4 *)FUN_00891268(0x48);
        local_8._0_1_ = 3;
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          puVar4[1] = (int)*(short *)((int)param_1 + 0xf6);
          *puVar4 = 0xb;
          *(undefined1 *)(puVar4 + 3) = 1;
          puVar4[2] = (param_5 == '\x01') + 1;
          puVar4[4] = *pfVar1;
          uVar3 = param_1[0x29];
          puVar4[7] = 0;
          puVar4[5] = uVar3;
          puVar4[6] = 0;
          puVar4[8] = 0;
          puVar4[0xe] = 7;
          puVar4[0xd] = 0;
          *(undefined2 *)(puVar4 + 9) = 0;
          FUN_00402160(&DAT_00bed1fc,0);
          puVar4[0x10] = 0;
          puVar4[0x11] = 0;
        }
        local_8._0_1_ = 0;
        puVar5 = (undefined4 *)FUN_00489fb0();
        uVar3 = *puVar5;
      }
      FUN_0056f5c0(uVar3,puVar4);
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_8._0_1_ = 4;
        FUN_004f3d80();
        _atexit((_func_4879 *)&LAB_00bcd1e0);
        local_8._0_1_ = 0;
      }
      FUN_004f7cc0();
      if ((DAT_00fdf6dc & 1) == 0) {
        DAT_00fdf6dc = DAT_00fdf6dc | 1;
        local_8._0_1_ = 5;
        FUN_00550820();
        _atexit((_func_4879 *)&LAB_00bce6b0);
        local_8._0_1_ = 0;
      }
      uVar3 = param_1[0x2d];
      uVar7 = 0;
      uVar6 = 0;
    }
    else {
      if (param_2 != 4) {
        ExceptionList = local_10;
        return param_1;
      }
      param_1[0x3f] = param_4 * 0.5;
      uVar3 = param_1[0x2d];
      uVar7 = 0;
      uVar6 = 0;
      FUN_0049b140(0,0,uVar3);
    }
    uVar3 = FUN_00551f90(uVar6,uVar7,uVar3);
  }
  param_1[0x3c] = uVar3;
  ExceptionList = local_10;
  return param_1;
}

