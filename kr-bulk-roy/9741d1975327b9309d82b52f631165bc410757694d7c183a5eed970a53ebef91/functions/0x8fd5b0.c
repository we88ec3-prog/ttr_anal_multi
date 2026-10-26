
void FUN_008fd5b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  uint uVar6;
  
  if (*(char *)(in_ECX + 0x1c) != '\0') {
    if ((*(int *)(in_ECX + 0x58) < 4) && (param_3 != 0)) {
      *(undefined4 *)(in_ECX + 0x58) = 4;
      return;
    }
    if (*(int *)(in_ECX + 0x58) == 6) {
      iVar2 = FUN_006dfc40();
      iVar2 = *(int *)(iVar2 + 0x18);
      iVar3 = FUN_006dfc40();
      iVar3 = *(int *)(iVar3 + 0x1c);
      uVar6 = 0;
      iVar4 = FUN_00572120();
      if (iVar4 != 0) {
        do {
          iVar4 = (uVar6 & 3) * 0x88 + 0xe + (iVar2 + -0x235) / 2;
          iVar1 = (uVar6 >> 2) * 0xbc + 0x1c + (iVar3 + -0x252) / 2;
          if ((((param_1 < iVar4) || (iVar4 + 0x80 <= param_1)) || (param_2 < iVar1)) ||
             (iVar1 + 0xb4 <= param_2)) {
            FUN_00572140();
            FUN_008fd440();
          }
          else {
            FUN_00572140();
            FUN_008fd440();
            if (param_3 != 0) {
              *(undefined1 *)(in_ECX + 0x60) = 1;
              *(uint *)(in_ECX + 100) = uVar6;
            }
          }
          uVar6 = uVar6 + 1;
          uVar5 = FUN_00572120();
        } while (uVar6 < uVar5);
      }
    }
  }
  return;
}

