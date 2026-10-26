
undefined4 FUN_00548a20(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xc);
  if (iVar1 == 0) {
    return 0;
  }
  if ((*(int *)(iVar1 + 0x38c) != 0x10) && (*(int *)(in_ECX + 0xa4) == 0)) {
    *(undefined4 *)(in_ECX + 0xbc) = 0;
    uVar3 = FUN_00546100();
    return uVar3;
  }
  iVar2 = *(int *)(in_ECX + 0xbc);
  *(undefined1 *)(param_2 + 4) = *(undefined1 *)(*(int *)(in_ECX + (param_1 * 3 + 3) * 4) + 0xb0);
  *(undefined2 *)(param_2 + 2) = 0;
  *(undefined4 *)(in_ECX + 0xbc) = 1;
  return CONCAT31((int3)((uint)iVar1 >> 8),iVar2 == 0);
}

