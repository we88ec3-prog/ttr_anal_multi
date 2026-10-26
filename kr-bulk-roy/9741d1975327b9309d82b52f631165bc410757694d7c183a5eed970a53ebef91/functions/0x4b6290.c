
void FUN_004b6290(int param_1)

{
  undefined4 uVar1;
  byte bVar2;
  short sVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092119e;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = *(undefined4 *)(param_1 + 10);
  local_20 = *(undefined4 *)(param_1 + 6);
  local_18 = 0;
  (**(code **)*DAT_00fba838)(local_20,local_1c,&local_18,0,local_14);
  bVar2 = *(byte *)(param_1 + 4);
  if ((DAT_00fb7c18 & 1) == 0) {
    DAT_00fb7c18 = DAT_00fb7c18 | 1;
    FUN_004449d0();
  }
  sVar3 = *(short *)(param_1 + 4);
  uVar1 = (&DAT_00fb7c20)[bVar2];
  if ((DAT_00fdf6dc & 1) == 0) {
    DAT_00fdf6dc = DAT_00fdf6dc | 1;
    local_8 = 0;
    FUN_00550820();
    _atexit((_func_4879 *)&LAB_00bce6b0);
    local_8 = 0xffffffff;
  }
  FUN_00551b80(0,(int)sVar3);
  FUN_00551dd0(&DAT_00fdf680,0,&local_20,uVar1,0x3f800000,1);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

