
int FUN_0040aa10(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(param_1 + 0xd8);
  FUN_0082ef00(&param_1);
  if (in_ECX == *(int *)(iVar2 + 0xbc)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(in_ECX + 0x10);
  }
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0040adb0(iVar2,uVar1);
  }
  if ((iVar2 != *(int *)(param_1 + 0xcc)) && (*(int *)(param_1 + 0xcc) != 0)) {
    if (*(int *)(param_1 + 0xd0) != 0) {
      FUN_00746580(6);
      *(undefined4 *)(param_1 + 0xcc) = 0;
      *(undefined4 *)(param_1 + 0xd0) = 0;
    }
    return iVar2;
  }
  return iVar2;
}

