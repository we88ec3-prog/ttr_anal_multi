
int FUN_004d4590(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int iVar4;
  
  iVar2 = 0;
  piVar3 = (int *)(in_ECX + 0x638);
  iVar4 = 2;
  do {
    if (((iVar4 - 1U < 10) && (piVar3[-0xf3] != 0)) && (piVar3 != (int *)0x428)) {
      iVar2 = iVar2 + piVar3[-0x108] * piVar3[-0x108];
    }
    if (((-1 < iVar4) && (iVar4 < 10)) && ((piVar3[-0x6f] != 0 && (piVar3 != (int *)0x218)))) {
      iVar2 = iVar2 + piVar3[-0x84] * piVar3[-0x84];
    }
    if (((-1 < iVar4 + 1) && (iVar4 + 1 < 10)) && ((piVar3[0x15] != 0 && (piVar3 != (int *)0x8)))) {
      iVar2 = iVar2 + *piVar3 * *piVar3;
    }
    iVar1 = iVar4 + 2;
    piVar3 = piVar3 + 0x18c;
    iVar4 = iVar4 + 3;
  } while (iVar1 < 10);
  return iVar2;
}

