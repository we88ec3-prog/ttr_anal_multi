
uint FUN_005f5f90(void)

{
  int *piVar1;
  code *pcVar2;
  uint in_EAX;
  uint uVar3;
  int *unaff_EDI;
  
  uVar3 = in_EAX;
  if (0 < (int)in_EAX) {
    uVar3 = (**(code **)(*unaff_EDI + 0x198))();
    if ((int)in_EAX <= (int)uVar3) {
      uVar3 = unaff_EDI[0x3d];
      piVar1 = *(int **)((uVar3 - 4) + in_EAX * 4);
      if ((char)piVar1[0xb3] != '\x01') {
        pcVar2 = *(code **)(*piVar1 + 0x90);
        *(undefined1 *)(piVar1 + 0xb3) = 1;
        (*pcVar2)(0);
        uVar3 = piVar1[10];
        if ((uVar3 & 8) != 0) {
          uVar3 = uVar3 ^ 8;
          piVar1[10] = uVar3;
        }
      }
      return CONCAT31((int3)(uVar3 >> 8),1);
    }
  }
  return uVar3 & 0xffffff00;
}

