
void FUN_004d06a0(void)

{
  int iVar1;
  int xRight;
  int yTop;
  int xLeft;
  int in_ECX;
  undefined1 auStack_48 [4];
  float local_44;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  tagRECT local_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093059a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_48;
  ExceptionList = &local_14;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 0;
    FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xffffffb0);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_c = 0xffffffff;
  if ((DAT_00fb9341 != '\0') && (*(int *)(in_ECX + 0x11c) != 0)) {
    local_38 = *(undefined4 *)(in_ECX + 0xa0);
    local_34 = *(undefined4 *)(in_ECX + 0xa4);
    local_30 = *(float *)(in_ECX + 0xa8) + 3.0;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_c = 0xffffffff;
    FUN_0079b910(&DAT_00fb76a8,&local_38);
    local_44 = local_44 + 0.5;
    iVar1 = FUN_008fed10();
    xRight = FUN_008fed10();
    yTop = FUN_008fed10();
    xLeft = FUN_008fed10();
    SetRect(&local_2c,xLeft,yTop,xRight,iVar1);
    if (*(uint *)(in_ECX + 0x138) < 8) {
      iVar1 = in_ECX + 0x124;
    }
    else {
      iVar1 = *(int *)(in_ECX + 0x124);
    }
    if ((DAT_00fcde44 & 1) == 0) {
      DAT_00fcde44 = DAT_00fcde44 | 1;
      local_c = 2;
      FUN_0055b8a0();
      _atexit(FUN_00bcdef0);
      local_c = 0xffffffff;
    }
    FUN_0055bbe0(iVar1,local_3c,0,*(undefined4 *)(in_ECX + 0x120),0xff000000,0);
  }
  if (*(int *)(in_ECX + 0xf0) != 0) {
    FUN_007bdf40(*(int *)(in_ECX + 0xf0));
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_48);
  return;
}

