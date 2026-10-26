
void FUN_00427bb0(void)

{
  int in_ECX;
  int iVar1;
  
  FUN_0074a980();
  FUN_00429340();
  FUN_00429430();
  iVar1 = 11000;
  do {
    FUN_00615fc0(iVar1);
    iVar1 = iVar1 + 1000;
  } while (iVar1 < 14000);
  *(undefined1 *)(in_ECX + 0xea) = 0;
  FUN_00749c50();
  return;
}

