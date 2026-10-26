
undefined4 FUN_006eadb0(int param_1,int param_2)

{
  short sVar1;
  short *psVar2;
  int in_EAX;
  undefined4 uVar3;
  short *in_ECX;
  
  uVar3 = 0;
  if (in_EAX != 0) {
    param_1 = param_1 - (int)in_ECX;
    psVar2 = in_ECX;
    while ((in_ECX = psVar2, param_2 != 0 && (sVar1 = *(short *)(param_1 + (int)in_ECX), sVar1 != 0)
           )) {
      *in_ECX = sVar1;
      param_2 = param_2 + -1;
      in_EAX = in_EAX + -1;
      psVar2 = in_ECX + 1;
      if (in_EAX == 0) {
        *in_ECX = 0;
        return 0x8007007a;
      }
    }
    if (in_EAX != 0) goto LAB_006eadfd;
  }
  in_ECX = in_ECX + -1;
  uVar3 = 0x8007007a;
LAB_006eadfd:
  *in_ECX = 0;
  return uVar3;
}

