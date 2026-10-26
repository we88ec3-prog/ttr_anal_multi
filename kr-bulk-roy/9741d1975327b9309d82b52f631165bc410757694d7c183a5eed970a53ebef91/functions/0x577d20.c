
void FUN_00577d20(float param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined2 local_c0 [2];
  undefined4 uStack_bc;
  uint *puStack_b8;
  char *pcStack_b4;
  float *local_b0;
  float *local_ac;
  float *local_a8;
  uint uStack_a4;
  float local_94;
  undefined1 *local_90;
  float local_8c;
  float local_88;
  float local_84;
  double local_80;
  undefined4 local_78;
  undefined4 local_74;
  float local_70 [5];
  uint local_5c;
  uint local_54 [4];
  undefined4 local_44;
  uint local_40;
  uint local_38 [4];
  undefined4 uStack_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091ddc8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_94;
  uStack_a4 = DAT_00d61f20 ^ (uint)&stack0xffffff60;
  ExceptionList = &local_14;
  local_88 = 744.0;
  local_94 = 128.0;
  local_a8 = (float *)0x577d87;
  FUN_006df330();
  local_a8 = (float *)0x577d8f;
  FUN_007b6d70();
  if (*(int *)((int)param_1 + 200) == 0xc) {
    local_88 = (float)((*(int *)((int)param_1 + 0xd0) >> 1) + -0x7b);
    local_94 = (float)((*(int *)((int)param_1 + 0xd4) >> 1) + -0x100);
    *(undefined4 *)((int)param_1 + 0x84) = 1;
  }
  else {
    local_a8 = (float *)0xe;
    local_ac = (float *)0xc10afc;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x577dc0;
    FUN_00402a70();
    local_c = 0;
    local_a8 = *(float **)((int)param_1 + 8);
    local_ac = (float *)0x577dd4;
    FUN_005737d0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x577df0;
      FUN_0089120c();
    }
    local_a8 = (float *)0x8;
    local_ac = (float *)0xc10b20;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x577e10;
    FUN_00402a70();
    local_90 = (undefined1 *)local_c0;
    local_c = 1;
    local_ac = (float *)0x7;
    local_b0 = (float *)0x0;
    local_c0[0] = 0;
    FUN_00402160(L"LeftSlot",8);
    puVar2 = (undefined4 *)FUN_0044f7e0(&local_80);
    local_a8 = (float *)puVar2[1];
    local_ac = (float *)*puVar2;
    local_b0 = local_70;
    pcStack_b4 = (char *)0x577e60;
    FUN_00573a90();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x577e7c;
      FUN_0089120c();
    }
    local_a8 = (float *)0xa;
    local_ac = (float *)0xc10b44;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x577ea0;
    FUN_00402a70();
    local_90 = (undefined1 *)local_c0;
    local_c = 2;
    local_ac = (float *)0x7;
    local_b0 = (float *)0x0;
    local_c0[0] = 0;
    FUN_00402160(L"MiddleSlot",10);
    puVar2 = (undefined4 *)FUN_0044f7e0(&local_80);
    local_a8 = (float *)puVar2[1];
    local_ac = (float *)*puVar2;
    local_b0 = local_70;
    pcStack_b4 = (char *)0x577ef0;
    FUN_00573a90();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x577f0c;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_ac = (float *)0xc10b64;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x577f30;
    FUN_00402a70();
    local_90 = (undefined1 *)local_c0;
    local_c = 3;
    local_ac = (float *)0x7;
    local_b0 = (float *)0x0;
    local_c0[0] = 0;
    FUN_00402160(L"RightSlot",9);
    puVar2 = (undefined4 *)FUN_0044f7e0(&local_80);
    local_a8 = (float *)puVar2[1];
    local_ac = (float *)*puVar2;
    local_b0 = local_70;
    pcStack_b4 = (char *)0x577f80;
    FUN_00573a90();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x577f9c;
      FUN_0089120c();
    }
    local_a8 = (float *)0xb;
    local_ac = (float *)0xc10a80;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x577fc0;
    FUN_00402a70();
    local_90 = (undefined1 *)local_c0;
    local_c = 4;
    local_ac = (float *)0x7;
    local_b0 = (float *)0x0;
    local_c0[0] = 0;
    FUN_00402160(L"StartButton",0xb);
    puVar2 = (undefined4 *)FUN_0044f7e0(&local_80);
    local_a8 = (float *)puVar2[1];
    local_ac = (float *)*puVar2;
    local_b0 = local_70;
    pcStack_b4 = (char *)0x578010;
    FUN_00573a90();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x57802c;
      FUN_0089120c();
    }
    local_a8 = (float *)0xa;
    local_ac = (float *)0xc10af0;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x578050;
    FUN_00402a70();
    local_90 = (undefined1 *)local_c0;
    local_c = 5;
    local_ac = (float *)0x7;
    local_b0 = (float *)0x0;
    local_c0[0] = 0;
    FUN_00402160(L"StopButton",10);
    puVar2 = (undefined4 *)FUN_0044f7e0(&local_80);
    local_a8 = (float *)puVar2[1];
    local_ac = (float *)*puVar2;
    local_b0 = local_70;
    pcStack_b4 = (char *)0x5780a0;
    FUN_00573a90();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x5780bc;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_ac = (float *)0xc10ba0;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x5780e0;
    FUN_00402a70();
    local_90 = (undefined1 *)local_c0;
    local_c = 6;
    local_ac = (float *)0x7;
    local_b0 = (float *)0x0;
    local_c0[0] = 0;
    FUN_00402160(L"LeftSlot",8);
    puVar2 = (undefined4 *)FUN_0044f7e0(&local_80);
    local_a8 = (float *)puVar2[1];
    local_ac = (float *)*puVar2;
    local_b0 = local_70;
    pcStack_b4 = (char *)0x578130;
    FUN_00573a90();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x57814c;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_ac = (float *)0xc10ba0;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x578170;
    FUN_00402a70();
    local_90 = (undefined1 *)local_c0;
    local_c = 7;
    local_ac = (float *)0x7;
    local_b0 = (float *)0x0;
    local_c0[0] = 0;
    FUN_00402160(L"MiddleSlot",10);
    puVar2 = (undefined4 *)FUN_0044f7e0(&local_80);
    local_a8 = (float *)puVar2[1];
    local_ac = (float *)*puVar2;
    local_b0 = local_70;
    pcStack_b4 = (char *)0x5781bd;
    FUN_00573a90();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x5781d9;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_ac = (float *)0xc10ba0;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x5781fd;
    FUN_00402a70();
    local_90 = (undefined1 *)local_c0;
    local_c = 8;
    local_ac = (float *)0x7;
    local_b0 = (float *)0x0;
    local_c0[0] = 0;
    FUN_00402160(L"RightSlot",9);
    puVar2 = (undefined4 *)FUN_0044f7e0(&local_80);
    local_a8 = (float *)puVar2[1];
    local_ac = (float *)*puVar2;
    local_b0 = local_70;
    pcStack_b4 = (char *)0x57824d;
    FUN_00573a90();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578268;
      FUN_0089120c();
    }
    local_a8 = (float *)0xc;
    local_ac = (float *)0xc10a8c;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x57828c;
    FUN_00402a70();
    local_c = 9;
    local_a8 = *(float **)((int)param_1 + 8);
    local_ac = (float *)0x5782a4;
    FUN_005737d0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x5782bc;
      FUN_0089120c();
    }
    if (*(int *)((int)param_1 + 200) == 0xb) {
      local_a8 = (float *)0xb;
      local_ac = (float *)0xc10bc4;
      local_5c = 0xf;
      local_70[4] = 0.0;
      local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
      local_b0 = (float *)0x5782ed;
      FUN_00402a70();
      local_90 = (undefined1 *)local_c0;
      local_c = 10;
      local_ac = (float *)0x7;
      local_b0 = (float *)0x0;
      local_c0[0] = 0;
      FUN_00402160(L"ItemOutline",0xb);
      puVar2 = (undefined4 *)FUN_0044f7e0(&local_80);
      local_a8 = (float *)puVar2[1];
      local_ac = (float *)*puVar2;
      local_b0 = local_70;
      pcStack_b4 = (char *)0x57833d;
      FUN_00573a90();
      local_c = 0xffffffff;
      if (0xf < local_5c) {
        local_a8 = (float *)local_70[0];
        local_ac = (float *)0x578359;
        FUN_0089120c();
      }
      local_a8 = (float *)0xf;
      local_ac = (float *)0xc10bf0;
      local_5c = 0xf;
      local_70[4] = 0.0;
      local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
      local_b0 = (float *)0x57837d;
      FUN_00402a70();
      local_90 = (undefined1 *)local_c0;
      local_c = 0xb;
      local_ac = (float *)0x7;
      local_b0 = (float *)0x0;
      local_c0[0] = 0;
      FUN_00402160(L"AcquisitionItem",0xf);
      puVar2 = (undefined4 *)FUN_0044f7e0(&local_80);
      local_a8 = (float *)puVar2[1];
      local_ac = (float *)*puVar2;
      local_b0 = local_70;
      pcStack_b4 = (char *)0x5783cd;
      FUN_00573a90();
      local_c = 0xffffffff;
      if (0xf < local_5c) {
        local_a8 = (float *)local_70[0];
        local_ac = (float *)0x5783e9;
        FUN_0089120c();
      }
      local_a8 = (float *)0x9;
      local_ac = (float *)0xc10c14;
      local_5c = 0xf;
      local_70[4] = 0.0;
      local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
      local_b0 = (float *)0x57840d;
      FUN_00402a70();
      local_90 = (undefined1 *)local_c0;
      local_c = 0xc;
      local_ac = (float *)0x7;
      local_b0 = (float *)0x0;
      local_c0[0] = 0;
      FUN_00402160(L"ItemImage",9);
      piVar3 = (int *)FUN_0044f7e0(&local_80);
      local_a8 = (float *)piVar3[1];
      local_ac = (float *)*piVar3;
      local_b0 = local_70;
      pcStack_b4 = (char *)0x57845d;
      FUN_00573a90();
      local_c = 0xffffffff;
      if (0xf < local_5c) {
        local_a8 = (float *)local_70[0];
        local_ac = (float *)0x578479;
        FUN_0089120c();
      }
    }
  }
  if (*(int *)((int)param_1 + 0x84) != 0) {
    local_a8 = (float *)0xb;
    local_ac = (float *)0xc10c20;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x5784e9;
    FUN_00402a70();
    local_c = 0xd;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x57850f;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x57852b;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_88 = local_88 + 14.0;
    local_ac = (float *)0xc10c2c;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_94 = local_94 + 86.0;
    local_b0 = (float *)0x57856b;
    FUN_00402a70();
    local_c = 0xe;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x578591;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x5785ad;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_ac = (float *)0xc10c2c;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x5785d2;
    FUN_00402a70();
    local_c = 0xf;
    local_84 = local_88 + 32.0;
    local_ac = local_70;
    local_a8 = (float *)local_94;
    local_b0 = (float *)0x578602;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578622;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_ac = (float *)0xc10c2c;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x578646;
    FUN_00402a70();
    local_c = 0x10;
    local_8c = local_88 + 64.0;
    local_ac = local_70;
    local_a8 = (float *)local_94;
    local_b0 = (float *)0x578676;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578692;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_94 = local_94 + 47.0;
    local_ac = (float *)0xc10c38;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x5786c4;
    FUN_00402a70();
    local_c = 0x11;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x5786ea;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578706;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_ac = (float *)0xc10c38;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x57872a;
    FUN_00402a70();
    local_c = 0x12;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x578750;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x57876c;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_ac = (float *)0xc10c38;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x578790;
    FUN_00402a70();
    local_c = 0x13;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x5787b6;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x5787d2;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_94 = local_94 + 47.0;
    local_ac = (float *)0xc10c44;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x578804;
    FUN_00402a70();
    local_c = 0x14;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x57882a;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578846;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_ac = (float *)0xc10c44;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x57886a;
    FUN_00402a70();
    local_c = 0x15;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x578890;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x5788ac;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_ac = (float *)0xc10c44;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x5788d0;
    FUN_00402a70();
    local_c = 0x16;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x5788f6;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578912;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_94 = local_94 + 47.0;
    local_ac = (float *)0xc10c2c;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x578944;
    FUN_00402a70();
    local_c = 0x17;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x57896a;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578986;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_ac = (float *)0xc10c2c;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x5789aa;
    FUN_00402a70();
    local_c = 0x18;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x5789d0;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x5789ec;
      FUN_0089120c();
    }
    local_a8 = (float *)0xb;
    local_ac = (float *)0xc10c50;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x578a10;
    FUN_00402a70();
    local_c = 0x19;
    local_a8 = (float *)(local_94 + 2.0);
    local_ac = local_70;
    local_b0 = (float *)0x578a44;
    local_90 = (undefined1 *)local_a8;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578a60;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_94 = local_94 + 47.0;
    local_ac = (float *)0xc10c38;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x578a92;
    FUN_00402a70();
    local_c = 0x1a;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x578ab8;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578ad4;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_ac = (float *)0xc10c38;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x578af8;
    FUN_00402a70();
    local_c = 0x1b;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x578b1e;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578b3a;
      FUN_0089120c();
    }
    local_a8 = (float *)0xb;
    local_ac = (float *)0xc10c5c;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x578b5e;
    FUN_00402a70();
    local_c = 0x1c;
    local_a8 = (float *)(local_94 + 1.0);
    local_ac = local_70;
    local_b0 = (float *)0x578b92;
    local_90 = (undefined1 *)local_a8;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578bae;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_94 = local_94 + 47.0;
    local_ac = (float *)0xc10c44;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x578be0;
    FUN_00402a70();
    local_c = 0x1d;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x578c06;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578c22;
      FUN_0089120c();
    }
    local_a8 = (float *)0x9;
    local_ac = (float *)0xc10c44;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x578c46;
    FUN_00402a70();
    local_c = 0x1e;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x578c6c;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578c88;
      FUN_0089120c();
    }
    local_a8 = (float *)0xb;
    local_ac = (float *)0xc10c68;
    local_5c = 0xf;
    local_70[4] = 0.0;
    local_70[0] = (float)((uint)local_70[0] & 0xffffff00);
    local_b0 = (float *)0x578cac;
    FUN_00402a70();
    local_c = 0x1f;
    local_a8 = (float *)(local_94 + 1.0);
    local_ac = local_70;
    local_b0 = (float *)0x578ce0;
    local_90 = (undefined1 *)local_a8;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578cfc;
      FUN_0089120c();
    }
    local_a8 = (float *)0xc10c50;
    local_94 = local_94 + 47.0;
    local_ac = (float *)0x578d1b;
    FUN_00402b70();
    local_c = 0x20;
    local_a8 = (float *)(local_94 + 2.0);
    local_ac = local_70;
    local_b0 = (float *)0x578d4f;
    local_90 = (undefined1 *)local_a8;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578d6b;
      FUN_0089120c();
    }
    local_a8 = (float *)0xc10c5c;
    local_ac = (float *)0x578d7c;
    FUN_00402b70();
    local_c = 0x21;
    local_a8 = (float *)(local_94 + 1.0);
    local_ac = local_70;
    local_b0 = (float *)0x578db0;
    local_94 = (float)local_a8;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578dcc;
      FUN_0089120c();
    }
    local_a8 = (float *)0xc10c68;
    local_ac = (float *)0x578ddd;
    FUN_00402b70();
    local_c = 0x22;
    local_a8 = (float *)local_94;
    local_ac = local_70;
    local_b0 = (float *)0x578e03;
    FUN_005739c0();
    local_c = 0xffffffff;
    if (0xf < local_5c) {
      local_a8 = (float *)local_70[0];
      local_ac = (float *)0x578e1f;
      FUN_0089120c();
    }
    local_8c = (float)**(int **)((int)param_1 + 0x11c);
    if ((int *)local_8c != *(int **)((int)param_1 + 0x11c)) {
      do {
        local_84 = **(float **)((int)local_8c + 0x10);
        local_90 = (undefined1 *)0x0;
        if (local_84 != *(float *)(*(int *)((int)local_8c + 0x10) + 4)) {
          local_70[0] = 0.0;
          local_70[1] = 0.0;
          local_70[2] = 4.48416e-44;
          local_80 = (double)(local_88 + 98.0);
          local_70[3] = 4.48416e-44;
          local_78 = 0x3f200000;
          local_74 = 0x3f200000;
          do {
            local_a8 = *(float **)((int)local_8c + 0xc);
            local_ac = (float *)0xc10c74;
            local_b0 = (float *)0x578ec1;
            FUN_0057e820();
            puStack_b8 = local_54;
            pcStack_b4 = "Data_";
            local_c = 0x23;
            uStack_bc = 0x578ede;
            local_b0 = (float *)local_38;
            FUN_00401cc0();
            local_a8 = local_70;
            local_ac = (float *)local_54;
            local_c = CONCAT31(local_c._1_3_,0x24);
            local_b0 = (float *)0x578efb;
            FUN_00573320();
            local_a8 = (float *)&local_78;
            local_ac = (float *)local_54;
            local_b0 = (float *)0x578f0d;
            FUN_00573420();
            puVar1 = local_90;
            local_94 = (float)(*(int *)((int)param_1 + 0xd4) / 2 + -0x100);
            local_a8 = (float *)(local_94 + 34.0 + (float)(*(int *)((int)local_8c + 0xc) * 0x2f) +
                                (float)(((int)local_90 / 5) * 0x15));
            local_ac = (float *)((float)(((int)local_90 % 5) * 0x16) + (float)local_80);
            local_b0 = (float *)0x578fa4;
            local_90 = (undefined1 *)local_ac;
            FUN_00573230();
            local_a8 = *(float **)((int)param_1 + 8);
            local_ac = (float *)0x578fb1;
            FUN_005737d0();
            local_90 = puVar1 + 1;
            if (0xf < local_40) {
              local_a8 = (float *)local_54[0];
              local_ac = (float *)0x578fcb;
              FUN_0089120c();
            }
            local_c = 0xffffffff;
            local_40 = 0xf;
            local_44 = 0;
            local_54[0] = local_54[0] & 0xffffff00;
            if (0xf < local_24) {
              local_a8 = (float *)local_38[0];
              local_ac = (float *)0x579002;
              FUN_0089120c();
            }
            local_84 = (float)((int)local_84 + 4);
            local_24 = 0xf;
            uStack_28 = 0;
            local_38[0] = local_38[0] & 0xffffff00;
          } while (local_84 != *(float *)(*(int *)((int)local_8c + 0x10) + 4));
        }
        local_a8 = (float *)0x57903f;
        FUN_0049e6a0();
      } while (local_8c != (float)*(int *)((int)param_1 + 0x11c));
    }
    if (*(int *)((int)param_1 + 0xcc) == 0) {
      *(undefined4 *)((int)param_1 + 0x88) = 0;
    }
    else {
      local_a8 = (float *)param_1;
      local_ac = (float *)0x57905f;
      FUN_0057dc20();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_94);
  return;
}

