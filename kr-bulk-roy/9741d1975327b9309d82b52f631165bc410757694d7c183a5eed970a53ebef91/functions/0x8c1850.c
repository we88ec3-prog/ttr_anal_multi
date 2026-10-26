
void FUN_008c1850(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  
  in_ECX[8] = in_ECX[4];
  iVar2 = in_ECX[2];
  iVar1 = (*in_ECX + iVar2) / 2;
  in_ECX[2] = iVar1;
  iVar2 = (in_ECX[4] + iVar2) / 2;
  in_ECX[4] = (iVar1 + iVar2) / 2;
  in_ECX[9] = in_ECX[5];
  in_ECX[6] = iVar2;
  iVar2 = (in_ECX[1] + in_ECX[3]) / 2;
  iVar1 = (in_ECX[5] + in_ECX[3]) / 2;
  in_ECX[3] = iVar2;
  in_ECX[7] = iVar1;
  in_ECX[5] = (iVar2 + iVar1) / 2;
  return;
}

