
void FUN_007ffcc0(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int local_8;
  
  piVar2 = (int *)(in_ECX + 0x1c);
  local_8 = 4;
  do {
    if (*piVar2 != 0) {
      FUN_007ffcc0();
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        if (*(int *)(iVar1 + 0x70) != 0) {
          FUN_00891d3d(*(int *)(iVar1 + 0x70));
          *(undefined4 *)(iVar1 + 0x70) = 0;
        }
        *(undefined4 *)(iVar1 + 0x74) = 0;
        FUN_0089120c(iVar1);
        *piVar2 = 0;
      }
    }
    piVar2 = piVar2 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return;
}

