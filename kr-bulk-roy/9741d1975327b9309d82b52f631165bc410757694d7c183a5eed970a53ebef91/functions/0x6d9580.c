
void FUN_006d9580(int param_1,int param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009296cc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_006d9780(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  param_1 = param_2;
  FUN_0047fdf0(&param_1);
  if (param_2 == DAT_00fb74f4) {
    pcVar2 = "1000.wav";
  }
  else {
    pcVar2 = (char *)FUN_004f6e80();
    if (pcVar2 == (char *)0x0) {
      ExceptionList = local_10;
      return;
    }
  }
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 1;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8 = 0xffffffff;
  }
  FUN_006d9b30(uVar1,pcVar2,1,DAT_00fb92d6);
  ExceptionList = local_10;
  return;
}

