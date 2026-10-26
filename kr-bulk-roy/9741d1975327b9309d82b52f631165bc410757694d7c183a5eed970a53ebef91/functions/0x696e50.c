
void FUN_00696e50(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int unaff_EDI;
  
  uVar2 = param_1;
  if ((byte)param_1 != ((byte)(*(uint *)(*(int *)(unaff_EDI + 0xf0) + 0x28) >> 9) & 1)) {
    if ((byte)param_1 == 0) {
      param_1 = 0x32e;
      iVar3 = FUN_00585620();
      FUN_005740f0(&param_1);
      if (in_ECX == *(int *)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      FUN_00757710();
      (**(code **)(**(int **)(unaff_EDI + 0xf0) + 200))();
    }
    else {
      param_1 = 0x32f;
      iVar3 = FUN_00585620();
      FUN_005740f0(&param_1);
      if (in_ECX == *(int *)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      FUN_00757710();
      (**(code **)(**(int **)(unaff_EDI + 0xf0) + 200))();
    }
    (**(code **)(**(int **)(unaff_EDI + 0xf0) + 0xa0))(uVar2);
    (**(code **)(**(int **)(unaff_EDI + 0xf0) + 200))();
  }
  return;
}

