
void FUN_008edf50(void)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  ushort *in_EAX;
  ushort uVar4;
  int unaff_ESI;
  uint uVar5;
  undefined1 local_3c [16];
  int local_2c;
  undefined4 local_18;
  undefined1 local_14 [4];
  uint local_10;
  uint local_c;
  short local_8;
  
  local_10 = (uint)*in_EAX;
  sVar2 = 1;
  if (*(short *)(unaff_ESI + 0x15c) != 0) {
    sVar2 = *(short *)(unaff_ESI + 0x76);
  }
  uVar5 = (uint)(short)*in_EAX;
  if (uVar5 < (uint)(int)sVar2) {
    cVar1 = FUN_008edd70(local_14,&local_18,local_3c);
    if (cVar1 == '\0') {
      if ((short)local_10 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(short *)(*(int *)(unaff_ESI + 0x88) + -2 + uVar5 * 2) -
                *(short *)(unaff_ESI + 0x8c)) + 1;
      }
      if (*(short *)(unaff_ESI + 0x15c) == 0) {
        uVar4 = *(ushort *)(unaff_ESI + 0x74);
      }
      else {
        uVar4 = (*(short *)(*(int *)(unaff_ESI + 0x88) + uVar5 * 2) - *(short *)(unaff_ESI + 0x8c))
                + 1;
      }
      local_c = (uint)uVar4;
      local_10 = (uint)uVar3;
      if (uVar3 < uVar4) {
        do {
          if ((local_2c != *(int *)(unaff_ESI + 0x7c)) || (local_8 != (short)local_10)) {
            FUN_008ede40(local_18);
          }
          local_10 = local_10 + 1;
        } while ((ushort)local_10 < (ushort)local_c);
      }
    }
  }
  else if (*(char *)(unaff_ESI + 0x231) != '\0') {
    *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
    return;
  }
  return;
}

