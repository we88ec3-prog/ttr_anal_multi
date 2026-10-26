
void FUN_00753660(int param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  void *local_8;
  
  uVar2 = 0x1000;
  if (*(int *)(unaff_ESI + 0x165a4) <
      *(int *)(unaff_ESI + 0x165a8) + *(int *)(unaff_ESI + 0x165ac) + param_1) {
    uVar2 = 0x2000;
    *(undefined4 *)(unaff_ESI + 0x165a8) = 0;
  }
  iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x165a0) + 0x2c))
                    (*(int **)(unaff_ESI + 0x165a0),
                     (*(int *)(unaff_ESI + 0x165a8) + *(int *)(unaff_ESI + 0x165ac)) *
                     *(int *)(unaff_ESI + 0x165b0),*(int *)(unaff_ESI + 0x165b0) * param_1,&local_8,
                     uVar2);
  if (-1 < iVar1) {
    FID_conflict__memcpy(local_8,param_2,*(int *)(unaff_ESI + 0x165b0) * param_1);
    (**(code **)(**(int **)(unaff_ESI + 0x165a0) + 0x30))(*(int **)(unaff_ESI + 0x165a0));
    *(int *)(unaff_ESI + 0x165ac) = *(int *)(unaff_ESI + 0x165ac) + param_1;
  }
  return;
}

