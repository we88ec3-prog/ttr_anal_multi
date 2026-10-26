
void FUN_00874d70(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  while (param_1 != param_2) {
    piVar2 = param_1 + 1;
    iVar1 = *param_1;
    param_1 = piVar2;
    if (iVar1 != 0) {
      if (*(int *)(iVar1 + 4) != 0) {
        FUN_00891d3d(*(int *)(iVar1 + 4));
        *(undefined4 *)(iVar1 + 4) = 0;
      }
      if (*(int *)(iVar1 + 8) != 0) {
        FUN_00891d3d(*(int *)(iVar1 + 8));
        *(undefined4 *)(iVar1 + 8) = 0;
      }
      if (*(int *)(iVar1 + 0xc) != 0) {
        FUN_00891d3d(*(int *)(iVar1 + 0xc));
        *(undefined4 *)(iVar1 + 0xc) = 0;
      }
      if (*(int *)(iVar1 + 0x10) != 0) {
        FUN_00891d3d(*(int *)(iVar1 + 0x10));
        *(undefined4 *)(iVar1 + 0x10) = 0;
      }
      if (*(int *)(iVar1 + 0x14) != 0) {
        FUN_00891d3d(*(int *)(iVar1 + 0x14));
        *(undefined4 *)(iVar1 + 0x14) = 0;
      }
      FUN_0089120c(iVar1);
    }
  }
  return;
}

