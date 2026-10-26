
void FUN_004cec40(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939e1e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  if (((in_ECX[0x57] != 0) && (*(int *)(in_ECX[0x57] + 0xa0) != 0)) && (param_1 != 0)) {
    FUN_007d6730(param_1,param_2);
  }
  if (in_ECX[0x109] != 0) {
    if (*(int *)(in_ECX[0x109] + 0x24) != 0) {
      FUN_007be5f0(uVar1);
    }
    if (in_ECX[0x109] != 0) {
      FUN_004c7db0();
      in_ECX[0x109] = 0;
    }
  }
  puVar2 = (undefined4 *)(**(code **)(*in_ECX + 0x4c))();
  local_20 = *puVar2;
  local_1c = puVar2[1];
  local_18 = (float)puVar2[2];
  if ((in_ECX[0x57] == 0) || (in_ECX[0xdc] == 0)) {
    local_24 = 0.0;
  }
  else {
    fVar4 = (float10)FUN_007a7100();
    local_24 = (float)fVar4;
  }
  local_18 = local_24 + 3.0 + local_18;
  if ((DAT_00fdf6dc & 1) == 0) {
    DAT_00fdf6dc = DAT_00fdf6dc | 1;
    local_8 = 0;
    FUN_00550820();
    _atexit((_func_4879 *)&LAB_00bce6b0);
    local_8 = 0xffffffff;
  }
  iVar3 = in_ECX[1];
  FUN_00551b80(0,param_1 + -2);
  iVar3 = FUN_00551dd0(&DAT_00fdf680,(short)iVar3,&local_20,0,0x3f800000,0);
  in_ECX[0x109] = iVar3;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

