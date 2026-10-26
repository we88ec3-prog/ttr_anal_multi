
void FUN_006b6620(void)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = ((*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8)) + -200) / 2;
  (**(code **)(**(int **)(in_ECX + 0x80) + 0xbc))
            (0,*(undefined4 *)(*(int *)(in_ECX + 0x80) + 0xc),iVar2,
             *(undefined4 *)(*(int *)(in_ECX + 0x80) + 0x14));
  piVar1 = *(int **)(in_ECX + 0x84);
  (**(code **)(*piVar1 + 0xbc))(iVar2 + 200,piVar1[3],iVar2 * 2 + 200,piVar1[5]);
  return;
}

