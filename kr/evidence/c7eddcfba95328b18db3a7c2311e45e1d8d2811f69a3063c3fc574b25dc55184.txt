
void FUN_004cb590(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  float10 fVar3;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00939eac;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fab100 & 1) == 0) {
    DAT_00fab100 = DAT_00fab100 | 1;
    local_8 = 0;
    FUN_0049d6a0(local_14);
    _atexit((_func_4879 *)&LAB_00bcce20);
  }
  local_8 = 0xffffffff;
  if ((DAT_00fab104 & 4) != 0) {
    FUN_0049d8e0();
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x68))(7,0x3f800000);
  FUN_004c9010(*(undefined4 *)(in_ECX + 4));
  *(undefined4 *)(in_ECX + 0x38) = 0;
  puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))();
  local_20 = *puVar2;
  local_1c = puVar2[1];
  local_18 = (float)puVar2[2];
  if ((*(int *)(*(int *)(in_ECX + 4) + 0x15c) == 0) || (*(int *)(*(int *)(in_ECX + 4) + 0x370) == 0)
     ) {
    local_24 = 0.0;
  }
  else {
    fVar3 = (float10)FUN_007a7100();
    local_24 = (float)fVar3;
  }
  local_18 = local_24 * 0.5 + local_18;
  uVar1 = *(undefined4 *)(*(int *)(in_ECX + 4) + 0xb4);
  if ((DAT_00fdf6dc & 1) == 0) {
    DAT_00fdf6dc = DAT_00fdf6dc | 1;
    local_8 = 1;
    FUN_00550820();
    _atexit((_func_4879 *)&LAB_00bce6b0);
    local_8 = 0xffffffff;
  }
  FUN_00551b80(0xffffffff,0xffffffff);
  FUN_00551dd0(&DAT_00fdf680,0,&local_20,0,uVar1,1);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

