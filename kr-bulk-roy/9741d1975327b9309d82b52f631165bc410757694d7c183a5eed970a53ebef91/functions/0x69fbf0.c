
void FUN_0069fbf0(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  ushort uVar4;
  int *piVar5;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0x642) {
    if (uVar1 == 0x641) {
      iVar2 = 0;
      piVar5 = (int *)(in_ECX + 0xfc);
      do {
        if (*(int *)(param_1 + 8) == *(int *)(*piVar5 + 0x20)) {
          iVar3 = *(int *)(*piVar5 + 0x24c);
          if (iVar3 == 0) {
LAB_0069fcf2:
            iVar3 = -1;
          }
          else {
            iVar3 = *(int *)(iVar3 + 0xcc);
            if (iVar3 == 0) {
              iVar3 = 0;
            }
            else {
              iVar3 = *(int *)(iVar3 + 0xdc);
            }
            if (iVar3 == 0) goto LAB_0069fcf2;
            iVar3 = *(int *)(iVar3 + 0x20);
          }
          piVar5[0x13] = iVar3;
          FUN_006a05a0(in_ECX,iVar2);
        }
        iVar2 = iVar2 + 1;
        piVar5 = piVar5 + 1;
        if (2 < iVar2) {
          return;
        }
      } while( true );
    }
    if (uVar1 == 0x3ea) {
LAB_0069fca7:
      FUN_0069fd30(in_ECX);
      return;
    }
    if (uVar1 == 0x578) {
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0x114) + 0x20)) goto LAB_0069fca7;
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0x118) + 0x20)) {
        FUN_006a0110(in_ECX);
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0xf0) + 0x20)) {
        iVar2 = FUN_004e14f0();
        uVar4 = *(short *)(iVar2 + 0x40) - 1;
      }
      else {
        if (iVar2 != *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) {
          return;
        }
        iVar2 = FUN_004e14f0();
        uVar4 = *(short *)(iVar2 + 0x40) + 1;
      }
      iVar2 = FUN_004e14f0();
      if ((int)(uint)uVar4 <= *(int *)(iVar2 + 0x3c)) {
        FUN_00534810();
        return;
      }
    }
  }
  else if (uVar1 == 0xf43b7) {
    FUN_006a12e0();
  }
  return;
}

