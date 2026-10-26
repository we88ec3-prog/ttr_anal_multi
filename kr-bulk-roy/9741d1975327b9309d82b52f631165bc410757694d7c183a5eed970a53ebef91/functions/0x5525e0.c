
int FUN_005525e0(void)

{
  char *in_EAX;
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined8 uVar5;
  
  pcVar2 = in_EAX;
  if (0xf < *(uint *)(in_EAX + 0x14)) {
    pcVar2 = *(char **)in_EAX;
  }
  pcVar3 = pcVar2 + *(int *)(in_EAX + 0x10);
  uVar1 = 0x811c9dc5;
  for (; pcVar2 != pcVar3; pcVar2 = pcVar2 + 1) {
    uVar1 = uVar1 * 0x1000193 ^ (int)*pcVar2;
  }
  uVar5 = FUN_008968d5(uVar1 & 0x7fffffff,0x1f31d);
  iVar4 = (int)((ulonglong)uVar5 >> 0x20) * 0x41a7 + (int)uVar5 * -0xb14;
  if (iVar4 < 0) {
    iVar4 = iVar4 + 0x7fffffff;
  }
  return iVar4;
}

