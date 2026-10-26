
void FUN_00564940(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,int param_7)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091deb9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00564a60(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  piVar2 = (int *)FUN_00891268(0x70);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    if (param_7 != 0) {
      param_5 = 0xffffffff;
    }
    FUN_00553e90(piVar2,param_5,param_6,0);
    *piVar2 = (int)CFlyingImage::vftable;
    piVar2[0x1a] = param_2;
    piVar2[0x1b] = param_3;
  }
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    local_8 = 1;
    FUN_005533d0();
    _atexit((_func_4879 *)&LAB_00bcd100);
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar2 + 4))();
  (**(code **)(*piVar2 + 0x20))(DAT_00fb73ac,DAT_00fb73b0);
  piVar2[0x10] = 0;
  uVar3 = FUN_0057ef20();
  FUN_0082f200(&DAT_00fb7358,uVar3);
  iVar1 = DAT_00fb7398 + 1;
  *(int *)(in_ECX + 0x40) = DAT_00fb7398;
  DAT_00fb7398 = iVar1;
  ExceptionList = local_10;
  return;
}

