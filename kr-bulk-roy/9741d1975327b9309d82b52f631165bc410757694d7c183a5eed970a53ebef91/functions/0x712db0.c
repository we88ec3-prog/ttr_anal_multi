
undefined4 FUN_00712db0(undefined4 param_1)

{
  double dVar1;
  double dVar2;
  int *in_EAX;
  int *unaff_ESI;
  float10 fVar3;
  float10 fVar4;
  
  if (*unaff_ESI != 5) {
    return 0;
  }
  if (unaff_ESI[4] != -1) {
    return 0;
  }
  if (unaff_ESI[5] != -1) {
    return 0;
  }
  if (*in_EAX == 5) {
    if (in_EAX[4] != -1) {
      return 0;
    }
    if (in_EAX[5] == -1) {
      dVar1 = *(double *)(unaff_ESI + 2);
      fVar3 = (float10)dVar1;
      dVar2 = *(double *)(in_EAX + 2);
      fVar4 = (float10)dVar2;
      switch(param_1) {
      case 0xc:
        fVar3 = fVar4 + fVar3;
        break;
      case 0xd:
        fVar3 = fVar3 - fVar4;
        break;
      case 0xe:
        fVar3 = fVar4 * fVar3;
        break;
      case 0xf:
        if ((float10)0 == fVar4) {
          return 0;
        }
        fVar3 = fVar3 / fVar4;
        break;
      case 0x10:
        if ((float10)0 == fVar4) {
          return 0;
        }
        fVar4 = (float10)FUN_008ff2e0((double)(fVar3 / fVar4));
        fVar3 = (float10)dVar1 - fVar4 * (float10)dVar2;
        break;
      case 0x11:
        fVar3 = (float10)FUN_008ff5a0();
        break;
      case 0x12:
        fVar3 = -fVar3;
        break;
      default:
        unaff_ESI[2] = 0;
        unaff_ESI[3] = 0;
        return 1;
      case 0x14:
        return 0;
      }
      *(double *)(unaff_ESI + 2) = (double)fVar3;
      return 1;
    }
    return 0;
  }
  return 0;
}

