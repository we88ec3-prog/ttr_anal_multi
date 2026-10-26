
void FUN_0065baf0(void)

{
  int iVar1;
  uint in_EAX;
  uint uVar2;
  int *in_EDX;
  undefined4 local_8;
  
  iVar1 = in_EDX[1];
  uVar2 = iVar1 - *in_EDX >> 2;
  local_8 = 0;
  if (uVar2 < in_EAX) {
    FUN_006492c0(in_EDX,iVar1,&local_8);
    return;
  }
  if (in_EAX < uVar2) {
    FUN_004088c0(in_EDX,*in_EDX + in_EAX * 4,iVar1);
  }
  return;
}

