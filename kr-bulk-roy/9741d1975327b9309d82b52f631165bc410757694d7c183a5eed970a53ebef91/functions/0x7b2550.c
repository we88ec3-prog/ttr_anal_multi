
void FUN_007b2550(int *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  cVar1 = *(char *)((int)param_1 + 0x39);
  piVar3 = param_1;
  while (cVar1 == '\0') {
    FUN_007b2550(piVar3[2]);
    piVar2 = (int *)*piVar3;
    if (piVar3[10] != 0) {
      FUN_007b2be0(param_1);
      FUN_0089120c(piVar3[10]);
    }
    piVar3[10] = 0;
    piVar3[0xb] = 0;
    piVar3[0xc] = 0;
    if (0xf < (uint)piVar3[8]) {
      FUN_0089120c(piVar3[3]);
    }
    piVar3[8] = 0xf;
    piVar3[7] = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    FUN_0089120c(piVar3);
    piVar3 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x39);
  }
  return;
}

