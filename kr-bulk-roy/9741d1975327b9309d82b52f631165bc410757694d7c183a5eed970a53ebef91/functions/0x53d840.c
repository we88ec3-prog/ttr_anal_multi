
void FUN_0053d840(int param_1,ushort param_2)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  short *psVar5;
  char *unaff_ESI;
  
  iVar3 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10);
  iVar1 = iVar3 >> 0x1f;
  iVar3 = iVar3 / 0x18 + iVar1;
  uVar4 = 0;
  if (iVar3 != iVar1) {
    psVar5 = (short *)(*(int *)(param_1 + 0x10) + 2);
    do {
      if (*psVar5 == *(short *)(unaff_ESI + 4)) {
        puVar2 = (ushort *)(*(int *)(param_1 + 0x10) + uVar4 * 0x18);
        if (puVar2 != (ushort *)0x0) goto LAB_0053d8b6;
        break;
      }
      uVar4 = uVar4 + 1;
      psVar5 = psVar5 + 0xc;
    } while (uVar4 < (uint)(iVar3 - iVar1));
  }
  FUN_005f84f0();
  puVar2 = (ushort *)(*(int *)(param_1 + 0x14) + -0x18);
LAB_0053d8b6:
  puVar2[10] = param_2;
  puVar2[2] = (ushort)(byte)unaff_ESI[1];
  *puVar2 = (ushort)(byte)unaff_ESI[2];
  puVar2[1] = *(ushort *)(unaff_ESI + 4);
  *(char *)(puVar2 + 5) = unaff_ESI[3];
  *(uint *)(puVar2 + 8) = (uint)(byte)unaff_ESI[6];
  *(char *)((int)puVar2 + 0xb) = *unaff_ESI;
  if (*unaff_ESI == '\x02') {
    *puVar2 = 0xff;
  }
  switch(unaff_ESI[1]) {
  case '\x01':
    puVar2[3] = *(ushort *)(unaff_ESI + 9);
    puVar2[4] = *(ushort *)(unaff_ESI + 7);
    *(uint *)(puVar2 + 6) =
         ((byte)unaff_ESI[0xb] - 1 | 0x100) << 0x10 | (uint)*(ushort *)(unaff_ESI + 0xd);
    return;
  case '\x02':
    puVar2[3] = *(ushort *)(unaff_ESI + 9);
    puVar2[4] = *(ushort *)(unaff_ESI + 7);
    return;
  case '\x03':
    puVar2[3] = *(ushort *)(unaff_ESI + 9);
    puVar2[4] = *(ushort *)(unaff_ESI + 7);
    *(uint *)(puVar2 + 6) = *(ushort *)(unaff_ESI + 0xb) | 0x3000000;
    return;
  case '\x04':
    *(uint *)(puVar2 + 8) = (uint)(byte)unaff_ESI[6];
    puVar2[3] = (ushort)(byte)unaff_ESI[8];
    puVar2[4] = (ushort)(byte)unaff_ESI[7];
    *(uint *)(puVar2 + 6) =
         ((byte)unaff_ESI[9] - 1 | 0x400) << 0x10 | (uint)*(ushort *)(unaff_ESI + 0xb);
    return;
  case '\x05':
    *(undefined4 *)(puVar2 + 6) = *(undefined4 *)(unaff_ESI + 7);
    return;
  case '\x06':
    puVar2[3] = (ushort)(byte)unaff_ESI[8];
    puVar2[4] = (ushort)(byte)unaff_ESI[7];
    *(uint *)(puVar2 + 6) =
         ((byte)unaff_ESI[9] - 1 | 0x100) << 0x10 | (uint)*(ushort *)(unaff_ESI + 0xb);
    return;
  case '\a':
    puVar2[3] = (ushort)(byte)unaff_ESI[8];
    puVar2[4] = (ushort)(byte)unaff_ESI[7];
    *(uint *)(puVar2 + 6) = (uint)(byte)unaff_ESI[9];
    return;
  case '\b':
    puVar2[3] = (ushort)(byte)unaff_ESI[8];
    puVar2[4] = (ushort)(byte)unaff_ESI[7];
    *(uint *)(puVar2 + 6) = (uint)(byte)unaff_ESI[9];
    return;
  case '\v':
    puVar2[3] = (ushort)(byte)unaff_ESI[10];
    puVar2[4] = (ushort)(byte)unaff_ESI[9];
    *(uint *)(puVar2 + 6) = (uint)*(ushort *)(unaff_ESI + 7);
  }
  return;
}

