
void FUN_008b8ee0(void)

{
  int iVar1;
  int iVar2;
  int in_EDX;
  
  iVar1 = *(int *)(*(int *)(*(int *)(in_EDX + 4) + 0x60) + 4);
  iVar2 = *(int *)(iVar1 + 0x9c);
  if ((iVar2 == 0) || (*(int *)(iVar2 + 0x10) != *(int *)(in_EDX + 0x48))) {
    FUN_008b8e90(iVar1,*(undefined4 *)(in_EDX + 0x48),0);
  }
  return;
}

