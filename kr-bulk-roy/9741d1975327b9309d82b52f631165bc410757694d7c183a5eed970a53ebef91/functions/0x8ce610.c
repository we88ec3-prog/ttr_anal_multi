
void FUN_008ce610(undefined4 param_1,undefined4 param_2)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  
  iVar2 = in_EAX[2];
  for (iVar1 = *in_EAX; iVar1 != 0; iVar1 = iVar1 + -1) {
    FUN_008ce340(iVar2,param_1,param_2);
    iVar2 = iVar2 + 0x1c;
  }
  return;
}

