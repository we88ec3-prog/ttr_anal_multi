
void FUN_0065b550(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int in_EAX;
  uint uVar2;
  int *in_ECX;
  int iVar3;
  int iVar4;
  
  uVar2 = FUN_0065b9d0(in_EAX,param_2,param_3);
  uVar1 = uVar2 + in_EAX;
  if (((int)uVar1 < 0) && (uVar1 != 0)) {
    iVar3 = (-uVar1 - 1 >> 5) * -4 + -4;
  }
  else {
    iVar3 = (uVar1 >> 5) * 4;
  }
  if (((int)uVar2 < 0) && (uVar2 != 0)) {
    iVar4 = (-uVar2 - 1 >> 5) * -4 + -4;
  }
  else {
    iVar4 = (uVar2 >> 5) * 4;
  }
  FUN_0065cad0(*in_ECX + iVar4,uVar2 & 0x1f,*in_ECX + iVar3,uVar1 & 0x1f);
  return;
}

