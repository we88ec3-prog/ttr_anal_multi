
int FUN_007293a0(int param_1)

{
  int *in_EAX;
  size_t sVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  if ((in_EAX == (int *)0x0) || ((char)in_EAX[0x17] != 'w')) {
    return -2;
  }
  *in_EAX = param_1;
  in_EAX[1] = unaff_ESI;
  iVar3 = unaff_ESI;
  do {
    if (iVar3 == 0) break;
    if (in_EAX[4] == 0) {
      in_EAX[3] = in_EAX[0x12];
      sVar1 = _fwrite((void *)in_EAX[0x12],1,0x4000,(FILE *)in_EAX[0x10]);
      if (sVar1 != 0x4000) {
        in_EAX[0xe] = -1;
        break;
      }
      in_EAX[4] = 0x4000;
    }
    in_EAX[0x19] = in_EAX[0x19] + in_EAX[1];
    in_EAX[0x1a] = in_EAX[0x1a] + in_EAX[4];
    iVar2 = FUN_00729a20(0);
    iVar3 = in_EAX[1];
    in_EAX[0x19] = in_EAX[0x19] - iVar3;
    in_EAX[0x1a] = in_EAX[0x1a] - in_EAX[4];
    in_EAX[0xe] = iVar2;
  } while (iVar2 == 0);
  if (param_1 != 0) {
    iVar3 = FUN_0072b700();
    in_EAX[0x13] = iVar3;
    return unaff_ESI - in_EAX[1];
  }
  in_EAX[0x13] = 0;
  return unaff_ESI - in_EAX[1];
}

