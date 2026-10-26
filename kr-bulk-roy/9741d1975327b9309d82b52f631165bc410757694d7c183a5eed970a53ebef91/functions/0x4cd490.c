
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cd490(int *param_1,int param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int in_ECX;
  undefined4 in_EDX;
  int iVar2;
  int *unaff_EDI;
  int local_384;
  int local_380;
  int local_37c;
  int local_378;
  undefined4 local_374;
  int *local_370;
  float local_36c;
  float local_368;
  tagRECT local_364;
  undefined1 local_354 [844];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = unaff_EDI[3] - unaff_EDI[1];
  local_370 = param_4;
  if (iVar2 < 0x11) {
    iVar2 = 0x10;
  }
  local_364.left = 0;
  local_364.top = 0;
  local_364.right = 0x20;
  local_364.bottom = 0x20;
  local_374 = in_EDX;
  OffsetRect(&local_364,param_2 << 5,in_ECX << 5);
  local_380 = unaff_EDI[1];
  local_37c = *unaff_EDI + -2;
  local_378 = unaff_EDI[3];
  local_36c = (float)*param_1;
  local_384 = (*unaff_EDI - iVar2) + -2;
  local_368 = (float)param_1[1];
  if ((_DAT_00fe1bc4 & 1) == 0) {
    _DAT_00fe1bc4 = _DAT_00fe1bc4 | 1;
    _atexit((_func_4879 *)&DAT_00bcec00);
  }
  FUN_007396c0(local_354,&local_384,param_3,local_36c,local_368);
  piVar1 = local_370;
  (**(code **)(*local_370 + 0x104))(local_370,0,local_374);
  (**(code **)(*piVar1 + 0x14c))(piVar1,4,2,local_354,0x1c);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

