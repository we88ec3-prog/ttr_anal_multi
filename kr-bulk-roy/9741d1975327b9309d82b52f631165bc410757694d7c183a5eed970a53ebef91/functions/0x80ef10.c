
undefined4 FUN_0080ef10(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  iVar1 = FUN_0080ee50();
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = ov_pcm_total(*(undefined4 *)(in_ECX + 8),0xffffffff);
  iVar1 = *(int *)(*(int *)(in_ECX + 0xc) + 4) * iVar1 * 2;
  uVar2 = FUN_0087dc3d(iVar1);
  param_1 = 0;
  iVar3 = FUN_0080f030(in_ECX,uVar2,&param_1);
  if ((iVar3 != 0) && (param_1 == iVar1)) {
    *(undefined4 *)(in_ECX + 0x1c) = uVar2;
    *(int *)(in_ECX + 0x20) = iVar1;
    ov_clear(*(undefined4 *)(in_ECX + 8));
    if (*(int *)(in_ECX + 8) != 0) {
      FUN_0089120c(*(int *)(in_ECX + 8));
      *(undefined4 *)(in_ECX + 8) = 0;
    }
    return 1;
  }
  FUN_00891d3d(uVar2);
  ov_clear(*(undefined4 *)(in_ECX + 8));
  if (*(int *)(in_ECX + 8) != 0) {
    FUN_0089120c(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  return 0;
}

