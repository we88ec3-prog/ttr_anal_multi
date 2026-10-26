
void FUN_005f4460(void)

{
  int iVar1;
  
  FUN_005f2f30();
  FUN_0046b6f0(10000);
  iVar1 = 0x44c;
  do {
    FUN_0046b6f0(iVar1 + -100);
    FUN_0043c570(iVar1);
    FUN_0043c570(iVar1 + 100);
    iVar1 = iVar1 + 1000;
  } while (iVar1 < 0x1004);
  return;
}

