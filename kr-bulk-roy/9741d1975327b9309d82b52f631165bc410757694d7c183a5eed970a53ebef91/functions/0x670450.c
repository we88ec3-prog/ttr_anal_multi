
void FUN_00670450(void)

{
  int iVar1;
  int in_EDX;
  
  iVar1 = *(int *)(*(int *)(in_EDX + 0xf4) + 0xcc);
  if (((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xdc), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0x20) != -1)) {
    FUN_00508520();
  }
  return;
}

