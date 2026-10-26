
byte FUN_0072a870(int *param_1,int param_2)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  short sVar6;
  bool bVar7;
  uint local_8;
  
  local_8 = 0;
  do {
    uVar3 = param_1[0x1d];
    if (uVar3 < 0x106) {
      FUN_0072a540();
      uVar3 = param_1[0x1d];
      if ((uVar3 < 0x106) && (param_2 == 0)) {
        return 0;
      }
      if (uVar3 == 0) {
        if (param_1[0x17] < 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = param_1[0xe] + param_1[0x17];
        }
        FUN_0072d0f0(iVar4,param_2 == 4);
        param_1[0x17] = param_1[0x1b];
        FUN_007299d0();
        if (*(int *)(*param_1 + 0x10) != 0) {
          return (param_2 == 4) * '\x02' + 1;
        }
        return (param_2 != 4) - 1U & 2;
      }
    }
    if (2 < uVar3) {
      uVar3 = (param_1[0x12] << ((byte)param_1[0x16] & 0x1f) ^
              (uint)*(byte *)(param_1[0xe] + 2 + param_1[0x1b])) & param_1[0x15];
      param_1[0x12] = uVar3;
      *(undefined2 *)(param_1[0x10] + (param_1[0xd] & param_1[0x1b]) * 2) =
           *(undefined2 *)(param_1[0x11] + uVar3 * 2);
      local_8 = (uint)*(ushort *)(param_1[0x10] + (param_1[0x1b] & param_1[0xd]) * 2);
      *(short *)(param_1[0x11] + param_1[0x12] * 2) = (short)param_1[0x1b];
    }
    if (((local_8 != 0) && (param_1[0x1b] - local_8 <= param_1[0xb] - 0x106U)) &&
       (param_1[0x22] != 2)) {
      if (param_1[0x22] == 3) {
        if (param_1[0x1b] - local_8 == 1) {
          iVar4 = FUN_0072a4a0();
          param_1[0x18] = iVar4;
        }
      }
      else {
        iVar4 = FUN_0072a340(local_8);
        param_1[0x18] = iVar4;
      }
    }
    if ((uint)param_1[0x18] < 3) {
      bVar2 = *(byte *)(param_1[0x1b] + param_1[0xe]);
      *(undefined2 *)(param_1[0x5a9] + param_1[0x5a8] * 2) = 0;
      *(byte *)(param_1[0x5a6] + param_1[0x5a8]) = bVar2;
      param_1[0x5a8] = param_1[0x5a8] + 1;
      *(short *)(param_1 + bVar2 + 0x25) = (short)param_1[bVar2 + 0x25] + 1;
      bVar7 = param_1[0x5a8] == param_1[0x5a7] + -1;
      param_1[0x1d] = param_1[0x1d] + -1;
LAB_0072aaf8:
      param_1[0x1b] = param_1[0x1b] + 1;
    }
    else {
      sVar6 = (short)param_1[0x1b] - (short)param_1[0x1c];
      iVar4 = param_1[0x18];
      *(short *)(param_1[0x5a9] + param_1[0x5a8] * 2) = sVar6;
      bVar2 = (char)iVar4 - 3;
      *(byte *)(param_1[0x5a6] + param_1[0x5a8]) = bVar2;
      param_1[0x5a8] = param_1[0x5a8] + 1;
      *(short *)(param_1 + (byte)(&DAT_00c089a0)[bVar2] + 0x126) =
           (short)param_1[(byte)(&DAT_00c089a0)[bVar2] + 0x126] + 1;
      uVar5 = sVar6 - 1;
      if (uVar5 < 0x100) {
        bVar2 = (&DAT_00c087a0)[uVar5];
      }
      else {
        bVar2 = (&DAT_00c088a0)[uVar5 >> 7];
      }
      *(short *)(param_1 + bVar2 + 0x262) = (short)param_1[bVar2 + 0x262] + 1;
      bVar7 = param_1[0x5a8] == param_1[0x5a7] + -1;
      uVar3 = param_1[0x18];
      param_1[0x1d] = param_1[0x1d] - uVar3;
      if ((uVar3 <= (uint)param_1[0x20]) && (2 < (uint)param_1[0x1d])) {
        param_1[0x18] = uVar3 - 1;
        do {
          param_1[0x1b] = param_1[0x1b] + 1;
          uVar3 = ((uint)*(byte *)(param_1[0x1b] + 2U + param_1[0xe]) ^
                  param_1[0x12] << ((byte)param_1[0x16] & 0x1f)) & param_1[0x15];
          param_1[0x12] = uVar3;
          *(undefined2 *)(param_1[0x10] + (param_1[0xd] & param_1[0x1b]) * 2) =
               *(undefined2 *)(param_1[0x11] + uVar3 * 2);
          local_8 = (uint)*(ushort *)(param_1[0x10] + (param_1[0x1b] & param_1[0xd]) * 2);
          *(short *)(param_1[0x11] + param_1[0x12] * 2) = (short)param_1[0x1b];
          piVar1 = param_1 + 0x18;
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
        goto LAB_0072aaf8;
      }
      param_1[0x1b] = param_1[0x1b] + uVar3;
      param_1[0x18] = 0;
      uVar3 = (uint)*(byte *)(param_1[0xe] + param_1[0x1b]);
      param_1[0x12] = uVar3;
      param_1[0x12] =
           (uVar3 << ((byte)param_1[0x16] & 0x1f) ^
           (uint)((byte *)(param_1[0xe] + param_1[0x1b]))[1]) & param_1[0x15];
    }
    if (bVar7) {
      if (param_1[0x17] < 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = param_1[0xe] + param_1[0x17];
      }
      FUN_0072d0f0(iVar4,0);
      iVar4 = *param_1;
      param_1[0x17] = param_1[0x1b];
      uVar3 = *(uint *)(*(int *)(iVar4 + 0x1c) + 0x14);
      if (*(uint *)(iVar4 + 0x10) < uVar3) {
        uVar3 = *(uint *)(iVar4 + 0x10);
      }
      if (uVar3 != 0) {
        FID_conflict__memcpy
                  (*(void **)(iVar4 + 0xc),*(void **)(*(int *)(iVar4 + 0x1c) + 0x10),uVar3);
        *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + uVar3;
        piVar1 = (int *)(*(int *)(iVar4 + 0x1c) + 0x10);
        *piVar1 = *piVar1 + uVar3;
        *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + uVar3;
        *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) - uVar3;
        piVar1 = (int *)(*(int *)(iVar4 + 0x1c) + 0x14);
        *piVar1 = *piVar1 - uVar3;
        iVar4 = *(int *)(iVar4 + 0x1c);
        if (*(int *)(iVar4 + 0x14) == 0) {
          *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar4 + 8);
        }
      }
      if (*(int *)(*param_1 + 0x10) == 0) {
        return 0;
      }
    }
  } while( true );
}

