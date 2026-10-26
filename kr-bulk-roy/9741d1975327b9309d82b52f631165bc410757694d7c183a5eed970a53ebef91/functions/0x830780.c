
bool FUN_00830780(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(int *)(*(int *)(in_ECX + 4) + 0x1c) == 0) && (*(int *)(*(int *)(in_ECX + 4) + 0x20) == 0))
  {
    return false;
  }
  iVar1 = FUN_0082fbf0(1);
  iVar2 = FUN_0082fbf0(0);
  return iVar1 == 0 && iVar2 == 0;
}

