
bool FUN_0044fa20(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  int iVar2;
  
  puVar1 = in_EAX + 4;
  if (7 < (uint)in_EAX[5]) {
    in_EAX = (undefined4 *)*in_EAX;
  }
  iVar2 = FUN_0044df20(0,in_EAX,*puVar1);
  return iVar2 < 0;
}

