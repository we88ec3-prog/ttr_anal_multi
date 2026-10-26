
void FUN_00470020(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  piVar1 = (int *)(in_ECX + 0x248);
  FUN_00470c20();
  iVar2 = *piVar1;
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar2 + 0xa4) = 1;
  iVar2 = *piVar1;
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar3 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar3 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar2 + 0x94) + 0x4c) = 1;
    }
  }
  *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) | 0x40000;
  (**(code **)(*(int *)*piVar1 + 0x90))(0);
  return;
}

