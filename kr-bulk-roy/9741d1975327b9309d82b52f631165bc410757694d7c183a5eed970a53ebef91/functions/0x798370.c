
void FUN_00798370(void)

{
  int iVar1;
  float fVar2;
  int *in_EAX;
  int *in_ECX;
  
  in_EAX[3] = *in_ECX;
  in_EAX[4] = in_ECX[1];
  in_EAX[5] = in_ECX[2];
  in_EAX[0x33] = 0;
  in_EAX[8] = in_ECX[5];
  in_EAX[0x33] = 0;
  iVar1 = in_ECX[4];
  in_EAX[0x33] = 0;
  in_EAX[7] = iVar1;
  in_EAX[6] = in_ECX[3];
  in_EAX[0x33] = 0;
  iVar1 = in_ECX[4];
  in_EAX[0x33] = 0;
  in_EAX[7] = iVar1;
  iVar1 = in_ECX[9];
  if (*in_EAX != 0) {
    *(int *)(*in_EAX + 0x7c) = iVar1;
  }
  in_EAX[0xc] = iVar1;
  iVar1 = in_ECX[8];
  if (*in_EAX != 0) {
    *(int *)(*in_EAX + 0x78) = iVar1;
  }
  in_EAX[0xb] = iVar1;
  in_EAX[0x33] = 0;
  fVar2 = (float)in_ECX[10];
  in_EAX[0x33] = 0;
  in_EAX[0xd] = (int)fVar2;
  if (*in_EAX != 0) {
    *(float *)(*in_EAX + 0x74) = (fVar2 / 1.3333334) * (float)in_EAX[0x2f];
  }
  in_EAX[10] = in_ECX[7];
  iVar1 = in_ECX[6];
  in_EAX[0x33] = 0;
  in_EAX[9] = iVar1;
  return;
}

