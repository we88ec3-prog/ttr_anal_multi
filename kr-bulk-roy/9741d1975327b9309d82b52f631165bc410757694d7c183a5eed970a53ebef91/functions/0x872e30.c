
void FUN_00872e30(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar1 = *(int **)(in_ECX + 0x188);
  for (piVar2 = *(int **)(in_ECX + 0x184); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    FUN_00780150(*piVar2,*(undefined4 *)(*piVar2 + 0x30));
  }
  return;
}

