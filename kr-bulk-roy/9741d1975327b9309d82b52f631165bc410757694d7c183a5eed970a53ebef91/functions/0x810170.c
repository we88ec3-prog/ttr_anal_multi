
int FUN_00810170(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int local_c;
  int local_8;
  
  iVar1 = (**(code **)(**(int **)(unaff_ESI + 4) + 0x18))
                    (*(undefined4 *)(unaff_ESI + 0x20018),unaff_ESI + 0x18,&local_8);
  if (-1 < iVar1) {
    if (local_8 == 0) {
      if (*(int *)(unaff_ESI + 0x20020) != 0) {
        (**(code **)(**(int **)(unaff_ESI + 4) + 0xc))(0);
        iVar1 = (**(code **)(**(int **)(unaff_ESI + 4) + 0x18))
                          (*(undefined4 *)(unaff_ESI + 0x20018),unaff_ESI + 0x18,&local_8);
        if (iVar1 < 0) {
          return iVar1;
        }
      }
    }
    else if (local_8 < *(int *)(unaff_ESI + 0x20018)) {
      iVar1 = (**(code **)(**(int **)(unaff_ESI + 4) + 0x18))
                        (*(int *)(unaff_ESI + 0x20018) - local_8,local_8 + 0x18 + unaff_ESI,&local_c
                        );
      if (iVar1 < 0) {
        return iVar1;
      }
      if (0 < local_c) {
        local_8 = local_8 + local_c;
      }
    }
    (**(code **)(**(int **)(unaff_ESI + 4) + 0x14))();
    uVar2 = FUN_008fed10();
    alBufferData(param_1,*(undefined4 *)(unaff_ESI + 0x14),unaff_ESI + 0x18,local_8,uVar2);
    FUN_00810080();
  }
  return iVar1;
}

