
void FUN_0077a930(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int iVar3;
  
  iVar1 = in_ECX[4];
  iVar2 = 0;
  iVar3 = 0;
  if (iVar1 != 0) {
    iVar3 = *(int *)(iVar1 + 0x34) - *(int *)(iVar1 + 0x2c);
  }
  iVar1 = in_ECX[0x24];
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x34) - *(int *)(iVar1 + 0x2c);
  }
  (**(code **)(*in_ECX + 0x5c))(0,iVar3,0,iVar2);
  return;
}

