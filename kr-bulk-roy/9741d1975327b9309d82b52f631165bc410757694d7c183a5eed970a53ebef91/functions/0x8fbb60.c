
int FUN_008fbb60(void)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int in_ECX;
  int *in_EDX;
  
  in_EDX[1] = in_EAX;
  *in_EDX = in_ECX;
  in_EDX[2] = *(int *)(in_EAX + 0x1c);
  piVar1 = in_EDX + 0x812;
  in_EDX[0x814] = (int)piVar1;
  in_EDX[0x813] = (int)piVar1;
  *piVar1 = 0;
  iVar2 = FUN_008fb610();
  if (iVar2 == 0) {
    iVar3 = FUN_008b9850();
    in_EDX[0x11] = iVar3;
    in_EDX[0xb] = (int)FUN_008fb5c0;
    in_EDX[0xc] = (int)FUN_008fb5e0;
    in_EDX[0xd] = *(int *)(in_ECX + 0x1c);
    in_EDX[4] = 0;
    in_EDX[3] = (int)(in_EDX + 0x412);
    iVar3 = FUN_008fba60(0x38);
    if ((iVar3 != 0) || (in_EDX[3] == 0)) {
      return 3;
    }
  }
  return iVar2;
}

