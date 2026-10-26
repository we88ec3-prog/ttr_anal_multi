
void FUN_00789250(void)

{
  uint uVar1;
  uint in_EAX;
  uint *unaff_EDI;
  
  uVar1 = unaff_EDI[1];
  if ((in_EAX < uVar1) && (*unaff_EDI <= in_EAX)) {
    if (uVar1 == unaff_EDI[2]) {
      FUN_00788300(1);
    }
    if (unaff_EDI[1] != 0) {
      FUN_00786620();
      unaff_EDI[1] = unaff_EDI[1] + 0x44;
      return;
    }
  }
  else {
    if (uVar1 == unaff_EDI[2]) {
      FUN_00788300(1);
    }
    if (unaff_EDI[1] != 0) {
      FUN_00786620();
    }
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x44;
  return;
}

