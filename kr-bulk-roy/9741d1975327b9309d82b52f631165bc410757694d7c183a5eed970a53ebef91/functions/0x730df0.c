
byte * FUN_00730df0(int *param_1)

{
  byte bVar1;
  int in_EAX;
  byte *pbVar2;
  byte *in_ECX;
  int iVar3;
  byte *unaff_EDI;
  
  if (in_EAX == 1) {
    bVar1 = *unaff_EDI;
    iVar3 = *(int *)(&DAT_00c07d58 + (uint)bVar1 * 4);
    *param_1 = iVar3;
    if (iVar3 != 1) {
      if (iVar3 == 0) {
        return (byte *)0x0;
      }
      iVar3 = 0;
      if (bVar1 != 0) {
        pbVar2 = unaff_EDI;
        do {
          if (*param_1 <= iVar3) break;
          pbVar2[(int)in_ECX - (int)unaff_EDI] = *pbVar2;
          pbVar2 = pbVar2 + 1;
          iVar3 = iVar3 + 1;
        } while (*pbVar2 != 0);
      }
      return unaff_EDI + *param_1;
    }
  }
  else {
    *param_1 = 1;
  }
  if (*unaff_EDI == 0x26) {
    pbVar2 = (byte *)FUN_00731380();
    return pbVar2;
  }
  *in_ECX = *unaff_EDI;
  return unaff_EDI + 1;
}

