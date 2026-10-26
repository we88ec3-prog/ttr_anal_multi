
void FUN_0080e850(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x14);
  iVar2 = (**(code **)(*piVar1 + 0x18))();
  do {
    if ((iVar2 == 0) || (*(int *)(param_1 + 4) == 0)) goto LAB_0080e8b4;
    iVar2 = (**(code **)(*piVar1 + 0x14))();
    if (iVar2 == 0) {
      (**(code **)(*piVar1 + 0x1c))();
      iVar2 = (**(code **)(*piVar1 + 0xc))();
      if (iVar2 == 0) {
LAB_0080e8b4:
        FID_conflict__wprintf("Music: ended loop\n");
        *(undefined4 *)(param_1 + 4) = 0;
        *(undefined4 *)(param_1 + 8) = 0;
        return;
      }
      (**(code **)(*piVar1 + 0x10))();
    }
    Sleep(1);
    iVar2 = (**(code **)(*piVar1 + 0x18))();
  } while( true );
}

