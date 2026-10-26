
void FUN_00446510(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  FUN_00755e50();
  FUN_00447bc0();
  FUN_0043c570(0x6220);
  FUN_0043c570(0x622a);
  FUN_0043c570(0x6248);
  FUN_00447cb0();
  FUN_00447da0();
  FUN_0043c570(0x5ef6);
  iVar2 = *(int *)(in_ECX + 0xf4);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar2 + 0xa4) = 1;
  iVar2 = *(int *)(in_ECX + 0xf4);
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar3 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar3 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar2 + 0x94) + 0x4c) = 1;
    }
  }
  iVar2 = *(int *)(in_ECX + 0x10c);
  piVar1 = (int *)(iVar2 + 0xc);
  *piVar1 = *piVar1 + -0x14;
  piVar1 = (int *)(iVar2 + 0x14);
  *piVar1 = *piVar1 + -0x14;
  FUN_00746f70();
  FUN_00749d00();
  return;
}

