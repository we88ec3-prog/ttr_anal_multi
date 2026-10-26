
void FUN_008c19e0(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  in_ECX[0xc] = in_ECX[6];
  iVar3 = (*in_ECX + in_ECX[2]) / 2;
  iVar2 = (in_ECX[4] + in_ECX[2]) / 2;
  in_ECX[2] = iVar3;
  iVar4 = (in_ECX[4] + in_ECX[6]) / 2;
  iVar1 = (iVar4 + iVar2) / 2;
  in_ECX[8] = iVar1;
  iVar2 = (iVar3 + iVar2) / 2;
  in_ECX[6] = (iVar1 + iVar2) / 2;
  in_ECX[4] = iVar2;
  in_ECX[10] = iVar4;
  in_ECX[0xd] = in_ECX[7];
  iVar3 = (in_ECX[1] + in_ECX[3]) / 2;
  iVar2 = (in_ECX[5] + in_ECX[3]) / 2;
  iVar4 = (in_ECX[5] + in_ECX[7]) / 2;
  in_ECX[3] = iVar3;
  iVar1 = (iVar4 + iVar2) / 2;
  iVar2 = (iVar3 + iVar2) / 2;
  in_ECX[9] = iVar1;
  in_ECX[0xb] = iVar4;
  in_ECX[5] = iVar2;
  in_ECX[7] = (iVar1 + iVar2) / 2;
  return;
}

