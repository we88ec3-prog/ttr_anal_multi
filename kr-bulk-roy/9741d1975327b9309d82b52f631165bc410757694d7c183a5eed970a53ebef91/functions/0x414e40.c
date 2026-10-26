
void FUN_00414e40(void)

{
  undefined1 uVar1;
  uint uVar2;
  int unaff_EDI;
  int local_10;
  uint local_c;
  char local_5;
  
  local_5 = *(int *)(unaff_EDI + 0x1a0) == -1;
  uVar2 = 0;
  do {
    uVar1 = *(undefined1 *)(unaff_EDI + 0x498 + uVar2);
    local_c = uVar2;
    FUN_0082ef00(&local_c);
    if ((local_10 != *(int *)(unaff_EDI + 0xcc)) && (*(int **)(local_10 + 0x10) != (int *)0x0)) {
      (**(code **)(**(int **)(local_10 + 0x10) + 0x94))(uVar1);
    }
    if ((*(char *)(unaff_EDI + 0x498 + uVar2) != '\0') && (local_5 != '\0')) {
      FUN_0075d6a0(uVar2);
      *(uint *)(unaff_EDI + 0x1a0) = uVar2;
      local_5 = '\0';
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 6);
  if (*(int *)(unaff_EDI + 0xd8) == 0) {
    FUN_0075d470(unaff_EDI + 200,0);
    return;
  }
  if (*(int *)(unaff_EDI + 0xd8) == 1) {
    FUN_0075d540(unaff_EDI + 200,0);
  }
  return;
}

