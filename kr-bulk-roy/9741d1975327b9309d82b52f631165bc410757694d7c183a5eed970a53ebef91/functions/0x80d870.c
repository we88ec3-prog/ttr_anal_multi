
void FUN_0080d870(int *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 uVar2;
  
  if (*param_1 == 1) {
    if (in_ECX != 0) {
      iVar1 = in_ECX + 4;
      FUN_0080a350(iVar1);
      FUN_0080df10(iVar1);
      return;
    }
    uVar2 = 0;
    FUN_0080a350(0);
    FUN_0080df10(uVar2);
  }
  return;
}

