
void FUN_00717eb0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x38) != 1) {
      *(undefined4 *)(iVar1 + 0x38) = 0;
    }
    *(undefined4 *)(iVar1 + 0x3c) = 0;
    FUN_0089a229(*(undefined4 *)(iVar1 + 0x40));
  }
  return;
}

