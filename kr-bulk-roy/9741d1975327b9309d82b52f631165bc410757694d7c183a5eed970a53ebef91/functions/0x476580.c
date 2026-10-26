
void FUN_00476580(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  
  FUN_00755e50();
  FUN_00671d70();
  FUN_0040f570(0xfa1);
  FUN_0040f570(0x1004);
  FUN_00615fc0(2000);
  FUN_00615fc0(6000);
  FUN_00615fc0(5000);
  FUN_0043c570(0xbb9);
  FUN_0043c570(0xbba);
  FUN_00478050();
  FUN_0043c570(8000);
  (**(code **)(**(int **)(in_ECX + 0x11c) + 0x198))(0x1b5a);
  iVar4 = *(int *)(*(int *)(in_ECX + 0x120) + 0xcc);
  if (iVar4 != 0) {
    FUN_00408920(iVar4,10);
  }
  iVar4 = 0;
  do {
    iVar2 = *(int *)(*(int *)(in_ECX + 0x120) + 0xcc);
    if ((((iVar2 == 0) || (iVar4 < 0)) ||
        (*(int *)(iVar2 + 0xac) - *(int *)(iVar2 + 0xa8) >> 2 <= iVar4)) ||
       (piVar3 = *(int **)(*(int *)(iVar2 + 0xa8) + iVar4 * 4), piVar3 == (int *)0x0)) {
LAB_004766cd:
      piVar3 = (int *)0x0;
    }
    else {
      iVar2 = (**(code **)(*piVar3 + 4))();
      if (iVar2 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_004766cd;
      }
    }
    *(int **)(in_ECX + 0xf4 + iVar4 * 4) = piVar3;
    (**(code **)(*piVar3 + 0x198))(0x3f2);
    iVar4 = iVar4 + 1;
    if (9 < iVar4) {
      iVar4 = 0;
      puVar5 = (undefined4 *)(in_ECX + 0x134);
      do {
        FUN_0043c570(iVar4 + 0xbbb);
        (**(code **)(*(int *)*puVar5 + 0x94))(0);
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar4 < 8);
      piVar3 = *(int **)(in_ECX + 0x120);
      puVar5 = (undefined4 *)piVar3[0x19];
      for (puVar1 = (undefined4 *)*puVar5; puVar1 != puVar5; puVar1 = (undefined4 *)*puVar1) {
        iVar4 = puVar1[2];
        if ((*(int *)(iVar4 + 0x60) != 0) && ((*(int **)(iVar4 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar4 + 0x1c) + 0x30))(iVar4);
        }
      }
      (**(code **)(*piVar3 + 0x128))();
      FUN_00476d10(in_ECX);
      return;
    }
  } while( true );
}

