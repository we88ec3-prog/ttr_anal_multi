
void FUN_00571f70(int *param_1)

{
  int *piVar1;
  char cVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  piVar1 = param_1;
  if (in_EAX != param_1) {
    iVar4 = param_1[1] - *param_1 >> 0x1f;
    iVar3 = (param_1[1] - *param_1) / 0x1c + iVar4;
    uVar5 = iVar3 - iVar4;
    if (iVar3 == iVar4) {
      FUN_004d7fe0(in_EAX,&param_1,*in_EAX,in_EAX[1]);
      return;
    }
    if (uVar5 <= (uint)((in_EAX[1] - *in_EAX) / 0x1c)) {
      FUN_00572460(*param_1,*in_EAX);
      FUN_0049bf30();
      in_EAX[1] = *in_EAX + ((piVar1[1] - *piVar1) / 0x1c) * 0x1c;
      return;
    }
    iVar4 = in_EAX[2] - *in_EAX;
    if (uVar5 <= (uint)(iVar4 / 0x1c)) {
      iVar3 = *param_1;
      param_1 = (int *)iVar4;
      FUN_00572460(iVar3,*in_EAX);
      iVar4 = FUN_00572480(piVar1[1]);
      in_EAX[1] = iVar4;
      return;
    }
    param_1 = (int *)iVar4;
    if (*in_EAX != 0) {
      FUN_0049bf30();
      FUN_0089120c(*in_EAX);
    }
    cVar2 = FUN_00556670();
    if (cVar2 != '\0') {
      iVar4 = FUN_00572480(piVar1[1]);
      in_EAX[1] = iVar4;
    }
  }
  return;
}

