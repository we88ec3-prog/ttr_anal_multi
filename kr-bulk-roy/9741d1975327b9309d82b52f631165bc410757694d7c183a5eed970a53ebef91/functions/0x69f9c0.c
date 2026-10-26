
void FUN_0069f9c0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  int iVar6;
  int local_c;
  int *local_8;
  
  local_8 = (int *)0xb;
  FUN_0082ef00(&local_8);
  if (local_c == *(int *)(in_ECX + 0x50)) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(local_c + 0x10);
  }
  *(undefined4 *)(in_ECX + 0x80) = uVar3;
  FUN_006a1520();
  FUN_00643ce0(53000);
  FUN_00643ce0(0xcfd0);
  FUN_0043c570(0xcf6c);
  FUN_00677fa0(0xa08c);
  FUN_00677fa0(0xa474);
  FUN_00677fa0(0xa85c);
  FUN_0044dd40(12000);
  FUN_0044dd40(21000);
  FUN_0044dd40(22000);
  FUN_00615fc0(30000);
  FUN_00615fc0(31000);
  FUN_0043c570(54000);
  *(undefined4 *)(*(int *)(in_ECX + 0x10c) + 0x144) = 3;
  piVar5 = (int *)(in_ECX + 0xec);
  *(undefined4 *)(*(int *)(in_ECX + 0x110) + 0x144) = 3;
  local_8 = piVar5;
  if (*(int *)(*piVar5 + 0xcc) != 0) {
    FUN_00408920(*(int *)(*piVar5 + 0xcc),10);
  }
  iVar6 = 0;
  do {
    iVar4 = *(int *)(*piVar5 + 0xcc);
    if ((((iVar4 == 0) || (iVar6 < 0)) ||
        (*(int *)(iVar4 + 0xac) - *(int *)(iVar4 + 0xa8) >> 2 <= iVar6)) ||
       (piVar5 = *(int **)(*(int *)(iVar4 + 0xa8) + iVar6 * 4), piVar5 == (int *)0x0)) {
LAB_0069fb7c:
      piVar5 = (int *)0x0;
    }
    else {
      iVar4 = (**(code **)(*piVar5 + 4))();
      if (iVar4 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_0069fb7c;
      }
    }
    *(int **)(in_ECX + 0x11c + iVar6 * 4) = piVar5;
    iVar6 = iVar6 + 1;
    piVar5 = local_8;
    if (9 < iVar6) {
      piVar5 = (int *)*local_8;
      puVar1 = (undefined4 *)piVar5[0x19];
      for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
        iVar6 = puVar2[2];
        if ((*(int *)(iVar6 + 0x60) != 0) && ((*(int **)(iVar6 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar6 + 0x1c) + 0x30))(iVar6);
        }
      }
      (**(code **)(*piVar5 + 0x128))();
      return;
    }
  } while( true );
}

