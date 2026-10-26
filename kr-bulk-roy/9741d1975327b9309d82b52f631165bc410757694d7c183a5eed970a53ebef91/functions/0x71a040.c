
uint FUN_0071a040(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 in_EAX;
  uint uVar3;
  undefined3 uVar4;
  
  FUN_0071baa0(in_EAX);
  if (param_1 == 0) {
    return 0;
  }
  pcVar2 = *(char **)(param_1 + 8);
  uVar3 = 0;
  if (pcVar2 != (char *)0x0) {
    cVar1 = *pcVar2;
    uVar4 = (undefined3)((uint)pcVar2 >> 8);
    uVar3 = CONCAT31(uVar4,cVar1);
    if ((((cVar1 == '1') || (cVar1 == 't')) || (cVar1 == 'T')) || ((cVar1 == 'y' || (cVar1 == 'Y')))
       ) {
      return CONCAT31(uVar4,1);
    }
  }
  return uVar3 & 0xffffff00;
}

