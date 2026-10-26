
void FUN_00443dc0(void)

{
  int iVar1;
  
  if (DAT_00fba80c == 0) {
    iVar1 = FUN_00891268(0x57c);
    if (iVar1 != 0) {
      DAT_00fba80c = FUN_006f1370();
      return;
    }
    DAT_00fba80c = 0;
  }
  return;
}

