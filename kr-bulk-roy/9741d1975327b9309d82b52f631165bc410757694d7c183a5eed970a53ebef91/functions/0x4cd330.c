
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cd330(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4,int *param_5
                 )

{
  undefined4 uVar1;
  int *piVar2;
  int iStack_384;
  undefined4 uStack_380;
  undefined4 uStack_37c;
  undefined4 uStack_378;
  undefined4 uStack_374;
  undefined4 uStack_370;
  undefined4 uStack_36c;
  int iStack_368;
  int iStack_364;
  int iStack_360;
  int iStack_35c;
  undefined1 auStack_358 [844];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&iStack_384;
  uVar1 = FUN_00489ee0();
  piVar2 = (int *)FUN_004e7c10(uVar1);
  if (piVar2 != (int *)0x0) {
    iStack_384 = (**(code **)(*piVar2 + 0x10))();
    if (iStack_384 != 0) {
      iStack_35c = param_3[3];
      iStack_364 = param_3[1];
      iStack_360 = *param_3 + -2;
      uStack_370 = 0x10;
      uStack_36c = 0x10;
      iStack_368 = (*param_3 - iStack_35c) + -2 + iStack_364;
      uStack_378 = 0;
      uStack_374 = 0;
      uStack_380 = 0x41800000;
      uStack_37c = 0x41800000;
      if ((_DAT_00fe1bc4 & 1) == 0) {
        _DAT_00fe1bc4 = _DAT_00fe1bc4 | 1;
        _atexit((_func_4879 *)&DAT_00bcec00);
      }
      FUN_007398a0(auStack_358,param_4,0xffffffff,0xff000000,uStack_380,uStack_37c);
      (**(code **)(*param_5 + 0x104))(param_5,0,iStack_384);
      (**(code **)(*param_5 + 0x14c))(param_5,4,10,&iStack_364,0x1c);
    }
  }
  __security_check_cookie(local_c ^ (uint)&iStack_384);
  return;
}

