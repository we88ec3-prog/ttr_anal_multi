
undefined4 * FUN_0080d8e0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914348;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[1] = MoonSound::TLCallback::vftable;
  *param_1 = MoonSound::Sound::vftable;
  param_1[1] = MoonSound::Sound::vftable;
  param_1[2] = param_3;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0xb] = 0xf;
  param_1[10] = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  FUN_0040b0b0(in_ECX,0);
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  local_8 = 0;
  *param_1 = MoonSound::SoundSolo::vftable;
  param_1[1] = MoonSound::SoundSolo::vftable;
  param_1[0x15] = 0xf;
  param_1[0x14] = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  FUN_00403040(param_2,0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}

