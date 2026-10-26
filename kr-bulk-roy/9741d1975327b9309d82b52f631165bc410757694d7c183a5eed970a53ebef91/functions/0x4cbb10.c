
void FUN_004cbb10(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int in_ECX;
  float10 fVar5;
  undefined4 uVar6;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939e5e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  if ((*(int *)(*(int *)(in_ECX + 4) + 0x15c) != 0) && (*(int *)(*(int *)(in_ECX + 4) + 0x370) != 0)
     ) {
    iVar2 = FUN_007a7800(0x1d);
    if (iVar2 != 0) {
LAB_004cbb7c:
      piVar3 = *(int **)(in_ECX + 4);
      uVar6 = 0x1d;
      goto LAB_004cbb94;
    }
    piVar3 = (int *)FUN_007a7800(0x1d);
    if (piVar3 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar3 + 4))();
      if (iVar2 == 1) goto LAB_004cbb7c;
    }
  }
  piVar3 = *(int **)(in_ECX + 4);
  uVar6 = 7;
LAB_004cbb94:
  (**(code **)(*piVar3 + 0x68))(uVar6,0x3f800000,uVar1);
  FUN_004c9010(*(undefined4 *)(in_ECX + 4));
  puVar4 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x4c))();
  local_20 = *puVar4;
  local_1c = puVar4[1];
  local_18 = (float)puVar4[2];
  if ((*(int *)(*(int *)(in_ECX + 4) + 0x15c) == 0) || (*(int *)(*(int *)(in_ECX + 4) + 0x370) == 0)
     ) {
    local_24 = 0.0;
  }
  else {
    fVar5 = (float10)FUN_007a7100();
    local_24 = (float)fVar5;
  }
  local_18 = local_24 * 0.5 + local_18;
  uVar6 = *(undefined4 *)(*(int *)(in_ECX + 4) + 0xb4);
  if ((DAT_00fdf6dc & 1) == 0) {
    DAT_00fdf6dc = DAT_00fdf6dc | 1;
    local_8 = 0;
    FUN_00550820();
    _atexit((_func_4879 *)&LAB_00bce6b0);
    local_8 = 0xffffffff;
  }
  FUN_00551b80(0xffffffff,0xffffffff);
  FUN_00551dd0(&DAT_00fdf680,0,&local_20,0,uVar6,1);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

