
void FUN_00779ba0(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int iVar3;
  
  iVar1 = in_ECX[4];
  iVar2 = 0;
  iVar3 = 0;
  if (iVar1 != 0) {
    iVar3 = *(int *)(iVar1 + 0x30) - *(int *)(iVar1 + 0x28);
  }
  iVar1 = in_ECX[0x24];
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x30) - *(int *)(iVar1 + 0x28);
  }
  (**(code **)(*in_ECX + 0x5c))(iVar3,0,iVar2,0);
  return;
}

