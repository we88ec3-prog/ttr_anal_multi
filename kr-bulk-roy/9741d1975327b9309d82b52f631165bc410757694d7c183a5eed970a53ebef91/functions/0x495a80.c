
void FUN_00495a80(int param_1)

{
  undefined2 uVar1;
  float local_20;
  float local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092120e;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = (float)*(ushort *)(param_1 + 4);
  local_1c = (float)*(ushort *)(param_1 + 6);
  local_18 = 0x477fff00;
  (**(code **)*DAT_00fba838)(local_20,local_1c,&local_18,0,local_14);
  uVar1 = *(undefined2 *)(param_1 + 2);
  if ((DAT_00fdf6dc & 1) == 0) {
    DAT_00fdf6dc = DAT_00fdf6dc | 1;
    local_8 = 0;
    FUN_00550820();
    _atexit((_func_4879 *)&LAB_00bce6b0);
    local_8 = 0xffffffff;
  }
  FUN_00551b80(0,uVar1);
  FUN_00551dd0(&DAT_00fdf680,0,&local_20,0,0x3f800000,1);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

