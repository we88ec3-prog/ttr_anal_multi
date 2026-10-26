
void FUN_00750550(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *unaff_ESI;
  
  piVar1 = (int *)unaff_ESI[0x532];
  piVar3 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(unaff_ESI[0x532] + 4) = unaff_ESI[0x532];
  unaff_ESI[0x533] = 0;
  if (piVar3 != (int *)unaff_ESI[0x532]) {
    do {
      piVar1 = (int *)*piVar3;
      FUN_0089120c(piVar3);
      piVar3 = piVar1;
    } while (piVar1 != (int *)unaff_ESI[0x532]);
  }
  (**(code **)(*unaff_ESI + 4))(unaff_ESI[0x4cb],&stack0x00000008,&stack0x0000001c);
  FUN_007504a0();
  iVar4 = FUN_008fed10();
  unaff_ESI[0x4ef] = iVar4;
  iVar4 = FUN_008fed10();
  unaff_ESI[0x4f0] = iVar4;
  if (unaff_ESI[0x4f1] != 0) {
    (**(code **)(*unaff_ESI + 0x24))(param_1);
    (**(code **)(*unaff_ESI + 0x20))(param_1);
    if ((char)unaff_ESI[0x503] == '\0') {
      (**(code **)(*unaff_ESI + 8))();
    }
    (**(code **)(*unaff_ESI + 0x10))();
    (**(code **)(*unaff_ESI + 0x14))();
    if ((char)unaff_ESI[0x503] == '\0') {
      (**(code **)(*unaff_ESI + 0x18))();
      (**(code **)(*unaff_ESI + 0x1c))();
    }
    (**(code **)(*unaff_ESI + 0x28))(param_1);
    if ((char)unaff_ESI[0x503] == '\0') {
      (**(code **)(*unaff_ESI + 0xc))();
    }
  }
  if (unaff_ESI[0x596d] != 0) {
    piVar1 = (int *)unaff_ESI[0x4f4];
    if ((((piVar1 != (int *)0x0) && (cVar2 = FUN_00746420(), cVar2 != '\0')) &&
        (((uint)piVar1[10] >> 7 & 1) != 0)) &&
       (cVar2 = (**(code **)(*piVar1 + 0x84))(), cVar2 != '\0')) {
      (**(code **)(*(int *)unaff_ESI[0x596d] + 0x14))(unaff_ESI[0x4f4]);
      *(undefined1 *)(unaff_ESI + 0x52f) = 1;
      return;
    }
    (**(code **)(*(int *)unaff_ESI[0x596d] + 0x14))(0);
  }
  *(undefined1 *)(unaff_ESI + 0x52f) = 1;
  return;
}

