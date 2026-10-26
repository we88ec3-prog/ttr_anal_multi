
void FUN_00839490(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  
  uVar1 = in_EAX[1];
  uVar2 = in_EAX[2];
  *in_ECX = *in_EAX;
  in_ECX[1] = uVar1;
  in_ECX[2] = uVar2;
  uVar1 = in_EAX[5];
  uVar2 = in_EAX[6];
  in_ECX[3] = in_EAX[4];
  in_ECX[4] = uVar1;
  in_ECX[5] = uVar2;
  uVar1 = in_EAX[9];
  uVar2 = in_EAX[10];
  in_ECX[6] = in_EAX[8];
  in_ECX[7] = uVar1;
  in_ECX[8] = uVar2;
  uVar1 = in_EAX[0xd];
  uVar2 = in_EAX[0xe];
  in_ECX[9] = in_EAX[0xc];
  in_ECX[10] = uVar1;
  in_ECX[0xb] = uVar2;
  return;
}

