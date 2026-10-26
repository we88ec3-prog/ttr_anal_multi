
void FUN_004c8fa0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((*(int *)(in_ECX + 0x15c) != 0) && (*(int *)(in_ECX + 0x370) != 0)) {
    iVar3 = FUN_007a7b30(&local_10,0);
    if (iVar3 != 0) {
      *param_1 = local_10;
      param_1[1] = local_c;
      param_1[2] = local_8;
      return;
    }
  }
  uVar1 = *(undefined4 *)(in_ECX + 0xa4);
  *param_1 = *(undefined4 *)(in_ECX + 0xa0);
  uVar2 = *(undefined4 *)(in_ECX + 0xa8);
  param_1[1] = uVar1;
  param_1[2] = uVar2;
  return;
}

