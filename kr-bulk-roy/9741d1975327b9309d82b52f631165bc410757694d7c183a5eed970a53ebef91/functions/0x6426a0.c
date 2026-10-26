
void FUN_006426a0(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x138);
  if (*(char *)(iVar1 + 0x141) != '\0') {
    FUN_006edb10("Not supported operation");
  }
  uVar2 = *(undefined4 *)(iVar1 + 0x118);
  if (*(char *)(*(int *)(unaff_EDI + 0x138) + 0x141) != '\0') {
    FUN_006edb10("Not supported operation");
  }
  FUN_006428d0(uVar2);
  return;
}

