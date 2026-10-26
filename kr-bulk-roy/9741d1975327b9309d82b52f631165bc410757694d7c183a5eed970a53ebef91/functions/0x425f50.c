
void FUN_00425f50(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_00755e50();
  FUN_00447bc0();
  FUN_0043c570(0x6220);
  FUN_0043c570(0x622a);
  FUN_00458240(0x623e);
  FUN_0043c570(0x5eec);
  FUN_00458240(0x5f50);
  iVar1 = *(int *)(in_ECX + 0xf4);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(in_ECX + 0xf4);
  if ((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
    }
  }
  return;
}

