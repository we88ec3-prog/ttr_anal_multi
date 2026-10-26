
void FUN_0080d440(int *param_1,int param_2,int param_3)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = in_EAX;
  if (0xf < (uint)in_EAX[5]) {
    puVar1 = (undefined4 *)*in_EAX;
  }
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 - (int)puVar1;
  }
  if (param_3 != 0) {
    param_3 = param_3 - param_2;
  }
  FUN_00402c80(iVar2,param_3);
  if (0xf < (uint)in_EAX[5]) {
    in_EAX = (undefined4 *)*in_EAX;
  }
  *param_1 = (int)in_EAX + iVar2;
  return;
}

