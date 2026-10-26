
uint FUN_00755c50(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined3 uVar5;
  uint uVar4;
  uint *in_EDX;
  uint *unaff_ESI;
  
  uVar4 = *unaff_ESI;
  uVar1 = *in_EDX;
  uVar5 = (undefined3)(uVar4 >> 8);
  if ((uVar4 == uVar1) && (unaff_ESI[1] == in_EDX[1])) {
    return CONCAT31(uVar5,1);
  }
  if (uVar4 == uVar1) {
    uVar4 = unaff_ESI[1];
    uVar5 = (undefined3)(uVar4 >> 8);
    if ((int)in_EDX[1] < (int)uVar4) {
      if ((int)uVar4 < (int)in_EDX[3]) {
        return CONCAT31(uVar5,1);
      }
    }
    else if ((int)in_EDX[1] < (int)unaff_ESI[3]) {
      return CONCAT31(uVar5,1);
    }
  }
  else {
    uVar2 = unaff_ESI[1];
    uVar3 = in_EDX[1];
    if (uVar2 == uVar3) {
      if ((int)uVar1 < (int)uVar4) {
        if ((int)uVar4 < (int)in_EDX[2]) {
          return CONCAT31(uVar5,1);
        }
      }
      else if ((int)uVar1 < (int)unaff_ESI[2]) {
        return CONCAT31(uVar5,1);
      }
    }
    else if (((int)uVar4 < (int)uVar1) && ((int)uVar3 < (int)uVar2)) {
      if (((int)uVar1 < (int)unaff_ESI[2]) && ((int)uVar2 < (int)in_EDX[3])) {
        return CONCAT31(uVar5,1);
      }
    }
    else if (((int)uVar1 < (int)uVar4) && ((int)uVar3 < (int)uVar2)) {
      if (((int)uVar4 < (int)in_EDX[2]) && ((int)uVar2 < (int)in_EDX[3])) {
        return CONCAT31(uVar5,1);
      }
    }
    else {
      if (((int)uVar1 < (int)uVar4) && ((int)uVar2 < (int)uVar3)) {
        if ((int)in_EDX[2] <= (int)uVar4) goto LAB_00755d00;
      }
      else if (((int)uVar1 <= (int)uVar4) ||
              (((int)uVar3 <= (int)uVar2 || ((int)unaff_ESI[2] <= (int)uVar1)))) goto LAB_00755d00;
      if ((int)uVar3 < (int)unaff_ESI[3]) {
        return CONCAT31(uVar5,1);
      }
    }
  }
LAB_00755d00:
  return uVar4 & 0xffffff00;
}

