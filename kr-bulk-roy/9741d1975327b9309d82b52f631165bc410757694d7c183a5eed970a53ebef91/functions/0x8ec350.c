
undefined4 FUN_008ec350(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = param_1;
  if (*(int *)(param_1 + 0x1c) != 0) {
LAB_008ec393:
    return *(undefined4 *)(iVar1 + 0x1c);
  }
  uVar2 = FUN_008baee0(*(undefined4 *)(param_1 + 8),0x260,&param_1);
  if (param_1 == 0) {
    iVar3 = FUN_008ebf50();
    if (iVar3 == 0) {
      *(undefined4 *)(iVar1 + 0x1c) = uVar2;
      goto LAB_008ec393;
    }
  }
  return 0;
}

