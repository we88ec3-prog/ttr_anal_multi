
bool FUN_0080f3c0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = -0xe;
  iVar1 = FUN_00891268(0x3c);
  if (iVar1 != 0) {
    iVar2 = FUN_0080f160(iVar1);
    if (-1 < iVar2) {
      if (0x1400000 < *(uint *)(iVar1 + 0x30)) {
        FUN_006edb60("WAVLoader::Load(%s): ulDataSize > 20 MB",param_1);
        if (*(int *)(iVar1 + 0x2c) != 0) {
          FUN_00891d3d(*(int *)(iVar1 + 0x2c));
          *(undefined4 *)(iVar1 + 0x2c) = 0;
        }
        return false;
      }
      iVar2 = FUN_0087dc3d(*(uint *)(iVar1 + 0x30));
      *(int *)(iVar1 + 0x2c) = iVar2;
      if (iVar2 == 0) {
        iVar2 = -0xe;
      }
      else {
        (**(code **)(**(int **)(iVar1 + 0x34) + 0x34))(*(undefined4 *)(iVar1 + 0x38),0);
        if (*(int **)(iVar1 + 0x34) == (int *)0x0) {
          iVar2 = 0;
        }
        else {
          iVar2 = (**(code **)(**(int **)(iVar1 + 0x34) + 0x10))
                            (*(undefined4 *)(iVar1 + 0x2c),1,*(undefined4 *)(iVar1 + 0x30));
        }
        if (iVar2 == *(int *)(iVar1 + 0x30)) {
          iVar2 = 0;
        }
        else {
          if (*(int *)(iVar1 + 0x2c) != 0) {
            FUN_00891d3d(*(int *)(iVar1 + 0x2c));
            *(undefined4 *)(iVar1 + 0x2c) = 0;
          }
          iVar2 = -2;
        }
      }
      if (*(int **)(iVar1 + 0x34) != (int *)0x0) {
        (**(code **)(**(int **)(iVar1 + 0x34) + 4))();
      }
      *(undefined4 *)(iVar1 + 0x34) = 0;
    }
    if (iVar2 == 0) {
      *(int *)(in_ECX + 8) = iVar1;
      return true;
    }
    FUN_0089120c(iVar1);
  }
  return iVar2 == 0;
}

