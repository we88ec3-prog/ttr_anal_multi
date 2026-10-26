
void FUN_00753700(void)

{
  int unaff_ESI;
  
  if (0 < *(int *)(unaff_ESI + 0x165ac)) {
    (**(code **)(**(int **)(unaff_ESI + 0x1c) + 400))
              (*(int **)(unaff_ESI + 0x1c),0,*(undefined4 *)(unaff_ESI + 0x165a0),0,0x1c);
    (**(code **)(**(int **)(unaff_ESI + 0x1c) + 0x164))(*(int **)(unaff_ESI + 0x1c),0x144);
    (**(code **)(**(int **)(unaff_ESI + 0x1c) + 0x144))
              (*(int **)(unaff_ESI + 0x1c),4,*(int *)(unaff_ESI + 0x165a8) * 6,
               *(int *)(unaff_ESI + 0x165ac) * 2);
    *(int *)(unaff_ESI + 0x165a8) = *(int *)(unaff_ESI + 0x165a8) + *(int *)(unaff_ESI + 0x165ac);
    *(undefined4 *)(unaff_ESI + 0x165ac) = 0;
  }
  return;
}

