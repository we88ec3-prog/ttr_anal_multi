
void FUN_0055a180(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092ec7e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(unaff_ESI + 0x3c) = *param_1;
  *(undefined4 *)(unaff_ESI + 0x40) = param_1[1];
  *(undefined4 *)(unaff_ESI + 0x44) = param_1[2];
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  puVar2 = (undefined4 *)FUN_0079b910(&DAT_00fb76a8,(undefined4 *)(unaff_ESI + 0x3c));
  *(undefined4 *)(unaff_ESI + 0x48) = *puVar2;
  *(undefined4 *)(unaff_ESI + 0x4c) = puVar2[1];
  *(undefined4 *)(unaff_ESI + 0x50) = puVar2[2];
  *(float *)(unaff_ESI + 0x4c) = *(float *)(unaff_ESI + 0x4c) - *(float *)(unaff_ESI + 0xf4);
  *(float *)(unaff_ESI + 0x48) =
       (*(float *)(unaff_ESI + 0x48) - *(float *)(unaff_ESI + 0xf0) * 0.5) + 0.5;
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

