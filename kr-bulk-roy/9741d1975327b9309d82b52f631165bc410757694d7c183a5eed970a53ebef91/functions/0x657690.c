
void FUN_00657690(void)

{
  int iVar1;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x254) == 2) {
    *(undefined4 *)(*(int *)(unaff_EDI + 0x248) + 0x154) = 0xffe243ff;
  }
  else {
    iVar1 = *(int *)(unaff_EDI + 600);
    if (iVar1 == 3) {
      *(undefined4 *)(*(int *)(unaff_EDI + 0x248) + 0x154) = 0xff99ff00;
    }
    else if (iVar1 == 4) {
      *(undefined4 *)(*(int *)(unaff_EDI + 0x248) + 0x154) = 0xff5aff78;
    }
    else if (iVar1 == 1) {
      *(undefined4 *)(*(int *)(unaff_EDI + 0x248) + 0x154) = 0xffff6600;
    }
    else {
      *(undefined4 *)(*(int *)(unaff_EDI + 0x248) + 0x154) = 0xffffff00;
    }
  }
  if (*(char *)(unaff_EDI + 0x250) == '\0') {
    *(undefined4 *)(*(int *)(unaff_EDI + 0x24c) + 0x154) = 0xffffffff;
  }
  else {
    *(undefined4 *)(*(int *)(unaff_EDI + 0x24c) + 0x154) = 0xff92ff00;
  }
  FUN_00749c50();
  FUN_00749c50();
  return;
}

