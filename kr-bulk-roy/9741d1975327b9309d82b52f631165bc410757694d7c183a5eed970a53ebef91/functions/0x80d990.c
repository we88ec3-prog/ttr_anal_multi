
void FUN_0080d990(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c243;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = MoonSound::SoundSolo::vftable;
  param_1[1] = MoonSound::SoundSolo::vftable;
  local_8 = 1;
  if ((int *)param_1[0xf] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xf] + 8))(uVar1);
    param_1[0xf] = 0;
  }
  if (0xf < (uint)param_1[0x15]) {
    FUN_0089120c(param_1[0x10]);
  }
  param_1[0x15] = 0xf;
  param_1[0x14] = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *param_1 = MoonSound::Sound::vftable;
  param_1[1] = MoonSound::Sound::vftable;
  if (param_1[0xe] != 0) {
    FUN_006edb10("Sound::_refCount != 0\n");
  }
  if (0xf < (uint)param_1[0xb]) {
    FUN_0089120c(param_1[6]);
  }
  param_1[0xb] = 0xf;
  param_1[10] = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  ExceptionList = local_10;
  return;
}

