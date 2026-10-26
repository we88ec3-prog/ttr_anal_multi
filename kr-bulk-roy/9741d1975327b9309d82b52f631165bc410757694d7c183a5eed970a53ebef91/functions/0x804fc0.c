
void FUN_00804fc0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  DWORD *pDVar5;
  DWORD *pDVar6;
  DWORD local_40 [11];
  float local_14;
  float local_10;
  float local_c;
  
  *(int *)(param_1 + 0x68) =
       *(int *)(param_1 + 0x68) + (*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40));
  *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + *(int *)(param_1 + 0x50);
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
  *(int *)(param_1 + 100) =
       *(int *)(param_1 + 100) + (*(int *)(param_1 + 0x3c) - *(int *)(param_1 + 0x38));
  *(int *)(param_1 + 0x6c) =
       *(int *)(param_1 + 0x6c) + (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x48));
  *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + *(int *)(param_1 + 0x54);
  *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + (uint)(*(char *)(param_1 + 0x59) != '\0');
  *(int *)(param_1 + 0x70) =
       *(int *)(param_1 + 0x70) + (*(int *)(param_1 + 0x48) - *(int *)(param_1 + 0x3c));
  *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + (uint)(*(char *)(param_1 + 0x58) != '\0');
  local_40[10] = timeGetTime();
  if (30000 < local_40[10] - *(int *)(param_1 + 0x60)) {
    iVar4 = *(int *)(param_1 + 0x5c);
    if (iVar4 != 0) {
      fVar1 = (float)iVar4;
      if (iVar4 < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      fVar2 = (float)*(int *)(param_1 + 100);
      if (*(int *)(param_1 + 100) < 0) {
        fVar2 = fVar2 + 4.2949673e+09;
      }
      local_10 = fVar2 / fVar1;
      fVar2 = (float)*(int *)(param_1 + 0x68);
      if (*(int *)(param_1 + 0x68) < 0) {
        fVar2 = fVar2 + 4.2949673e+09;
      }
      local_c = fVar2 / fVar1;
      fVar2 = (float)*(int *)(param_1 + 0x6c);
      if (*(int *)(param_1 + 0x6c) < 0) {
        fVar2 = fVar2 + 4.2949673e+09;
      }
      fVar3 = (float)*(int *)(param_1 + 0x70);
      if (*(int *)(param_1 + 0x70) < 0) {
        fVar3 = fVar3 + 4.2949673e+09;
      }
      local_14 = fVar3 / fVar1;
      if (*(int *)(param_1 + 0x8c) != 0) {
        FUN_006f0400();
        FUN_006f0400(0,
                     "[NetStat] PacketProcess Count %u Time %u (ClientPacket Count %u Time %u) / (Overtimed %u / Starved %u)"
                     ,*(undefined4 *)(param_1 + 0x74),*(undefined4 *)(param_1 + 100),
                     *(undefined4 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x68),
                     *(undefined4 *)(param_1 + 0x7c),*(undefined4 *)(param_1 + 0x80));
        FUN_006f0400(0,
                     "[NetStat] PacketProcess Time FrameAVG %.3f (ClientPacket AVG %.3f)  SendFlush TimeAVG %.3f"
                     ,(double)local_10,(double)local_c,(double)(fVar2 / fVar1));
        FUN_006f0400(0,"[NetStat] SendFlush Time %u / FrameMove Time %u (AVG %.3f)",
                     *(undefined4 *)(param_1 + 0x6c),*(undefined4 *)(param_1 + 0x70),
                     (double)local_14);
      }
    }
    local_40[0] = 0;
    local_40[1] = 0;
    local_40[2] = 0;
    local_40[3] = 0;
    local_40[4] = 0;
    local_40[5] = 0;
    local_40[6] = 0;
    local_40[7] = 0;
    local_40[8] = 0;
    local_40[9] = 0;
    pDVar5 = local_40;
    pDVar6 = (DWORD *)(param_1 + 0x5c);
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pDVar6 = *pDVar5;
      pDVar5 = pDVar5 + 1;
      pDVar6 = pDVar6 + 1;
    }
    *(DWORD *)(param_1 + 0x60) = local_40[10];
  }
  return;
}

