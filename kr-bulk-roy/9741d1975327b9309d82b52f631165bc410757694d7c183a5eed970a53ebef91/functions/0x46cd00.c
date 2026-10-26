
void FUN_0046cd00(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  int *piVar5;
  int *unaff_ESI;
  int iVar6;
  
  if (*(int *)(param_1 + 0x10) != 0x578) {
    return;
  }
  iVar6 = *(int *)(param_1 + 8);
  if (*(int *)(unaff_ESI[0x71] + 0x20) != iVar6) {
    if (*(int *)(unaff_ESI[0x72] + 0x20) == iVar6) {
      FUN_0046d0c0();
      return;
    }
    if (*(int *)(unaff_ESI[0x73] + 0x20) == iVar6) {
      if (unaff_ESI[0x75] != 0) {
        FUN_0046dcf0();
      }
    }
    else if (*(int *)(unaff_ESI[0x74] + 0x20) != iVar6) {
      iVar6 = 0;
      piVar5 = unaff_ESI + 0x3d;
      do {
        if ((iVar6 < 0x31) && (*(int *)(*piVar5 + 0x20) == *(int *)(param_1 + 8))) {
          iVar6 = unaff_ESI[0x16b];
          if ((iVar6 != 0) && ((*(uint *)(iVar6 + 0x28) >> 8 & 1) != 0)) {
            iVar2 = FUN_00404aa0();
            *(int *)(iVar2 + 0x13d0) = iVar6;
            iVar6 = FUN_00404aa0();
            piVar5 = *(int **)(iVar6 + 0x165b4);
            if (piVar5 != (int *)0x0) {
              cVar1 = FUN_00746420();
              if (((cVar1 == '\0') || (((uint)((int *)unaff_ESI[0x16b])[10] >> 7 & 1) == 0)) ||
                 (cVar1 = (**(code **)(*(int *)unaff_ESI[0x16b] + 0x84))(), cVar1 == '\0')) {
                pcVar4 = *(code **)(*piVar5 + 0x14);
                iVar6 = 0;
              }
              else {
                iVar6 = unaff_ESI[0x16b];
                pcVar4 = *(code **)(*piVar5 + 0x14);
              }
              (*pcVar4)(iVar6);
            }
          }
          uVar3 = 0;
          if (((*(uint *)(unaff_ESI[0x6f] + 0x28) >> 9 & 1) != 0) ||
             ((*(uint *)(unaff_ESI[0x70] + 0x28) >> 9 & 1) != 0)) {
            uVar3 = 1;
          }
          FUN_0046d180(uVar3);
          return;
        }
        if ((iVar6 == 1) || (iVar6 == 2)) {
          FUN_0046d690();
        }
        iVar6 = iVar6 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar6 < 0x34);
      return;
    }
    (**(code **)(*unaff_ESI + 0xd4))();
    return;
  }
  FUN_0046ce70(unaff_ESI);
  return;
}

