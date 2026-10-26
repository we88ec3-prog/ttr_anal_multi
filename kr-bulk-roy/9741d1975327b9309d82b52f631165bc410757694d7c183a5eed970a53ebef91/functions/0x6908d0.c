
void FUN_006908d0(undefined4 param_1)

{
  int iVar1;
  int unaff_EDI;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(*(int *)(unaff_EDI + 0x134) + 0x24c);
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xcc), iVar1 != 0)) {
    FUN_006438f0(iVar1);
  }
  FUN_00757710();
  switch(param_1) {
  case 3:
  case 4:
    uVar3 = 2;
    uVar2 = 0x3e;
    FUN_00585620(0x3e,2);
    uVar2 = FUN_00585330(uVar2);
    FUN_00690d80(unaff_EDI,uVar2,uVar3);
    FUN_0075cd30(*(undefined4 *)(unaff_EDI + 0x134));
    *(undefined4 *)(unaff_EDI + 0x208) = 2;
    break;
  case 7:
    uVar3 = 0;
    uVar2 = 0x32c;
    FUN_00585620(0x32c,0);
    uVar2 = FUN_00585330(uVar2);
    FUN_00690d80(unaff_EDI,uVar2,uVar3);
    uVar3 = 1;
    uVar2 = 0x3c;
    goto LAB_0069098b;
  case 8:
  case 9:
    uVar3 = 3;
    uVar2 = 0x3f;
    FUN_00585620(0x3f,3);
    uVar2 = FUN_00585330(uVar2);
    FUN_00690d80(unaff_EDI,uVar2,uVar3);
    FUN_0075cd30(*(undefined4 *)(unaff_EDI + 0x134));
    *(undefined4 *)(unaff_EDI + 0x208) = 3;
    break;
  case 0x15:
    uVar3 = 9;
    uVar2 = 0x32d;
    FUN_00585620(0x32d,9);
    uVar2 = FUN_00585330(uVar2);
    FUN_00690d80(unaff_EDI,uVar2,uVar3);
    FUN_0075cd30(*(undefined4 *)(unaff_EDI + 0x134));
    *(undefined4 *)(unaff_EDI + 0x208) = 9;
    goto LAB_00690956;
  case 0x17:
    uVar3 = 0;
    uVar2 = 0x32c;
    FUN_00585620(0x32c,0);
    uVar2 = FUN_00585330(uVar2);
    FUN_00690d80(unaff_EDI,uVar2,uVar3);
    uVar3 = 10;
    uVar2 = 0x3d;
    goto LAB_0069098b;
  case 0x18:
    uVar3 = 0;
    uVar2 = 0x32c;
    FUN_00585620(0x32c,0);
    uVar2 = FUN_00585330(uVar2);
    FUN_00690d80(unaff_EDI,uVar2,uVar3);
    uVar3 = 0xb;
    uVar2 = 0x3d;
LAB_0069098b:
    FUN_00585620(uVar2,uVar3);
    uVar2 = FUN_00585330(uVar2);
    FUN_00690d80(unaff_EDI,uVar2,uVar3);
    uVar3 = 2;
    uVar2 = 0x3e;
    FUN_00585620(0x3e,2);
    uVar2 = FUN_00585330(uVar2);
    FUN_00690d80(unaff_EDI,uVar2,uVar3);
    uVar3 = 3;
    uVar2 = 0x3f;
    FUN_00585620(0x3f,3);
    uVar2 = FUN_00585330(uVar2);
    FUN_00690d80(unaff_EDI,uVar2,uVar3);
    FUN_0075cd30(*(undefined4 *)(unaff_EDI + 0x134));
    *(undefined4 *)(unaff_EDI + 0x208) = 0;
LAB_00690956:
    (**(code **)(**(int **)(unaff_EDI + 0x100) + 0x90))(0);
    break;
  case 0x1b:
  case 0x1c:
    uVar3 = 0xe;
    uVar2 = 0x47;
    FUN_00585620(0x47,0xe);
    uVar2 = FUN_00585330(uVar2);
    FUN_00690d80(unaff_EDI,uVar2,uVar3);
    FUN_0075cd30(*(undefined4 *)(unaff_EDI + 0x134));
    *(undefined4 *)(unaff_EDI + 0x208) = 0xe;
  }
  iVar1 = *(int *)(*(int *)(unaff_EDI + 0x134) + 0x24c);
  if (iVar1 != 0) {
    FUN_00749920(iVar1);
  }
  (**(code **)(**(int **)(unaff_EDI + 0x134) + 200))();
  return;
}

