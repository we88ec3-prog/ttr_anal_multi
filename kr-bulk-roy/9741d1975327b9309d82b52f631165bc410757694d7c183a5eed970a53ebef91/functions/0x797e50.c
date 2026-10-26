
void FUN_00797e50(int param_1,int param_2)

{
  int iVar1;
  int *in_EAX;
  
  iVar1 = *in_EAX;
  in_EAX[0x2d] = param_1;
  in_EAX[0x2e] = param_2;
  in_EAX[0x2f] = (int)((float)param_1 / (float)param_2);
  *(int *)(iVar1 + 0x84) = param_1;
  *(int *)(iVar1 + 0x88) = param_2;
  in_EAX[0x33] = 0;
  if (*in_EAX != 0) {
    *(float *)(*in_EAX + 0x74) = ((float)in_EAX[0xd] / 1.3333334) * (float)in_EAX[0x2f];
  }
  return;
}

