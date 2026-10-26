
undefined4 FUN_008eb8e0(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (*(code **)(unaff_ESI + 0x1fc) == (code *)0x0) {
    return 0;
  }
  iVar1 = (**(code **)(unaff_ESI + 0x1fc))();
  if (iVar1 != 0) {
    return 0;
  }
  uVar2 = FUN_008eb860(*(undefined4 *)(unaff_ESI + 0x68));
  return uVar2;
}

