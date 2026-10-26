
void FUN_0083ce90(float *param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_2c4 [2];
  int local_2bc;
  float *local_2b8;
  undefined4 local_2b4;
  undefined4 local_2b0;
  undefined4 local_2ac;
  undefined4 local_2a8;
  undefined4 local_2a4;
  undefined4 local_2a0;
  undefined4 local_29c [4];
  undefined4 uStack_28c;
  undefined4 uStack_27c;
  undefined4 local_264;
  double local_260;
  int iStack_258;
  undefined4 local_244;
  undefined4 *local_240;
  undefined4 local_23c;
  int local_234;
  uint local_230;
  undefined1 local_228 [524];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00906dab;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)local_2c4;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffd30;
  ExceptionList = &local_14;
  local_2b8 = param_1;
  local_2c4[0] = param_2;
  local_2bc = param_3;
  if ((0 < (int)param_4) &&
     (((param_4 <= *(uint *)(in_ECX + 0x450) || (iVar2 = FUN_0083dfa0(in_ECX,param_4), iVar2 != 0))
      && (param_3 != 0)))) {
    FUN_008392d0(uVar1);
    local_c = 0;
    local_244 = 0x18;
    local_2b4 = 0;
    local_2b0 = 0;
    local_2ac = 0;
    local_2a8 = 0;
    local_2a4 = 0;
    FUN_0083ee30(in_ECX + 0x43c);
    iVar2 = **(int **)(in_ECX + 0x43c);
    local_240 = (undefined4 *)(iVar2 + 8);
    *local_240 = 0;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(uint *)(iVar2 + 0x18) = param_4 * 4;
    *(uint *)(iVar2 + 0x10) = param_4 * 2;
    local_23c = 1;
    local_230 = param_4;
    local_234 = local_2bc;
    local_260 = (double)-(*(float *)(in_ECX + 0xb8) * local_2b8[2] +
                          *(float *)(in_ECX + 0xa0) * *local_2b8 +
                          *(float *)(in_ECX + 0xac) * local_2b8[1] + *(float *)(in_ECX + 0xc4));
    if (*(int *)(in_ECX + 0x448) == 0) {
      D3DXDeclaratorFromFVF(0x142,local_228);
      (**(code **)(**(int **)(in_ECX + 0xec) + 0x158))
                (*(int **)(in_ECX + 0xec),local_228,(int *)(in_ECX + 0x448));
    }
    local_264 = local_2c4[0];
    _memset(local_29c,0,0x34);
    uStack_27c = 0x3f800000;
    uStack_28c = 0x3f800000;
    local_29c[0] = 0x3f800000;
    iStack_258 = FUN_00849ea0();
    local_2a0 = 0;
    if (iStack_258 == 1) {
      FUN_00841880(&local_2a0);
      FUN_00841060(in_ECX + 0x3d0);
    }
    else if (iStack_258 == 2) {
      FUN_00841880(&local_2a0);
      FUN_008410e0(in_ECX + 0x3e0);
    }
    else if (iStack_258 == 3) {
      uVar3 = FUN_00841880(&local_2a0);
      FUN_00840fc0(in_ECX + 0x3c0,local_2c4,uVar3);
    }
    else {
      FUN_0083ec20();
    }
    local_c = 0xffffffff;
    FUN_00839400();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)local_2c4);
  return;
}

