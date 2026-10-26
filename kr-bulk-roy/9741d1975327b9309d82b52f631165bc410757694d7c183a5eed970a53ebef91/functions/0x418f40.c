
void FUN_00418f40(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  int iVar5;
  
  FUN_004198f0();
  FUN_004199e0();
  FUN_00419ad0();
  iVar5 = *(int *)(*(int *)(in_ECX + 0x84) + 0xcc);
  if (iVar5 != 0) {
    FUN_00408920(iVar5,0xb);
  }
  iVar5 = 0;
  do {
    iVar3 = *(int *)(*(int *)(in_ECX + 0x84) + 0xcc);
    if ((((iVar3 == 0) || (iVar5 < 0)) ||
        (*(int *)(iVar3 + 0xac) - *(int *)(iVar3 + 0xa8) >> 2 <= iVar5)) ||
       (piVar4 = *(int **)(*(int *)(iVar3 + 0xa8) + iVar5 * 4), piVar4 == (int *)0x0)) {
LAB_00418ff2:
      piVar4 = (int *)0x0;
    }
    else {
      iVar3 = (**(code **)(*piVar4 + 4))();
      if (iVar3 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_00418ff2;
      }
    }
    *(int **)(in_ECX + 0x88 + iVar5 * 4) = piVar4;
    (**(code **)(*piVar4 + 0x198))(0x6e0410);
    iVar5 = iVar5 + 1;
    if (10 < iVar5) {
      *(undefined4 *)(in_ECX + 0xbc) = 0;
      piVar4 = *(int **)(in_ECX + 0x84);
      puVar1 = (undefined4 *)piVar4[0x19];
      for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
        iVar5 = puVar2[2];
        if ((*(int *)(iVar5 + 0x60) != 0) && ((*(int **)(iVar5 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar5 + 0x1c) + 0x30))(iVar5);
        }
      }
      (**(code **)(*piVar4 + 0x128))();
      return;
    }
  } while( true );
}

