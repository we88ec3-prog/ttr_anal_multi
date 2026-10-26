
void FUN_0040b5b0(undefined4 param_1)

{
  int iVar1;
  int unaff_ESI;
  int local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(unaff_ESI + 0xd8);
  local_8 = param_1;
  FUN_0082ef00(&local_8);
  if (local_c == *(int *)(iVar1 + 0xbc)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(local_c + 0x10);
  }
  if (iVar1 != *(int *)(unaff_ESI + 0xcc)) {
    if ((*(int *)(unaff_ESI + 0xcc) != 0) && (*(int *)(unaff_ESI + 0xd0) != 0)) {
      FUN_00746580(6);
    }
    if (iVar1 != 0) {
      FUN_00746580(5);
      (**(code **)(**(int **)(unaff_ESI + 0xdc) + 200))();
      FUN_0040b520(param_1);
      (**(code **)(**(int **)(unaff_ESI + 0xd8) + 200))();
    }
    *(undefined4 *)(unaff_ESI + 0xd0) = *(undefined4 *)(iVar1 + 0x80);
    *(int *)(unaff_ESI + 0xcc) = iVar1;
  }
  return;
}

