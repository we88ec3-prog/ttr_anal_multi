
void FUN_008ed030(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_EAX;
  
  uVar1 = in_EAX[2];
  uVar2 = in_EAX[1];
  in_EAX[2] = *in_EAX;
  in_EAX[1] = uVar1;
  *in_EAX = uVar2;
  return;
}

