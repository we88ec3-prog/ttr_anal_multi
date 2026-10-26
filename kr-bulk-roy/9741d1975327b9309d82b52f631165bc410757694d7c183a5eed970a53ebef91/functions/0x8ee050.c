
void FUN_008ee050(int param_1)

{
  char cVar1;
  uint *in_EAX;
  ushort uVar2;
  undefined1 local_38 [16];
  int local_28;
  undefined4 local_14;
  undefined1 local_10 [4];
  uint local_c;
  ushort local_8;
  
  if (*in_EAX < 2) {
    cVar1 = FUN_008edd70(local_10,&local_14,local_38);
    if (cVar1 == '\0') {
      uVar2 = 0;
      if (*(short *)(param_1 + 0x15c) == 0) {
        local_c = (uint)*(ushort *)(param_1 + 0x74);
      }
      else if ((*(short *)(param_1 + 0x15c) == 1) && (0 < *(short *)(param_1 + 0x76))) {
        local_c = (uint)(ushort)(*(short *)(*(int *)(param_1 + 0x88) + -2 +
                                           *(short *)(param_1 + 0x76) * 2) + 1);
      }
      else {
        local_c = 0;
      }
      if ((ushort)local_c != 0) {
        do {
          if ((local_28 != *(int *)(param_1 + 0x7c)) || (local_8 != uVar2)) {
            FUN_008ede40(local_14);
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < (ushort)local_c);
      }
    }
  }
  else if (*(char *)(param_1 + 0x231) != '\0') {
    *(undefined4 *)(param_1 + 0xc) = 0x86;
    return;
  }
  return;
}

