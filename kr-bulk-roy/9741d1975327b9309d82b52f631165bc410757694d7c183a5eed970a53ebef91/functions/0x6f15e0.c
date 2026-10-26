
int FUN_006f15e0(void)

{
  undefined4 *in_EAX;
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int *unaff_EDI;
  
  if (unaff_EDI == (int *)0x0) {
    return -0x7fffbffb;
  }
  in_EAX[in_EAX[7] + 2] = unaff_EDI;
  iVar1 = (**(code **)(*(int *)in_EAX[in_EAX[7] + 2] + 0x10))(*in_EAX,in_EAX[1]);
  in_EAX[7] = in_EAX[7] + 1;
  pcVar2 = " but NOT initialized";
  if (-1 < iVar1) {
    pcVar2 = " and initialized";
  }
  uVar3 = (**(code **)(*unaff_EDI + 4))(in_EAX[7],pcVar2);
  FID_conflict__wprintf("%s device (%d) is created%s\n",uVar3);
  return iVar1;
}

