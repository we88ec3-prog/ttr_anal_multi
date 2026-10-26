
void FUN_007f7b10(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  float *pfVar7;
  undefined4 *puVar8;
  code *pcVar9;
  char *pcVar10;
  float local_1bc;
  float local_1b8;
  undefined **local_1b4;
  undefined4 local_1b0;
  int **local_1ac;
  float local_1a8;
  int *local_1a4;
  int *local_1a0;
  int *local_19c;
  uint local_198;
  float local_194;
  undefined1 local_190 [56];
  char local_158 [256];
  char local_58 [64];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009347e5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar1;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  piVar5 = DAT_00fb76a8;
  local_8 = 0xffffffff;
  local_19c = DAT_00fb76a8;
  **(float **)(param_1 + 0x40) = *(float *)(param_1 + 0x28) / *(float *)(param_1 + 0x30);
  local_194 = -*(float *)(param_1 + 0x2c) / *(float *)(param_1 + 0x34);
  *(float *)(*(int *)(param_1 + 0x40) + 0x10) = local_194;
  *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x20) = 0x3f800000;
  local_194 = (float)FUN_00891268(0x1d0);
  local_8 = 2;
  if (local_194 == 0.0) {
    local_1a0 = (int *)0x0;
  }
  else {
    local_1a0 = (int *)FUN_00854c30(local_194);
  }
  local_8 = 0xffffffff;
  iVar3 = *(int *)(param_1 + 0x24);
  if (iVar3 == 0) {
    pcVar10 = "base";
    pfVar7 = &local_1a8;
LAB_007f7c68:
    pcVar9 = *(code **)(*piVar5 + 0xa0);
  }
  else {
    if (iVar3 == 2) {
      pcVar10 = "splite";
      pfVar7 = &local_1bc;
      goto LAB_007f7c68;
    }
    pcVar9 = *(code **)(*piVar5 + 0xa0);
    if (iVar3 == 3) {
      pcVar10 = "map_tile";
      pfVar7 = &local_1b8;
    }
    else {
      pcVar10 = "splite";
      pfVar7 = &local_194;
    }
  }
  piVar2 = (int *)(*pcVar9)(pfVar7,pcVar10);
  local_1a0[0x59] = *piVar2;
  _memset(local_158,0,0x100);
  FUN_007f7930();
  _sprintf(local_58,"ALPHA_LAYER_%d",*(undefined4 *)(param_1 + 4));
  local_198 = 0;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 3;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  (**(code **)(*piVar5 + 0x50))(local_58,*(undefined4 *)(param_1 + 0x7c),&local_198);
  piVar2 = *(int **)(param_1 + 0x7c);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(param_1 + 0x7c) = 0;
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 4;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  local_1a8 = (float)FUN_00891268(0xbc);
  local_8 = 5;
  if (local_1a8 == 0.0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00856910();
    piVar5 = local_19c;
  }
  local_8 = 0xffffffff;
  *(uint *)(iVar3 + 0xb8) = local_198;
  FUN_00843fa0(local_1a0,1);
  if (local_198 != 0) {
    uVar1 = local_198 & 0xffff;
    if ((uVar1 < (uint)((local_19c[0x41] - piVar5[0x40]) / 0x34)) &&
       (*(uint *)(local_19c[0x44] + uVar1 * 4) == local_198 >> 0x10)) {
      puVar8 = (undefined4 *)(uVar1 * 0x34 + piVar5[0x40]);
      goto LAB_007f7e02;
    }
  }
  puVar8 = (undefined4 *)0x0;
LAB_007f7e02:
  *(undefined4 *)(param_1 + 0x7c) = *puVar8;
  local_1a8 = (float)FUN_00891268(0xbc);
  local_8 = 6;
  if (local_1a8 == 0.0) {
    local_194 = 0.0;
  }
  else {
    local_194 = (float)FUN_00856910();
  }
  local_8 = 0xffffffff;
  _memset(local_158,0,0x100);
  piVar5 = (int *)(param_1 + 0x44);
  piVar2 = piVar5;
  if (0xf < *(uint *)(param_1 + 0x58)) {
    piVar2 = (int *)*piVar5;
  }
  piVar4 = (int *)(param_1 + 8);
  if (0xf < *(uint *)(param_1 + 0x1c)) {
    piVar4 = (int *)*piVar4;
  }
  _sprintf(local_158,"%s%s",piVar4,piVar2);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 7;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  local_1b0 = FUN_0079a5f0(&DAT_00fb76a8);
  local_1ac = &local_1a4;
  local_1b4 = `long___cdecl_Graphics::LoadTextureFromFile(IDirect3DDevice9*,char_const*,IDirect3DTexture9**)'
              ::__l2::CreateTextureFromFileBox::vftable;
  iVar3 = FUN_00737d40();
  if (iVar3 == 0) {
    if (0xf < *(uint *)(param_1 + 0x58)) {
      piVar5 = (int *)*piVar5;
    }
    if ((DAT_00fe3314 & 1) == 0) {
      DAT_00fe3314 = DAT_00fe3314 | 1;
      local_8 = 8;
      FUN_007ed9f0();
      _atexit((_func_4879 *)&LAB_00bd0ae0);
      local_8 = 0xffffffff;
    }
    if (DAT_00fe3318 != 0) {
      FUN_007ed8d0(local_190,piVar5);
      local_8 = 9;
      FUN_007edcd0();
      local_8 = 0xffffffff;
      FUN_007ee080();
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 10;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
    piVar5 = (int *)(param_1 + 0x44);
    if (0xf < *(uint *)(param_1 + 0x58)) {
      piVar5 = (int *)*piVar5;
    }
    (**(code **)(*local_19c + 0x50))(piVar5,local_1a4,&local_198);
    if (local_1a4 != (int *)0x0) {
      (**(code **)(*local_1a4 + 8))(local_1a4);
      local_1a4 = (int *)0x0;
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0xb;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  }
  piVar5 = local_1a0;
  *(uint *)((int)local_194 + 0xb8) = local_198;
  FUN_00843fa0(local_1a0,2);
  uVar6 = (**(code **)(*piVar5 + 0xc))();
  *(undefined4 *)(param_1 + 0x80) = uVar6;
  (**(code **)*piVar5)(1);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

