
void FUN_0075e120(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x24) != 0) {
    FUN_00443da0();
    FUN_00443da0();
    uVar1 = FUN_008fed10();
    *(undefined4 *)(unaff_ESI + 200) = uVar1;
    uVar1 = FUN_008fed10();
    *(undefined4 *)(unaff_ESI + 0xcc) = uVar1;
    return;
  }
  *(undefined4 *)(unaff_ESI + 200) = 0;
  *(undefined4 *)(unaff_ESI + 0xcc) = 0;
  return;
}

