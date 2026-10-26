
void FUN_00798440(int param_1,undefined4 param_2)

{
  undefined4 local_38;
  undefined1 local_34 [4];
  undefined1 local_30 [28];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009326ae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&local_38);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_c = 0xffffffff;
  FUN_007c9190(local_30,400,300,800,600);
  local_38 = *(undefined4 *)(param_1 + 0x24);
  FUN_007cb270(local_30,param_2,0,local_34,local_38,1);
  ExceptionList = local_14;
  return;
}

