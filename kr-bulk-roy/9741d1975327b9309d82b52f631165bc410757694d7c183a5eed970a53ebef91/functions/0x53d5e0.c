
void FUN_0053d5e0(int *param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  ushort *puVar8;
  
  iVar1 = *param_1;
  iVar3 = param_1[1] - iVar1 >> 0x1f;
  iVar6 = (param_1[1] - iVar1) / 0x14 + iVar3;
  uVar5 = 0;
  if (iVar6 != iVar3) {
    psVar7 = (short *)(iVar1 + 2);
    do {
      if (*psVar7 == *(short *)(param_2 + 4)) {
        puVar8 = (ushort *)(iVar1 + uVar5 * 0x14);
        if (puVar8 != (ushort *)0x0) goto LAB_0053d654;
        break;
      }
      uVar5 = uVar5 + 1;
      psVar7 = psVar7 + 10;
    } while (uVar5 < (uint)(iVar6 - iVar3));
  }
  FUN_0053dd00();
  puVar8 = (ushort *)(param_1[1] + -0x14);
LAB_0053d654:
  puVar8[2] = (ushort)(byte)param_2[1];
  *puVar8 = (ushort)(byte)param_2[2];
  puVar8[1] = *(ushort *)(param_2 + 4);
  *(char *)(puVar8 + 5) = param_2[3];
  *(uint *)(puVar8 + 8) = (uint)(byte)param_2[6];
  *(char *)((int)puVar8 + 0xb) = *param_2;
  if (*param_2 == '\x02') {
    *puVar8 = 0xff;
  }
  switch(param_2[1]) {
  case '\x01':
    puVar8[3] = *(ushort *)(param_2 + 9);
    puVar8[4] = *(ushort *)(param_2 + 7);
    *(uint *)(puVar8 + 6) =
         ((byte)param_2[0xb] - 1 | 0x100) << 0x10 | (uint)*(ushort *)(param_2 + 0xd);
    return;
  case '\x02':
    puVar8[3] = *(ushort *)(param_2 + 9);
    puVar8[4] = *(ushort *)(param_2 + 7);
    return;
  case '\x03':
    puVar8[3] = *(ushort *)(param_2 + 9);
    puVar8[4] = *(ushort *)(param_2 + 7);
    *(uint *)(puVar8 + 6) = *(ushort *)(param_2 + 0xb) | 0x3000000;
    return;
  case '\x04':
    *(uint *)(puVar8 + 8) = (uint)(byte)param_2[6];
    puVar8[3] = (ushort)(byte)param_2[8];
    puVar8[4] = (ushort)(byte)param_2[7];
    *(uint *)(puVar8 + 6) =
         ((byte)param_2[9] - 1 | 0x400) << 0x10 | (uint)*(ushort *)(param_2 + 0xb);
    return;
  case '\x05':
    break;
  case '\x06':
    puVar8[3] = (ushort)(byte)param_2[8];
    puVar8[4] = (ushort)(byte)param_2[7];
    *(uint *)(puVar8 + 6) =
         ((byte)param_2[9] - 1 | 0x100) << 0x10 | (uint)*(ushort *)(param_2 + 0xb);
    return;
  case '\a':
  case '\b':
    puVar8[3] = (ushort)(byte)param_2[8];
    puVar8[4] = (ushort)(byte)param_2[7];
    *(uint *)(puVar8 + 6) = (uint)(byte)param_2[9];
  default:
    return;
  }
  *(undefined4 *)(puVar8 + 6) = *(undefined4 *)(param_2 + 7);
  if ((char)puVar8[5] == '\0') {
    FUN_004054c0();
    FUN_0058aad0(0xf4351);
    return;
  }
  FUN_004054c0();
  puVar4 = (undefined4 *)FUN_00891268(0x18);
  if (puVar4 == (undefined4 *)0x0) {
    FUN_0058aa50(0);
    return;
  }
  uVar2 = *(undefined4 *)(puVar8 + 6);
  puVar4[1] = 0xffffffff;
  puVar4[2] = 0xffffffff;
  puVar4[3] = 0;
  puVar4[4] = 0xf42f1;
  *puVar4 = FoxUI::FXUIEventD1::vftable;
  puVar4[5] = uVar2;
  FUN_0058aa50(puVar4);
  return;
}

