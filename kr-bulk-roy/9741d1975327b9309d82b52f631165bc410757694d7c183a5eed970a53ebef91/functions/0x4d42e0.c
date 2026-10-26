
void FUN_004d42e0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int iVar4;
  
  iVar2 = 999;
  piVar3 = (int *)(in_ECX + 0x428);
  iVar4 = 1;
  do {
    if ((((iVar4 - 1U < 10) && (piVar3[-0xf3] != 0)) && (piVar3 != (int *)0x428)) &&
       (piVar3[-0x108] < iVar2)) {
      iVar2 = piVar3[-0x108];
    }
    if (((-1 < iVar4) && (iVar4 < 10)) &&
       ((piVar3[-0x6f] != 0 && ((piVar3 != (int *)0x218 && (piVar3[-0x84] < iVar2)))))) {
      iVar2 = piVar3[-0x84];
    }
    if ((((-1 < iVar4 + 1) && (iVar4 + 1 < 10)) && (piVar3[0x15] != 0)) &&
       ((piVar3 != (int *)0x8 && (*piVar3 < iVar2)))) {
      iVar2 = *piVar3;
    }
    if (((-1 < iVar4 + 2) && (iVar4 + 2 < 10)) &&
       ((piVar3[0x99] != 0 && ((piVar3 != (int *)0xfffffdf8 && (piVar3[0x84] < iVar2)))))) {
      iVar2 = piVar3[0x84];
    }
    if ((((-1 < iVar4 + 3) && (iVar4 + 3 < 10)) && (piVar3[0x11d] != 0)) &&
       ((piVar3 != (int *)0xfffffbe8 && (piVar3[0x108] < iVar2)))) {
      iVar2 = piVar3[0x108];
    }
    iVar1 = iVar4 + 4;
    piVar3 = piVar3 + 0x294;
    iVar4 = iVar4 + 5;
  } while (iVar1 < 10);
  return;
}

