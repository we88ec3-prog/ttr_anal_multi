
void FUN_006b9ce0(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int local_c;
  
  piVar2 = (int *)(in_ECX + 0xa0);
  local_c = 5;
  do {
    iVar1 = piVar2[-5];
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar1 + 0xa4) = 1;
    iVar1 = piVar2[-5];
    if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
       (iVar1 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar1 == 0xbf6b)) {
      FUN_0077b200();
    }
    (**(code **)(*(int *)piVar2[-5] + 200))();
    iVar1 = *piVar2;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar1 + 0xa4) = 1;
    iVar1 = *piVar2;
    if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
       (iVar1 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar1 == 0xbf6b)) {
      FUN_0077b200();
    }
    (**(code **)(*(int *)*piVar2 + 200))();
    piVar2 = piVar2 + 1;
    local_c = local_c + -1;
  } while (local_c != 0);
  return;
}

