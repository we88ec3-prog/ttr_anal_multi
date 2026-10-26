
bool FUN_00865d20(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x58);
  if (*(int *)(*(int *)(*piVar1 + 4) + 0xc + (int)piVar1) == 0) {
    FUN_00725100(0xfffffff4,0xffffffff,2);
    FUN_006ddcc0(piVar1,in_ECX + 0x24,4,0);
    FUN_006ddcc0(piVar1,in_ECX + 0x28,4,0);
    FUN_006ddcc0(piVar1,in_ECX + 0x2c,4,0);
    iVar2 = FUN_00865de0(in_ECX,*(undefined4 *)(in_ECX + 0x58));
    return iVar2 != 0;
  }
  return false;
}

