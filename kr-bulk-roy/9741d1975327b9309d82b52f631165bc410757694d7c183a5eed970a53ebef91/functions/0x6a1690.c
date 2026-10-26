
void FUN_006a1690(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_00755e50();
  FUN_006199f0();
  FUN_00672900();
  FUN_006a9e80(31000);
  FUN_006a9e80(32000);
  FUN_006a9e80(33000);
  FUN_006a3080();
  FUN_00615fc0(50000);
  FUN_00615fc0(51000);
  FUN_006a3170();
  (**(code **)(**(int **)(in_ECX + 0x110) + 0x198))(0x2b5d);
  *(int *)(*(int *)(in_ECX + 0x110) + 0x2a8) = in_ECX;
  *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x144) = 0x14;
  iVar1 = *(int *)(in_ECX + 0x118);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(in_ECX + 0x118);
  if ((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
    }
  }
  return;
}

