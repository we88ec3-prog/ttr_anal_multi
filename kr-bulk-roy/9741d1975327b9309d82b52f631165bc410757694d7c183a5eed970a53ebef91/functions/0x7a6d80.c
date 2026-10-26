
void FUN_007a6d80(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  float10 fVar4;
  float10 fVar5;
  undefined1 local_20 [12];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cbae;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int **)(in_ECX + 0xac) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0xac) + 0x40))(local_14);
    if (*(uint *)(iVar1 + 0x60) < 0x10) {
      iVar1 = iVar1 + 0x4c;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x4c);
    }
    if ((DAT_00fe1770 & 1) == 0) {
      DAT_00fe1770 = DAT_00fe1770 | 1;
      local_8 = 0;
      FUN_007b7da0();
      _atexit((_func_4879 *)&LAB_00bce790);
      local_8 = 0xffffffff;
    }
    uVar2 = FUN_007b8230(&DAT_00fe173c,iVar1);
    *(undefined4 *)(in_ECX + 0x108) = uVar2;
  }
  iVar1 = *(int *)(in_ECX + 0x108);
  if (iVar1 != 0) {
    puVar3 = (undefined4 *)(**(code **)(*(int *)(in_ECX + 4) + 8))(local_20);
    fVar4 = (float10)(**(code **)(*(int *)(in_ECX + 4) + 0x10))();
    fVar5 = (float10)(**(code **)(*(int *)(in_ECX + 4) + 0x18))();
    *(undefined4 *)(iVar1 + 0x44) = *puVar3;
    *(undefined4 *)(iVar1 + 0x48) = puVar3[1];
    *(undefined4 *)(iVar1 + 0x4c) = puVar3[2];
    *(undefined4 *)(iVar1 + 0x28) = *puVar3;
    *(undefined4 *)(iVar1 + 0x2c) = puVar3[1];
    uVar2 = puVar3[2];
    *(float *)(iVar1 + 0x58) = (float)fVar4;
    *(float *)(iVar1 + 0x3c) = (float)fVar4;
    *(undefined4 *)(iVar1 + 0x30) = uVar2;
    *(undefined4 *)(iVar1 + 0x70) = 1;
    *(float *)(iVar1 + 0x40) = (float)fVar5;
    *(undefined4 *)(iVar1 + 0x6c) = 0;
    *(float *)(iVar1 + 0x18) = (float)fVar5;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

