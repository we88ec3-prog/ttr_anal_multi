
int FUN_00509350(int param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int in_ECX;
  
  iVar2 = in_ECX + -0x50 + in_EAX * 0x50;
  if (iVar2 - 1U < 0x1e0) {
    iVar1 = param_1 + iVar2 * 0x18;
    if ((*(int *)(param_1 + 0xc + iVar2 * 0x18) != 0) && (*(int *)(iVar1 + 8) != 0)) {
      return iVar1;
    }
  }
  else {
    FUN_006edb60(&DAT_00c0ddc0);
  }
  return 0;
}

