
void FUN_005fd250(void)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  iVar1 = (**(code **)(*in_EAX + 0x1ac))();
  if (0 < iVar1) {
    do {
      FUN_005f6060();
      iVar2 = iVar2 + 1;
      iVar1 = (**(code **)(*in_EAX + 0x1ac))();
    } while (iVar2 < iVar1);
  }
  in_EAX[0x50] = 0;
  (**(code **)(*(int *)in_EAX[0x4b] + 0x90))(1);
  (**(code **)(*(int *)in_EAX[0x3f] + 0x90))(1);
  (**(code **)(*(int *)in_EAX[0x40] + 0x90))(1);
  piVar3 = in_EAX + 0x5c;
  iVar1 = 5;
  do {
    (**(code **)(*(int *)*piVar3 + 0x90))(1);
    piVar3 = piVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

