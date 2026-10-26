
void FUN_008f3370(undefined4 param_1)

{
  longlong lVar1;
  int *in_EAX;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  
  uVar3 = 0;
  if ((((char)in_EAX[0x4b] != '\0') || (iVar2 = FUN_008f31d0(param_1), iVar2 == 0)) &&
     (*(char *)((int)in_EAX + 0x12d) == '\0')) {
    iVar2 = *in_EAX;
    if (in_EAX[0x3c] != 0) {
      do {
        lVar1 = (longlong)(int)*(short *)(*(int *)(iVar2 + 0x288) + uVar3 * 2) *
                (longlong)in_EAX[0x16];
        lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
        *(uint *)(in_EAX[0x3d] + uVar3 * 4) =
             ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)in_EAX[0x3c]);
    }
    uVar3 = 0;
    if ((short)in_EAX[0x42] != 0) {
      do {
        *(undefined4 *)(in_EAX[0x43] + uVar3 * 8) = 0;
        *(undefined4 *)(in_EAX[0x43] + 4 + uVar3 * 8) = 0;
        *(undefined4 *)(in_EAX[0x44] + uVar3 * 8) = 0;
        *(undefined4 *)(in_EAX[0x44] + 4 + uVar3 * 8) = 0;
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(ushort *)(in_EAX + 0x42));
    }
    uVar3 = 0;
    if ((short)in_EAX[0x3e] != 0) {
      do {
        *(undefined4 *)(in_EAX[0x3f] + uVar3 * 4) = 0;
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(ushort *)(in_EAX + 0x3e));
    }
    piVar4 = &DAT_00bead40;
    piVar5 = in_EAX + 0x2b;
    for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    iVar2 = FUN_008f30a0();
    if (iVar2 == 0) {
      *(undefined1 *)((int)in_EAX + 0x12d) = 1;
    }
  }
  return;
}

