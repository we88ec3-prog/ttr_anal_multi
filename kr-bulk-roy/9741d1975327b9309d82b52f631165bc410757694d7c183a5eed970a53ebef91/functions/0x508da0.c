
int FUN_00508da0(void)

{
  int in_EAX;
  int iVar1;
  int in_EDX;
  
  if (in_EAX - 1U < 100) {
    iVar1 = in_EAX * 0x20 + in_EDX;
    if ((*(int *)(iVar1 + 0xc) != 0) && (*(int *)(iVar1 + 8) != 0)) {
      return iVar1;
    }
  }
  else {
    FUN_006edb60(&DAT_00c0ddc0);
  }
  return 0;
}

