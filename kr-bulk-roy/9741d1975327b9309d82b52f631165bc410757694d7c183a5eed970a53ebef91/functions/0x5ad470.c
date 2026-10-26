
void FUN_005ad470(void)

{
  int iVar1;
  int unaff_ESI;
  
  (**(code **)(**(int **)(unaff_ESI + 0x234) + 0xd4))();
  iVar1 = *(int *)(unaff_ESI + 0x238);
  *(undefined4 *)(iVar1 + 0x140) = 0;
  *(undefined4 *)(iVar1 + 0x144) = 0xffffffff;
  (**(code **)(**(int **)(unaff_ESI + 0x238) + 0xd0))();
  if (*(char *)(unaff_ESI + 0x244) != '\0') {
    FUN_00652420();
    return;
  }
  return;
}

