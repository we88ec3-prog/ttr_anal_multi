
void FUN_008d0dd0(int param_1)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  
  iVar1 = *in_EAX;
  iVar2 = *(int *)(iVar1 + 0x1e4);
  in_EAX[6] = *(int *)(iVar1 + 0x1a0);
  in_EAX[7] = *(int *)(iVar1 + 0x1a4);
  in_EAX[5] = *(int *)(iVar2 + 0x14);
  if (param_1 != 0) {
    in_EAX[4] = *(int *)(iVar2 + 0x1c);
    return;
  }
  in_EAX[4] = *(int *)(iVar2 + 0x18);
  return;
}

