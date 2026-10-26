
bool FUN_0082cdf0(void)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar3 = *(int *)(in_ECX + 0x24);
  if ((iVar3 == 0) && (*(int *)(in_ECX + 0x28) == 0)) {
    return false;
  }
  local_c = *in_EAX;
  local_8 = in_EAX[1];
  FUN_0082ce80();
  uVar1 = FUN_008fed10();
  local_14 = uVar1;
  local_10 = FUN_008fed10();
  local_c = uVar1;
  local_8 = local_10;
  iVar2 = FUN_00832da0(*(undefined4 *)(in_ECX + 0x28),&local_c);
  iVar3 = FUN_00832da0(iVar3,&local_14);
  return iVar2 == 0 && iVar3 == 0;
}

