
undefined4 FUN_00838b60(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  piVar1 = (int *)(in_ECX + 8);
  if (*(int *)(in_ECX + 8) != 0) {
    (**(code **)(*(int *)*piVar1 + 8))((int *)*piVar1);
  }
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x68))
                    (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0xc),0x208,0,0,piVar1,0);
  if ((iVar2 == 0) && (*piVar1 != 0)) {
    return 1;
  }
  return 0;
}

